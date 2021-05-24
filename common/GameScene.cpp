#include "GameScene.h"

#include "audio/include/AudioEngine.h"


using namespace cocos2d;


static const char BACKGROUND_FILE_NAME[] = "res/chalkboard.jpg";

static const char TITLE_LABEL_TEXT[] = "FALLING\nFORTY-TWO";
static const char TITLE_LABEL_FONT_FILE_NAME[] = "fonts/KG Second Chances Sketch.ttf";
static const int TITLE_LABEL_FONT_SIZE = 40;

static const char CIRCLE_SPRITESHEET_FILE_NAME[] = "res/chalk-circle.plist";
static const char CIRCLE_SPRITE_NAME[] = "chalk-circle/00";
static const Size CIRCLE_SPRITE_SIZE = {64, 64};

static const char LINE_SPRITESHEET_FILE_NAME[] = "res/chalk-line.plist";
static const char LINE_SPRITE_NAME[] = "chalk-line/00";
static const Size LINE_SPRITE_SIZE = {320, 320.f/1419*91};

static const char SOME_TEXT_LABEL_TEXT[] = "You're gonna enjoy\nthis new version\nso much!";
static const char SOME_TEXT_FONT_FILE_NAME[] = "fonts/DK Cool Crayon.ttf";
static const int SOME_TEXT_FONT_SIZE = 24;


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

    // display title
    auto titleLabel = Label::createWithTTF(TITLE_LABEL_TEXT, TITLE_LABEL_FONT_FILE_NAME, TITLE_LABEL_FONT_SIZE);
    titleLabel->setAlignment(TextHAlignment::CENTER);
    titleLabel->setAnchorPoint(Vec2::ANCHOR_MIDDLE_TOP);
    titleLabel->setPosition(Vec2(winSize.width / 2, winSize.height));
    addChild(titleLabel);

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

    // display some text
    auto someTextLabel = Label::createWithTTF(SOME_TEXT_LABEL_TEXT, SOME_TEXT_FONT_FILE_NAME, SOME_TEXT_FONT_SIZE);
    someTextLabel->setAlignment(TextHAlignment::CENTER);
    someTextLabel->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    someTextLabel->setPosition(Vec2(winSize.width / 2, winSize.height / 4));
    addChild(someTextLabel);

    return true;
}

