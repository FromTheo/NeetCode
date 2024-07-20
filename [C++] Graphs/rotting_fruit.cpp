#include <iostream>
#include <vector> 
#include <queue>      //std::queue
#include <utility>    //std::pair 

using namespace std; 

/* -------- Subject -------- 
You are given a 2-D matrix grid. Each cell can have one of three possible values:
- 0 representing an empty cell
- 1 representing a fresh fruit
- 2 representing a rotten fruit
Every second, if a fresh fruit is horizontally or vertically adjacent to a rotten fruit, 
then the fresh fruit also becomes rotten.
Return the minimum number of seconds that must elapse until there are zero fresh fruits remaining. 
If this state is impossible within the grid, return -1.*/ 

/* -------- Explanation --------
Let's denote m as the number of rows and n as the number of columns of the grid, which is assumed to be rectangular.
We will proceed in the same way as 'islands_and_treasure.cpp', but instead of adding the chests to the std::queue, 
we add the rotten fruits, while incrementing the 'fresh' counter to keep track of how many there are (so we know when to stop). 
Following the analogy, we create the same 'directions' vector, then a while loop, 
and we stop when all the cells are visited or when 'fresh' == 0.
The change here is that we need to iterate directly over the number of rotten fruits, as there can be multiple per second. 
Otherwise, the principle remains the same. 
Still, thanks to the first-in, first-out property of std::queue, we apply the necessary modifications to the cells containing a fresh fruit. */

int orangesRotting(vector<vector<int>>& grid) 
{
    int m = grid.size(); 
    int n = grid.front().size(); 
    queue<pair<int,int>> q; 
    int fresh = 0; 
    int compteur = 0; 
    for(int i = 0; i < m ; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(grid[i][j] == 1) fresh++;
            if(grid[i][j] == 2) q.push({i,j}); 
        }
    }
    vector<vector<int>> directions{{0,1},{0,-1}, {-1,0}, {1,0}}; 
    while(fresh > 0 && !q.empty())
    {
        int length = q.size(); 
        for(int i = 0; i < length; ++i)
        {
            int row = q.front().first; 
            int col = q.front().second; 
            q.pop(); 
            for(int i = 0; i < 4; ++i)
            {
                int x = row + directions[i].front(); 
                int y = col + directions[i].back(); 
                if(x >= 0 && x < m && y>=0 && y < n && grid[x][y] == 1)
                {
                    grid[x][y] = 2; 
                    q.push({x,y}); 
                    fresh--; 
                }
            }
        } 
        compteur++; 
    }
    if(fresh == 0) return compteur; 
    return -1;
}

int main()
{
    vector<vector<int>> grid1{{1,1,0}, {0,1,1}, {0,1,2}};
    vector<vector<int>> grid2{{1,0,1}, {0,2,0}, {1,0,1}};
    int nb1 = orangesRotting(grid1);
    cout << nb1 << endl; //Output : 4.
    int nb2 = orangesRotting(grid2);
    cout << nb2 << endl; //Output : -1. 
    return 0; 
}