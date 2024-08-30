#include <iostream>

using namespace std; 

/* -------- Subject --------  
Given a 32-bit unsigned integer n, reverse the bits of the binary representation of n and return the result. */

uint32_t reverseBits(uint32_t n) 
{
    uint32_t result = 0;


    for (int i = 0; i < 32; ++i) //Iterate through each bit position (32 bits in total). 
    {
        result = (result << 1) | (n & 1); //Add the rightmost bit of n to result using bitwise OR. 
        n >>= 1; //Shift n to the right to process the next bit. 
    }

    return result;
}

int main()
{
    int n = 5; 
    cout << reverseBits(n) << endl; //Output : 2684354560

    return 0; 
}
