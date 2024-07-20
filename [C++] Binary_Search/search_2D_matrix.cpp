#include <iostream>
#include <vector> 
#include <algorithm>     //std::find 

using namespace std; 

/* -------- Subject -------- 
You are given an m x n 2-D integer array matrix and an integer target. 
- Each row in matrix is sorted in non-decreasing order.
- The first integer of every row is greater than the last integer of the previous row.
Return true if target exists within matrix or false otherwise. */ 

/* -------- Explanation --------
Let’s start by deal with two specific cases: the case of a row matrix and the case of a column matrix. 
For the general case, using the assumption of monotonicity, we search for the row that may contain the target value—specifically, 
where lower_bound ≤ target ≤ upper_bound. 
Once we find the index of this row, we can simply apply std::find. */

bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
    int m = matrix.size(); //Number of rows.
    int n = matrix.front().size(); //Number of cols. 
    if(m == 1) //Only one row. 
    {
        auto it = std::find(matrix.front().begin(), matrix.front().end(), target);
        return it != matrix.front().end(); 
    }
    if(n == 1) //Only one col. 
    {
        std::vector<int> values(m);
        for(int i = 0; i < m; i++)
        {
            values[i] = matrix[i].front(); 
        }
        auto it = std::find(values.begin(), values.end(), target); 
        return it != values.end(); 
    }
    int i = 0; 
    int nombre_g = matrix.front().front(); 
    int nombre_d = matrix.front().back(); 
    while(target < nombre_g or target>nombre_d)
    {
        i++; 
        nombre_g = matrix[i].front(); 
        nombre_d = matrix[i].back(); 
    }
    auto it = std::find(matrix[i].begin(), matrix[i].end(), target); 
    return it != matrix[i].end(); 
}

int main()
{
    vector<vector<int>> matrix = {{1,2,4,8},{10,11,12,13},{14,20,30,40}};
    int target = 10, target2 = 15; 
    cout << searchMatrix(matrix, target) << endl; //Output : 1. 
    cout << searchMatrix(matrix, target2) << endl; //Output : 0. 
}