//  insertion_sort.cpp
//  sorting algorithm O(n^2)
//
//  Created by Pedro Rodrigues Grijó on 04/18/2016.
#include "insertion_sort.h"

void insertion_sort(int *array, int size) {
  
  int i, j;
  int key;

  for (i = 1; i < size; i++) {
      
    key = array[i];
      
    for (j = i - 1; j > -1 && array[j] > key; j--)
      array[j + 1] = array[j];
      
    array[j + 1] = key;
  }
}
