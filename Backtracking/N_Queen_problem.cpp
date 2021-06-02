#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> board, int row, int col, int n)
{
    // Checking in this row prev cols
    for(int i = 0 ; i < col; i++)
    {
        if(board[row][i] == 1)
            return false;
    }

    // Upper left Diagonal
    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if(board[i][j] == 1)
            return false;
    }

    // Lower left diagonal
    for(int i = row, j = col; i< n && j >= 0; i++, j--)
    {
        if(board[i][j] == 1)
            return false;
    }

    return true;
}

bool solve(vector<vector<int>>& board, int col, int n)
{
    // All queens are placed
   if(col == n)
        return true;
    
    // Try placing queen in each row one by one in this particular column
    for(int i = 0; i < n ; i++)
    {
        // Is it ok to place here?
        if(isSafe(board, i, col, n))
        {
            // Ok placed
            board[i][col] = 1;

            // Now place in further columns
            if(solve(board, col + 1, n)) // is successfully placed?
                return true;

            // Backtrack
            board[i][col] = 0;
        }
    }
    // Tried for all rows
    return false;
}

int main()
{
    vector<vector<int>> board(4, vector<int>(4,0));

    if(solve(board, 0, 4))
    {
        for (int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4 ; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }  
    }
    return 0;
}