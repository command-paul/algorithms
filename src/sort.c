#include "sort.h"

void insertionSort(int *arr, int len){
	int i, j, key;
	for (i = 1; i < len; ++i) {
		key = arr[i];
		j = i-1;
		while (j >= 0 && arr[j] > key) {
			arr[j+1] = arr[j];
			--j;
		}
		arr[j+1] = key;
	}
}

/* Function to merge the two haves arr[l..m] and arr[m+1..r] of array arr[] */
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0;
    j = 0;
    k = l;
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
 
    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the sub-array
  of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2; //Same as (l+r)/2, but avoids overflow for large l and h
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void quickSort (int *arr, int n) {
    int i, j, p, t;
    if (n < 2)
        return;
    p = arr[n / 2];
    for (i = 0, j = n - 1;; i++, j--) {
        while (arr[i] < p)
            i++;
        while (p < arr[j])
            j--;
        if (i >= j)
            break;
        t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }
    quickSort(arr, i);
    quickSort(arr + i, n - i);
}

void bubbleSort (int *arr, int n) {
    int i, t, s = 1;
    while (s) {
        s = 0;
        for (i = 1; i < n; i++) {
            if (arr[i] < arr[i - 1]) {
                t = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = t;
                s = 1;
            }
        }
    }
}

void selectionSort (int *arr, int n) {
    int i, j, m, t;
    for (i = 0; i < n; i++) {
        for (j = i, m = i; j < n; j++) {
            if (arr[j] < arr[m]) {
                m = j;
            }
        }
        t = arr[i];
        arr[i] = arr[m];
        arr[m] = t;
    }
}


