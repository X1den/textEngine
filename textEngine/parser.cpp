#include <fstream>
#include <stdexcept>
#include <vector>
#include "parser.h"
#include "scene.h"
#include "include/json.hpp"

using json = nlohmann::json;

std::vector<Scene> Parser::loadScene(const std::string& filename) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Cannot open file: " << filename << std::endl;
		return {};
	}
	json j;
	file >> j;

	std::vector <Scene> scenes;
	for (auto& s : j["Scenes"]) {
		Scene scene(
			s["name_scene"],
			s["id"],
			s["objects"].get<std::vector <std::string>>()
		);
		scenes.push_back(scene);
	}
	return scenes;
}

void Parser::loadSc(const std::string& filename) {
	std::ifstream load(filename);
	if (!load.is_open()) std::cerr << "Error while opening the file. Load Scene";
	load >> main_scene;
}

void Parser::loadSt(const std::string& filename) {
	std::ifstream load(filename);
	if (!load.is_open()) std::cerr << "Error while opening the file. Load Story";
	load >> main_story;
}

void Parser::saveSc(const std::string& filename) {
	std::ofstream save(filename);
	if (!save.is_open()) std::cerr << "Error while opening the file. Save Scene";
	save << main_scene.dump(4);
}

void Parser::saveSt(const std::string& filename) {
	std::ofstream save(filename);
	if (!save.is_open()) std::cerr << "Error while opening the file. Save Story";
	save << main_story.dump(4);
}