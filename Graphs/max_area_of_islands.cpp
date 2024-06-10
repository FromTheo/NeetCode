#include <iostream>
#include <vector> 

using namespace std; 

/* -------- Subject -------- 
You are given a matrix grid where grid[i] is either a 0 (representing water) or 1 (representing land).
An island is defined as a group of 1's connected horizontally or vertically. 
You may assume all four edges of the grid are surrounded by water.
The area of an island is defined as the number of cells within the island.
Return the maximum area of an island in grid. If no island exists, return 0. */ 

/* -------- Explanation --------
We will once again use DFS (Depth First Search). This algorithm is similar to 'number_of_islands.cpp'.
For the iterative DFS function, the cells that satisfy the constraints of being within the grid and being a land cell are set to 0, 
and we return 1 plus the same function calculated for the neighbors of the initially called cell. 
By this process, we will thus have a kind of volume calculated for a given island, by iterating a sufficient number of times.

Then within the 'maxAreaOfIsland' function, we will iterate over all possible indices and keep track of the largest area. */

int dfs(vector<vector<int>>& grid, int i, int j, int m, int n) 
{
    if (i < 0 or i >= m or j < 0 or j >= n or grid[i][j] == 0) 
    {
        return 0;
    }
    grid[i][j] = 0;
    return 1 + dfs(grid, i - 1, j, m, n) + dfs(grid, i + 1, j, m, n) + dfs(grid, i, j - 1, m, n) +  dfs(grid, i, j + 1, m, n);
}

int maxAreaOfIsland(vector<vector<int>>& grid) 
{
    int m = grid.size();
    int n = grid.front().size();

    int area = 0;

    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {   
            if(grid[i][j] == 1)
            {
                area = max(area, dfs(grid, i, j, m, n));
            }
        }
    }
    return area; 
}

int main()
{
    vector<vector<int>> grid{{0,1,1,0,1}, {1,0,1,0,1}, {0,1,1,0,1}, {0,1,0,0,1}};
    cout << maxAreaOfIsland(grid) << endl; //Output : 6.
    return 0; 
}