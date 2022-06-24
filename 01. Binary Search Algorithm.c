#include <stdio.h>

int binarySearch(int arr[], int n, int target)
{
    int start = 0, end = n;

    while (start <= end)
    {
        int mid = start + ((end - start) / 2);

        if (arr[mid] == target)
        {
            return mid;
            break;
        }

        else
        {
            if (target < arr[mid])
                end = mid - 1;

            else
                start = mid + 1;
        }
    }

    return -1;
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

    int target;
    printf("Enter the target element : ");
    scanf("%d", &target);

    int ans = binarySearch(arr, n, target);
    printf("The element %d is present at %d index.\n", target, ans);

    return 0;
}