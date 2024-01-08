#include<bits/stdc++.h>
using namespace std;

class node{
    public:    //access modifier
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

void printLL(node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

void isEmptyLL(node* head){
    if(head==NULL){
        cout<<"List is empty"<<endl;
    }else{
        cout<<"List is notempty"<<endl;
    }
}

int lenLL(node* head){
    int count=0;
    while(head!=NULL){
        count++;
        head=head->next;
    }
    return count;
}

void destroyLL(node* &head,node* &tail){
    while(head!=NULL){
        node* temp=head;
        head=head->next;
        delete temp;
    }
    head=NULL;
    tail=NULL;
}

//Important Operations - 
void insertAtSpecificLocation(node* &head,node* &tail,int d,int index){
    int count=0;
    node* n=new node(d);
    //Case 1 (if index==0)
    if(index==0){
        n->next=head;
        head=n;
        return;
    }

    //Case 2 (in between)
    count++;
    node* tempHead=head->next;
    node* prev=head;
    while (tempHead!=NULL){
        if(count==index){
            prev->next=n;
            n->next=tempHead;
            return;
        }
        prev=tempHead;
        tempHead=tempHead->next;
        count++;
    }

    //Agar koi index out of range dala toh last mei element add hoga.
    //Case 3 (inserting at tail)
    tail->next=n;
    tail=n;     
}

void deleteAtSpecificLocation(node* &head,node* &tail,int index){
    int count=0;
    //Case 1 (for index==0)- 
    if(index==0){
        node* temp=head;
        head=head->next;
        delete temp;
        return ;
    }

    //Case 2 (for all other indices)- 
    count++;
    node* temp=head->next;
    node* prev=head;
    while(temp!=NULL){
        if(count==index){
            prev->next=temp->next;
            delete temp;
            break;                        //Note - yaha par break likhna instead of return cause iske baad
        }                                 //       tail dobara assign karni hai.
        prev=temp;
        temp=temp->next;
        count++;
    }

    //Re-assinging tail -
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    tail=temp;
}

int main(){
    node* head=NULL;
    node* tail=NULL;
    int n,d;
    cin>>n;
    while(n>0){
        cin>>d;      //1
        insertAtTail(head,tail,d);
        n--;
    }
    printLL(head);
    //isEmptyLL(head);
    //cout<<"length - "<<lenLL(head)<<endl;
    //destroyLL(head,tail);

    //Index starts from 0
    //insertAtSpecificLocation(head,tail,10,0);
    //insertAtSpecificLocation(head,tail,20,3);
    insertAtSpecificLocation(head,tail,30,5);

    // deleteAtSpecificLocation(head,tail,0);
    //deleteAtSpecificLocation(head,tail,4);
    printLL(head);
    return 0;
}