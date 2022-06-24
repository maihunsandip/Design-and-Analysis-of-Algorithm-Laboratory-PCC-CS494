#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int start, int end)
{
    int pivot = arr[end];

    int i = start - 1;

    for (int j = start; j < end; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[end]);

    return (i + 1);
}

void quickSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int pi = partition(arr, start, end);

        quickSort(arr, start, pi - 1);
        quickSort(arr, pi + 1, end);
    }
}

void printArray(int arr[], int n)
{
    printf("The sorted array is : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the size of the array : ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the array : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, n);

    printArray(arr, n);

    return 0;
}