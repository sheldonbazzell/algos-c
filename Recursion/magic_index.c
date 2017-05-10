#include <stdio.h>
#include <math.h>

int magic_index(int arr[], int start, int end);

int main(void)
{
    int n;
    printf("How many integers in your array?\n");
    scanf("%d", &n);
    printf("%d\n", n);
    int arr[n];
    printf("Enter the values of your array:\n");
    for (int i = 0; i < n; ++i)
    {
        scanf("%d\n", &arr[i]);
    }
    for(int j = 0; j < n; ++j)
    {
        printf("%d ", arr[j]);
    }
    int x = magic_index(arr, 0, n - 1);
    printf("Your magic index was %d.\n", x);
    return 0;
}

int magic_index(int arr[], int start, int end)
{
    printf("Start: %d, End: %d\n", start, end);
    if (start > end) return -1;
    int mid = ceil((float) (start + end) / 2);
    if (arr[mid] == mid) return mid;
    else if (arr[mid] > mid) return magic_index(arr, start, mid - 1);
    else return magic_index(arr, mid + 1, end);
}

