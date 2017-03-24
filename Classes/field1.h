#pragma once

#include "field.h"
#include "cocos2d.h"

class Field1 : public Field {
public:
	virtual void initField();
	virtual void changedField();

	CREATE_FUNC(Field1);
};
