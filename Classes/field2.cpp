#include "field2.h"

USING_NS_CC;

void Field2::initField()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto bg = Sprite::create("field2.png");
	bg->setPosition(visibleSize / 2);
	addChild(bg, 0, "bg");

	auto left = ObjectN::create();
	left->setArea(Rect(0, 0, 40, 200));
	left->setTexture("left.png");
	left->setTouchEvent(CallFunc::create([this] {
		Control::getInstance()->changeField("field1");
		Control::getInstance()->showMsg("turn left");
	}));
	addObject(left, "left", 1, true);

	auto rope = ObjectN::create();
	rope->setArea(Rect(345, 0, 30, 190));
	rope->setTouchEvent(CallFunc::create([this] {
		Control::getInstance()->showMsg("There was a noise behind.");
		removeChildByName("rope");
	}));
	addObject(rope, "rope", 2, true);
}
