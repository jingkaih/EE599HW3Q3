#ifndef TEMPLATE_SOLUTION_H
#define TEMPLATE_SOLUTION_H

#include <string>
#include <vector>
#include <set>

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}/*Here is a parameterized constructor*/
};

class SinglyLinkedList
{
  public:
    // default constructor
    // SinglyLinkedList();
    static ListNode *prev;// = nullptr;
    static ListNode *head_;// = nullptr;
    int lbi;
    int vec_len;
    // static std::set<ListNode *> str;// to store a set of pointers that point to every node, only used in counting the size of acyclic linked list.
    // Creates a linked list out of vector “inputs” and connects the last
    // item’s next to i(th) item in the list.
    // - If i is -1(I personally changed to 'less than or equals to 0'), the last item’s next is nullptr.
    // - If i is greater than input size, the last item’s next is nullptr.
    SinglyLinkedList(const std::vector<int> &inputs, int i)
    {
      prev = nullptr;
      head_ = nullptr;
      lbi = i;
      vec_len = inputs.size();

      for(auto x : inputs)
      create(x);

      if(i > 0 && i <= vec_len)
      link_back();
    }

    ~SinglyLinkedList() {} // destructor, cleans up
    void create(int i);// only thing it will do is create a new node
    void link_back();// link back to designated node, use together with function create()
    bool empty(); // checks if empty
    int size(); // returns size
    void push_back(int i); // inserts at the back
    void push_front(int i); // inserts at the front
    void insert_after(ListNode* p, int i); // inserts value i after p
    void erase(ListNode* p); // Erases node p
    void pop_front(); // removes the first item
    void pop_back(); // removes the last item
    int back(); // returns the value of last item
    int front(); // returns the value of first item
    ListNode *GetBackPointer(); // Returns pointer to last item
    ListNode *GetIthPointer(int i);// Returns pointer to i(th) element
    void print();// Prints the list: ex. Empty list: {}. List with items: {1, 2, 3}
    //ListNode *head__; // Pointer to the first element
};


#endif