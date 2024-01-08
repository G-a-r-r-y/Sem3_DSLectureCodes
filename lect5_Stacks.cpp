//Stack Implementation via an array - 
#include<bits/stdc++.h>
using namespace std;

//Five Major operations on a stack - 
// 1.Push
// 2.isEmpty 
// 3.Pop 
// 4.Top 
// 5.Size 

int top=-1; //Important Condition

void push(int stack[],int ele,int maxSize){
    if(top==maxSize-1){
        cout<<"Stack OverFlow."<<endl;
    }else{
        top=top+1;
        stack[top]=ele;
    }
}

bool isEmpty(){  //No need to pass any argument cause top is globally declared.
    if(top==-1){
        return true;
    }else{
        return false;
    }
}

void pop(){
    if(isEmpty()){
        cout<<"Stack UnderFlow."<<endl;
    }else{
        top=top-1; //decrementing top's position will detach last element from stack .
    }
}

int Top(int stack[]){
    if(top==-1){
        cout<<"Stack is Empty."<<endl;
        return -1;
    }else{
        return stack[top];
    }
}

int size(){
    return top+1; //Cause top is initiallised with -1.
}

int main(){
    int stack[10]; // Yaha par hum maanke chal rahe hai ki stack ki max limit is 10.
    cout<<"IsEmpty - "<<isEmpty()<<endl;
    push(stack,10,10);
    push(stack,9,10);
    push(stack,8,10);
    push(stack,7,10);
    push(stack,6,10);
    push(stack,5,10);
    cout<<"IsEmpty - "<<isEmpty()<<endl;
    cout<<"Top - "<<Top(stack)<<endl;
    cout<<"Size - "<<size()<<endl;
    pop();
    cout<<"Top - "<<Top(stack)<<endl;
    cout<<"Size - "<<size()<<endl;
    return 0;
}