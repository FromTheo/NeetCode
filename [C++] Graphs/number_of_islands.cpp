#include <iostream>
#include <vector> 

using namespace std; 

/* -------- Subject -------- 
Given a 2D grid grid where '1' represents land and '0' represents water, count and return the number of islands.
An island is formed by connecting adjacent lands horizontally or vertically and is surrounded by water. 
You may assume water is surrounding the grid (i.e., all the edges are water). */ 

/* -------- Explanation --------
We will work in a manner similar to 'surrounded_regions.cpp'. 
Indeed, we will also construct an iterative function here (dfs = depth first search), which, 
when we are on a cell of the grid and it is a land cell, sets it to 0 and applies this same function to the neighbors of this cell.
Now, in the numIsland function, we initialize m as the number of rows and n as the number of columns. 
Then, we traverse all the indices (rows and columns) simultaneously: as soon as a cell is land, we increment the counter and apply dfs to this cell. 
Thus, by applying dfs, all the neighbors are set to 0, and if we find another cell with a value of 1, it means it is another island. */

void dfs(vector<vector<char>>& grid, int i, int j, int m, int n) 
{
    if (i < 0 or i >= m or j < 0 or j >= n or grid[i][j] == '0') 
    {
        return;
    }
    grid[i][j] = '0';
        
    dfs(grid, i - 1, j, m, n);
    dfs(grid, i + 1, j, m, n);
    dfs(grid, i, j - 1, m, n);
    dfs(grid, i, j + 1, m, n);
}

int numIslands(vector<vector<char>>& grid) 
{
    int m = grid.size();
    int n = grid.front().size();
        
    int compteur = 0;
        
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (grid[i][j] == '1') 
            {
                dfs(grid, i, j, m, n);
                compteur++;
            }
        }
    }      
    return compteur;
}

int main()
{
    vector<vector<char>> grid1{{'0','1','1','1','0'}, {'0','1','0','1','0'}, {'1','1','0','0','0'}, {'0','0','0','0','0'}};
    vector<vector<char>> grid2{{'0','1','0','0','1'}, {'1','1','0','0','1'}, {'0','0','1','0','0'}, {'0','0','0','1','1'}};
    cout << numIslands(grid1) << endl; //Output : 1.
    cout << numIslands(grid2) << endl; //Output : 4.
    return 0; 
}