//Queue implementation using linked list -
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

void insertAtTail(node* &head,node* &tail,int d){
    node* n=new node(d);
    if(head==NULL and tail==NULL){
        head=n;
        tail=n;
    }else{
        tail->next=n;
        tail=n;
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

class UserQueue{
    node* head;
    node* tail;
    int maxSize=0;
    int currSize=0;
   
    public:
    UserQueue(int m){
        head=NULL;
        tail=NULL;
        maxSize=m;
    }
   
    //enqueue -
    void enqueue(int d){
        if(currSize>=maxSize){
            cout<<"Queue OverFlow "<<endl;
        }else{
            insertAtTail(head,tail,d);
            currSize++;
        }
    }
   
    //dequeue -
    void dequeue(){
        if(currSize==0){
            cout<<"Queue UnderFlow "<<endl;
        }else{
            deleteAtHead(head,tail);
            currSize--;
        }
    }
   
    //front -
    int front(){
        if(currSize==0){
            cout<<"Queue UnderFlow "<<endl;
            return -1;
        }else{
            return head->data;
        }
    }
   
    //isEmpty -
    bool isEmpty(){
        if(currSize==0){
            return true;
        }else{
            return false;
        }
    }
   
    //size -
    int size(){
        return currSize;
    }
};

int main(){
    UserQueue q(10);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout<<q.front()<<endl;
    q.dequeue();
    cout<<q.front()<<endl;
    cout<<q.isEmpty()<<endl;
    cout<<q.size()<<endl;
    return 0;
}