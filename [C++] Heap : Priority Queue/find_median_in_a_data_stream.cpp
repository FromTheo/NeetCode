#include <queue> 
#include <iostream>

using namespace std;

/* -------- Subject --------  
You are given an array of CPU tasks tasks, where tasks[i] is an uppercase english character from A to Z. 
You are also given an integer n.
Each CPU cycle allows the completion of a single task, and tasks may be completed in any order.
The only constraint is that identical tasks must be separated by at least n CPU cycles, to cooldown the CPU.
Return the minimum number of CPU cycles required to complete all tasks. */ 

class MedianFinder 
{
    private:
    priority_queue<int> maxHeap; //Max-heap for the lower half.
    priority_queue<int, vector<int>, greater<int>> minHeap; //Min-heap for the upper half.

    // [ ----------- maxHeap.top()] [minHeap.top() ------------]  

    public:
    MedianFinder() {}
    
    void addNum(int num) 
    {
    maxHeap.push(num);
        
        //Ensure all elements in maxHeap are <= elements in minHeap.
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        // If minHeap has more elements than maxHeap, rebalance.
        if (minHeap.size() > maxHeap.size()) 
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() 
    {
        if (maxHeap.size() == minHeap.size()) //If both heaps have the same size, the median is the average of the two tops.
        {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        } 
        else //Otherwise, the median is the top of the max-heap.
        { 
            return maxHeap.top();
        }
    }
};

int main()
{
    MedianFinder medianFinder; 
    medianFinder.addNum(1);    //arr = [1]
    medianFinder.findMedian(); //return 1.0
    medianFinder.addNum(3);    //arr = [1, 3]
    medianFinder.findMedian(); //return 2.0
    medianFinder.addNum(2);    //arr[1, 2, 3]
    medianFinder.findMedian(); //return 2.0

    return 0; 
}