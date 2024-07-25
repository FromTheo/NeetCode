#include <vector>
#include <iostream> 
#include <stack>        //std::stack

using namespace std; 

/* -------- Subject --------  
Design a stack class that supports the push, pop, top, and getMin operations.
- MinStack() initializes the stack object.
- void push(int val) pushes the element val onto the stack.
- void pop() removes the element on the top of the stack.
- int top() gets the top element of the stack.
- int getMin() retrieves the minimum element in the stack. */ 

/* -------- Explanation --------
- When creating an object of type MinStack, min is initialized to the value INT_MAX, 
  which ensures that it contains at least one value.
- For push(int), we add to the stack without any verification, and if the added value is smaller than min.top(), 
  we add it to min as well. This verification is crucial as it maintains the order structure in min.
- For pop(), we check if the element removed from the stack is the same as the one (potentially) removed from min. 
  If so, we remove it from min as well. */

class MinStack 
{
    private:
        std::stack<int> stack;
        std::stack<int> min;
    public:
        MinStack() 
        {
            min.push(INT_MAX);
        }
    
        void push(int val) 
        {
            if (val <= min.top())
            {
                min.push(val);
            }        
            stack.push(val);
        }
    
        void pop() 
        {
            if (stack.top() == min.top())
                min.pop();
            stack.pop();
        }
    
        int top() 
        {
            return stack.top();        
        }
    
        int getMin() 
        {
            return min.top();
        }
};
