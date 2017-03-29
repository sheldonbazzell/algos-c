#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void mergeSort(int arr[], int left, int right)
{
	// divide arr until left not < right
    if (left < right)
    {
        int mid = left+(right-left)/2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);

        merge(arr, left, mid, right);
    }
}

void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int leftSize = mid - left + 1;
    int rightSize =  right - mid;
 
    int L[leftSize], R[rightSize];
 	// populate Left & Right subarrays
    for (i = 0; i < leftSize; i++)
        L[i] = arr[left + i];
    for (j = 0; j < rightSize; j++)
        R[j] = arr[mid + 1+ j];

    i = j = 0;
    // merged subarray iterator
    k = left;

    while (i < leftSize && j < rightSize)
    {
		if (L[i] <= R[j])
		{
			arr[k++] = L[i++];
		}
		else
		{
			arr[k++] = R[j++];
		}
	}
	while (i < leftSize)
	{
		arr[k++] = L[i++];
	}
	while (j < rightSize)
	{
		arr[k++] = R[j++];
	}
}

void printArr(int arr[], int arrSize)
{
	for (int i = 0; i < arrSize; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(void)
{
	int n;

	printf("Enter the length of your array:\n");
	scanf("%d",&n);

	int arr[n];
	printf("Enter the values of your array:\n");
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&arr[i]);
	}

	printf("\nInitial array:\n");
	printArr(arr, n);

	mergeSort(arr, 0, n-1);

	printf("\nSorted array:\n");
	printArr(arr, n);

	return 0;
}