#include <iostream>
#include <vector>
#include <algorithm>        //std::min_element, std::max_element
#include <iterator>         //std::distance

using namespace std; 

/* -------- Subject -------- 
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0. */ 

/* -------- Explanation --------
We will copy the vector 'prices' into 'copy', and we will add all possible profits into 'profits'.
Then, we will take the smallest element in the vector (except the last one because we cannot resell it afterward),
and then look for the maximum price after buying (possible using std::distance from <iterator>).
In the end, we return the maximum possible profit. */

int maxProfit(vector<int>& prices) 
{
    vector<int> copy = prices; 
    vector<int> profits{0}; 
    while(copy.size() != 1)
    {
        auto it = min_element(copy.begin(), copy.end()-1); 
        int index = std::distance(copy.begin(), it); 
        if(index == copy.size()-1) continue;
        auto it2 = max_element(copy.begin()+index, copy.end()); 
        int min = *it;
        int max = *it2; 
        if(it < it2) profits.push_back(max-min); 
        copy.erase(it);
    }
    return *max_element(profits.begin(), profits.end()); 
}


int main()
{
    vector<int> prices{10,1,5,6,7,1}, prices2{10,8,7,5,2};
    cout << maxProfit(prices) << endl;  //Output : 6.
    cout << maxProfit(prices2) << endl; //Output : 0.
    return 0; 
}
