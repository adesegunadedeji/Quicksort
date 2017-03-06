// Quicksort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


#define SIZE 3// array size of 8 Elements
using namespace std;


void ArrayPartition(int *arr, int start, int end, int *pivotLoc);
void sort(int *arr, int start, int end);


int main()
{
	int i;
	int arr[SIZE] = { 2,1,3};// Unsorted Arrays:
	sort(arr, 0, SIZE - 1);
	for( i = 0; i < SIZE; i++)
	{
		cout << " "<<arr[i] << " " ;
		//cout << endl;
	};
	
	system("pause");
	return 0;
}

void sort(int *arr, int start, int end) 

{

	int pivot;
	if (start < end) {
		ArrayPartition(arr, start, end, &pivot); //this will find the pivot location and partition the array
		sort(arr, start, pivot - 1); // QuickSort the Left Sub Array
		sort(arr, pivot + 1, end);// QuickSort the Right Sub Array
	}
}

void ArrayPartition(int *arr, int start, int end, int *pivot) {
	int left = start;
	int right = end;
	int temp;
	*pivot = left;

	while (true) {
		//Pivot pointing at left:
		while (arr[*pivot] <= arr[right] && *pivot != right) {
			right--;
		}
		if (*pivot == right) {
			break;
		}
		else if (arr[*pivot] > arr[right]) {
			temp = arr[right];
			arr[right] = arr[*pivot];
			arr[*pivot] = temp;
			*pivot = right; 

		}
		//Pivot pointing at right;
		while (arr[*pivot] >= arr[left] && *pivot != left) {
			left++;
		}
		if (*pivot == left) {
			break;
		}

		else if (arr[*pivot] < arr[left]) {
			temp = arr[left];
			arr[left] = arr[*pivot];
			arr[*pivot] = temp;
			*pivot = left;

		}
	}
}
