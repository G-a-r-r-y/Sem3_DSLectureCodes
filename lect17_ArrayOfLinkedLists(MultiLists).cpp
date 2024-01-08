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

int main(){
    node* arr[7]={NULL};
    for(int i=0;i<7;i++){
        cout<<"Enter data for "<<i<<" index - "<<endl;
        insertInArr(arr,i);
        cout<<endl;
    }
    cout<<"Printing all data - "<<endl;
    printWhole(arr);
    return 0;
}