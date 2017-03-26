#pragma once

#include "field.h"
#include "object.h"
#include "control.h"
#include "item.h"

#include "cocos2d.h"

class Field : public cocos2d::Layer {
protected:
	std::map<std::string, ObjectN*> mObjectList;
	void addObject(ObjectN* obj, std::string objName, int ZOder, bool addChild);

public:
	virtual ~Field();

	virtual bool init();

	virtual void initField();
	virtual void changedField();

	ObjectN* getObject(std::string objName);

	CREATE_FUNC(Field);
};
