//  merge_sort.cpp
//  sorting
//  - Change the sentinel values (originally INT_MAX) accordingly.
// 	- When calling merge_sort in your code, pass "array size - 1" as the third argument
//  Created by Pedro Rodrigues Grijó on 05/18/2016.

#include <stdlib.h>
#include <limits.h>
#include "merge_sort.h"

void merge_sort(int *original_array, int start, int end) {

	int mid;

	if (end > start) {
		mid = (end + start) / 2;
		merge_sort(original_array, start, mid);
		merge_sort(original_array, mid + 1, end);
		merge(original_array, start, mid, end);
	}
}

void merge(int *original_array, int start, int mid, int end) {

	int i, j, k;
	int left_size = mid - start + 1;
	int right_size = end - mid;
	int *left_array, *right_array;

	left_array = (int *)malloc((left_size + 1) * sizeof(int));
	right_array = (int *)malloc((right_size + 1) * sizeof(int));

	for (i = 0; i < left_size; i++) 
		left_array[i] = original_array[start + i];

	for (i = 0; i < right_size; i++) 
		right_array[i] = original_array[mid + i + 1];
	
	left_array[left_size] = INT_MAX;
	right_array[right_size] = INT_MAX;	

	for (i = 0, j = 0, k = start; k <= end; k++) {
		if (left_array[i] <= right_array[j]) {
			original_array[k] = left_array[i];
			i++;
		}
		else {
			original_array[k] = right_array[j];
			j++;
		}
	}

	free(left_array);
	free(right_array);
}