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
 * @file stats.h
 * @brief Header file for statistical analysis functions on a byte array
 *
 * This header declares a set of functions used to analyze an array of
 * unsigned char data, including functions to validate the array, find
 * the mean, median, maximum, and minimum values, sort the array, and
 * print the array and its statistics to the screen in a formatted way.
 *
 * @author VU Nguyen Xuan Uyen
 * @date 03 August 2026
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief A function that checks if an array is valid (not NULL and length > 0).
 * @param array The array of unsigned char values
 * @param length The length of the array
 * @return true if the array is valid, false otherwise
 */
bool is_valid_array(unsigned char *array, unsigned int length);

/**
 * @brief A function that performs merge sort on an array.
 * @param array The array of unsigned char values
 * @param left The left index of the array
 * @param right The right index of the array
 */
void merge_sort(unsigned char *array, unsigned int left, unsigned int right);

/**
 * @brief A function that merges two sorted subarrays.
 * @param array The array of unsigned char values
 * @param left The left index of the array
 * @param mid The middle index of the array
 * @param right The right index of the array
 */
void merge(unsigned char *array, unsigned int left, unsigned int mid, unsigned int right);

/**
 * @brief A function that prints the statistics of
 * an array including minimum, maximum, mean, and median.
 * @param array The array of unsigned char values
 * @param length The length of the array
 */
void print_statistics(unsigned char *array, unsigned int length);

/**
 * @brief A function that prints the elements of an array.
 * @param array The array of unsigned char values
 * @param length The length of the array
 */
void print_array(unsigned char *array, unsigned int length);

/**
 * @brief A function that finds the median of an array.
 * @param array The array of unsigned char values
 * @param length The length of the array
 * @return The median value
 */
unsigned char find_median(unsigned char *array, unsigned int length);

/**
 * @brief A function that finds the mean of an array.
 * @param array The array of unsigned char values
 * @param length The length of the array
 * @return The mean value
 */
unsigned char find_mean(unsigned char *array, unsigned int length);

/**
 * @brief A function that finds the maximum of an array.
 * @param array The array of unsigned char values
 * @param length The length of the array
 * @return The maximum value
 */
unsigned char find_maximum(unsigned char *array, unsigned int length);

/**
 * @brief A function that finds the minimum of an array.
 * @param array The array of unsigned char values
 * @param length The length of the array
 * @return The minimum value
 */
unsigned char find_minimum(unsigned char *array, unsigned int length);

/**
 * @brief A function that sorts an array in descending order.
 * @param array The array of unsigned char values
 * @param length The length of the array
 */
void sort_array(unsigned char *array, unsigned int length);

#endif /* __STATS_H__ */
