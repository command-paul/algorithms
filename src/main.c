#include <stdio.h>
#include "sort.h"

int main(){
	int arr[] = {4, 5, 20, 6, 2, 3, 12, 1};
	insertionSort(arr, 8);
	int i;
	for (i = 0; i < 8; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
