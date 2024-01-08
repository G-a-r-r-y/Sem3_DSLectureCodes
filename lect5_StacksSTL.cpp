#include<iostream>
#include<stack>
using namespace std;

int main(){
    //Five Major operations on a stack - 
    // 1.push
    // 2.empty 
    // 3.pop 
    // 4.top 
    // 5.size 

    //Syntax - 
    stack<int> stack1;  //Note - Stack ke saath uska data type bhi mention karna padhta hai
    cout<<stack1.empty()<<endl;
    stack1.push(10);
    stack1.push(15);
    stack1.push(20);
    stack1.push(25);
    cout<<stack1.empty()<<endl;
    cout<<stack1.top()<<endl;
    stack1.pop();
    cout<<stack1.top()<<endl;
    return 0;
}