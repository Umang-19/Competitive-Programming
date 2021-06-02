#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> grid, int i, int j, int num, int N)
{
    for (int k = 0; k < N; k++)
    {
        if (grid[i][k] == num || grid[k][j] == num)
            return false;
    }

    int s = sqrt(N);
    int rs = i - i % s;
    int cs = j - j % s;

    for (int i = rs; i < rs + s; i++)
    {
        for (int j = cs; j < cs + s; j++)
        {
            if (grid[i][j] == num)
                return false;
        }
    }

    return true;
}

bool solve(vector<vector<int>> &grid, int N)
{
    int i, j;
    bool flag = false;
    for (int ri = 0; ri < N; ri++)
    {
        for (int cj = 0; cj < N; cj++)
        {
            if (grid[ri][cj] == 0)
            {
                i = ri;
                j = cj;
                flag = true;
                break;
            }
        }
        if(flag)
            break;
    }
    if(!flag) return true; 
    
    for (int num = 1; num <= N; num++)
    {
        if (isSafe(grid, i, j, num, N))
        {
            grid[i][j] = num;
            if (solve(grid, N))
                return true;

            grid[i][j] = 0;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> grid{{1, 0, 3, 0}, {0, 0, 2, 1}, {0, 1, 0, 2}, {2, 4, 0, 0}};

    if (solve(grid, 4))
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
                cout << grid[i][j] << " ";
            cout << endl;
        }
    }
    return 0;
}