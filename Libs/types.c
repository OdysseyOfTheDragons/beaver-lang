/**
 * @file
 * @brief Utility functions to manipulate the application types.
 *
 * @author Alexandre Conseil
 * @date 2024
 */

#include "Include/def.h"
#include "Include/errors.h"
#include "Include/mathematics.h"
#include "Include/types.h"

enum TYPES type(ValueType *value) {
	if (value == NULL) {
		return -1;
	}

	return value->type;
}

StringType *type_string(char *value) {
	StringType *val = (StringType *)malloc(sizeof(StringType));

	val->content = value;
	val->length = strlen(value);
	val->hash = hash_string(val->content, val->length);
	return val;
}

bool verify_object(const enum TYPES expected, ValueType* object) {
	errors_reset();

	if (object == NULL) {
		errors_set(INVALID_OBJECT);
		return false;
	}

	if (type(object) != expected) {
		errors_set(INCORRECT_TYPE);
		return false;
	}

	if (expected == STRING_TYPE) {
		if (object->data.stringValue == NULL) {
			errors_set(INVALID_OBJECT);
			return false;
		}
	}

	return true;
}

void destroy_string(StringType *object) {
	free(object->content);
	free(object);
}

ValueType *type_empty(const int type, ...) {
	va_list args;

	va_start(args, type);

	ValueType *val = (ValueType *)malloc(sizeof(ValueType));

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
			val->data.stringValue = type_string(va_arg(args, char *));

			break;

		default:
			val->type = INT_TYPE;
			val->data.intValue = 0;
	}

	va_end(args);
	return val;
}

void destroy_type(ValueType *object) {
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

int fetch_int(ValueType *object) {
	if (!verify_object(INT_TYPE, object)) { return 0; }
	return object->data.intValue;
}

void set_int(ValueType *object, const int value) {
	if (!verify_object(INT_TYPE, object)) { return; }
	object->data.intValue = value;
}

bool fetch_bool(ValueType *object) {
	if (!verify_object(BOOL_TYPE, object)) { return false; }
	return object->data.boolValue;
}

void set_bool(ValueType *object, const bool value) {
	if (!verify_object(BOOL_TYPE, object)) { return; }
	object->data.boolValue = value;
}

double fetch_double(ValueType *object) {
	if (!verify_object(DOUBLE_TYPE, object)) { return 0.0; }
	return object->data.doubleValue;
}

void set_double(ValueType *object, const double value) {
	if (!verify_object(DOUBLE_TYPE, object)) { return; }
	object->data.doubleValue = value;
}

char   *fetch_string(ValueType *object) {
	if (!verify_object(STRING_TYPE, object)) { return (char*)malloc(sizeof(char)); }
	return object->data.stringValue->content;
}

size_t string_length(ValueType* object) {
	if (!verify_object(STRING_TYPE, object)) { return 0; }
	else { return object->data.stringValue->length; }
}

uint64_t string_hash(ValueType* object) {
	if (!verify_object(STRING_TYPE, object)) { return 0; }
	else { return object->data.stringValue->hash; }
}

void set_string(ValueType *object, char *value) {
	if (!verify_object(STRING_TYPE, object)) { return; }

	StringType* obj = object->data.stringValue;
	obj->content = value;
	obj->length = strlen(value);
	obj->hash = hash_string(obj->content, obj->length);
}
