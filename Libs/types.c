/**
 * @file
 * @brief Utility functions to manipulate the application types.
 *
 * @author Alexandre Conseil
 * @date 2024
 */

#include "Include/def.h"
#include "Include/types.h"

enum TYPES type(ValueType* value) {
	if (value == NULL) {
		return -1;
	}

	return value->type;
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
			val->data.intValue = va_arg(args, int);
			break;

		case BOOL_TYPE:
			val->data.boolValue = (bool)va_arg(args, int);
			break;

		case DOUBLE_TYPE:
			val->data.doubleValue = va_arg(args, double);
			break;

		case STRING_TYPE:
			val->data.stringValue = type_string(va_arg(args, char*));
			break;

		default:
			val->type = INT_TYPE;
			val->data.intValue = 0;
	}

	va_end(args);
	return val;
}

void destroy_type(ValueType* object) {
	switch (type(object)) {
		case INT_TYPE:
		case BOOL_TYPE:
		case DOUBLE_TYPE:
			break;

		case STRING_TYPE:
			destroy_string(object->data.stringValue);
			break;

		default:
			break;
	}

	free(object);
}

int fetch_int(ValueType* object) {
	if (object == NULL) {
		errno = INVALID_OBJECT;
		return -1;
	}

	if (type(object) != INT_TYPE) {
		errno = INCORRECT_TYPE;
		return -1;
	}

	return object->data.intValue;
}

void set_int(ValueType* object, const int value) {
	if (object == NULL) {
		errno = INVALID_OBJECT;
		return;
	}

	if (type(object) != INT_TYPE) {
		errno = INCORRECT_TYPE;
		return;
	}

	object->data.intValue = value;
}

bool fetch_bool(ValueType* object) {
	if (object == NULL) {
		errno = INVALID_OBJECT;
		return false;
	}

	if (type(object) != BOOL_TYPE) {
		errno = INCORRECT_TYPE;
		return false;
	}

	return object->data.boolValue;
}

void set_bool(ValueType* object, const bool value) {
	if (object == NULL) {
		errno = INVALID_OBJECT;
		return;
	}

	if (type(object) != BOOL_TYPE) {
		errno = INCORRECT_TYPE;
		return;
	}

	object->data.boolValue = value;
}


double fetch_double(ValueType* object) {
	if (object == NULL) {
		errno = INVALID_OBJECT;
		return 0.0;
	}

	if (type(object) != DOUBLE_TYPE) {
		errno = INCORRECT_TYPE;
		return 0.0;
	}

	return object->data.doubleValue;
}

void set_double(ValueType* object, const double value) {
	if (object == NULL) {
		errno = INVALID_OBJECT;
		return;
	}

	if (type(object) != DOUBLE_TYPE) {
		errno = INCORRECT_TYPE;
		return;
	}

	object->data.doubleValue = value;
}

char* fetch_string(ValueType* object) {
	if (object == NULL) {
		errno = INVALID_OBJECT;
		return (char*)calloc(1, sizeof(char));
	}

	if (type(object) != STRING_TYPE) {
		errno = INCORRECT_TYPE;
		return (char*)calloc(1, sizeof(char));
	}

	return object->data.stringValue->content;
}

void set_string(ValueType* object, char* value) {
	if (object == NULL) {
		errno = INVALID_OBJECT;
		return;
	}

	if (type(object) != STRING_TYPE) {
		errno = INCORRECT_TYPE;
		return;
	}

	object->data.stringValue->content = value;
}
