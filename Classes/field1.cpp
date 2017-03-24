#include "field1.h"

USING_NS_CC;

void Field1::initField()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto bg = Sprite::create("field1.png");
	bg->setPosition(visibleSize / 2);
	addChild(bg, 0, "bg");

	auto door = ObjectN::create();
	door->setArea(Rect(190, 100, 70, 110));
	door->setTouchEvent(CallFunc::create([this] {
		if (Item::getInstance()->getSelectedItem() == "key") {
			Control::getInstance()->showMsg("Great!You are a friend who can escape!");
			Item::getInstance()->deleteItem("key");
		}
		else {
			Control::getInstance()->showMsg("The door is locked.");
		}
	}));
	addObject(door, "door", 1, true);

	auto right = ObjectN::create();
	right->setArea(Rect(440, 0, 40, 200));
	right->setTexture("right.png");
	right->setTouchEvent(CallFunc::create([this] {
		Control::getInstance()->changeField("field2");
		Control::getInstance()->showMsg("turn right");
	}));
	addObject(right, "right", 2, true);

	auto key = ObjectN::create();
	key->setTexture("key.png");
	key->setPosition(Vec2(300, 100));
	key->setArea(Rect(280, 200, 40, 40));
	key->setTouchEvent(CallFunc::create([this] {
		Control::getInstance()->showMsg("I got the key");
		Item::getInstance()->itemGet("key");
		removeChildByName("key");
	}));
	addObject(key, "key", 2, false);
}

void Field1::changedField() {
	auto field2 = Control::getInstance()->getField("field2");
	if (!field2->getChildByName("rope")) {
		addChild(mObjectList["key"], 2, "key");
	}
}