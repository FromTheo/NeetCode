#include <iostream>
#include <vector>

using namespace std;  

/* -------- Subject -------- 
Given an m x n matrix, return all elements of the matrix in spiral order. */ 

/* -------- Explanation --------
We initialize v, the resulting vector, and traverse the matrix in a spiral order, having initialized the necessary constants. 
We fill the vector v until count equals the number of elements in the matrix.*/

vector<int> spiralOrder(vector<vector<int>>& matrix) 
{
    int count = 0;
    int m = matrix.size();      //Number of rows.
    int n = matrix[0].size();   //Number of cols. 
    int left = 0, right = n-1, top = 0, bottom = m-1;
    int total_ele = m * n;
    vector<int> v;
    while(count < total_ele)
    {
        for(int i = left; i <= right && count < total_ele; i++)
        {
            v.push_back(matrix[top][i]);
            count++;
        }
        top++;

        for(int i = top ;i <= bottom && count < total_ele; i++)
        {
            v.push_back(matrix[i][right]);
            count++;
        }
        right--;

        for(int i = right; i >= left && count < total_ele; i--)
        {
            v.push_back(matrix[bottom][i]);
            count++;
        }
        bottom--;

        for(int i = bottom; i >= top && count < total_ele; i--)
        {
            v.push_back(matrix[i][left]);
            count++;
        }
        left++;
    }
    return v;
}

int main()
{
    vector<vector<int>> v1{{1,2,3},{4,5,6},{7,8,9}}; 
    vector<int> r1 = spiralOrder(v1);
    for(const int& i : r1)
    {
        cout << i << " "; 
    }
    //Output : 1 2 3 6 9 8 7 4 5 
    return 0; 
}