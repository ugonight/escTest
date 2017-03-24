#pragma once

#include "cocos2d.h"

class Item : public cocos2d::Layer {
public:
	virtual bool init();

	void itemGet(std::string itemName);
	void deleteItem(std::string itemName);

	std::string getSelectedItem();

	static Item* getInstance();

	CREATE_FUNC(Item);

private:
	class ItemObj {
		std::string imgName;
		bool getFlag = 0;

	public:
		ItemObj(std::string imageName) {
			imgName = imageName;
		}

		std::string getImage() { return imgName; };
		void setGetFlag(bool i) { getFlag = i; };
		bool getGetFlag() { return getFlag; };
	};

	std::map<std::string, ItemObj*> mItemList;
	std::string mSelectedItem;
	
	void initItem();
	void updateItem();

	bool touchEvent(cocos2d::Touch* touch, cocos2d::Event* event);
};
