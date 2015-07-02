#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include<malloc.h>
struct word
{
    char *str;
    int index;
};

struct duparray
{
    struct word* arr;
    int size;
};

struct duparray* create_dup_array(char *str[], int size)
{
    int i;
    struct duparray *dup = (struct duparray*) malloc(sizeof(struct duparray));
    if (dup)
    {
        dup->size = size;
        dup->arr  = (struct word*)malloc(sizeof(struct word) * size);

        for(i = 0; i< size; i++) {
            dup->arr[i].str = (char*)malloc(sizeof(strlen(str[i] + 1)));
            strcpy(dup->arr[i].str, str[i]);
            dup->arr[i].index = i;
         }
    }
    return dup;
}

int comparechar(const void *x, const void *y)
{
        return (*(char *)x - *(char*)y);
}
int compareword(const void *x, const void *y)
{
        struct word *a = (struct word*)x;
        struct word *b = (struct word*)y;
        return (strcmp(a->str, b->str));
}

int main()
{
    char *s[] =  { "art", "rat", "bats", "banana", "stab", "tar" };
    int i,j;
    int size = sizeof(s)/ sizeof(s[0]);
    struct duparray *dup = create_dup_array(s, size);

    for (i = 0; i < size; i++)
    {
        printf("%s\n", s[i]);
    }

    printf("====================\n");
    for (i = 0; i < size; i++)
    {
        qsort(dup->arr[i].str, strlen(dup->arr[i].str), sizeof(char), comparechar);
    }

    qsort(dup->arr, size, sizeof(dup->arr[0]), compareword);

    for (i = 0; i < size; i++)
    {
        printf("%s  ", dup->arr[i].str);
        printf("%s\n", s[dup->arr[i].index]);
    }
}
