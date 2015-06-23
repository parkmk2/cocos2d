#include "OptionScene.h"
#include "MainMenuScene.h"

USING_NS_CC;

CCScene* OptionScene::scene()
{
	CCScene *scene = CCScene::create();
	OptionScene *layer = OptionScene::create();
	scene->addChild(layer);
	return scene;
}

bool OptionScene::init()
{
	if(!CCLayer::init())
	{
		return false;
	}

	initBg();
	initMenu();
}

void OptionScene::initBg()
{
	
	CCSprite *background = CCSprite::create("background1.png");
	background->setPosition(ccp(background->getContentSize().width/2, background->getContentSize().height/2));
	this->addChild(background);

}

void OptionScene::initMenu()
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	//back button
	CCMenuItemSprite *backMenu = CCMenuItemSprite::create(
		CCSprite::create("button.png",CCRect(394, 324, 197, 54)),
		CCSprite::create("button.png",CCRect(591, 324, 197, 54)),
		this,
		menu_selector(OptionScene::menuFunc));
	backMenu->setTag(optionState::back);
	backMenu->setPosition(ccp(size.width - backMenu->getContentSize().width, backMenu->getContentSize().height));

	CCMenu *pMenu = CCMenu::create(backMenu, NULL);
	pMenu->setPosition(ccp(0, 0));
	this->addChild(pMenu);
}

void OptionScene::menuFunc(CCObject* pSender)
{
	CCMenuItem *item =  (CCMenuItem*)pSender;
	
	switch(item->getTag())
	{
	case back:
		CCScene *pScene = MainMenu::scene();
		CCDirector::sharedDirector()->replaceScene(pScene);
		break;

	};
}




