#include <iostream>
#include <vector>

using namespace std;  

/* -------- Subject -------- 
Given a square n x n matrix of integers matrix, rotate it by 90 degrees clockwise.
You must rotate the matrix in-place. Do not allocate another 2D matrix and do the rotation. */ 

/* -------- Explanation --------
Method 1: Much better. We take the transpose of the matrix using std::swap. 
Then, we notice that simply reversing the order of the rows gives us the desired matrix.

Method 2: Doesn't fully follow the instructions as it allocates another 2D matrix. 
We rotate by placing the row vector into the column vector using two for loops. */


//Method 1: 
void rotate(vector<vector<int>>& matrix) 
{
    int row = matrix.size();
    for(int i=0;i<row; i++)
    {
        for(int j=0; j<=i;j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for(int i=0;i<row;i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
        
}

//Method 2: 
void rotate(vector<vector<int>>& matrix) 
{
    int n = matrix.size(); 
    vector<vector<int>> copy = matrix; 
    for(int i = 0; i < n; i++)
    {
        vector<int> ligne = matrix[i]; 
        cout << endl; 
        for(int j = 0; j < n ; j++)
        {
            copy[j][n-i-1] = ligne[j];
        }
    }
    matrix = copy ;
}

int main()
{
    vector<vector<int>> v1{{1,2},{3,4}}; 
    rotate(v1); 
    vector<vector<int>> v2{{1,2,3},{4,5,6},{7,8,9}}; 
    rotate(v2); 
    for(const vector<int> & v: v1)
    {
        for(const int& i : v)
        {
            cout << i << " ";
        }
        cout << endl; 
    }
    /* Output : 
    3 1 
    4 2 */ 
    for(const vector<int> & v: v2)
    {
        for(const int& i : v)
        {
            cout << i << " ";
        }
        cout << endl; 
    }
    /* Output : 
    7 4 1 
    8 5 2 
    9 6 3  */
    return 0; 
}