#include<stdio.h>
#include<string.h>

void swap(char *x, char *y)
{
    char t = *x;
    *x = *y;
    *y = t;
}

int palindrome(char *str)
{
    int len, i, j;
    len = strlen(str);

    if (len % 2 == 0)
    {
        i = len/2 -1;
        j = len/2;
    }
    else
        i = j = len/2;

    while(i >= 0 && j < len)
    {
       // printf("1. i=%d j=%d\n", i,j);
        if (str[i] == ' ')
            i--;
        if (str[j] == ' ')
            j++;
        if (str[i--] != str[j++])
            return -1;
        //printf("2. i=%d j=%d\n", i,j);
    }

    if ((i <= 0) && (j == (len)))
        printf("Given string is palindrome: %s\n", str);
    return 0;

}

void permute(char *str, int l, int r)
{
    int i,j;
    if (l == r)
    {
        palindrome(str);
        //printf("%s\n", str);
    }
    else {
        for(i = l; i <= r; i++)
        {
                swap(str + l, str + i);
                permute(str, l+1, r);
                swap(str + l, str + i);
        }
    }
}

int main()
{
    //char str[] = "airanaria";
    char str[] = "air a aarin";
    palindrome(str);
    permute(str, 0, (strlen(str)) - 1);
    return 0;
}
