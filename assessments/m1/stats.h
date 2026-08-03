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
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

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
 * @brief A function that sorts an array in ascending order.
 * @param array The array of unsigned char values
 * @param length The length of the array
 */
void sort_array(unsigned char *array, unsigned int length);


#endif /* __STATS_H__ */
