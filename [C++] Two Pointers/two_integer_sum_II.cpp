#include <iostream>
#include <vector>

using namespace std; 

/* -------- Subject --------  
Given an array of integers numbers that is sorted in non-decreasing order.
Return the indices (1-indexed) of two numbers, [index1, index2], such that they add up to a given target number target and index1 < index2. 
Note that index1 and index2 cannot be equal, therefore you may not use the same element twice.
There will always be exactly one valid solution. */

/* -------- Explanation --------
Method 1: Less optimal. We go through all possible pairs of elements in numbers, then we check the given conditions.
Method 2: We use the (crucial) assumption that the vector is sorted in ascending order, then we test. */

vector<int> twoSum(vector<int>& numbers, int target) 
{
    //Method 1: 
    /*int size = numbers.size(); 
    vector<int> res; 
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(numbers[i] < numbers[j] && numbers[i] + numbers[j] == target) res = vector<int>{i+1,j+1}; 
        }
    } 
    return res; */

    // Method 2 : 
    int i = 0;
    int j = numbers.size()-1; 
    while(i < j)
    { 
        int currentSum = numbers[i] + numbers[j];
        if(currentSum > target) j--; 
        else if(currentSum < target) i++;
        else return {i+1,j+1}; 
    }
    return {};
} 

int main()
{
    vector<int> v{1,2,3,4};
    int target = 3;
    for(const int& i : twoSum(v,target))
    {
        cout << i << " "; 
    }
    //Output : 1 2 
    return 0; 
}