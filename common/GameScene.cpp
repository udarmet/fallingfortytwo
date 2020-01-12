#include "GameScene.h"

#include <SimpleAudioEngine.h>


using namespace cocos2d;


static const char BACKGROUND_FILE_NAME[] = "res/chalkboard.jpg";
static const char CIRCLE_SPRITESHEET_FILE_NAME[] = "res/chalk-circle.plist";
static const char CIRCLE_SPRITE_NAME[] = "chalk-circle/00";
static const Size CIRCLE_SPRITE_SIZE = {64, 64};
static const char LINE_SPRITESHEET_FILE_NAME[] = "res/chalk-line.plist";
static const char LINE_SPRITE_NAME[] = "chalk-line/00";
static const Size LINE_SPRITE_SIZE = {320, 320.f/1419*91};


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
    backgroundSprite->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
    backgroundSprite->setPosition(Vec2(0, 0));
    auto backgroundSize = backgroundSprite->getContentSize();
    backgroundSprite->setScale(std::max(winSize.width / backgroundSize.width, winSize.height / backgroundSize.height));
    addChild(backgroundSprite);

    // display circle
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile(CIRCLE_SPRITESHEET_FILE_NAME);
    auto circleSprite = Sprite::createWithSpriteFrameName(CIRCLE_SPRITE_NAME);
    circleSprite->setPosition(winSize / 2);
    circleSprite->setContentSize(CIRCLE_SPRITE_SIZE);
    addChild(circleSprite);

    // display line
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile(LINE_SPRITESHEET_FILE_NAME);
    auto lineSprite = Sprite::createWithSpriteFrameName(LINE_SPRITE_NAME);
    lineSprite->setPosition(winSize / 2);
    lineSprite->setContentSize(LINE_SPRITE_SIZE);
    addChild(lineSprite);

    return true;
}

