#include "field.h"

USING_NS_CC;

bool Field::init()
{
	if (!Layer::init())
	{
		return false;
	}

	initField();

	return true;
}

void Field::initField() {
	//オブジェクトを配置したり
}

void Field::addObject(ObjectN* obj, std::string s, int z, bool addchild) {
	mObjectList[s] = obj;
	obj->retain();
	if (addchild) this->addChild(obj, z, s);
}

void Field::changedField() {
	//現在のフィールドに移動したときに呼び出される処理を書く
}

ObjectN* Field::getObject(std::string s) {
	return mObjectList[s];
}