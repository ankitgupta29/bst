#include<stdio.h>
#include<string.h>

void longest_common_prefix(char *str[])
{
    int size = 0;
    while(str[size] != '\0') { size++; }
    //printf("no of strings: %d\n", size);

    int len = strlen(str[0]);
    //printf("len of first string: %d\n", len);

    int i,j;
    for (i = 0; i < len; i++)
    {
        for (j = 1; j < size; j++)
        {
            char c =  str[0][i];
            if (i >= strlen(str[j]) || str[j][i] != c)
            {
                printf("%.*s\n", i, str[0]);
                return;
            }
        }
    }
    printf("%s\n", str[0]);
}

int main()
{
    //char *str[] = {"abcde", "abcece", "abcde" };
    char *str[] = {"abcde", "abcde", "abcde" };

    longest_common_prefix(str);
}
