#include <stdio.h>
#include <limits.h>

int matrixChainOrder(int arr[], int i, int j)
{
    if (i == j)
        return 0;

    int min = INT_MAX;

    for (int k = i; k < j; k++)
    {
        int count = matrixChainOrder(arr, i, k) + matrixChainOrder(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]);

        if (count < min)
            min = count;
    }

    return min;
}

int main()
{
    int n;
    printf("Enter the size of the Array : ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the Array : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Minimum number of multiplications is %d", matrixChainOrder(arr, 1, n - 1));

    // getchar();

    return 0;
}