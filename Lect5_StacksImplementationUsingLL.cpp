//Stack implementation using linked list -

// Operations -
// 1. Push
// 2. Pop
// 3. Top
// 4. Isempty
// 5. size

#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int d){
        data=d;
        next=NULL;
    }
};

void insertAtHead(node* &head,node* &tail,int d){
    node* n=new node(d);
    if(head==NULL and tail==NULL){
        head=n;
        tail=n;
    }else{
        n->next=head;
        head=n;
    }
}

void deleteAtHead(node* &head,node* &tail){
    if(head==NULL and tail==NULL){
        return;
    }else{
        node* temp=head;
        head=head->next;
        delete temp;
    }
}

class Userstack{
    node* head;
    node* tail;
    int maxSize=0;
    int currSize=0;
   
    public:
    Userstack(int m){
        head=NULL;
        tail=NULL;
        maxSize=m;
    }
   
    //Push -
    void push(int d){
        if(currSize>=maxSize){
            cout<<"Stack OverFlow - "<<endl;
        }else{
            insertAtHead(head,tail,d);
            currSize++;  
        }
    }
   
    //pop -
    void pop(){
        if(currSize==0){
            cout<<"Stack UnderFlow - "<<endl;
        }else{
            deleteAtHead(head,tail);
            currSize--;
        }
    }
   
    //Top -
    int top(){
       if(currSize==0){
           cout<<"Stacak UnderFlow - "<<endl;
            return -1;
       }else{
           return head->data;
       }
    }
   
    //isEmpty
    bool isEmpty(){
        if(currSize==0){
            return true;
        }else{
            return false;
        }
    }
   
    int size(){
        return currSize;
    }
};

int main(){
    Userstack s(10);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    cout<<s.isEmpty()<<endl;
    cout<<s.size()<<endl;
    s.pop();s.pop();s.pop();
    cout<<s.top()<<endl;
    return 0;
}

