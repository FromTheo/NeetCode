#include <map>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

/* -------- Subject --------  
You are given an array of CPU tasks tasks, where tasks[i] is an uppercase english character from A to Z. 
You are also given an integer n.
Each CPU cycle allows the completion of a single task, and tasks may be completed in any order.
The only constraint is that identical tasks must be separated by at least n CPU cycles, to cooldown the CPU.
Return the minimum number of CPU cycles required to complete all tasks. */ 

int leastInterval(vector<char>& tasks, int n) 
{
    //Compute the frequency of each task. 
    map<char, int> taskCount;
    for (const char& task : tasks) 
    {
        taskCount[task]++;
    }

    auto it = max_element(taskCount.begin(), taskCount.end(), [](const pair<char, int>& p, const pair<char, int>& q)
    {
        return p.second < q.second; 
    }); 
    int maxFreq = it -> second;

    auto equal_to_max_frequency = [&maxFreq](const pair<char, int> &p)
    {
        return p.second == maxFreq; 
    }; 
    int maxCount = count_if(taskCount.begin(), taskCount.end(), equal_to_max_frequency);

    //Compute the minimal number of cycles
    int partCount = maxFreq - 1;                                //Number of "blocks". 
    int emptySlots = partCount * (n - (maxCount - 1));          //Number of empty cases. 
    int availableTasks = tasks.size() - (maxFreq * maxCount);   //Number of tasks remaining after reserving places for the most frequent tasks.
    int idles = max(0, emptySlots - availableTasks);            //Number of inactivity cycles required if the remaining tasks are not enough to fill the empty boxes.
    
    return tasks.size() + idles;
}

int main()
{
    vector<char> tasks{'A','A','A','B','C'};
    int n = 3;
    cout << leastInterval(tasks, n) << endl; //Output : 9 
    return 0; 
}