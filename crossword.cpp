#include<iostream>

#include<cstring>
using namespace std;

#define M 3
#define N 3

// Let the given dictionary be following
string dictionary[] = {"GEEKS", "FOR", "QUIZ", "GO"};
int n = sizeof(dictionary)/sizeof(dictionary[0]);

bool isWord(string &str)
 {

          for (int i=0; i<n; i++) {
                  if (str.compare(dictionary[i]) == 0)
                  {
                      cout << "find word\n";
                      return true;
                  }
          }
          return false;
 }

void printWord(char arr[M][N], int row, int col, string& str, bool v[M][N])
{
    v[row][col] = true;
    str = str + arr[row][col];
    if (isWord(str))
        cout << str << endl;

    int i,j;
    for (i = row-1; i <= row+1; i++) {
        for (j = col-1; j <= col+1; j++) {

            if (j >=0 && j < N && i >= 0 && i < M && (v[i][j] == false))
                printWord(arr, i, j, str, v);
        }
    }
    str.erase(str.length() - 1);
    v[row][col] = false;
}

int main()
{
    char m[M][N] = {{'G','I','Z'},
                    {'U','E','K'},
                    {'Q','S','E'}};
    int i,j;

    std:string str = " ";
    bool v[M][N] = {{false}};
    for (i = 0; i < M; i++)
        for (j = 0; j < N; j++)
            printWord(m, i, j, str, v);

}
