#include <vector>
#include <iostream> 
#include <queue> 

using namespace std; 

/* -------- Subject --------  
You are given an array prerequisites where prerequisites[i] = [a, b] indicates that you must take course b first if you want to take course a.
For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
There are a total of numCourses courses you are required to take, labeled from 0 to numCourses - 1.
Return true if it is possible to finish all courses, otherwise return false.*/ 

/* -------- Explanation --------
We will try to see if there is a cycle: and in this case, it will not be possible to complete all the courses.
We can view this problem as a graph, where the nodes represent the courses and the (directed) edges represent the prerequisites.
std::vector<int> indegree will store the number of incoming edges to each course (the prerequisites, actually).
std::vector<int> result will store the topological order of the courses.
Now, we perform Kahn's algorithm. We create an empty queue 'q' to store the nodes to visit.
We will iterate over all the courses and enqueue the courses without prerequisites (indegree[] == 0).
Then, we will take the neighbors of these courses (i.e., those whose preceding courses are prerequisites), decrement and add them to 'q'.
We return 'true' if result.size() == n, meaning all courses have been completed. */

bool canFinish(int n, vector<vector<int>>& prerequisites) 
{
    vector<int> adj[n];
    vector<int> indegree(n, 0);
    vector<int> resultat;

    for(const vector<int>& x: prerequisites)
    {
        adj[x[0]].push_back(x[1]);
        indegree[x[1]]++;
    }

    queue<int> q;
    for(int i = 0; i < n; i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int t = q.front();
        resultat.push_back(t);
        q.pop();

        for(int x: adj[t])
        {
            indegree[x]--;
            if(indegree[x] == 0)
            {
                q.push(x);
            }
        }
    }
    return resultat.size() == n;
}

int main()
{
    vector<vector<int>> prerequisites1{{0,1}}, prerequisites2{{0,1},{1,0}}; 
    int n = 2; 
    cout << canFinish(n, prerequisites1) << endl; //Output : 1.
    cout << canFinish(n, prerequisites2) << endl; //Output : 0.
    return 0; 
}
