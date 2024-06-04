#include <string>
#include <algorithm> 
#include <iostream> 
#include <map> 

using namespace std; 

/* -------- Subject --------  
Given an integer array nums and an integer k, return the k most frequent elements within the array.
The test cases are generated such that the answer is always unique.
You may return the output in any order. */ 

/* -------- Explanation --------
I will create a map<int, int> in which I will add each element from nums associated with its number of occurrences. 
Then, through a for loop, I will successively calculate the k largest elements from the map and add them to the resulting vector.*/

vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int,int> M; 
    vector<int> res(k);
    for(const int& i : nums)
    {
        M[i]++; 
    }
    for(int i = 0; i < k; i++)
    {
        auto it = max_element(M.begin(), M.end(), [](const std::pair<int,int>&p, const std::pair<int,int>&q)
        {
            return p.second < q.second; 
        }); 
        int value = (*it).first; 
        M.erase(it); 
        res[i] = value; 
    }
    return res;
}

int main()
{
    vector<int> nums1{1,2,2,3,3,3}, nums2{7,7};
    int k1(2), k2(1); 
    for(const int& i : topKFrequent(nums1,k1))
    {
        cout << i << " "; 
    }
    //Output : 2 3 
    cout << endl; 
    for(const int& i : topKFrequent(nums2,k2))
    {
        cout << i << " "; 
    }
    //Output : 7 
    cout << endl; 
    return 0; 
}


