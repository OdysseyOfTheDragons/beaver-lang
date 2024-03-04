/**
 * @file
 * @brief Errors library.
 *
 * @author Alexandre Conseil
 * @date 2024
 */

#ifndef _ERRORS
#define _ERRORS
#include "Include/def.h"
#include "Include/types.h"

/**
 * @brief Checks if there are pending errors to catch.
 * @warning This function **must** be called after every function which
 * may raise an error!
 */
bool errors_check(void);

/**
 * @brief Resets the errors if there were any.
 * @warning This function **must** be called after every error, in order
 * for the cached errors to be reset.
 */
void errors_reset(void);

/** @brief Sets the current error. */
void errors_set(const enum ERRORS code);
#endif
