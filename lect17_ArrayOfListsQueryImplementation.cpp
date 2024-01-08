//2 queries implemented here - 
// 1. which day has the most number of lectures?
// 2. How many lectures of a particular subject are there on a specific day?

#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    string subject;
    int time;
    node* next;
    node(string s,int t){
        subject=s;
        time=t;
        next=NULL;
    }
};

node* insertValues(){
    char ch;
    cout<<"Want to enter new data ?(y/n) -";
    cin>>ch;
    if(ch=='n'){
        return NULL;
    }
    string s;
    int t;
    cout<<"Enter subject - ";
    cin>>s;
    cout<<"Enter time - ";
    cin>>t;
    node* n=new node(s,t);
    n->next=insertValues();
    return n;
}

void insertInArr(node* arr[],int index){
    node* head=NULL;
    head=insertValues();
    arr[index]=head;
}

void printWhole(node* arr[]){
    for(int i=0;i<7;i++){
        cout<<endl;
        cout<<"For index - "<<i<<" - "<<endl;
        if(arr[i]!=NULL){
            node* head=arr[i];
            while(head!=NULL){
                cout<<'{'<<head->subject<<','<<head->time<<'}'<<" ";
                head=head->next;
            }
        }else{
            cout<<"No data entered";
        }
        cout<<endl;
    }
}

void query1(node* arr[]){
    int index;
    int count=0;
    for(int i=0;i<7;i++){
        int innerCount=0;
        if(arr[i]==NULL){
            continue;
        }else{
            node* head=arr[i];
            while(head!=NULL){
                innerCount++;
                head=head->next;
            }
        }
        if(innerCount>count){
            count=innerCount;
            index=i;   
        }
    }
    cout<<"Index - "<<index<<" (day) has the most number of lectures - "<<count<<endl;
}

void query2(node* arr[],int index){
    int count=0;
    node* head=arr[index];
    while(head!=NULL){
        count++;
        head=head->next;
    }
    cout<<"Number of lectures - "<<count<<endl;
}

int main(){
    node* arr[7]={NULL};
    for(int i=0;i<7;i++){
        cout<<"Enter data for "<<i<<" index - "<<endl;
        insertInArr(arr,i);
        cout<<endl;
    }
    cout<<"Printing all data - "<<endl;
    printWhole(arr);
    cout<<endl;
    cout<<"Query 1 Answer - "<<endl;
    query1(arr);
    cout<<endl;
    cout<<"Query 2 Answer - "<<endl;
    int index;
    cout<<"Enter the index of the particular day - ";
    cin>>index;
    query2(arr,index);
    return 0;
}