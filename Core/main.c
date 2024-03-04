#include "Include/def.h"
#include "Include/errors.h"
#include "Include/string.h"
#include "Include/types.h"

int main(void) {
	ValueType *val1 = type_empty(INT_TYPE, 10);

	printf("> %d=%d %d\n", type(val1), INT_TYPE, fetch_int(val1));
	ValueType *val2 = type_empty(DOUBLE_TYPE);

	printf("> %lf\n", fetch_double(val2));

	char   *str = (char *)calloc(13, sizeof(char));
	strcat(str, "Hello, ");
	ValueType *val3 = type_empty(STRING_TYPE, str);

	char* str2 = (char*)calloc(6, sizeof(char));
	strcat(str2, "world");
	ValueType *val4 = type_empty(STRING_TYPE, str2);
	ValueType* val5 = string_concat(val3, val4);
	printf("! %s %d\n", fetch_string(val5), string_hash(val5));

	printf("! %d %d %d\n", string_hash(val3), string_hash(val4),
			string_hash(val5));
	printf("\n\n");
	printf("ValueType int %ld\n", sizeof(val1));
	printf("ValueType string %ld\n", sizeof(val3));

	int     i;
	double  d;
	bool    b;
	char    c;
	char    s[10];

	printf("int %ld double %ld bool %ld char %ld string[10] %ld\n",
			sizeof(i), sizeof(d), sizeof(b), sizeof(c), sizeof(s));

	destroy_type(val1);
	destroy_type(val2);
	destroy_type(val3);
	destroy_type(val4);
	destroy_type(val5);
	errors_reset();
	return EXIT_SUCCESS;
}
