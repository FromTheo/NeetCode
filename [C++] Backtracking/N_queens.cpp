#include <vector>
#include <string>
#include <iostream> 

using namespace std; 

/* -------- Subject --------  
The n-queens puzzle is the problem of placing n queens on an n x n chessboard so that no two queens can attack each other.
A queen in a chessboard can attack horizontally, vertically, and diagonally.
Given an integer n, return all distinct solutions to the n-queens puzzle.
Each solution contains a unique board layout where the queen pieces are placed. 'Q' indicates a queen and '.' indicates an empty space.
You may return the answer in any order. */

void backtrack(int n, int row, vector<string>& board, vector<vector<string>>& result);
bool isValid(const vector<string>& board, int row, int col, int n);


vector<vector<string>> solveNQueens(int n) 
{
    vector<vector<string>> result;
    vector<string> board(n, string(n, '.')); 
        
    backtrack(n, 0, board, result);
        
    return result;
}

void backtrack(int n, int row, vector<string>& board, vector<vector<string>>& result) 
{
    if (row == n) //If we placed queens on all lines. 
    {
        result.push_back(board);  // Ajouter la configuration actuelle de l'échiquier à la liste des résultats
        return;
    }

    for (int col = 0; col < n; ++col) 
    {
        if (isValid(board, row, col, n)) //Check if we can place a Queen at the position (row, col)
        {
            board[row][col] = 'Q';  //Choose. 
            backtrack(n, row + 1, board, result); //Research nd placing the Queens on the next rows. 
            board[row][col] = '.'; //Unchoose. 
        }
    }
}
    
bool isValid(const vector<string>& board, int row, int col, int n)
{
    for (int i = 0; i < row; ++i) //Check column. 
    {
        if (board[i][col] == 'Q') 
        {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) 
    {
        if (board[i][j] == 'Q') 
        {
            return false;
        }
    }
        
    for (int i = row, j = col; i >= 0 && j < n; --i, ++j) 
    {
        if (board[i][j] == 'Q') 
        {
            return false;
        }
    }
        
    return true;
}

int main()
{
    for(const vector<string>& v : solveNQueens(4))
    {
        for(const string& s : v)
        {
            cout << s;
            cout << endl; 
        } 
        cout << endl; 
    }
    /* Output : 
    .Q..
    ...Q
    Q...
    ..Q.

    ..Q.
    Q...
    ...Q
    .Q.. */ 

    return 0; 
}