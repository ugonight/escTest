#pragma once

#include "cocos2d.h"

class Field;

class Control : public cocos2d::Scene {
private:
	std::map<std::string, Field*> mFieldList;

public:
	~Control();

	virtual bool init();
	void initField();

	void changeField(std::string field);
	void showMsg(std::string msg);

	Field* getField(std::string field);

	static Control* getInstance();

	CREATE_FUNC(Control);
};
