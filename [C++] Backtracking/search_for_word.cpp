#include <vector>
#include <string>
#include <iostream> 

using namespace std; 

/* -------- Subject --------  
Given a 2-D grid of characters board and a string word, return true if the word is present in the grid, otherwise return false.
For the word to be present it must be possible to form it with a path in the board with horizontally or vertically neighboring cells. 
The same cell may not be used more than once in a word. */

bool backtrack(vector<vector<char>>& board, const string& word, int row, int col, int index);

bool exist(vector<vector<char>>& board, string word) 
{
    int rows = board.size();
    int cols = board[0].size();
        
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            if (board[i][j] == word[0] && backtrack(board, word, i, j, 0)) 
            {
                return true;
            }
        }
    }
        
    return false;
}
    
bool backtrack(vector<vector<char>>& board, const string& word, int row, int col, int index) 
{
    if (index == word.length()) //The word was found.  
    {
        return true;
    }
    
    if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[index]) //Limits checking. 
    {
        return false;
    } 
        
    char temp = board[row][col]; 
    board[row][col] = '#'; //Mark the cell as visited by replacing the character with '#'. 
        
    bool found = backtrack(board, word, row - 1, col, index + 1) ||
                 backtrack(board, word, row + 1, col, index + 1) ||
                 backtrack(board, word, row, col - 1, index + 1) ||
                 backtrack(board, word, row, col + 1, index + 1);
        
    board[row][col] = temp;
        
    return found;
}

int main()
{
    vector<vector<char>> board{{'A', 'B', 'C', 'D'}, {'S', 'A', 'A', 'T'}, {'A', 'C', 'A', 'E'}};
    string word = "CAT"; 
    cout << exist(board, word) << endl; //Output : 1

    return 0; 
}