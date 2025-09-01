#include <string>
#include <vector>
#include "scene.h"
#include "include/json.hpp"

using json = nlohmann::json;

json Scene::to_json() const {
	return {
		{"name_scene", name_scene},
		{"id", id},
		{"objects", objects},
	};
}

Scene Scene::from_json(const json& j) {
	return Scene(
		j["name_scene"].get<std::string>(),
		j["id"].get<int>(),
		j["objects"].get<std::vector<std::string>>()
	);
}