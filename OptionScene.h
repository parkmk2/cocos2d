#ifndef __OPTION_SCENE_H__
#define __OPTION_SCENE_H__

#include "cocos2d.h"

class OptionScene : public cocos2d::CCLayer
{
public:
	static cocos2d::CCScene* scene();
	virtual bool init();	

	void menuFunc(CCObject* pSender);

	CREATE_FUNC(OptionScene);

private :
	enum optionState { back };

	void initBg();
	void initMenu();
};


#endif