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
	auto Categories = ClientManager::Categories;
	auto Modules = ClientManager::GetModulesFromCategory(Categories.at(currentCategory));
	float boxWidth = RenderUtils::GetTextWidth(SortArrayOfStrings(Categories).back(), 1.0f);
	Vec4 boxPos = Vec4(10, 10, boxWidth + 30, Categories.size() * 10 + 10);
	MC_Colour whiteText = MC_Colour(255, 255, 255), greenText = MC_Colour(50, 255, 100);
	for (int C = 0; C < Categories.size(); C++) {
		RenderUtils::RenderText(selectedCategory && currentCategory == C ? Categories.at(C) + " >" : Categories.at(C), Vec2(boxPos.x + 2, C * 10 + 10), selectedCategory && currentCategory == C ? greenText : whiteText, 1.0f, 1.0f);
	}
	if (selectedModule) {
		std::vector< std::string> ModulesText;
		for (auto Mod : Modules) {
			ModulesText.push_back(Mod->name);
		}
		float modulesWidth = RenderUtils::GetTextWidth(SortArrayOfStrings(ModulesText).back(), 1.0f);
		Vec4 modulesPos = Vec4(boxWidth + 30, 10, boxWidth + modulesWidth + 40, Modules.size() * 10 + 10);
		for (int M = 0; M < Modules.size(); M++) {
			RenderUtils::RenderText(selectedModule && currentModule == M ? Modules.at(M)->name + " >" : Modules.at(M)->name, Vec2(modulesPos.x + 2, M * 10 + 10), selectedModule && Modules.at(M)->isEnabled ? greenText : whiteText, 1.0f, 1.0f);
		}
		RenderUtils::FillRectangle(modulesPos, MC_Colour(90, 90, 90), .3f);
		RenderUtils::DrawRectangle(modulesPos, MC_Colour(255, 255, 255), .3f, .8f);
	}
	RenderUtils::FillRectangle(boxPos, MC_Colour(90, 90, 90), .3f);
	RenderUtils::DrawRectangle(boxPos, MC_Colour(255, 255, 255), .3f, .8f);
	RenderUtils::FlushText();
}

void TabGUI::onKey(uint64_t key, bool isDown) {
	auto Categories = ClientManager::Categories;
	auto Modules = ClientManager::GetModulesFromCategory(Categories.at(currentCategory));
	if (isDown) {
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
		}
	}
}