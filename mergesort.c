#include<stdio.h>
#define MAX 10000

void merge(int arr[], int l, int m, int r) {
    int len_a  = m - l + 1;
    int len_b  = r -m ;
    int a[len_a + 1];
    int b[len_b + 1];
    int i;

    for (i = 0; i < len_a; i++) {
        a[i] = arr[l + i];
    }

    for (i = 0; i < len_b; i++) {
        b[i] = arr[m + 1 + i];
    }

    a[len_a] = b[len_b] = MAX;

    int j = 0;
    i = 0;
    int k = l;
    for (; k <= r; k++)
    {
        if (a[i] <= b[j])
            arr[k] =  a[i++];
        else
            arr[k] = b[j++];
    }
}

void mergesort(int arr[], int l, int r)
{
    if (l < r) {
        int m = (l + r)/2;
        mergesort(arr, l, m);
        mergesort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main()
{
    int arr[] = {4, 65, 2, -31, 0, 99, 2, 83, 782, 1}; //{12, 28, 7, 34, 33, 5, 36, 24};
    int len  = sizeof(arr)/ sizeof(arr[0]);
    mergesort(arr, 0, len -1);
    int i = 0;
    for (; i < len; i++)
        printf("%d  ", arr[i]);

    return 0;
}
