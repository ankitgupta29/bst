#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX_CHAR 26

int max;
char max_str[100];
int longest_palindrome_string(char *str)
{
    int count,i;
    int len = strlen(str);
    for(i = 0; i < len; i++)
    {
       //printf("start: %d\n", i);
       count =  palindrome(str, i);
       //printf("count: %d\n", count);
    }
    return count;
}

int palindrome(char *str, int start)
{
    int i, j;
    int len = strlen(str);
    if (start == 0)
        return 1;

    i = j = start;

    int count = 0;
    while(i >= 0 && j < len)
    {
        if (str[i] == ' ')
            i--;
        if (str[j] == ' ')
            j++;
        if (str[i--] != str[j++])
            return -1;
        count++;
    }

    /* decrement i and increment j because of extra loop at last */
    i = i +1;
    j = j -1;

    if ((i == 0) || (j == (len - 1)))
        printf("Given string is palindrome:  %s from %d - %d\n", str, i, j);
    count = (j- i + 1);

    if (count > max)
    {
        max = count;
        int k = 0;
        while(i <= j)
            max_str[k++] = str[i++];
    }

    return max;
}
int main()
{
    char str[] = "anknakank";
    int length = longest_palindrome_string(str);
    printf("length: %d: %s\n", length, max_str);
    return 0;
}
