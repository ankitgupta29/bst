#include<stdio.h>

//int a[] = {11, 15, 6, 8, 9, 10};
int a[] = {11, 15, 26, 38, 9, 10};

int main()
{
    int len = sizeof(a)/sizeof(a[0]);
    int sum = 45;
    int i;
    for (i = 0; i < len; i++)
        if (a[i+1] < a[i])
            break;
    //Now i is the max element in array

    int j = i+1; //j is smallest element in array

    while (i != j)
    {
        if (a[i] + a[j] == sum) {
                printf("found it: %d %d\n", a[i], a[j]);
                return 0;
        }
        else if (a[i] + a[j] > sum)
                i = (i - 1 + len) % len;
        else
                j = (j + 1 + len) % len;
    }
    printf ("Not Found\n");
    return -1;
}
