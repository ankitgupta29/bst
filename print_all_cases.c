#include<stdio.h>
#include<ctype.h>
#include<string.h>

void print_all_case(char *str, int l, int r)
{
    if (l == r)
    {
        printf("%s\n", str);
        return;
    }

    str[l] = toupper(str[l]);
    print_all_case(str, l+1, r);

    str[l] = tolower(str[l]);
    print_all_case(str, l+1, r);

}

int main()
{
    char str[] = "abcd";
    print_all_case(str, 0, strlen(str));
    return 0;
}
