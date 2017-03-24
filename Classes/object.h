#pragma once
#include "cocos2d.h"

class ObjectN : public cocos2d::Sprite {
	cocos2d::Rect mArea;
	cocos2d::CallFunc *mTouchEvent;

	bool touchOn(cocos2d::Touch* touch, cocos2d::Event* event);

public:
	virtual bool init();

	void setArea(cocos2d::Rect rect);
	void setTouchEvent(cocos2d::CallFunc *func);

	CREATE_FUNC(ObjectN);
};
