#include <iostream>
#include <vector> 

using namespace std; 

/* -------- Subject -------- 
You are given a 2-D matrix board containing 'X' and 'O' characters.
If a continous, four-directionally connected group of 'O's is surrounded by 'X's, it is considered to be surrounded.
Change all surrounded regions of 'O's to 'X's and do so in-place by modifying the input board. */ 

/* -------- Explanation --------
To simplify the task and make the code clearer, we'll create a recursive function that allows, for a given pair {i,j}, modifying 'board' such that if this pair corresponds to an 'O', we'll look at all its neighbors and call the function on each of them. 
For example, in the case where: board = X X X X
                                        X O O X 
                                        X O O X 
                                        X X X O,
capture(board,3,3) will modify it on : X X X X 
                                       X O O X 
                                       X O O X 
                                       X X X T.
This function is used to keep the 'O's on the edge and differentiate them from others. 
Now, we just need to replace all 'O's with 'X's (because those remaining are surrounded), 
and 'T's with 'O's (those on the edge). */ 

void capture(vector<vector<char>>& board, int i, int j) 
{
    int m = board.size();
    int n = board.front().size();

    if (i < 0 or j < 0 or i == m or j == n or board[i][j] != 'O') 
    {
        return;
    }
    board[i][j] = 'T';
    capture(board, i + 1, j);
    capture(board, i - 1, j);
    capture(board, i, j + 1);
    capture(board, i, j - 1);
}

void solve(vector<vector<char>>& board) 
{
    int m = board.size();
    if (m == 0) return;
    int n = board.front().size();

    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (board[i][j] == 'O' && (i == 0 || j == 0 || i == m - 1 || j == n - 1)) 
            {
                capture(board, i, j);
            }
        }
    }

    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (board[i][j] == 'O') 
            {
                board[i][j] = 'X';
            }
        }
    }

    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (board[i][j] == 'T') 
            {
                board[i][j] = 'O';
            }
        }
    }
}

int main()
{
    vector<vector<char>> board = {{'X','X','X','X'}, {'X', 'O', 'O', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'X', 'O'}};  
    solve(board); 
    for(const vector<char>& v : board)
    {
        for(const char& x : v)
        {
            cout << x << " ";
        }
        cout << endl; 
    }
    /* Output : 
    X X X X 
    X X X X 
    X X X X 
    X X X O  */
    return 0; 
}
