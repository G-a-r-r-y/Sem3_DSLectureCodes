
//Note - Yeh saare operations singly linked list(forward_list) ke liye discuss ho rahe hai!!!!!!!!

#include<bits/stdc++.h>
using namespace std;

int main(){
    //Declaration  - 
    // forward_list <dataType> listName={ele1,ele2...};

    forward_list <int>list1={1,2,3,4,5};

    //Operations - 
    //1. assign() - Used to assign new set of values to forward list - 
    
    forward_list<int>list2;
    //list2.assign({1,2,3});  //Note - Curly bracket ke ander elements likhne hai  
    
    forward_list<int>list3;
    //list3.assign(3,5); //Assign 3 elements of value 5

    //2. push_front() - 
    //list1.push_front(10);

    //3. pop_front() - 
    //list1.pop_front();

    //4. emplace_front() - 


    //5. insert_after(it, ele) - 
    // Used to insert the element ele after the iterator it.
    // Can also be used to insert multiple elements after the iterator it.
    // Returns the iterator of the last inserted element

    //list1.insert_after(list1.begin(),100);
    //list1.insert_after(list1.begin(),{200,300});  //Note - mulitple elements {} mei likhenge.

    //6. erase_after(it) -  
    // Used to delete the element after the iterator it.
    // Returns an iterator of the element next to the deleted element.
    // Note - erase_after(it1,it2) deletes every element between it1 and it2, including it1. 
    //list1.erase_after(list1.begin());

    //7. remove(ele) - 
    // Remove all occurences of ele from the list.
    //list1.remove(3);

    //8. clear() - clears entire list.

    //9. empty() - Returns true if list is empty else returns false

    //10. reverse() - reverses the linked list 

    //12. merger() - merges 2 sorted linked list int one

    //13. sort() - sorts the linked list

    //14. max_size() - Returns the max number of elements the can be held by the linked list.

    // Important!!!!!!!!
    // Printing a liked list formed via using STL - 
    forward_list<int>list4={1,2,3,4,5,6};
    for(auto x:list4){
        cout<<x<<" ";
    }
    return 0;
}