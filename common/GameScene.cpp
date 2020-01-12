#include "GameScene.h"

#include <SimpleAudioEngine.h>


using namespace cocos2d;


static constexpr char BACKGROUND_FILE_NAME[] = "res/chalkboard.jpg";


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

    // display background image
    auto winSize = Director::getInstance()->getWinSize();
    auto backgroundSprite = Sprite::create();
    backgroundSprite->initWithFile(BACKGROUND_FILE_NAME);
    backgroundSprite->setAnchorPoint(Vec2(0, 0));
    backgroundSprite->setPosition(Vec2(0, 0));
    auto backgroundSize = backgroundSprite->getContentSize();
    backgroundSprite->setScale(std::max(winSize.width / backgroundSize.width, winSize.height / backgroundSize.height));
    addChild(backgroundSprite);

    return true;
}

