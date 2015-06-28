#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX_CHAR 26

void swap(char *x, char *y)
{
    char t = *x;
    *x = *y;
    *y = t;
}

int if_anagram(char *str, char *ptr)
{
    int len1 = strlen(str);
    int len2 = strlen(ptr);
    int i;
    int a[MAX_CHAR] = {0, };

    if (len1 != len2)
        return -1;
    for (i = 0; i < len1; i++)
    {
        if (str[i] >= 65 && str[i] <= 90)
                a[str[i] - 'a' + 32]++;
        else
                a[str[i] - 'a']++;
    }

    for (i = 0; i < len2; i++)
        if (ptr[i] >= 65 && ptr[i] <= 90)
                a[ptr[i] - 'a' + 32]--;
        else
                a[ptr[i] - 'a']--;

    for(i=0 ; i < MAX_CHAR; i++)
        if (a[i] != 0)
            return -1;
    return 0;
}

int palindrome(char *str)
{
    int i, j;
    int len = strlen(str);
    printf("len: %d\n", len);
    if (len == 1)
        return 1;
    if (len % 2 == 0)
    {
        i = len/2 -1;
        j = len/2;
    }
    else
        i = j = len/2;

    while(i >= 0 && j < len)
    {
       printf("1. i=%d j=%d\n", i,j);
        if (str[i] == ' ')
            i--;
        if (str[j] == ' ')
            j++;
        if (str[i--] != str[j++])
            return -1;
        printf("2. i=%d j=%d\n", i,j);
    }
    /* last extra loop */
     i = i +1;
     j = j -1;

    if ((i == 0) && (j == (len - 1)))
        printf("Given string is palindrome:  %s\n", str);
    return 0;

}

void anagram(char *str, int l, int r)
{
    int i,j;
    if (l == r)
    {
        //palindrome(str);
        printf("%s\n", str);

    }
    else {
        for(i = l; i <= r; i++)
        {
                swap(str + l, str + i);
                anagram(str, l+1, r);
                swap(str + l, str + i);
        }
    }
}

void anagram_allcases(char *str, int l, int r)
{
    int i,j;
    if (l == r)
    {
        palindrome(str);
        printf("%s\n", str);

    }
    else {
        for(i = l; i <= r; i++)
        {
                swap(str + l, str + i);
                anagram(str, l+1, r);
                swap(str + l, str + i);

                str[i] = toupper(str[i]);

                swap(str + l, str + i);
                anagram(str, l+1, r);
                str[l] = tolower(str[l]);
        }
    }

    /* print the complete uppercase at last */
}

int main()
{
    char str[] = "aira na ria";
    //char str[] = "ab";
    //char str[] = "anknakank";
    palindrome(str);

    //int length = longest_palindrome_string(str);
    //printf("Longest_palindrome: %d\n", length);
    /*
    anagram(str, 0, (strlen(str)) - 1);
    anagram_allcases(str, 0, (strlen(str)) - 1);
    int ret = if_anagram("ankit", "tiknA");
    if (ret)
        printf("Not\n");
    else
        printf("anagram\n");
    ret = if_anagram("ankit", "niKTaa");
    if (ret)
        printf("not\n");
    else
        printf("anagram\n");
        */
    return 0;
}
