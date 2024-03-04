/**
 * @file
 * @brief Mathematical functions for some miscellaneous actions.
 *
 * @author Alexandre Conseil
 * @date 2024
 */

#include "Include/def.h"
#include "Include/mathematics.h"
#include "Include/types.h"

#define FNV_PRIME_32 16777619
#define FNV_OFFSET_BASIS_32 2166136261

uint64_t hash_string(const char* key, size_t length) {
    uint64_t hash = FNV_OFFSET_BASIS_32;
    for (size_t i = 0; i < length; ++i) {
        hash ^= (uint64_t)key[i];
        hash *= FNV_PRIME_32;
    }
    return hash;
}
