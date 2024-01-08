#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next=NULL;
    node(int d){
        data=d;
        next=NULL;
    }
};

//Making a circular Linked list - 
void insertAtTail(node* &head,node* &tail,int d){
    node* n=new node(d);
    if(head==NULL and tail==NULL){
        head=n;
        tail=n;
    }else{
        tail->next=n;
        tail=n;
        tail->next=head;
    }
}

void printLL(node* head){
    int i=0;
    while(i<12){
        cout<<head->data<<" ";
        head=head->next;
        i++;
    }
}

void insertAnEle(node* &head,node* &tail,int index,int d){
    //Case 1 -
    node* n=new node(d); 
    if(index==0){
        n->next=head;
        head=n;
        tail->next=n;
        return;
    }


    //Case 2 (in between) -
    int count=1;
    node* tempHead=head->next;
    node* prev=head;
    while(tempHead!=head){
        if(count==index){
            prev->next=n;
            n->next=tempHead;
            return;
        }
        tempHead=tempHead->next;
        prev=prev->next;
        count++;
    }

    //Case 3 (tail) - 
    tail->next=n;
    tail=n;
    tail->next=head;
    return;
}

void deleteAnEle(node* &head,node* &tail,int index){
    //Case 1 -
    if(index==0){
        node* temp=head;
        head=head->next;
        tail->next=head;
        delete temp;
        return;
    }


    //Case 2 (in between) -
    int count=1;
    node* tempHead=head->next;
    node* prev=head;
    while(tempHead!=head){
        if(count==index){
            prev->next=tempHead->next;
            delete tempHead;
            return;
        }
        tempHead=tempHead->next;
        prev=prev->next;
        count++;
    }

    //Case 3 (tail) - 
    node* tempNode=tail;
    node* prevTail=head;
    while(prevTail->next!=tail){
        prevTail=prevTail->next;
    }
    prevTail->next=head;
    delete tempNode;
    tail=prevTail;
    return;
}

int main(){
    node* head=NULL;
    node* tail=NULL;
    insertAtTail(head,tail,1);
    insertAtTail(head,tail,2);
    insertAtTail(head,tail,3);
    insertAtTail(head,tail,4);
    insertAtTail(head,tail,5);
    insertAtTail(head,tail,6);
    printLL(head);
    cout<<endl;
    
    //Insert at any index
    //insertAnEle(head,tail,0,100);
    //insertAnEle(head,tail,3,300);
    //insertAnEle(head,tail,6,600);

    //Delete at any index
    //deleteAnEle(head,tail,0);
    //deleteAnEle(head,tail,3);
    deleteAnEle(head,tail,8);
    printLL(head);
    return 0;
}