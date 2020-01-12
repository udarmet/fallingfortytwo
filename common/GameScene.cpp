#include "GameScene.h"

#include <SimpleAudioEngine.h>


using namespace cocos2d;


Scene* GameScene::createScene()
{
    return GameScene::create();
}


bool GameScene::init()
{
    if (!Scene::init())
    {
        return false;
    }
    return true;
}

