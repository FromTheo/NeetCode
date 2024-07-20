#include <iostream>
#include <vector>
#include <algorithm>        //std::fill

using namespace std;  

/* -------- Subject -------- 
Given an m x n matrix of integers matrix, if an element is 0, set its entire row and column to 0's.
You must update the matrix in-place. */ 

/* -------- Explanation --------
Initializations: m to the number of rows and n to the number of columns.
- If m == 1, and if there is a zero, set everything to 0.
- Otherwise, we will traverse the matrix row by row and store the coordinates of the zeros (if any) in two vectors.
  Then, we will need to use two more for loops to modify the matrix accordingly.
  Indeed, we have to proceed this way and not modify the matrix simultaneously because otherwise, as soon as we find a zero,
  the matrix will be set to 0 everywhere afterward. */

void setZeroes(vector<vector<int>>& matrix) 
{
    int m = matrix.size();
    int n = matrix.front().size();
    vector<int> a_enlever_colonnes; 
    vector<int> a_enlever_lignes; 
    for(int i = 0; i < m; ++i)
    {
        vector<int> recherche = matrix[i]; 
        for(int j=0; j < n; ++j)
        {
            if(recherche[j] == 0)
            {
                a_enlever_colonnes.push_back(j);
                a_enlever_lignes.push_back(i);
            } 
        }
    }
    for(const int& index : a_enlever_colonnes)
    {
        for(int j = 0; j < m; ++j)
        {
            matrix[j][index] = 0; 
        }
    }
    for(const int& index : a_enlever_lignes)
    {
        fill(matrix[index].begin(), matrix[index].end(), 0); 
    }
}

int main()
{
    vector<vector<int>> matrix1{{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    for(const vector<int>& v : matrix1)
    {
        for(const int& i : v)
        {
            cout << i << " ";
        }
        cout << endl; 
    }
    /* Output : 
    0 1 2 0 
    3 4 5 2 
    1 3 1 5 */
    cout << endl; 
    setZeroes(matrix1);
    cout << endl; 
    for(const vector<int>& v : matrix1)
    {
        for(const int& i : v)
        {
            cout << i << " ";
        }
        cout << endl; 
    }
    /* Output : 
    0 0 0 0 
    0 4 5 0 
    0 3 1 0 */
    cout << endl; 
    vector<vector<int>> matrix2{{1,2,3,4},{5,0,7,8},{0,10,11,12},{13,14,15,0}};
    for(const vector<int>& v : matrix2)
    {
        for(const int& i : v)
        {
            cout << i << " ";
        }
        cout << endl; 
    }
    /* Output : 
    1 2 3 4 
    5 0 7 8 
    0 10 11 12 
    13 14 15 0 */
    cout << endl; 
    setZeroes(matrix2);
    cout << endl; 
    for(const vector<int>& v : matrix2)
    {
        for(const int& i : v)
        {
            cout << i << " ";
        }
        cout << endl; 
    }
    /* Output : 
    0 0 3 0 
    0 0 0 0 
    0 0 0 0 
    0 0 0 0 */
    return 0; 
}