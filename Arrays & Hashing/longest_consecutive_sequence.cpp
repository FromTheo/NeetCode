#include <vector>
#include <iostream> 
#include <algorithm>

using namespace std; 

/* -------- Subject --------  
Given an array of integers nums, return the length of the longest consecutive sequence of elements.
A consecutive sequence is a sequence of elements in which each element is exactly 1 greater than the previous element. */ 

/* -------- Explanation --------
Let's handle separately the cases where nums is empty or contains only one element.
After sorting in ascending order, we will increment 'counter' as soon as the next element is equal to the current element + 1.
In the case of equality, we do nothing (there is simply a duplicate in nums).
Otherwise, we add 'counter' to res and then reinitialize it to 1. Finally, we return the largest element in res.
Note: Instead of using std::vector<int> res, we could also use std::priority_queue<int> res and return res.top(). */

int longestConsecutive(std::vector<int>& nums) 
{
    if (nums.empty()) return 0;
    if (nums.size() == 1) return 1;

    std::vector<int> copy = nums;
    std::vector<int> res{1}; 
    int compteur = 1; 
    std::sort(copy.begin(), copy.end()); // Sort in ascending order by default. 

    for (int i = 1; i < copy.size(); ++i)
    {
        int current = copy[i];
        int previous = copy[i - 1];
        if (current == previous + 1)
        { 
            compteur++; 
        }
        else if (current != previous)
        {
            res.push_back(compteur);
            compteur = 1;
        } 
        // If current == previous, do nothing (duplicate case). 
    }
    res.push_back(compteur);
    return *std::max_element(res.begin(), res.end()); 
}

int main()
{
    vector<int> nums{2,20,4,10,3,4,5}, nums2{0,3,2,5,4,6,1,1}, nums3{0,0}, nums4{0,-1};
    cout << longestConsecutive(nums) << endl; //Output : 4.
    cout << longestConsecutive(nums2) << endl; //Output : 7.
    cout << longestConsecutive(nums3) << endl; //Output : 1. 
    cout << longestConsecutive(nums4) << endl; //Output : 2.
    return 0; 
}