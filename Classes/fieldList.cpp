#include "control.h"
#include "field.h"

//FieldƒNƒ‰ƒX‚ğinclude
#include "field1.h"
#include "field2.h"

void Control::initField() {
	//ê–Ê“o˜^
	mFieldList["field1"] = Field1::create();
	mFieldList["field2"] = Field2::create();


	for (auto field : mFieldList) {
		field.second->retain();
	}
}