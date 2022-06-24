#include <stdio.h>

void merge(int arr[], int left, int mid, int right)
{
    int sizeOne = mid - left + 1;
    int sizeTwo = right - mid;

    int first[sizeOne], second[sizeTwo];

    for (int i = 0; i < sizeOne; i++)
    {
        first[i] = arr[left + i];
    }

    for (int j = 0; j < sizeTwo; j++)
    {
        second[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < sizeOne && j < sizeTwo)
    {
        if (first[i] <= second[j])
        {
            arr[k] = first[i];
            i++;
        }

        else
        {
            arr[k] = second[j];
            j++;
        }

        k++;
    }

    while (i < sizeOne)
    {
        arr[k] = first[i];
        i++;
        k++;
    }

    while (j < sizeTwo)
    {
        arr[k] = second[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
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

    mergeSort(arr, 0, n - 1);

    printArray(arr, n);

    return 0;
}