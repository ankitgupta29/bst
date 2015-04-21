#include <stdio.h>

void swap(int *a, int *b)
{
    /* if two addresses are same then we have to check them */
    if (a == b)
        return;
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void quicksort(int a[], int l, int r)
{
    if (l < r)
    {
        int p = partition(a, l, r);
        quicksort(a, l, p-1);
        quicksort(a, p+1, r);
    }

}

int partition(int a[], int l, int r) {

    int x = a[r];
    int i = l-1;
    int j = l;

    for (j = l; j < r; j++) {

        if (a[j] <= x) {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i+1], &a[r]);
    return i+1;
}

int main()
{
    int arr[] = {12, 28, 7, 34, 33, 5, 36, 24};
    int len  = sizeof(arr)/ sizeof(arr[0]);
    quicksort(arr, 0, len -1);
    int i = 0;
    for (; i < len; i++)
        printf("%d  ", arr[i]);

    return 0;

}
