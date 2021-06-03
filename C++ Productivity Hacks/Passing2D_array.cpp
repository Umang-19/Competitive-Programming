#include<bits/stdc++.h>
using namespace std;

// <---------------- PASSING 2-D ARRAY IN FUNCTION -------------------> 
/* METHOD - 1 
const int M = 3;
const int N = 3;
void fun(int arr[M][N])
{
    for(int i = 0; i < M ; i++)
    {
        for(int j = 0; j < N ; j++)
            cout << arr[i][j] << endl;
    }
}
int main () 
{
    int arr[][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
    fun(arr);
    return 0;
}
*/

// METHOD - 2
void fun(int *arr, int M, int N)
{
    for(int i = 0; i < M ; i++)
    {
        for(int j = 0; j < N ; j++)
            cout << *(arr + i * N + j) << endl;
    }
}
int main () 
{
    int arr[][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
    fun(&arr[0][0], 3,3);
    return 0;
}