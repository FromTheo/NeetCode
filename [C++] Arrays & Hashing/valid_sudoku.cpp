#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std; 

/* -------- Subject --------  
You are given a a 9 x 9 Sudoku board board. A Sudoku board is valid if the following rules are followed:
Each row must contain the digits 1-9 without duplicates.
Each column must contain the digits 1-9 without duplicates.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without duplicates.
Return true if the Sudoku board is valid, otherwise return false. */

/* -------- Explanation --------
Nous allons créer 3 cartes : une correspondant aux boîtes, une autre pour les lignes et enfin une pour les colonnes. 
- Commencons par vérifier la validité lignes / colonnes. 
On va parcourir tous les éléments un par un et incrémenter chaque élément de rows & cols si un chiffre est présent. 
On renvoie false si une a trouvé une case où nous acvons incrémenté au moins 2 fois. 
- Concernant les boxes, nous allons aussi parcourir avec 2 boucles for, et faire les mêmes vérifications. */ 

bool isValidSudoku(vector<vector<char> >& board) 
{
    unordered_map<char,int> eachBox;
    unordered_map<char,int> rows;
    unordered_map<char,int> cols;

    //Rows and cols validity : 
    for(int i = 0 ; i < 9 ; i++)
    {
        for(int j = 0 ; j< 9 ; j++)
        {
            if(board[i][j] != '.')
            {
                rows[board[i][j]]++;
            }
            if(board[j][i]!='.')
            {
                cols[board[j][i]]++;
            }
            if(rows[board[i][j]]>1) return false;
            if(cols[board[j][i]]>1) return false;
        }
        rows.clear();
        cols.clear();
    }

    //Boxes validity : 
    for(int i=0 ; i < 9 ;i+=3)
    {
        for(int j=0 ; j <9 ;j+=3)
        {
            eachBox.clear();
            for(int x = i ; x < i+3 ; x++)
            {
                for(int y = j ; y < j+3; y++)
                {
                    if(board[x][y]!='.')
                    {
                        eachBox[board[x][y]]++;
                    }
                    if(eachBox[board[x][y]]>1) return false ;
                }
            }
        }
    }
    return true;
}

int main()
{
    vector<vector<char> > board{
    {"1","2",".",".","3",".",".",".","."},
    {"4",".",".","5",".",".",".",".","."},
    {".","9","8",".",".",".",".",".","3"},
    {"5",".",".",".","6",".",".",".","4"},
    {".",".",".","8",".","3",".",".","5"},
    {"7",".",".",".","2",".",".",".","6"},
    {".",".",".",".",".",".","2",".","."},
    {".",".",".","4","1","9",".",".","8"},
    {".",".",".",".","8",".",".","7","9"}};
    cout << isValidSudoku(board) << endl; //Output : 1. 
    vector<vector<char> > board2{
    {"1","2",".",".","3",".",".",".","."},
    {"4",".",".","5",".",".",".",".","."},
    {".","9","1",".",".",".",".",".","3"},
    {"5",".",".",".","6",".",".",".","4"},
    {".",".",".","8",".","3",".",".","5"},
    {"7",".",".",".","2",".",".",".","6"},
    {".",".",".",".",".",".","2",".","."},
    {".",".",".","4","1","9",".",".","8"},
    {".",".",".",".","8",".",".","7","9"}}; 
    cout << isValidSudoku(board2) << endl; //Output : 0. (Look at the top left box)
    return 0; 
}