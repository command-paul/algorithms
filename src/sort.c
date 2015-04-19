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
