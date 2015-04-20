#include "search.h"

int linearSearch(int *arr, int elem, int len){
	int i = 0;
	for(i = 0; i<len; i++){
		if(arr[i] == elem)
			return i;
	}
	return -1;
}

int binarySearch(int *arr, int elem, int len){
	int low = 0, high = len - 1;
	while ( high >= low ) {
		int mid = ( low + high ) / 2;
		if ( elem < arr[mid] )
			high = mid - 1;
		else if ( elem > arr[mid] )
			low = mid + 1;
		else {
			return mid;
		}
	}
	return -1;
}


