/**
 * @file
 * @brief Basic error handling functions.
 *
 * @author Alexandre Conseil
 * date 2024
 */

#include "Include/def.h"
#include "Include/types.h"

bool errors_check(void) {
	return errno != NONE;
}

void errors_set(const enum ERRORS code) {
	errno = code;
}

void errors_reset(void) {
	errors_set(NONE);
}
