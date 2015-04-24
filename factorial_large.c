#include<stdio.h>
#define MAX 1000

int multiply(int arr[], int n, int len)
{
    int carry = 0;
    int i;
    for (i = 0; i < len; i++)
    {
        int sum  = arr[i] * n + carry;
        arr[i] = sum % 10;
        carry = sum / 10;
    }
    while(carry)
    {
        arr[len] = carry % 10;
        carry =  carry / 10;
        ++len;
    }
    return len;
}

int main() {

    int arr[MAX] = {0,};
    arr[0] = 1;
    int x = 20;
    int len =1;
    int i;

    for (i = 2; i <= x; i++)
        len = multiply(arr, i, len);

    printf("Factorial:  ");
    for (i = len -1; i >=0; i--)
        printf("%d", arr[i]);
    printf("\n\n");
}
