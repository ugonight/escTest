#include "control.h"
#include "field.h"

//Field�N���X��include
#include "field1.h"
#include "field2.h"

void Control::initField() {
	//��ʓo�^
	mFieldList["field1"] = Field1::create();
	mFieldList["field2"] = Field2::create();


	for (auto field : mFieldList) {
		field.second->retain();
	}
}