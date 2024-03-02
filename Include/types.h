#ifndef _TYPES
#define _TYPES
#include "def.h"

/// The type of any value
typedef struct {
	enum { INT_TYPE, BOOL_TYPE, DOUBLE_TYPE, STRING_TYPE } type;
	union {
		int     intValue;
		bool    boolValue;
		double  doubleValue;
		string *stringValue;
	} data;
} ValueType;

/// The return type of any function
typedef struct {
	bool    success;
	enum { NONE, NO_COMPARISON } error;
	ValueType *ret;
} ReturnType;
#endif
