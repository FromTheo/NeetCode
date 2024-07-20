#include <iostream>
#include <vector>
#include <algorithm>        //std::fill

using namespace std; 

/* -------- Subject -------- 
You are given an integer array digits, where each digits[i] is the ith digit of a large integer. 
It is ordered from most significant to least significant digit, and it will not contain any leading zero.
Return the digits of the given integer after incrementing it by one.*/ 

/* -------- Explanation --------
Let's first handle the simple case where the units digit is not a 9: we make an increment without carrying over.
Now, concerning the case where digits.back() == 9, we will check how long the digits remain 9.
As long as this is the case, we set the digit to 0 and keep a carry of 1.
We decrement the index, and as soon as we find a digit that is not 9,
we increment digits[] at that position.
If at the end of the loop the index == 0, it means we had only 9s, so we create a new vector
that contains one more digit. */

vector<int> plusOne(vector<int>& digits) 
{
    if(digits.back() != 9)
    {
        digits.back()++;
        return digits;
    }
    else
    {
        int index = digits.size()-1;
        while(digits[index] == 9 && index >0)
        {
            digits[index] = 0;
            if(digits[index-1] == 9)
            {
                index--; 
            }
            else
            {
                digits[index-1]++;
            }
        }
        if(index == 0)
        {
            vector<int> resultat(digits.size()+1);
            resultat[0] = 1;
            fill(resultat.begin()+1, resultat.end(), 0); 
            return resultat; 
        }
        return digits;
    }
}

int main()
{
    vector<int> digits1{1,2,3,4}, digits2{9,9,9}, digits3{8,9,9,9};
    for(const int& i : plusOne(digits1))
    {
        cout << i << " "; 
    }
    cout << endl; 
    //Output : 1 2 3 5
    for(const int& i : plusOne(digits2))
    {
        cout << i << " "; 
    }
    cout << endl; 
    //Output : 1 0 0 0
    for(const int& i : plusOne(digits3))
    {
        cout << i << " "; 
    }
    cout << endl; 
    //Output : 9 0 0 0
    return 0; 
}
