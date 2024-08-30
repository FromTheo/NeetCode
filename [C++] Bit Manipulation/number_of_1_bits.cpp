#include <iostream> 

using namespace std;  

/* -------- Subject -------- 
You are given an unsigned integer n. Return the number of 1 bits in its binary representation. */ 

/* -------- Explanation --------
On va initialiser un compteur égal à 0 qui est incrémenté à chaque bit égal à 1 rencontré. */

int hammingWeight(int n) 
{
    int count = 0;
    while(n)
    {
        count++;
        n = n & (n-1);
    }
    return count;
}

int main()
{
    int n = 2147483645; // n = 1111111111111111111111111111101 in binary. 
    cout << hammingWeight(n) << endl; //Output : 30
    return 0; 
}
