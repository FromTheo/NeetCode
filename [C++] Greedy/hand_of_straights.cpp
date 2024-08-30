#include <iostream>
#include <vector>
#include <map>

using namespace std; 

/* -------- Subject --------  
You are given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize.
You want to rearrange the cards into groups so that each group is of size groupSize, and card values are consecutively increasing by 1.
Return true if it's possible to rearrange the cards in this way, otherwise, return false. */

bool isNStraightHand(const vector<int>& hand, int groupSize) 
{
    if(hand.size() % groupSize != 0) return false; 
        
    map<int, int> cardCount;
    for(const int& card : hand) 
    {
        cardCount[card]++;
    }
        
    for(map<int,int>::const_iterator it = cardCount.begin(); it != cardCount.end(); ++it) // for(const pair<int,int>& p : cardCount) 
    {
        int card = it->first;
        int count = it->second;
            
        if(count > 0) 
        {
            for(int i = 0; i < groupSize; ++i)
            {
                if(cardCount[card + i] < count) 
                {
                    return false;
                }
                cardCount[card + i] -= count;
            }
        }
    }
    return true;
}

int main()
{
    cout << isNStraightHand(vector<int>{1,2,4,2,3,5,3,4}, 4) << endl; //Output : 1 
    cout << isNStraightHand(vector<int>{1,2,3,3,4,5,6,7}, 4) << endl; //Output : 0 
    return 0; 
}
