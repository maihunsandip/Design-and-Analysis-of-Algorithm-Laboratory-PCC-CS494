#include <stdio.h>
#include <limits.h>

int maximum(int arr[], int n)
{
    int max = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    return max;
}

int minimum(int arr[], int n)
{
    int min = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }

    return min;
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

    int max = maximum(arr, n);
    int min = minimum(arr, n);

    printf("Maximum element of the array is : %d\n", max);
    printf("Minimum element of the array is : %d\n", min);

    return 0;
}