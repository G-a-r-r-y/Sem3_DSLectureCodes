#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* prev;
    node* next;
    node(int d){
        data=d;
        prev=NULL;
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
        head->prev=n;
        head=n;
    }
}


void insertAtTail(node* &head,node* &tail,int d){
    node* n=new node(d);
    if(head==NULL and tail==NULL){
        head=n;
        tail=n;
    }else{
        tail->next=n;
        n->prev=tail;
        tail=n;
    }
}

void insertAtAnyIndex(node* &head,node* &tail,int d,int index){
    node* n=new node(d);
    int count=0;
    //Case 1 (index==0)
    if(index==0){
        n->next=head;
        head->prev=n;
        head=n;
        return;
    }

    //Case 2 (in between) - 
    count++;
    node* temp=head->next;
    while(temp!=NULL){
        if(count==index){
            temp->prev->next=n;
            n->prev=temp->prev;
            n->next=temp;
            temp->prev=n;
            node* tempHead=head;
            return;
        }
        temp=temp->next;
        count++;
    }

    //Case 3 (insert at tail) - 
    tail->next=n;
    n->prev=tail;
    tail=n;
}

void deleteAtAnyIndex(node* &head,node* &tail,int index){
    int count=0;
    //Case 1 (index==0)
    if(index==0){
        node* temp=head;
        head=head->next;
        delete temp;
        head->prev=NULL;
        return;
    }

    //Case 2 (in between) - 
    count++;
    node* temp=head->next;
    while(temp->next!=NULL){
        if(count==index){
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            delete temp;
            return;
        }
        temp=temp->next;
        count++;
    }

    //Case 3 (deleting tail) - 
    if(count==index){           //Note - writing this condition to make sure ki agar
        temp->prev->next=NULL;  //       user index out of bound jaaye toh koi element delete na ho.
        tail=temp->prev;
        delete temp;
    }
}

void printDoublyLL(node* head){
    cout<<endl;
    cout<<"NULL - "<<head->data<<" - "<<head->next->data<<endl;
    head=head->next;
    while(head->next!=NULL){
        cout<<head->prev->data<<" - "<<head->data<<" - "<<head->next->data<<endl;
        head=head->next;
    }
    cout<<head->prev->data<<" - "<<head->data<<" - NULL"<<endl<<endl;
}

int main(){
    node* head=NULL;
    node* tail=NULL;
    int n;
    cin>>n;
    while(n>0){
        int d;
        cin>>d;
        insertAtTail(head,tail,d);
        n--;
    }
    printDoublyLL(head);
    //insertAtAnyIndex(head,tail,100,4);
    deleteAtAnyIndex(head,tail,4);
    printDoublyLL(head);
    return 0;
}