
#include <stdio.h>

void swap(int *a, int *b)
{
    /* if two addresses are same then we have to check them */
    if (a == b)
        return;

    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int main() {

    int x = 100;
    int y = 5;
    swap(&x, &y);
    printf("x: %d y: %d\n", x, y);
}
