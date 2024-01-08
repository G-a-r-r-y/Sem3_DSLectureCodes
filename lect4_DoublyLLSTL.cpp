#include<iostream>
#include<list>
using namespace std;


int main(){
    //Creates a list with elements - 1 2 3 
    list<int>l1{1,2,3};

    //Creates a list l2 of integer type and copies value of 1 into it
    //list<int>l2=1;

    // Functions used with Doubly Linked List using STL - 
    // 1. front()
    // 2. back()
    // 3. push_front(ele)
    // 4. push_back(ele)
    // 5. pop_front()
    // 6. pop_back()
    // 7. begin()
    // 8. end()
    // 9. empty()
    // 10. insert()
    // 11. erase()
    // 12. assign()
    // 13. remove()
    // 14. reverse()
    // 15. size()
    // 16. resize()
    // 17. sort()
    // 18. max_size()
    // 19. unique()
    // 20. merge()

    // Insert Function - 
    // 1. insert(iterator,element) -  inserts element in the list before the position pointed by the iterator
    // 2. insert(iterator, count, element) - inserts element in the list before the position pointed by 
    //                                         the iterator, count number of times.
    // 3. insert(iterator, start_iterator, end_iterator) - insert the element pointed by start_iterator to 
    //                                                     the element pointed by end_iterator before the position pointed by iterator

    // Splice Function - 
    // 1. splice(iterator, list_name) : Transfers complete list list_name at position pointed by 
    //                                  the iterator.
    // 2. splice(iterator, list_name, iterator_pos) : Transfer elements pointed 
    //                                                 by iterator_pos from list_name at position pointed by iterator.
    // 3. splice(iterator, list_name, itr_start, itr_end) : Transfer range specified 
    //                                                      by itr_start and itr_end from list_name at position pointed by iterator

    return 0;
}