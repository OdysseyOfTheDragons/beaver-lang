#include "Include/def.h"

ReturnType* min(ValueType* a, ValueType* b) {
	ReturnType* ret = (ReturnType*)malloc(sizeof(ReturnType));
	ret->success = true;
	ret->error = NONE;
	ret->ret = NULL;

	if (a->type != b->type || a->type == BOOL_TYPE) {
		ret->success = false;
		ret->error = NO_COMPARISON;
		return ret;
	}

	int int_a, int_b;
	double double_a, double_b;
	char *char_a, *char_b;

	switch (a->type) {
		case INT_TYPE:
			int_a = a->data.intValue;
			int_b = a->data.intValue;
			ret->ret = int_a <= int_b ? a : b;
			break;

		case DOUBLE_TYPE:
			double_a = a->data.doubleValue;
			double_b = a->data.doubleValue;
			ret->ret = double_a <= double_b ? a : b;
			break;

		case STRING_TYPE:
			char_a = a->data.stringValue->content;
			char_b = a->data.stringValue->content;
			ret->ret = strcmp(char_a, char_b) <= 0 ? a : b;
			break;

		default:
			ret->ret = a;
			break;
	}

	return ret;
}
