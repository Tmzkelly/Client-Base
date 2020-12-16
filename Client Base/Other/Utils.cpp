#include "Utils.h"

bool Utils::hasExtension(std::string fileName) {
	std::string::size_type idx;
	idx = fileName.rfind('.');

	return idx != std::string::npos;
}

bool Utils::doesPathExist(std::string path) {
	struct stat buffer;
	return (stat(path.c_str(), &buffer) == 0);
}

void Utils::CreateDir(std::string path) {
	if (!hasExtension(path)) {
		std::string envPath = getenv("APPDATA");
		if (envPath.length() <= 0)
			return;

		std::string roamingDir = envPath + std::string("\\..\\Local\\Packages\\Microsoft.MinecraftUWP_8wekyb3d8bbwe\\RoamingState\\");
		if (!doesPathExist(roamingDir))
			return;

		std::string precisePath = std::string(roamingDir + path);
		std::filesystem::create_directories(precisePath);
	}
}

void Utils::DeletePath(std::string path) {
	std::string precisePath = getenv("APPDATA") + std::string("\\..\\Local\\Packages\\Microsoft.MinecraftUWP_8wekyb3d8bbwe\\RoamingState\\" + path);
	if (doesPathExist(precisePath)) {
		if (std::filesystem::is_directory(precisePath)) {
			std::filesystem::remove_all(precisePath);
		}
		else {
			std::filesystem::remove(precisePath);
		}
	}
}

void Utils::WriteToFile(std::string str, std::string path) {
	if (hasExtension(path)) {
		std::string precisePath = getenv("APPDATA") + std::string("\\..\\Local\\Packages\\Microsoft.MinecraftUWP_8wekyb3d8bbwe\\RoamingState\\" + path);
		if (!doesPathExist(precisePath)) {
			std::filesystem::path p(precisePath);
			std::filesystem::create_directories(p.parent_path().string());
		}

		CloseHandle(CreateFileA(precisePath.c_str(), GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL));
		if (doesPathExist(precisePath) && str.length() > 0) {
			std::ofstream fileOutput;
			fileOutput.open(precisePath.c_str(), std::ios_base::app);
			fileOutput << str << std::endl;
			fileOutput.close();
		}
	}
}

void Utils::DebugLogOutput(std::string str) {
	WriteToFile(str, "Client/Output.txt");
	return;
}

uintptr_t Utils::FindAddr(uintptr_t ptrBase, std::vector<unsigned int> offsets) {
	uintptr_t curr = NULL;
	if (ptrBase != NULL) {
		curr = ptrBase;
		for (unsigned int I = 0; I < offsets.size(); I++) {
			curr = *(uintptr_t*)(curr += offsets[I]);
			if (curr == NULL) {
				break;
			}
		}
	}
	return curr;
}

uintptr_t Utils::FindSig(const char* szSignature) {
	const char* pattern = szSignature;
	uintptr_t firstMatch = 0;
	static const uintptr_t rangeStart = (uintptr_t)GetModuleHandleA("Minecraft.Windows.exe");
	static MODULEINFO miModInfo;
	static bool init = false;
	if (!init) {
		init = true;
		GetModuleInformation(GetCurrentProcess(), (HMODULE)rangeStart, &miModInfo, sizeof(MODULEINFO));
	}
	static const uintptr_t rangeEnd = rangeStart + miModInfo.SizeOfImage;

	BYTE patByte = GET_BYTE(pattern);
	const char* oldPat = pattern;

	for (uintptr_t pCur = rangeStart; pCur < rangeEnd; pCur++)
	{
		if (!*pattern)
			return firstMatch;

		while (*(PBYTE)pattern == ' ')
			pattern++;

		if (!*pattern)
			return firstMatch;

		if (oldPat != pattern) {
			oldPat = pattern;
			if (*(PBYTE)pattern != '\?')
				patByte = GET_BYTE(pattern);
		}

		if (*(PBYTE)pattern == '\?' || *(BYTE*)pCur == patByte)
		{
			if (!firstMatch)
				firstMatch = pCur;

			if (!pattern[2])
				return firstMatch;

			pattern += 2;
		}
		else
		{
			pattern = szSignature;
			firstMatch = 0;
		}
	}
}

std::string Utils::ptrToStr(uintptr_t ptr) {
	std::ostringstream ss;
	ss << std::hex << ((UINT64)ptr) << std::endl;
	return ss.str();
}