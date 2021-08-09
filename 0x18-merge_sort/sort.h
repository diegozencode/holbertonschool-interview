#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

void print_array(const int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge_helper(int *array, size_t size, int *tmp);
void merge_sorting(int *array, int size, int middle, int *tmp);

#endif /* SORT_H */
