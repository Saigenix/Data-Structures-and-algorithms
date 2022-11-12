#include <stdio.h>

void bubblesort(int *arr, int n)
{

    int gb;

    for (int i = 0; i < n - 1; i++)
    {

        for (int j = 0; j < n - 1 - i; j++)
        {

            if (arr[j] > arr[j + 1])
            {

                gb = arr[j];

                arr[j] = arr[j + 1];

                arr[j + 1] = gb;
            }
        }
    }
}

void main()
{

    int a[] = {23, 45, 29, 11, 30, 3, 41};

    int n = 7;

    bubblesort(a, n);

    for (int i = 0; i < n; i++)
    {

        printf("%d ", a[i]);
    }
}