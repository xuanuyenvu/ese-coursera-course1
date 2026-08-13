/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material.
 *
 *****************************************************************************/
/**
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stdint.h>
#include <stddef.h>

/**
 * @brief Sets a value of a data array
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char *ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char *ptr, unsigned int index);

/**
 * @brief Returns a value of a data array
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char *ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char *ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero.
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char *ptr, unsigned int size);

/**
 * @brief Moves a block of memory from source to destination, handling overlap.
 *
 * This function copies 'length' bytes from the memory area pointed to by 'src'
 * to the memory area pointed to by 'dst'. It correctly handles overlapping
 * memory areas.
 *
 * @param src Pointer to the source memory area.
 * @param dst Pointer to the destination memory area.
 * @param length Number of bytes to move.
 *
 * @return Pointer to the destination memory area (dst).
 */
uint8_t *my_memmove(uint8_t *src, uint8_t *dst, size_t length);

/**
 * @brief Copies a block of memory from source to destination.
 *
 * This function copies 'length' bytes from the memory area pointed to by 'src'
 * to the memory area pointed to by 'dst'. It does not handle overlapping
 * memory areas.
 *
 * @param src Pointer to the source memory area.
 * @param dst Pointer to the destination memory area.
 * @param length Number of bytes to copy.
 *
 * @return Pointer to the destination memory area (dst).
 */
uint8_t *my_memcopy(uint8_t *src, uint8_t *dst, size_t length);

/**
 * @brief Sets a block of memory to a specified value.
 *
 * This function sets the first 'length' bytes of the memory area pointed to by 'src'
 * to the specified 'value'.
 *
 * @param src Pointer to the memory area to be set.
 * @param length Number of bytes to set.
 * @param value The value to set each byte to.
 *
 * @return Pointer to the memory area (src).
 */
uint8_t *my_memset(uint8_t *src, size_t length, uint8_t value);

/**
 * @brief Sets a block of memory to zero.
 *
 * This function sets the first 'length' bytes of the memory area pointed to by 'src'
 * to zero.
 *
 * @param src Pointer to the memory area to be zeroed.
 * @param length Number of bytes to zero.
 *
 * @return Pointer to the memory area (src).
 */
uint8_t *my_memzero(uint8_t *src, size_t length);

/**
 * @brief Reverses the order of bytes in a block of memory.
 *
 * This function reverses the order of the first 'length' bytes in the memory area
 * pointed to by 'src'.
 *
 * @param src Pointer to the memory area to be reversed.
 * @param length Number of bytes to reverse.
 *
 * @return Pointer to the memory area (src).
 */
uint8_t *my_reverse(uint8_t *src, size_t length);

/**
 * @brief Reserves a block of memory for an array of 32-bit integers.
 *
 * This function allocates memory for an array of 'length' 32-bit integers
 * and returns a pointer to the allocated memory.
 *
 * @param length Number of 32-bit integers to allocate.
 *
 * @return Pointer to the allocated memory, or NULL if allocation fails.
 */
int32_t *reserve_words(size_t length);

/**
 * @brief Frees a previously allocated block of memory for 32-bit integers.
 *
 * This function frees the memory previously allocated by 'reserve_words'.
 *
 * @param src Pointer to the memory area to be freed.
 */
void free_words(uint32_t *src);

#endif /* __MEMORY_H__ */
