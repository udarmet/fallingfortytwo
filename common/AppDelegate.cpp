#include "AppDelegate.h"

#include "audio/include/AudioEngine.h"

#include "GameScene.h"


using namespace cocos2d;


static const char APP_NAME[] = "Falling Forty-two";
static const Size DESIGN_RESOLUTION_SIZE = {320, 480};
static const float FRAMERATE = 60;


AppDelegate::AppDelegate()
{
}


AppDelegate::~AppDelegate() 
{
    AudioEngine::end();
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
        glview = GLViewImpl::createWithRect(APP_NAME, cocos2d::Rect(0, 0, DESIGN_RESOLUTION_SIZE.width, DESIGN_RESOLUTION_SIZE.height));
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
    if (ratio > DESIGN_RESOLUTION_SIZE.width / DESIGN_RESOLUTION_SIZE.height)
    {
        glview->setDesignResolutionSize(DESIGN_RESOLUTION_SIZE.height * ratio, DESIGN_RESOLUTION_SIZE.height, ResolutionPolicy::EXACT_FIT);
    }
    else
    {
        glview->setDesignResolutionSize(DESIGN_RESOLUTION_SIZE.width, DESIGN_RESOLUTION_SIZE.width / ratio, ResolutionPolicy::EXACT_FIT);
    }

    // create a scene. it's an autorelease object
    auto scene = GameScene::createScene();
    director->runWithScene(scene);

    return true;
}


void AppDelegate::applicationDidEnterBackground()
{
    Director::getInstance()->stopAnimation();
    AudioEngine::pauseAll();
}


void AppDelegate::applicationWillEnterForeground()
{
    Director::getInstance()->startAnimation();
    AudioEngine::resumeAll();
}

