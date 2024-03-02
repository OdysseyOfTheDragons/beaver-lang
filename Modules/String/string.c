#include "Include/def.h"

struct String {
	char   *content;
	int     length;
	int     hash;
};

string *string_empty(char *s) {
	string *c = (string *)malloc(sizeof(string));

	c->content = s;
	c->length = strlen(s);
	c->hash = 0;

	return c;
}
