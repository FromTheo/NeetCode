#include <iostream>
#include <vector> 
#include <queue>      //std::queue

using namespace std; 

/* -------- Subject -------- 
You are given a m * n 2D grid initialized with these three possible values:
-1 = A water cell that can not be traversed.
0 = A treasure chest.
INF = A land cell that can be traversed. We use the integer 2^31 - 1 = 2147483647 to represent INF.
Fill each land cell with the distance to its nearest treasure chest. 
If a land cell cannot reach a treasure chest than the value should remain INF.
Assume the grid can only be traversed up, down, left, or right. */ 

/* -------- Explanation --------
Let's denote m as the number of rows and n as the number of columns of the grid, which is assumed to be rectangular.
Next, let's add all the points in the grid that are treasures. They are already visited. 
We now construct the vector 'directions' storing all possible directions.
We iterate using a while loop: as long as q is not empty (in other words, as long as all cells are not visited).
By the first-in-first-out property of std::queue, we start by processing the cells containing a treasure.
We then create all possible index pairs with the elements of 'directions' and check if they are still within 
the grid or if it's not a land cell. 
If these tests pass, we change the value of grid[][] by adding the value of the cell we came from + 1. 
Through this process, we visit all cells of the grid. */

void islandsAndTreasure(vector<vector<int>>& grid) 
{
    int m = grid.size(); 
    int n = grid.front().size(); 
    
    queue<pair<int,int>> q; 

    for(int i = 0; i < m; ++i)
    {
        for(int j =0;  j< n; ++j)
        {
            if(grid[i][j] == 0)
            {
                q.push({i,j}); 
            }
        }
    }

    vector<vector<int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    while(!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop(); 

        for(int i = 0; i< 4; ++i)
        {
            int x = row + directions[i].front(); 
            int y = col + directions[i].back(); 
            if(x < 0 or x >= m or y < 0 or y >=n or grid[x][y] != INT_MAX)
            {
                continue; 
            }
            grid[x][y] = grid[row][col]+1;
            q.push({x,y});
        }
    }
}

int main()
{
    vector<vector<int>> grid{
    {2147483647,-1,0,2147483647},
    {2147483647,2147483647,2147483647,-1},
    {2147483647,-1,2147483647,-1},
    {0,-1,2147483647,2147483647}};

    islandsAndTreasure(grid); 

    for(const vector<int> & v : grid)
    {
        for(const int& i : v)
        {
            cout << i << " "; 
        }
        cout << endl; 
    }
    /* Output : 
    3  -1  0  1 
    2   2  1  -1 
    1  -1  2  -1 
    0  -1  3  4 
    */
    return 0; 
}