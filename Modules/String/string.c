/**
 * @file
 * @brief Module to manipulate strings.
 *
 * @author Alexandre Conseil
 * @date 2024
 */

#include "Include/def.h"
#include "Include/errors.h"
#include "Include/types.h"

bool string_equals(ValueType* a, ValueType* b) {
	if (!verify_object(STRING_TYPE, a) || !verify_object(STRING_TYPE, b)) {
		return false;
	}

	if ((string_length(a) != string_length(b)) ||
			(string_hash(a) != string_hash(b))) {
		return false;
	}

	return true;
}

ValueType* string_concat(ValueType* a, ValueType* b) {
	if (!verify_object(STRING_TYPE, a) || !verify_object(STRING_TYPE, b)) { 
		return 
			type_empty(STRING_TYPE, (char*)calloc(1, sizeof(char)));
   	}

	int length = string_length(a) + string_length(b) + 1;
	char* result = (char*)malloc(length * sizeof(char));
	result[0] = '\0';

	strcat(result, fetch_string(a));
	strcat(result, fetch_string(b));

	return type_empty(STRING_TYPE, result);
}
