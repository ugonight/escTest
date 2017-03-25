#include "control.h"
#include "field.h"	
#include "item.h"	

USING_NS_CC;

static Control* instance;

Control *Control::getInstance() {

	return instance;
}

Control::~Control() {
	for (auto field : mFieldList) {
		CC_SAFE_RELEASE_NULL(field.second);
	}
}

bool Control::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	initField();

	addChild(mFieldList["field1"], 0, "field");

	auto item = Item::create();
	addChild(item, 1, "item");

	auto msg = Label::createWithTTF("Hellow,World", "fonts/Marker Felt.ttf", 24);
	msg->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + 60));
	msg->setTextColor(Color4B::BLACK);
	this->addChild(msg, 1, "msg");

	instance = this;

	return true;
}

void Control::changeField(std::string s) {
	removeChildByName("field");
	addChild(mFieldList[s], 0, "field");
	mFieldList[s]->changedField();
}

void Control::showMsg(std::string s) {
	((Label*)getChildByName("msg"))->setString(s);
}

Field* Control::getField(std::string field) {
	return mFieldList[field];
}