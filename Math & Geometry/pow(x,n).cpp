#include <iostream>

using namespace std;  

/* -------- Subject -------- 
Pow(x, n) is a mathematical function to calculate the value of x raised to the power of n (i.e., x^n).
Given a floating-point value x and an integer value n, implement the myPow(x, n) function, which calculates x raised to the power n. */ 

/* -------- Explanation --------
We will operate on the principle of recurrence. 
First of all, let's address the special case where n == 0; in this case, we return 1. 
If n < 0, then we ensure that we calculate a positive power by taking the inverse of x, while making sure that x is non-zero. 
We use std::abs to handle rounding errors. Finally, we recursively call (depending on the parity of n) the function myPow(). 
This technique is much faster than calling the function at the previous rank. */

double myPow(double x, int n) 
{
    if(n==0) return 1.0; 

    if(n < 0)
    {
        if(std::abs(x) < 1e-15) return 0.0; 
        x = 1/x; 
        n = -1 * n; 
    }

    if(n%2 == 0) 
    {
        double y = myPow(x,n/2);
        return y*y; 
    }

    else 
    {
        double y = myPow(x,(n-1)/2);
        return y*y*x; 
    }
}

int main()
{
    double x = 2.00000; 
    double y = 1.10000;
    double z = 2.00000; 
    int a = 5;
    int b = 10; 
    int c = -3; 
    cout << myPow(x,a) << endl; //Output : 32
    cout << myPow(y,b) << endl; //Output : 2.59374
    cout << myPow(z,c) << endl; //Output : 0.125
    return 0; 
}