#ifndef __MAINMENU_SCENE_H__
#define __MAINMENU_SCENE_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

class MainMenu : public cocos2d::CCLayer
{
public:

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuFunc(CCObject* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(MainMenu);

protected:
	enum menuState { start, option, exit };
};

#endif // __MainMenu_SCENE_H__
