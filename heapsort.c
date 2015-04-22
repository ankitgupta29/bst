#include<stdio.h>

void swap(int *a, int *b)
{
    /* if two addresses are same then we have to check them */
    if (a == b)
        return;
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int get_left(int i)
{
    return (2 * i + 1);
}

int get_right(int i)
{
    return (2 * i +  2);
}

int get_parent(int i)
{
    return ((i -1 )/ 2);
}

void heapify(int arr[], int i, int len)
{
   int left = get_left(i);
   int right = get_right(i);
   //int len = sizeof(arr) / sizeof(arr[0]);
   int largest = i;

   if (left < len && arr[left] > arr[largest])
           largest = left;

   if (right < len && arr[right] > arr[largest])
           largest = right;

   if (i != largest) {
           swap(&arr[i], &arr[largest]);
           heapify(arr, largest, len);
   }
}

void build_heap(int a[], int len)
{
    //int len = sizeof(a) / sizeof(a[0]);
    int i;
    for (i = (len/2 -1); i >= 0; i--)
    {
        heapify(a, i, len);
    }

}

void heapsort(int arr[], int len)
{
    int i;
    for (i = len -1; i > 0; i--)
    {
        swap(&arr[len-1], &arr[0]);
        len = len - 1;
        heapify(arr, 0, len);
    }

}

int main()
{
    int arr[] = {12, 28, 7, 34, 33, 5, 36, 24};
    int len  = sizeof(arr)/ sizeof(arr[0]);
    build_heap(arr, len);
    int i = 0;
    printf("\nBuild Heap: ");
    for (; i < len; i++)
        printf("%d  ", arr[i]);

    printf("\n Heap Sort: ");
    heapsort(arr, len);
    i = 0;
    for (; i < len; i++)
        printf("%d  ", arr[i]);
    return 0;

}
