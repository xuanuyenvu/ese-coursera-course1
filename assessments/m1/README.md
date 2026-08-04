# Statistics Analysis - Course 1 Module 1 (Introduction to Embedded Systems)

**Author:** VU Nguyen Xuan Uyen
**Date:** 03 August 2026

## Functions

- `is_valid_array()` : Validates that a given array pointer is not `NULL` and its length is non-zero. Prints an error message and returns `false` if invalid.
- `print_statistics()` : Prints the mean, median, maximum, and minimum of the array to the screen. Skips processing if the array is invalid.
- `print_array()` : Prints every element of the array to the screen.
- `find_median()` : Sorts the array and returns its median value.
- `find_mean()` : Returns the average value of all elements in the array.
- `find_maximum()` : Returns the largest value found in the array.
- `find_minimum()` : Returns the smallest value found in the array.
- `sort_array()` : Sorts the array in place by calling `merge_sort()`.
- `merge_sort()` : Recursive merge sort implementation that splits the array and merges sorted halves.
- `merge()` : Merges two sorted sub-arrays into a single sorted sequence; used internally by `merge_sort()`.

## How to Build and Run

```bash
gcc -Wall -o stats stats.c
./stats
```