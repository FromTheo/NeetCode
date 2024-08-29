#include <iostream>
#include <vector>
#include <algorithm>        // std::max_element 
#include <cmath>            // std::ceil

using namespace std; 

/* -------- Subject --------  
You are given an integer array piles where piles[i] is the number of bananas in the ith pile. 
You are also given an integer h, which represents the number of hours you have to eat all the bananas.
You may decide your bananas-per-hour eating rate of k. Each hour, you may choose a pile of bananas and eats k bananas from that pile. 
If the pile has less than k bananas, you may finish eating the pile but you can not eat from another pile in the same hour.
Return the minimum integer k such that you can eat all the bananas within h hours. */

/* -------- Explanation --------
We initialize low and high, the bounds defining the search range. Using a binary search, we will update res with a while loop. 
In each iteration of the loop, we calculate the center of the search window, then the total hours needed to eat all the bananas at speed k, stored in the variable hours. 
We check if hours <= h, and if so, we update res and set low to k + 1. */

int minEatingSpeed(const vector<int>& piles, int h) 
{
    int low = 1;
    int high = * max_element(piles.begin(), piles.end()); 
    int n = piles.size();

    int res = high;

    while (low <= high) 
    {
        int k = low + (high - low) / 2;
        long int hours = 0;

        for (int i = 0; i < n; i++) 
        {
            hours += ceil((double)piles[i] / k);
        }
            
        if (hours <= h) 
        {
            res = min(res, k);
            high = k - 1;
        } 
        else 
        {
            low = k + 1;
        }
    }

    return res;
}

int main()
{
    cout << minEatingSpeed({25,10,23,4}, 4) << endl;    //Output : 25
    cout << minEatingSpeed({1,4,3,2}, 9) << endl;       //Output : 2
    return 0; 
}