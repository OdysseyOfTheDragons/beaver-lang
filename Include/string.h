/**
 * @file
 * @brief String module.
 *
 * @author Alexandre Conseil
 * @date 2024
 */

#ifndef _STRING
#define _STRING
#include "Include/def.h"

/**
 * @brief Checks equality between two strings.
 * @param a the first string
 * @param b the second string
 * @raise INCORRECT_TYPE at least one of the objects is not a string
 * @raise INVALID_OBJECT at least one of the strings is corrupted
 */
bool string_equals(ValueType* a, ValueType* b);

/**
 * @brief Appends the second string to the first.
 *
 * This function is immutable.
 *
 * @param a the first string
 * @param b the second string
 * @raise INCORRECT_TYPE at least one of the objects is not a string
 * @raise INVALID_OBJECT at least one of the strings is corrupted
 */
ValueType* string_concat(ValueType* a, ValueType* b);
#endif
