#include "MainMenuScene.h"
#include "OptionScene.h"

USING_NS_CC;

CCScene* MainMenu::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    MainMenu *layer = MainMenu::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainMenu::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object

	CCMenuItemSprite *startMenu = CCMenuItemSprite::create(
		CCSprite::create("button.png", CCRect(0,0,197,54)),
		CCSprite::create("button.png", CCRect(197,0,197,54)), 
		this,
		menu_selector(MainMenu::menuFunc));
	startMenu->setTag(menuState::start);

	CCMenuItemSprite *optionMenu = CCMenuItemSprite::create(
		CCSprite::create("button.png", CCRect(0, 108, 197, 54)),
		CCSprite::create("button.png", CCRect(197, 108, 197, 54)),
		this, menu_selector(MainMenu::menuFunc));
	optionMenu->setTag(menuState::option);

	CCMenuItemSprite *exitMenu = CCMenuItemSprite::create(
		CCSprite::create("button.png", CCRect(197, 270, 197, 54)),
		CCSprite::create("button.png", CCRect(394, 270, 197, 54)),
		this, menu_selector(MainMenu::menuFunc));
	exitMenu->setTag(menuState::exit);

//	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

//	startMenu->setPosition(ccp(origin.x + visibleSize.width/2 - startMenu->getContentSize().width/2 , origin.y + startMenu->getContentSize().height/2));

    // create menu, it's an autorelease object
	CCMenu* pMenu = CCMenu::create(startMenu,optionMenu, exitMenu, NULL);
	pMenu->alignItemsVerticallyWithPadding(20);
	pMenu->setPosition(ccp(origin.x + visibleSize.width/2 , origin.y + visibleSize.height/2));

	
	CCSprite* backGround = CCSprite::create("background1.png",CCRect(0,0,visibleSize.width, visibleSize.height));
	backGround->setPosition(ccp(backGround->getContentSize().width/2,backGround->getContentSize().height/2));
	this->addChild(backGround);

	this->addChild(pMenu);

//	this->setTouchEnabled(true);

	//¹è°æÀ½
	//CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("background-music-aac.wav", true);
	
    return true;
}


void MainMenu::menuFunc(CCObject* pSender)
{
	CCMenuItem* item = (CCMenuItem*)pSender;
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
	switch(item->getTag())
	{
	case start:
		break;
	case option:
		{
		CCScene *pScene = OptionScene::scene();
		CCDirector::sharedDirector()->replaceScene(pScene);
		}
		break;
	case exit:
		CCDirector::sharedDirector()->end();
		break;
	};

//    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}
