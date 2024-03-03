/**
 * @file
 * @brief The base types of the application.
 *
 * @author Alexandre Conseil
 * @date 2024
 */
#ifndef _TYPES
#define _TYPES
#include "Include/def.h"

// --- The types

/** @brief A single string. */
typedef struct StringType {
	char* content; ///< The content of the string.
	int length; ///< Length of the string, for access in constant time.
	int hash; ///< Used to quickly compare two strings.
} StringType;

/** @brief All the different supported types. */
enum TYPES {
	INT_TYPE, ///< This object is an `int`.
	BOOL_TYPE, ///< This object is a `bool`.
	DOUBLE_TYPE, ///< This object is a `double`.
	STRING_TYPE ///< This object is a `string`.
};

/** @bref All the different supported errors. */
enum ERRORS {
	NONE, ///< There was no error.
	NO_COMPARISON, ///< You can't compare two non-comparable types
				   ///< (two booleans, an integer and a string...).
	INCORRECT_TYPE, ///< The given type is not the one expected.
	INVALID_OBJECT ///< The value object isn't valid (corrupted).
};

/**
 * @brief A wrapper for the variable types, in order to achieve polymorphism.
 *
 * As `C` is a statically-typed language, it is difficult to create
 * objects which may have multiple types. But this language needs for
 * example an array to hold integers and doubles.
 *
 * To do so, one way is to make every type an object, but pointing to a
 * different type. Doing so keeps the static typing (because there is a
 * single object type) while adding polymorphism.
 */
typedef struct ValueType {
	enum TYPES type; ///< The type of the current object.
	union {
		int intValue; ///< The integer value.
		bool boolValue; ///< The boolean value.
		double doubleValue; ///< The float value.
		StringType* stringValue; ///< Pointer to the string value.
	} data; ///< A pointer to the statically typed value.
} ValueType;

// --- The functions

/**
 * @brief Generates a `ValueType` pointer to the given data.
 * 
 * Please provide as a first parameter the type of the new value,
 * and as a second parameter the value.
 *
 * @warning It is impossible to check the type of the given parameter,
 * or to check the number of arguments given. As such, it is the duty
 * of the caller to check if 1) there is two arguments and 2) the second
 * argument is of the type specified by `type`.
 *
 * @param type the value type
 * @param value the value data
 * @return the `ValueType` object
 */
ValueType* type_empty(const int type, ...);

/**
 * @brief Generates a string object.
 * @todo Add the `hash` variable, based on the real hash of the string.
 * @param value the string to store
 */
StringType* type_string(char* value);

/**
 * @brief Destroys a string value.
 * @param object the string to delete
 */
void destroy_string(StringType* object);

/**
 * @brief Destroys a value type and its content.
 * @param object the value to delete
 */
void destroy_type(ValueType* object);

/**
 * @brief Returns the type of the value.
 * @param value the value whose type is to be determined
 * @raise INVALID_OBJECT the object is corrupted
 */
enum TYPES type(ValueType* value);

/**
 * @brief Access the integer in the value.
 * 
 * @param object the object whose integer value is to be extracted
 * @raise INCORRECT_TYPE object is not of the expected type
 * @raise INVALID_OBJECT the object is corrupted
 */
int fetch_int(ValueType* object);

/**
 * @brief Set a new value to an integer.
 * 
 * @param object the object whose value is to be changed
 * @param value the new value
 * @raise INCORRECT_TYPE object is not of the expected_type
 * @raise INVALID_OBJECT the object is corrupted
 */
void set_int(ValueType* object, const int value);

/**
 * @brief Access the boolean in the value.
 * 
 * @param object the object whose boolean value is to be extracted
 * @raise INCORRECT_TYPE object is not of the expected type
 * @raise INVALID_OBJECT the object is corrupted
 */
bool fetch_bool(ValueType* object);

/**
 * @brief Set a new value to a boolean.
 * 
 * @param object the object whose value is to be changed
 * @param value the new value
 * @raise INCORRECT_TYPE object is not of the expected_type
 * @raise INVALID_OBJECT the object is corrupted
 */
void set_bool(ValueType* object, const bool value);

/**
 * @brief Access the double in the value.
 * 
 * @param object the object whose double value is to be extracted
 * @raise INCORRECT_TYPE object is not of the expected type
 * @raise INVALID_OBJECT the object is corrupted
 */
double fetch_double(ValueType* object);

/**
 * @brief Set a new value to a double.
 * 
 * @param object the object whose value is to be changed
 * @param value the new value
 * @raise INCORRECT_TYPE object is not of the expected_type
 * @raise INVALID_OBJECT the object is corrupted
 */
void set_double(ValueType* object, const double value);

/**
 * @brief Access the string in the value.
 * 
 * @param object the object whose string value is to be extracted
 * @raise INCORRECT_TYPE object is not of the expected type
 * @raise INVALID_OBJECT the object is corrupted
 */
char* fetch_string(ValueType* object);

/**
 * @brief Set a new value to a string.
 * 
 * @param object the object whose value is to be changed
 * @param value the new value
 * @raise INCORRECT_TYPE object is not of the expected_type
 * @raise INVALID_OBJECT the object is corrupted
 */
void set_string(ValueType* object, char* value);
#endif
