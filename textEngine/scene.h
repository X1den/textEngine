#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "include/json.hpp"

using json = nlohmann::json;

class Scene {
public:
	Scene(std::string name_scene, int id, std::vector <std::string> objects)
		: name_scene{ name_scene }, id{ id }, objects{ objects } { }

	void info() {
		std::cout << "Scene name: " << name_scene << "\n";
		std::cout << "Scene ID: " << id << "\n";
		std::cout << "Objects: ";
		for (int i = 0; i < objects.size(); i++) {
			std::cout << objects[i];
			if (i < objects.size() - 1) std::cout << ", ";
		}
		std::cout << std::endl;
	}

	void addObjects(std::vector <std::string>& obj) {
		objects.insert(objects.end(), obj.begin(), obj.end());
	}

	json to_json() const;
	static Scene from_json(const json& j);

private:
	std::string name_scene;
	int id;
	std::vector <std::string> objects;
};