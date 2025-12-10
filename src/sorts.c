/*li bgha yzid chi sorting function yzid implementation dyalha
wl prototype f sorts.h*/
/*please respect structure dl comments so it be easier bach yb9a
hdchi mfhom dima*/
#include "../include/sorts.h"
#include <stdlib.h>

// ==================== QUICK SORT ====================

// Simple swap function
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// partition function - puts smaller elements on left, larger on right
int partition(int *arr, int low, int high)
{
    int pivot = arr[high]; // Take last element as pivot
    int i = low - 1;       // Index of smaller element

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// helper function for quick sort (recursive approach)
void quick_sort_helper(int *arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quick_sort_helper(arr, low, pi - 1);
        quick_sort_helper(arr, pi + 1, high);
    }
}

// Main quick sort function
void quick_sort(int *arr, int n)
{
    if (n <= 1)
        return;
    quick_sort_helper(arr, 0, n - 1);
}

// ==================== MERGE SORT ====================

// Merge two sorted halves
void merge(int *arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp arrays
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    // Copy data to temp arrays we created
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temp arrays back lol
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

// helper function for merge sort (recursive approach too lol)
void merge_sort_helper(int *arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        merge_sort_helper(arr, left, mid);
        merge_sort_helper(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Main merge sort function
void merge_sort(int *arr, int n)
{
    if (n <= 1)
        return;
    merge_sort_helper(arr, 0, n - 1);
}

// ==================== HEAP SORT ====================

// Make a max heap - put largest element at root
void heapify(int *arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Check if left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Check if right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root, swap and continue heapifying
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Main heap sort function
void heap_sort(int *arr, int n)
{
    if (n <= 1)
        return;

    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }



///////// Partie othmane  -- Shell Sor -- Insertion Sort---Selection Sort
#include <stdio.h>
#include "sorts.h"

/*
 * swap()
 * Swaps the values of two integers.
 * Very common helper function for sorting algorithms.
 */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
 * insertionSort()
 * Think of sorting your cards in your hand.
 * You take one element and insert it where it belongs among the previous ones.
 */
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];      // current element we want to place correctly
        int j = i - 1;

        // Move elements that are bigger than key one step forward
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Place key to its new correct position
        arr[j + 1] = key;
    }
}

/*
 * selectionSort()
 * Imagine picking the smallest number and putting it first,
 * then picking the next smallest and putting it second… and so on.
 */
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;  // assume the first unsorted element is the smallest

        // Find the true smallest element
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        // Put the smallest element in its correct position
        swap(&arr[i], &arr[minIndex]);
    }
}


/*
 * shellSort()
 * A better version of insertion sort.
 * Starts by comparing elements far apart, then gradually reduces the gap.
 * This makes big mistakes disappear faster.
 */
void shellSort(int arr[], int n) {
    // Start with a big gap, then reduce it each time
    for (int gap = n / 2; gap > 0; gap /= 2) {

        // Perform a "gapped insertion sort"
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;

            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }

            arr[j] = temp; // place element correctly
        }
    }
}
