//Implementation of Queue via arrays - 

#include<iostream>
using namespace std;
// Queue Operations - 
    // 1.Enqueue - Adds an element to the back of the queue if the queue is not full otherwise it will print “OverFlow”.
    // 2.Dequeue - Removes the element from the front of the queue if the queue is not empty otherwise it will print “UnderFlow”
    // 3.Front - Returns front element
    // 4.Size
    // 5.IsEmpty

//Important!!!!
int rear=-1;
int front=-1;

void Enqueue(int queue[],int ele,int maxSize){
    if(rear==maxSize){
        cout<<"Queue OverFlow"<<endl;
    }else{
        // Doubt - Yaha par for index -1 element insert kyu ho raha hai?
        // cout<<rear<< " - " <<ele<<endl;
        queue[rear]=ele;
        ++rear;
    }
}

//Note - Yahapar front se remove karna hai(FIFO)
void Dequeue(int queue[]){
    if(front==rear){  //Remember this condition for queue underflow!!!!!
        cout<<"Queue UnderFlow"<<endl;
    }else{
        queue[front]=0;
        front++;
    }
}

int Front(int queue[]){
    if(front==rear){
        cout<<"Queue UnderFlow"<<endl;
        return -1;
    }else{
        return queue[front];
    }
}

int size(){
    return rear-front;
}

bool isEmpty(){
    if(front==rear){
        return true;
    }else{
        return false;
    }
}


int main(){
    int queue[10];   
    cout<<"Is Empty - "<<isEmpty()<<endl; 
    Enqueue(queue,5,10);
    Enqueue(queue,6,10);    
    Enqueue(queue,7,10);
    Enqueue(queue,8,10);
    Enqueue(queue,9,10);
    cout<<"Is Empty - "<<isEmpty()<<endl;
    cout<<"Size - "<<size()<<endl;
    cout<<"Front -"<<Front(queue)<<endl;
    Dequeue(queue);
    cout<<"Size (After Dequeue)- "<<size()<<endl;
    cout<<"Front (After Dequeue)- "<<Front(queue)<<endl;
    return 0;
}