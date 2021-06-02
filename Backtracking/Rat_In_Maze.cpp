#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> maze, int x, int y, int n)
{
    if(x < n && y < n && maze[x][y] == 1)
        return true;
    return false;
}

bool solve(vector<vector<int>> maze, int x, int y, int n, vector<vector<int>>& ans)
{
    if(x == n-1 && y == n-1 )
    {
        ans[x][y] = 1;
        return true;
    }

    if(isSafe(maze, x, y, n))
    {
        ans[x][y] = 1;

        if(solve(maze, x+1, y, n , ans) || solve(maze, x, y+1, n, ans))
            return true;
        
        ans[x][y] = 0;
    }
    return false;
}

int main()
{
    vector<vector<int>> maze{{1,0,0,0}, {1, 1, 0, 1}, {0, 1, 0, 0}, {1, 1, 1, 1}};
    vector<vector<int>> ans(4, vector<int>(4,0));

    if(solve(maze, 0, 0,4, ans))
    {
        for (int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4 ; j++)
                cout << ans[i][j] << " ";
            cout << endl;
        }
        
    }
}