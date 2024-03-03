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

/** @brief A single integer. */
typedef struct IntType {
	int content; ///< The integer stored.
} IntType;

/** @brief A single boolean. */
typedef struct BoolType {
	bool content; ///< The boolean stored.
} BoolType;

/** @brief A single double. */
typedef struct DoubleType {
	double content; ///< The stored double.
} DoubleType;

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
	INCORRECT_TYPE ///< The given type is not the one expected.
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
		IntType* intValue; ///< Pointer to the integer.
		BoolType* boolValue; ///< Pointer to the boolean.
		DoubleType* doubleValue; ///< Pointer to the float.
		StringType* stringValue; ///< Pointer to the string.
	} data; ///< A pointer to the statically typed value.
} ValueType;

/** @brief The returned value of any function call. */
typedef struct ReturnType {
	bool success; ///< Whether the current function succeeded.
	ValueType* ret; ///< If `success`, the content the function returned.
	enum ERRORS error; ///< If not `success`, the error code of the function.
} ReturnType;

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
 * @brief Generates a `ReturnType` object to return from a function.
 *
 * Please provide as a first parameter the success of the function,
 * and as a second parameter either the return value or the error code,
 * based on `success`.
 *
 * If `success` is `true`, the expected `data` is a `ValueType`.
 * Else, it is expected to be an `error` integer.
 *
 * The default values for `ret` and `error` are
 * respectively `NULL` and `NONE`.
 *
 * @note This is not a pointer, but an object stored in the heap.
 *
 * @warning It is impossible to check the type of the given parameter, or to check the number of arguments given. As such, it is the duty of the caller to check if 1) there is two arguments and 2) the second argument is of the
 * good type as what is defined by `success`.
 * 
 * @param success the success of the function
 * @param data either the returned value or the error code
 */
ReturnType return_type(const bool success, ...);

/**
 * @brief Generates an integer object.
 * @param value the integer to store
 */
IntType* type_int(const int value);

/**
 * @brief Generates a boolean object.
 * @param value the boolean to store
 */
BoolType* type_bool(const bool value);

/**
 * @brief Generates a double value.
 * @param value the double to store
 */
DoubleType* type_double(const double value);

/**
 * @brief Generates a string object.
 * @todo Add the `hash` variable, based on the real hash of the string.
 * @param value the string to store
 */
StringType* type_string(char* value);

/**
 * @brief Destroys an integer value.
 * @param object the integer to delete
 */
void destroy_int(IntType* object);

/**
 * @brief Destroys a boolean value.
 * @param object the boolean to delete
 */
void destroy_bool(BoolType* object);

/**
 * @brief Destroys a double value.
 * @param object the double to delete
 */
void destroy_double(DoubleType* object);

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
 */
int type(ValueType* value);

/**
 * @brief Access the integer in the value.
 * 
 * @param object the object whose integer value is to be extracted
 * @raise INCORRECT_TYPE object is not of the expected type
 */
ReturnType fetch_int(ValueType* object);

/**
 * @brief Set a new value to an integer.
 * 
 * @param object the object whose value is to be changed
 * @param value the new value
 * @raise INCORRECT_TYPE object is not of the expected_type
 */
ReturnType set_int(ValueType* object, const int value);

/**
 * @brief Access the boolean in the value.
 * 
 * @param object the object whose boolean value is to be extracted
 * @raise INCORRECT_TYPE object is not of the expected type
 */
ReturnType fetch_bool(ValueType* object);

/**
 * @brief Set a new value to a boolean.
 * 
 * @param object the object whose value is to be changed
 * @param value the new value
 * @raise INCORRECT_TYPE object is not of the expected_type
 */
ReturnType set_bool(ValueType* object, const bool value);

/**
 * @brief Access the double in the value.
 * 
 * @param object the object whose double value is to be extracted
 * @raise INCORRECT_TYPE object is not of the expected type
 */
ReturnType fetch_double(ValueType* object);

/**
 * @brief Set a new value to a double.
 * 
 * @param object the object whose value is to be changed
 * @param value the new value
 * @raise INCORRECT_TYPE object is not of the expected_type
 */
ReturnType set_double(ValueType* object, const double value);

/**
 * @brief Access the string in the value.
 * 
 * @param object the object whose string value is to be extracted
 * @raise INCORRECT_TYPE object is not of the expected type
 */
ReturnType fetch_string(ValueType* object);

/**
 * @brief Set a new value to a string.
 * 
 * @param object the object whose value is to be changed
 * @param value the new value
 * @raise INCORRECT_TYPE object is not of the expected_type
 */
ReturnType set_string(ValueType* object, char* value);
#endif
