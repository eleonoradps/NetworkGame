//
// Created by efarhan on 7/31/19.
//

#include <engine/scene.h>

void neko::SceneManager::ParseSceneJson(json& sceneJson)
{
    if (CheckJsonParameter(sceneJson, "sceneName", json::value_t::string))
    {
        currentScene_.sceneName = sceneJson["sceneName"];
    }
    else
    {
        currentScene_.sceneName = "New Scene";
    }
    if(CheckJsonParameter(sceneJson, "scenePath", json::value_t::string))
    {
        currentScene_.scenePath = sceneJson["scenePath"];
    }
    if (CheckJsonParameter(sceneJson, "entities", json::value_t::array))
    {
        for (auto& entityJson : sceneJson["entities"])
        {
            ParseEntityJson(entityJson);
        }
    }
}

