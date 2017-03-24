#include "item.h"

USING_NS_CC;

static Item* instance;

Item *Item::getInstance() {

	return instance;
}

bool Item::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto itemWindow = Sprite::create("itemWindow.png");
	itemWindow->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
	itemWindow->setPosition(Vec2::ZERO);
	addChild(itemWindow, 0, "itemWindow");

	auto possession = Layer::create();
	addChild(possession, 1, "possession");

	auto frame = Sprite::create("select.png");
	frame->setPosition(Vec2(-32, 0));
	frame->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
	addChild(frame, 2, "frame");

	initItem();
	updateItem();

	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(Item::touchEvent, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	mSelectedItem = "";
	instance = this;

	return true;
}

void Item::updateItem() {
	auto possession = getChildByName("possession");
	possession->removeAllChildren();
	for (auto item : mItemList) {
		if (item.second->getGetFlag()) {
			auto spr = Sprite::create(item.second->getImage());
			spr->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
			spr->setPosition(Vec2(32 * possession->getChildrenCount(), 0));
			possession->addChild(spr, 1, item.first);
		}
	}
}

void Item::itemGet(std::string s) {
	mItemList[s]->setGetFlag(1);
	updateItem();
}

void Item::deleteItem(std::string s) {
	mItemList[s]->setGetFlag(0);
	updateItem();
	mSelectedItem = "";
}

bool Item::touchEvent(cocos2d::Touch* touch, cocos2d::Event* event) {
	auto window = getChildByName("itemWindow");
	auto targetBox = window->getBoundingBox();
	auto touchPoint = touch->getLocation();
	if (targetBox.containsPoint(touchPoint)) {
		for (auto item : getChildByName("possession")->getChildren()) {
			if (item->getBoundingBox().containsPoint(touchPoint)) {
				mSelectedItem = item->getName();
				getChildByName("frame")->setPositionX(item->getPositionX());
				break;
			}
		}

		return true;
	}
	return false;
}

std::string Item::getSelectedItem() { return mSelectedItem; }