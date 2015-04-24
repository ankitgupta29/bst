#include<stdio.h>
#define row 4
#define col 5
#define MAX 100

int mat[row][col] = {
                        {1, 2, 3, 4, 5},
                        {2, 4, 5, 8, 10},
                        {3, 5, 7, 9, 11},
                        {1, 3, 5, 7, 9},
                 };

int find_common()
{
   int min_row = 0;
   int i;
   int col_min[row];

   for (i =0; i < row; i++)
        col_min[i] = col - 1;

    while(col_min[i] >= 0) {

        for (i = 0; i < row; i++)
        {
            if (mat[i][col_min[i]] < mat[min_row][col_min[min_row]])
                min_row = i;
        }

        int eq_cnt = 0;

        for (i = 0; i < row; i++)
        {
            if (mat[i][col_min[i]] > mat[min_row][col_min[min_row]]) {
                if (col_min[i] == 0)
                    return -1;

                col_min[i] = col_min[i] - 1;
            }
            else
                eq_cnt++;
        }

        if (eq_cnt == row)
            return mat[min_row][col_min[min_row]];
   }

return -1;
}

int main() {

    int n = find_common();
    if (n < 0)
        printf("No such Number\n");
    else
        printf("Common number: %d\n", n);

}
