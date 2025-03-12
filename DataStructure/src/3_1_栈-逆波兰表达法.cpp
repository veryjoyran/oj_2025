#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <stdio.h>

using namespace std;

int calculate(char symbol,int left_num,int right_num)
{
    if(symbol=='+')
        return left_num+right_num;
    else if(symbol=='-')
        return left_num-right_num;
    else if(symbol=='*')
        return left_num*right_num;
}


int main() {
    stack<int> num_stack;
    stack<char> symbol_stack;
    string s;
    int result=0;

    while(cin>>s){
        if(s[0]=='+'||s[0]=='-'||s[0]=='*')
        {
            symbol_stack.push(s[0]);
        }
        else{
            num_stack.push(stoi(s));
        }
        if(num_stack.size()>=2&&symbol_stack.size()>=1)
        {
            int right_num=num_stack.top();
            num_stack.pop();
            int left_num=num_stack.top();
            num_stack.pop();

            char symbol=symbol_stack.top();
            symbol_stack.pop();

            result=calculate(symbol,left_num,right_num);
            num_stack.push(result);



        }

    }
    cout<<result;


    return 0;
}
