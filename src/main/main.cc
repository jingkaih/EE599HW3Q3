#include <iostream>
#include "src/lib/solution.h"

int main()
{
    //acyclic linked list
    std::vector<int> myvect = {1,3,5,7,9,11};
    SinglyLinkedList mylist(myvect,0);
    mylist.print();
    // mylist.push_back(100);
    // mylist.push_front(0);
    // mylist.insert_after(mylist.head_->next->next,2);
    // mylist.erase(mylist.head_->next);
    // mylist.pop_front();
    // mylist.pop_back();
    // ListNode *pt = mylist.GetBackPointer();
    // std::cout << pt->val <<std::endl;

    //cyclic linked list
    std::vector<int> myvect_1 = {1,3,5,7,9,11};
    SinglyLinkedList mylist_1(myvect_1,2);

    ListNode *p = mylist_1.head_;
    int i = 20;
    while (i != 0)
    {
        std::cout << p->val <<' ';
        p = p->next;
        i--;
    }
    

    return EXIT_SUCCESS;
}