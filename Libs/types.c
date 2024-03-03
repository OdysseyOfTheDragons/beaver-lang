/**
 * @file
 * @brief Utility functions to manipulate the application types.
 *
 * @author Alexandre Conseil
 * @date 2024
 */

#include "Include/def.h"
#include "Include/types.h"

int type(ValueType* value) {
	return value->type;
}

IntType* type_int(const int value) {
	IntType* val = (IntType*)malloc(sizeof(IntType));
	val->content = value;
	return val;
}

void destroy_int(IntType* object) {
	free(object);
}

BoolType* type_bool(const bool value) {
	BoolType* val = (BoolType*)malloc(sizeof(BoolType));
	val->content = value;
	return val;
}

void destroy_bool(BoolType* object) {
	free(object);
}

DoubleType* type_double(const double value) {
	DoubleType* val = (DoubleType*)malloc(sizeof(DoubleType));
	val->content = value;
	return val;
}

void destroy_double(DoubleType* object) {
	free(object);
}

StringType* type_string(char* value) {
	StringType* val = (StringType*)malloc(sizeof(StringType));
	val->content = value;
	val->length = strlen(value);
	val->hash = 0;
	return val;
}

void destroy_string(StringType* object) {
	free(object->content);
	free(object);
}

ValueType* type_empty(const int type, ...) {
	va_list args;
	va_start(args, type);

	ValueType* val = (ValueType*)malloc(sizeof(ValueType));
	val->type = type;

	switch (type) {
		case INT_TYPE:
			val->data.intValue = type_int(va_arg(args, int));
			break;

		case BOOL_TYPE:
			val->data.boolValue = type_bool((bool)va_arg(args, int));
			break;

		case DOUBLE_TYPE:
			val->data.doubleValue = type_double(va_arg(args, double));
			break;

		case STRING_TYPE:
			val->data.stringValue = type_string(va_arg(args, char*));
			break;

		default:
			val->type = INT_TYPE;
			val->data.intValue = type_int(0);
	}

	va_end(args);
	return val;
}

void destroy_type(ValueType* object) {
	switch (type(object)) {
		case INT_TYPE:
			destroy_int(object->data.intValue);
			break;

		case BOOL_TYPE:
			destroy_bool(object->data.boolValue);
			break;

		case DOUBLE_TYPE:
			destroy_double(object->data.doubleValue);
			break;

		case STRING_TYPE:
			destroy_string(object->data.stringValue);
			break;

		default:
			break;
	}

	free(object);
}

ReturnType return_type(bool success, ...) {
	va_list args;
	va_start(args, success);

	ReturnType rt = {
		.success = success,
		.ret = NULL,
		.error = NONE
	};

	if (success) {
		rt.ret = va_arg(args, ValueType*);
	} else {
		rt.error = va_arg(args, int);
	}

	va_end(args);
	return rt;
}

ReturnType fetch_int(ValueType* object) {
	if (type(object) != INT_TYPE) {
		return return_type(false, INCORRECT_TYPE);
	}

	return return_type(true, object->data.intValue->content);
}

ReturnType set_int(ValueType* object, const int value) {
	if (type(object) != INT_TYPE) {
		return return_type(false, INCORRECT_TYPE);
	}

	object->data.intValue->content = value;
	return return_type(true, NULL);
}

ReturnType fetch_bool(ValueType* object) {
	if (type(object) != BOOL_TYPE) {
		return return_type(false, INCORRECT_TYPE);
	}

	return return_type(true, object->data.boolValue->content);
}

ReturnType set_bool(ValueType* object, const bool value) {
	if (type(object) != BOOL_TYPE) {
		return return_type(false, INCORRECT_TYPE);
	}

	object->data.boolValue->content = value;
	return return_type(true, NULL);
}


ReturnType fetch_double(ValueType* object) {
	if (type(object) != DOUBLE_TYPE) {
		return return_type(false, INCORRECT_TYPE);
	}

	return return_type(true, object->data.doubleValue->content);
}

ReturnType set_double(ValueType* object, const double value) {
	if (type(object) != DOUBLE_TYPE) {
		return return_type(false, INCORRECT_TYPE);
	}

	object->data.doubleValue->content = value;
	return return_type(true, NULL);
}

ReturnType fetch_string(ValueType* object) {
	if (type(object) != STRING_TYPE) {
		return return_type(false, INCORRECT_TYPE);
	}

	return return_type(true, object->data.stringValue->content);
}

ReturnType set_string(ValueType* object, char* value) {
	if (type(object) != STRING_TYPE) {
		return return_type(false, INCORRECT_TYPE);
	}

	object->data.stringValue->content = value;
	return return_type(true, NULL);
}
