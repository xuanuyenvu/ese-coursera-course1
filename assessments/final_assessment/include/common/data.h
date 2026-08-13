/**
 * @file data.h
 * @brief Abstraction of Data Conversion operations
 *
 * This header file provides an abstraction of integer to ASCII and
 * ASCII to integer conversion operations.
 *
 * @author VU Nguyen Xuan Uyen
 * @date 13 Aug 2026
 *
 */

#ifndef __DATA_H__
#define __DATA_H__

#include <stdint.h>
#include <stddef.h>

#define BASE_2 2
#define BASE_8 8
#define BASE_10 10
#define BASE_16 16

/**
 * @brief Converts a signed 32-bit integer to an ASCII string.
 *
 * @param data  Number to convert
 * @param ptr   Pointer to buffer to store the converted c-string
 * @param base  Base to convert to (2 to 16)
 *
 * @return Length of the converted data (including null terminator)
 */

uint8_t my_itoa(int32_t data, uint8_t *ptr, uint32_t base);

/**
 * @brief Converts an ASCII string back to a signed 32-bit integer.
 *
 * @param ptr    Pointer to c-string to convert
 * @param digits Number of digits in the c-string (including sign if present)
 * @param base   Base of the c-string number (2 to 16)
 *
 * @return Converted 32-bit signed integer
 */
int32_t my_atoi(uint8_t *ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */