#pragma once
#include "scene.h"
#include "include/json.hpp"

using json = nlohmann::json;

class StoryEngine {
public:
	void addScenes(const Scene& scene);

	void listScenes();

private:
	std::vector<Scene> scenes;
};