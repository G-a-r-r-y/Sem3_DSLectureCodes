#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    int col;
    node* next;
    node(int d,int c){
        data=d;
        col=c;
        next=NULL;
    }
};

void insertAtTail(node* &head,node* &tail){
    int d,c;
    cout<<"Enter data and column - ";
    cin>>d>>c;
    node* n=new node(d,c);
    if(head==NULL and tail==NULL){
        head=n;
        tail=n;
    }else{
        tail->next=n;
        tail=n;
    }
}

node* insertEles(node* &head,node* &tail){
    char ch;
    cout<<"Want to insert an element?(y/n) - ";
    cin>>ch;
    if(ch=='y'){
        insertAtTail(head,tail);
        insertEles(head,tail);
    }
    return head;
}

void printHelper(node* arr[],int i){
    node* head=arr[i];
    int counter=1;
    while(head!=NULL){
        if(counter==head->col){
            cout<<head->data<<" ";
            head=head->next;
        }else{
            cout<<0<<" ";
        }
        counter++;
    }

    // while(head!=NULL){
    //     cout<<'{'<<head->col<<" , "<<head->data<<'}'<<" ";
    //     head=head->next;        
    // }
}

void printSparce(node* arr[],int n){
    for(int i=1;i<=n;i++){
        cout<<endl;
        printHelper(arr,i);
    }
}

int len(node* head){
    int c=0;
    while(head!=NULL){
        c++;
        head=head->next;
    }
    return c;
}

int main(){
    int n;
    cin>>n;
    node* arr[n+1];
    node* head=NULL;
    node* tail=NULL;
    for(int i=1;i<=n;i++){
        cout<<endl;
        head=NULL;
        tail=NULL;
        cout<<"For "<<i<<" row - "<<endl;
        arr[i]=insertEles(head,tail);
    }

    // for(int i=1;i<=n;i++){
    //     cout<<endl;
    //     cout<<len(arr[i]);
    // }

    // Note - Print simply karado, koi matrix mei dikhane ki zarurat nhi.
    printSparce(arr,n);
    return 0;
}