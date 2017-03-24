#include "object.h"

USING_NS_CC;

bool ObjectN::init() {
	if (!Sprite::init())
	{
		return false;
	}

	mArea = Rect(0, 0, 0, 0);

	mTouchEvent = CallFunc::create([]() {return; });
	mTouchEvent->retain();

	//デフォルトで中央に表示
	this->setPosition(Director::getInstance()->getVisibleSize() / 2);

	return true;
}

void ObjectN::setArea(cocos2d::Rect rect) {
	mArea = rect;

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(ObjectN::touchOn, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

bool ObjectN::touchOn(cocos2d::Touch* touch, cocos2d::Event* event) {
	if (mArea.containsPoint(Vec2(touch->getLocationInView().x, touch->getLocationInView().y))) {
		runAction(mTouchEvent);
		return true;
	}

	return false;
}

void ObjectN::setTouchEvent(cocos2d::CallFunc *func) { mTouchEvent = func; mTouchEvent->retain(); }

