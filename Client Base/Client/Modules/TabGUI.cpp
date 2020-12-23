#include "TabGUI.h"
#include "../ClientManager.h"

std::vector<std::string> SortArrayOfStrings(std::vector<std::string> stringVecArr) {
	std::vector<std::string> stringArr;

	for (int I = 0; I < stringVecArr.size(); I++) {
		stringArr.push_back(stringVecArr.at(I));
	};

	for (int I = 0; I < stringArr.size(); I++) {
		std::string temp = stringArr[I];

		int J = I - 1;
		while (J >= 0 && temp.length() < stringArr[J].length()) {
			stringArr[J + 1] = stringArr[J];
			J--;
		}
		stringArr[J + 1] = temp;
	};
	return stringArr;
};

void TabGUI::onRender() {
	RenderUtils::RenderText("Client", Vec2(12, 0), MC_Colour(50, 200, 150), 1.0f, 1.0f);
	if (Minecraft::ClientInstance() != nullptr && Minecraft::ClientInstance()->MinecraftGame()->canUseKeys()) {
		auto Categories = ClientManager::Categories;
		auto Modules = ClientManager::GetModulesFromCategory(Categories.at(currentCategory));
		float boxWidth = RenderUtils::GetTextWidth(SortArrayOfStrings(Categories).back(), 1.0f);
		Vec4 boxPos = Vec4(10, 0, boxWidth + 30, Categories.size() * 10 + 10);
		MC_Colour whiteText = MC_Colour(255, 255, 255), selectedColourText = MC_Colour(50, 175, 200);
		for (int C = 0; C < Categories.size(); C++) {
			RenderUtils::RenderText(">>", Vec2(boxPos.z - 10, currentCategory * 10 + 10), selectedColourText, 1.0f, selectedCategory ? 1.0f : 0.f);
			RenderUtils::RenderText(Categories.at(C), Vec2(boxPos.x + 2, C * 10 + 10), selectedCategory && currentCategory == C ? selectedColourText : whiteText, 1.0f, 1.0f);
		}
		if (selectedModule) {
			std::vector< std::string> ModulesText;
			for (auto Mod : Modules) {
				ModulesText.push_back(Mod->name);
			}
			float modulesWidth = RenderUtils::GetTextWidth(SortArrayOfStrings(ModulesText).back(), 1.0f);
			Vec4 modulesPos = Vec4(boxWidth + 30, 0, boxWidth + modulesWidth + 50, Modules.size() * 10 + 10);
			RenderUtils::RenderText(Categories.at(currentCategory), Vec2(modulesPos.x + 2, 0), MC_Colour(50, 200, 150), 1.0f, 1.0f);
			for (int M = 0; M < Modules.size(); M++) {
				RenderUtils::RenderText(">>", Vec2(modulesPos.z - 10, currentModule * 10 + 10), selectedColourText, 1.0f, selectedModule ? 1.0f : 0.f);
				RenderUtils::RenderText(Modules.at(M)->name, Vec2(modulesPos.x + 2, M * 10 + 10), selectedModule && Modules.at(M)->isEnabled ? selectedColourText : whiteText, 1.0f, 1.0f);
			}
			RenderUtils::FillRectangle(modulesPos, MC_Colour(90, 90, 90), .3f);
			RenderUtils::DrawRectangle(modulesPos, MC_Colour(255, 255, 255), .3f, .8f);
		}
		RenderUtils::FillRectangle(boxPos, MC_Colour(90, 90, 90), .3f);
		RenderUtils::DrawRectangle(boxPos, MC_Colour(255, 255, 255), .3f, .8f);
		RenderUtils::FlushText();
	}
}

void TabGUI::onKey(uint64_t key, bool isDown, bool* cancel) {
	auto Categories = ClientManager::Categories;
	auto Modules = ClientManager::GetModulesFromCategory(Categories.at(currentCategory));
	if (isDown && Minecraft::ClientInstance() != nullptr && Minecraft::ClientInstance()->MinecraftGame()->canUseKeys()) {
		if (key == 0x25) { //Left
			if (selectedModule) {
				currentModule = 0;
				selectedModule = false;
			}
			else {
				if (selectedCategory) {
					selectedCategory = false;
				}
			}
			*cancel = true;
		}
		if (key == 0x27) { //Right
			if (!selectedCategory) {
				selectedCategory = true;
			}
			else {
				if (!selectedModule) {
					selectedModule = true;
				}
				else {
					Module* currModule = Modules.at(currentModule);
					if (currModule != nullptr) currModule->isEnabled = !currModule->isEnabled;
				}
			}
			*cancel = true;
		}
		if (key == 0x26) { //Up
			if (selectedCategory && !selectedModule) {
				if (!currentCategory) currentCategory = Categories.size();
				currentCategory--;
			}
			else {
				if (selectedModule) {
					if (!currentModule) currentModule = Modules.size();
					currentModule--;
				}
			}
			*cancel = true;
		}
		if (key == 0x28) { //Down
			if (selectedCategory && !selectedModule) {
				currentCategory++;
				if (currentCategory >= Categories.size()) currentCategory = 0;
			}
			else {
				if (selectedModule) {
					currentModule++;
					if (currentModule >= Modules.size()) currentModule = 0;
				}
			}
			*cancel = true;
		}
	}
}