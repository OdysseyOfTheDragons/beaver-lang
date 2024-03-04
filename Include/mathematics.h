/**
 * @file
 * @brief Mathematical library.
 *
 * @author Alexandre Conseil
 * @date 2024
 */

#ifndef _MATHS
#define _MATHS
/**
 * @brief Hashes a string using the FNV algorithm.
 * @param string the string to hash
 */
uint64_t hash_string(const char* key, size_t length);
#endif
