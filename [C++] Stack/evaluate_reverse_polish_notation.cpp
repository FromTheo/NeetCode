#include <vector>
#include <string>
#include <stack>
#include <cstdlib>      //std::atoi
#include <iostream> 

using namespace std; 

/* -------- Subject --------  
You are given an array of strings tokens that represents a valid arithmetic expression in Reverse Polish Notation.
Return the integer that represents the evaluation of the expression.
- The operands may be integers or the results of other operations.
- The operators include '+', '-', '*', and '/'.
- Assume that division between integers always truncates toward zero. */ 

int evalRPN(std::vector<std::string>& tokens) 
{
    std::stack<int> stack;
    for (const std::string& token : tokens) 
    {
        if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            int operand2 = stack.top(); stack.pop();
            int operand1 = stack.top(); stack.pop();
            int result;
                
            if (token == "+") 
            {
                result = operand1 + operand2;
            } 
            else if (token == "-") 
            {
                result = operand1 - operand2;
            } 
            else if (token == "*") 
            {
                result = operand1 * operand2;
            } 
            else if (token == "/") 
            {
                result = operand1 / operand2;
            }
                
            stack.push(result);
        } 
        else // Token is a number
        {
            stack.push(std::atoi(token.c_str()));
        }
    } 
    return stack.top();
}

int main()
{
    vector<string> tokens{"1","2","+","3","*","4","-"};
    cout << evalRPN(tokens) << endl; //Output : 5 = ((1+2)*3)-4 
    return 0; 
}