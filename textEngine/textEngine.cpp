#include <iostream>
#include <string>
#include <filesystem>
#include "story_engine.h"
#include "scene.h"
#include "parser.h"
#include "include/json.hpp"

using json = nlohmann::json;

int main() {
    const std::string scenename = "data/scene.json";

    Parser project;

    std::vector <Scene> scenes = project.loadScene(scenename);

    for (auto& out : scenes) {
        out.info();
    }

    return 0;
}