#include "field.h"

USING_NS_CC;

Field::~Field() {
	for (auto obj : mObjectList) {
		CC_SAFE_RELEASE_NULL(obj.second);
	}
}

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
	//�I�u�W�F�N�g��z�u������
}

void Field::addObject(ObjectN* obj, std::string s, int z, bool addchild) {
	mObjectList[s] = obj;
	obj->retain();
	if (addchild) this->addChild(obj, z, s);
}

void Field::changedField() {
	//���݂̃t�B�[���h�Ɉړ������Ƃ��ɌĂяo����鏈��������
}

ObjectN* Field::getObject(std::string s) {
	return mObjectList[s];
}