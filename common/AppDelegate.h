#ifndef __APP_DELEGATE_H__
#define __APP_DELEGATE_H__

#include <cocos2d.h>


class AppDelegate : private cocos2d::Application
{
public:

    AppDelegate();
    virtual ~AppDelegate();

    virtual void initGLContextAttrs();

    virtual bool applicationDidFinishLaunching();
    virtual void applicationDidEnterBackground();
    virtual void applicationWillEnterForeground();

    static constexpr char APP_NAME[] = "Falling Forty-two";
    static constexpr float DESIGN_RESOLUTION_WIDTH = 320;
    static constexpr float DESIGN_RESOLUTION_HEIGHT = 480;
    static constexpr float FRAMERATE = 60;
};


#endif // __APP_DELEGATE_H__

