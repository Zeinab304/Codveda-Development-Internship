#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void binarySearch(int arr[], int left, int right, int key)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
        {
            printf("Element found at index: %d\n", mid);
            return;
        }
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    printf("Element not found in the array.\n");
}

int main()
{
    int arr[100];
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Sorting the array using bubble sort
    bubbleSort(arr, n);
    printf("\nArray sorted using Bubble Sort.\n");
    printf("time complexity: O(n^2)\n");

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    // Searching for an element using binary search
    int key;
    printf("\n\nEnter the element to search: ");
    scanf("%d", &key);

    int left = 0, right = n - 1;
    printf("Performing Binary Search.\n");
    printf("time complexity: O(log n)\n");

    binarySearch(arr, left, right, key);

    return 0;
}
