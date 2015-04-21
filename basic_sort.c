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
int main()
{
    int arr[] = {8, 4 , 2, 9, 5, 20, 18, 16};
    int len  = sizeof(arr) / sizeof(arr[0]);
    int i= 0;
    int j = i+1;

    /* insertion_sort */
    for (i = 1; i < len; i++)
    {
        int j = i;
        while (j > 0) {
                if (arr[j] < arr[j-1])
                    swap(&arr[j], &arr[j-1]);
                j--;
        }

    }

    i = 0;
    printf("\nInsertion Sort: ");
    for (; i < len; i++)
        printf("%d  ", arr[i]);

    /* bubble_sort */
    i = 0; j= 0;
    int temp_len = len;
    for (i = 0; i < temp_len; i++)
    {
        for(j = i+1; j < temp_len; j++, i++)
        {
                if (arr[i] > arr[j])
                    swap(&arr[i], &arr[j]);
        }
        temp_len = temp_len -1;
    }

    printf("\nBubble Sort:    ");
    i = 0;
    for (; i < len; i++)
        printf("%d  ", arr[i]);

    /* selection sort */

    int min;
    i = 0; j= 0;
    for (i = 0; i < len; i++)
    {
        min = i;
        for(j = i+1; j < len; j++)
        {
                if (arr[j] < arr[min])
                    min = j;

        }
        swap(&arr[min], &arr[i]);
    }
    printf("\nSelection Sort: ");
    i = 0;
    for (; i < len; i++)
        printf("%d  ", arr[i]);

    return 0;
}
