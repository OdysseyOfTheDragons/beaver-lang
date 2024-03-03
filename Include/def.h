/**
 * @file
 * @brief Commonly imported definitions.
 *
 * @author Alexandre Conseil
 * @date 2024
 */

#ifndef _DEFINITIONS
#define _DEFINITIONS
#include <errno.h>
#include <stdarg.h>
// #include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The `stdbool.h` may be imported, but please understand that this may
// have some unwanted consequences in the code, because of the variadic
// functions. These functions automatically promote `bool` to `int`,
// and because their sizes are different ($1$ byte vs. $4$), the arguments
// are not accessed properly.
// This is the reason why I modify the `bool` type to be an `int`, and
// provide the two `true` and `false` keywords.
// The whole conversion costs $3$ whole bytes, which won't be used, but one
// can't have everything!
#define bool int
#define true 1
#define false 0
#endif
