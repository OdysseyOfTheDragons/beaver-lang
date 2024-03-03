#include "Include/def.h"
#include "Include/types.h"

int main(void) {
	ValueType* val1 = type_empty(INT_TYPE, 10);
	printf("> %d=%d %d\n", type(val1), INT_TYPE, fetch_int(val1));
	ValueType* val2 = type_empty(DOUBLE_TYPE);
	printf("> %lf\n", fetch_double(val2));

	char* str = (char*)calloc(13, sizeof(char));
	ValueType* val3 = type_empty(STRING_TYPE, str);

	printf("\n\n");
	printf("ValueType int %ld\n", sizeof(val1));
	printf("ValueType string %ld\n", sizeof(val3));

	int i;
	double d;
	bool b;
	char c;
	char s[10];
	printf("int %ld double %ld bool %ld char %ld string[10] %ld\n",
			sizeof(i), sizeof(d), sizeof(b), sizeof(c), sizeof(s));
	
	destroy_type(val1);
	destroy_type(val2);
	destroy_type(val3);
	return EXIT_SUCCESS;
}
