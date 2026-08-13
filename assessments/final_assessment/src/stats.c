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
 * @file stats.c
 * @brief Implementation file for statistical analysis functions on a byte array
 *
 * This file contains the implementation of functions used to analyze an
 * array of unsigned char data. It includes functions to calculate the
 * mean, median, maximum, and minimum of the data set, sort the array in
 * descending order using merge sort, and print the data and statistics
 * to the screen in a formatted way.
 *
 * @author VU Nguyen Xuan Uyen
 * @date 03 August 2026
 *
 */

#include "stats.h"

bool is_valid_array(unsigned char *array, unsigned int length)
{
  if (array == NULL)
  {
    printf("Error: Array is NULL.\n");
    return false;
  }
  else if (length == 0)
  {
    printf("Error: Array length is zero.\n");
    return false;
  }
  return true;
}

void print_statistics(unsigned char *array, unsigned int length)
{
  if (!is_valid_array(array, length))
  {
    return;
  }

  unsigned char mean = find_mean(array, length);
  unsigned char median = find_median(array, length);
  unsigned char maximum = find_maximum(array, length);
  unsigned char minimum = find_minimum(array, length);

  printf("Statistics:\n");
  printf("Mean: %u\n", mean);
  printf("Median: %u\n", median);
  printf("Maximum: %u\n", maximum);
  printf("Minimum: %u\n", minimum);
}

void print_array(unsigned char *array, unsigned int length)
{
  if (!is_valid_array(array, length))
  {
    return;
  }

  printf("Array: ");
  for (unsigned int i = 0; i < length; i++)
  {
    printf("%u ", array[i]);
  }
  printf("\n");
}

unsigned char find_median(unsigned char *array, unsigned int length)
{
  sort_array(array, length);
  if (length % 2 == 0)
  {
    return (array[length / 2 - 1] + array[length / 2]) / 2;
  }
  else
  {
    return array[length / 2];
  }
}

unsigned char find_mean(unsigned char *array, unsigned int length)
{
  unsigned int sum = 0;
  for (unsigned int i = 0; i < length; i++)
  {
    sum += array[i];
  }
  return sum / length;
}

unsigned char find_maximum(unsigned char *array, unsigned int length)
{
  unsigned char max = array[0];
  for (unsigned int i = 1; i < length; i++)
  {
    if (array[i] > max)
    {
      max = array[i];
    }
  }
  return max;
}

unsigned char find_minimum(unsigned char *array, unsigned int length)
{
  unsigned char min = array[0];
  for (unsigned int i = 1; i < length; i++)
  {
    if (array[i] < min)
    {
      min = array[i];
    }
  }
  return min;
}

void sort_array(unsigned char *array, unsigned int length)
{
  merge_sort(array, 0, length - 1);
}

void merge_sort(unsigned char *array, unsigned int left, unsigned int right)
{
  if (left < right)
  {
    unsigned int mid = left + (right - left) / 2;

    merge_sort(array, left, mid);
    merge_sort(array, mid + 1, right);

    merge(array, left, mid, right);
  }
}

void merge(unsigned char *array, unsigned int left, unsigned int mid, unsigned int right)
{
  unsigned int n1 = mid - left + 1;
  unsigned int n2 = right - mid;

  unsigned char *L = (unsigned char *)malloc(n1 * sizeof(unsigned char));
  unsigned char *R = (unsigned char *)malloc(n2 * sizeof(unsigned char));

  for (unsigned int i = 0; i < n1; i++)
    L[i] = array[left + i];
  for (unsigned int j = 0; j < n2; j++)
    R[j] = array[mid + 1 + j];

  unsigned int i = 0, j = 0, k = left;
  while (i < n1 && j < n2)
  {
    if (L[i] >= R[j])
    {
      array[k] = L[i];
      i++;
    }
    else
    {
      array[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1)
  {
    array[k] = L[i];
    i++;
    k++;
  }

  while (j < n2)
  {
    array[k] = R[j];
    j++;
    k++;
  }

  free(L);
  free(R);
}