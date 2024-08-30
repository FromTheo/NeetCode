#include <iostream> 

using namespace std; 

/* -------- Subject --------  
Given two integers a and b, return the sum of the two integers without using the + and - operators. */ 

int getSum(int a, int b) 
{
    return add(a, b);
}

int add(int a, int b) 
{
    if (a == 0 || b == 0) 
    {
        return a | b;
    }
    return add(a ^ b, (a & b) << 1);
}

int main()
{
    cout << getSum(4,7) << endl; //Output : 11 

    return 0; 
}