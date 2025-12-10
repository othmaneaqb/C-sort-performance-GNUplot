#ifndef SORTS_H
#define SORTS_H

// Simple sorting function declarations
// li dar sorting function akhra yzid prototype dyalha hna

void quick_sort(int *arr, int n);
void merge_sort(int *arr, int n);
void heap_sort(int *arr, int n);

// Small helper: swap two numbers
void swap(int *a, int *b);

// The three sorting algorithms we implemented
void insertionSort(int arr[], int n);
void selectionSort(int arr[], int n);
void shellSort(int arr[], int n);

#endif
