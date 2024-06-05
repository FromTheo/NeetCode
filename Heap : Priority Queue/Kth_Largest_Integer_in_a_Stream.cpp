#include <iostream>
#include <vector> 
#include <queue>      //std::priority_queue
#include <functional> //std::greater 

using namespace std; 


/* -------- Subject --------  
Design a class to find the kth largest integer in a stream of values, including duplicates. 
E.g. the 2nd largest from [1, 2, 3, 3] is 3. The stream is not necessarily sorted.
Implement the following methods:
- constructor(int k, int[] nums) Initializes the object given an integer k and the stream of integers nums.
- int add(int val) Adds the integer val to the stream and returns the kth largest integer in the stream. */ 

/* -------- Explanation --------
We will add as private fields of the class the integer k and a std::priority_queue where priority is given to the smallest integers 
(thanks to std::greater<int>):this makes it a min-heap. 
By default, it is a max-heap. We fill the constructor by inserting the values from nums into Q, 
then we remove the priority elements using pop() until Q has size k.
Regarding the member function add, we follow the same principle. */ 

class KthLargest 
{
    private : 
        int k; 
        priority_queue<int,vector<int>, greater<int>> Q; 


    public:
        KthLargest(int k, vector<int>& nums) : k(k) 
        {
            for(const int& i : nums)
            {
                Q.push(i); 
            }
            while(Q.size() > k)
            {
                Q.pop(); 
            }
        }
    
        int add(int val) 
        {
            Q.push(val); 
            while(Q.size() > k)
            {
                Q.pop();
            }
            return Q.top();     
    }
};

int main()
{
    int k = 3; 
    vector<int> nums{1,2,3,3}; 
    KthLargest K(k,nums); 
    cout << K.add(3) << endl; //Output : 3. 
    cout << K.add(5) << endl; //Output : 3. 
    cout << K.add(7) << endl; //Output : 3. 
    cout << K.add(8) << endl; //Output : 5. 
    return 0; 
}
