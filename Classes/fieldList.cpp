#include "control.h"
#include "field.h"

//Fieldクラスをinclude
#include "field1.h"
#include "field2.h"

void Control::initField() {
	//場面登録
	mFieldList["field1"] = Field1::create();
	mFieldList["field2"] = Field2::create();


	for (auto field : mFieldList) {
		field.second->retain();
	}
}