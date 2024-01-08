#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* child;
    node(int d){
        data=d;
        next=NULL;
        child=NULL;
    }
};


void createListOfLists(node* &head){

    //For first node(left most start only)
    if(head==NULL){
        int d;
        cout<<"Enter data for start node - ";
        cin>>d;
        head=new node(d);
    }

    cout<<endl;
    cout<<"For "<<head->data<<" - "<<endl;
    char ch1,ch2;
    cout<<"Want to insert a next node?(y/n) - ";
    cin>>ch1;
    if(ch1=='y'){
        int nextData;
        cout<<"Enter Data - ";
        cin>>nextData;
        head->next=new node(nextData);
    }
    cout<<"Want to insert a child node?(y/n) - ";
    cin>>ch2;
    if(ch2=='y'){
        int childData;
        cout<<"Enter Data - ";
        cin>>childData;
        head->child=new node(childData);
    }

    if(head->next==NULL and head->child==NULL){
        return;
    }else if(head->next!=NULL and head->child==NULL){
        createListOfLists(head->next);
    }else if(head->next==NULL and head->child!=NULL){
        createListOfLists(head->child);
    }else{
        createListOfLists(head->next);
        createListOfLists(head->child);
    }
}


//Flatten the linked list (For printing row wise) - 
void flatten(node* head){ 
    if(head==NULL){
        return ;
    }

    //Assigning tail - 
    node* temp=NULL;
    node* tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }

    node* curr=head;
    while(curr!=tail){
        if(curr->child!=NULL){
            tail->next=curr->child;
            temp=curr->child;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            tail=temp;
        }
        curr=curr->next;
    }
}


void printLL(node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main(){
    node* start=NULL;
    createListOfLists(start);
    return 0;
}