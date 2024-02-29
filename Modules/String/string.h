#ifndef _STRINGS
#define _STRINGS
typedef struct {
	char* content;
	int length;
	int hash;
} string;
// typedef struct String string;
string* string_empty(char* s);
#endif
