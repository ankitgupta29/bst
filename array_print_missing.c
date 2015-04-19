//http://www.geeksforgeeks.org/print-missing-elements-that-lie-in-range-0-99/
#include<stdio.h>

void insert()
{

}

int arr[] = {9, 6, 900, 850, 5, 90, 100, 99}; //{88, 105, 3, 2, 200, 0, 10};

int main()
{
    int i=0;
    int temp[100] = {0,};
    int len = sizeof(arr)/ sizeof(arr[0]);
    for(; i < len; i++) {
        if (arr[i] < 100)
                temp[arr[i]] = 1;
    }

    i = 0;

    int start = 0;
    int end = 0;

    while(i < 100)
    {
        //printf("start:%d end: %d\n", start, end);
        if(temp[i] == 0)
        {
            if (start < 0)
                    start = end = i;
            if (i < 99 && (temp[i+1] == 0)) {
                end = ++i;
            }
            else {
                if (start == end)
                    printf("%d\n", start);
                else
                    printf("%d-%d\n", start, end);

                start = end = -1;
                i++;
            }
        }
        else {
                i++;
        }

    }
 return 0;
}
