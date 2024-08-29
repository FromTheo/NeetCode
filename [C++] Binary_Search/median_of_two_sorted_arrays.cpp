#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

/* -------- Subject --------  
You are given two integer arrays nums1 and nums2 of size m and n respectively, where each is sorted in ascending order.
Return the median value among all elements of the two arrays. */

/* -------- Explanation --------
The idea behind my algorithm is quite simple. We will merge the two vectors and then sort the resulting vector in ascending order. 
Then, depending on the parity of n, its size, we will apply the classic formula for the median. */

double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2) 
{
    vector<int> nums(nums1.size() + nums2.size()); 
    copy(nums1.begin(), nums1.end(), nums.begin()); 
    copy(nums2.begin(), nums2.end(), nums.begin()+nums1.size());
    sort(nums.begin(), nums.end());
    int n = nums.size(); 

    if(n%2 != 0) return nums[std::floor(n/2)];
    else return (nums[n/2-1] + nums[n/2])/(double)2;
}

int main()
{
    cout << findMedianSortedArrays(vector<int>{1,2},vector<int>{3}) << endl;      //Output : 2.0
    cout << findMedianSortedArrays(vector<int>{1,3},vector<int>{2,4}) << endl;    //Output : 2.5 
    return 0; 
}