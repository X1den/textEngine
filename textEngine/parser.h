#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include "include/json.hpp"

using json = nlohmann::json;

class Scene;

class Parser {
public:
	void loadSt(const std::string& filename);

	void loadSc(const std::string& filename);

	void saveSt(const std::string& filename);

	void saveSc(const std::string& filename);

	std::vector<Scene> loadScene(const std::string& filename);

private:
	json main_scene;
	json main_story;
};