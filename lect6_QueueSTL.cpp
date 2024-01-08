#include<iostream>
#include<queue>
using namespace std;

//Simple Queue - 
// int main(){
//     // Operations - 
//     // 1.empty()
//     // 2.push(element)
//     // 3.pop()
//     // 4.front() - returns front element
//     // 5.back() - returns last element
    
//     //Syntax - 
//     queue<int>queue1;
//     cout<<queue1.empty()<<endl;
//     queue1.push(2);
//     queue1.push(3);
//     queue1.push(4);
//     queue1.push(5);
//     cout<<queue1.empty()<<endl;
//     cout<<"Front - "<<queue1.front()<<endl;
//     cout<<"Back - "<<queue1.back()<<endl;
//     queue1.pop();
//     cout<<"After POP - "<<endl;
//     cout<<"Front - "<<queue1.front()<<endl;
//     cout<<"Back - "<<queue1.back()<<endl;
//     return 0;
// }

// ----------------------------------------------------------------------------------------------

//Priority Queue - 
int main(){ 
    // Operations - 
    // 1.empty()
    // 2.push(element)
    // 3.pop()
    // 4.top()
    // 5.swap()  - Yeh samjh nhi aaya
    // 6.size()
    
    //Syntax - 
    // In priority queue, the elements are placed in decreasing order of their values and the first 
    // element represents the largest of all the inserted elements.

    priority_queue<int>priorityQueue1;
    cout<<priorityQueue1.empty()<<endl;
    priorityQueue1.push(10);
    priorityQueue1.push(9);
    priorityQueue1.push(8);
    priorityQueue1.push(7);
    priorityQueue1.push(11);
    cout<<priorityQueue1.empty()<<endl;
    cout<<"Top - "<<priorityQueue1.top()<<endl;
    cout<<"Size - "<<priorityQueue1.size()<<endl;
    priorityQueue1.pop();
    cout<<"After POP - "<<endl;
    cout<<"Top - "<<priorityQueue1.top()<<endl;
    cout<<"Size - "<<priorityQueue1.size()<<endl;
    return 0;
}