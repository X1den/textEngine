#include "story_engine.h"
#include "scene.h"
#include "include/json.hpp"

using json = nlohmann::json;

void StoryEngine::addScenes(const Scene& scene) {
	scenes.push_back(scene);
}

void StoryEngine::listScenes() {
	for (auto& s : scenes) {
		s.info();
	}
}