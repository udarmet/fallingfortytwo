#include "AppDelegate.h"

#include <audio/include/SimpleAudioEngine.h>

#include "GameScene.h"


using namespace cocos2d;
using namespace CocosDenshion;


static constexpr char APP_NAME[] = "Falling Forty-two";
static constexpr float DESIGN_RESOLUTION_WIDTH = 320;
static constexpr float DESIGN_RESOLUTION_HEIGHT = 480;
static constexpr float FRAMERATE = 60;


AppDelegate::AppDelegate()
{
}


AppDelegate::~AppDelegate() 
{
    SimpleAudioEngine::end();
}


void AppDelegate::initGLContextAttrs()
{
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8, 0};
    GLView::setGLContextAttrs(glContextAttrs);
}


bool AppDelegate::applicationDidFinishLaunching()
{
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if (!glview)
    {
#if CC_TARGET_PLATFORM == CC_PLATFORM_LINUX
        glview = GLViewImpl::createWithRect(APP_NAME, cocos2d::Rect(0, 0, DESIGN_RESOLUTION_WIDTH, DESIGN_RESOLUTION_HEIGHT));
#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
        glview = GLViewImpl::create(APP_NAME);
#endif
        director->setOpenGLView(glview);
    }
#ifdef COCOS2D_DEBUG
    director->setDisplayStats(true);
#endif
    director->setAnimationInterval(1 / FRAMERATE);

    // Set the design resolution
    auto frameSize = glview->getFrameSize();
    float ratio = frameSize.width / frameSize.height;
    if (ratio > DESIGN_RESOLUTION_WIDTH / DESIGN_RESOLUTION_HEIGHT)
    {
        glview->setDesignResolutionSize(DESIGN_RESOLUTION_HEIGHT * ratio, DESIGN_RESOLUTION_HEIGHT, ResolutionPolicy::EXACT_FIT);
    }
    else
    {
        glview->setDesignResolutionSize(DESIGN_RESOLUTION_WIDTH, DESIGN_RESOLUTION_WIDTH / ratio, ResolutionPolicy::EXACT_FIT);
    }

    // create a scene. it's an autorelease object
    auto scene = GameScene::createScene();
    director->runWithScene(scene);

    return true;
}


void AppDelegate::applicationDidEnterBackground()
{
    Director::getInstance()->stopAnimation();
    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
    SimpleAudioEngine::getInstance()->pauseAllEffects();
}


void AppDelegate::applicationWillEnterForeground()
{
    Director::getInstance()->startAnimation();
    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
    SimpleAudioEngine::getInstance()->resumeAllEffects();
}

