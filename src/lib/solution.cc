#include "solution.h"
#include <iostream>

ListNode *SinglyLinkedList::head_ = nullptr;
ListNode *SinglyLinkedList::prev = nullptr;
std::set<ListNode *> SinglyLinkedList::str = {};


void SinglyLinkedList::create(int i)
{
    
    ListNode *thisone = new ListNode(i);

    if(prev == nullptr)
    {
        head_ = thisone;
        prev = thisone;
    }
    else
    {
        prev->next = thisone;
        prev = thisone;
    }

    str.insert(thisone);
}

void SinglyLinkedList::link_back()
{
  ListNode *p = head_;
  int i = lbi;
  while(i != 1)
  {
    p = p->next;
    i--;
  }
  prev->next = p;
}

void SinglyLinkedList::push_back(int i)
{
  create(i);
  if(lbi > 0 && lbi <= vec_len)
  link_back();
}

bool SinglyLinkedList::empty()
{
  if(head_ == NULL)
  return true;
  else
  return false;
}

int SinglyLinkedList::size()
{
  int s = 1;
  ListNode *temp = head_;
  while(temp->next != nullptr)
  {
    temp = temp->next;
    s++;
  }
  return s;
  //return str.size();   ---this line of code is all what we need when the list is an acyclic linked list since it uses a set to root out any duplicate pointer.
}

void SinglyLinkedList::push_front(int i)
{
  ListNode *temp = head_;
  head_ = new ListNode(i);
  head_->next = temp;
  str.insert(head_);
}

void SinglyLinkedList::insert_after(ListNode* p, int i)
{
  ListNode *ins = new ListNode(i);
  ListNode *temp = p->next;
  p->next = ins;
  ins->next = temp;
  str.insert(ins);
}

void SinglyLinkedList::erase(ListNode* p)//Cannot erase the last node!!!
{
  ListNode *temp = p->next;
  p->val = temp->val;
  p->next = temp->next;
//   std::set<ListNode *>::iterator it = str.find(p);
//   it--;
//   (*it)->next = p->next;
}

void SinglyLinkedList::pop_front()
{
  head_ = head_->next;
}

void SinglyLinkedList::pop_back()
{
  ListNode *temp = head_;
  if(temp->next == nullptr)
  head_ = nullptr;

  while(temp->next->next != nullptr)
  {
    temp = temp->next;
  }
  temp->next = nullptr;
}

int SinglyLinkedList::back()
{
  ListNode *temp = head_;

  while(temp->next != nullptr)
  {
    temp = temp->next;
  }
  return temp->val;
}

int SinglyLinkedList::front()
{
  return head_->val;
}

ListNode *SinglyLinkedList::GetBackPointer()
{
  ListNode *temp = head_;

  while(temp->next != nullptr)
  {
    temp = temp->next;
  }
  return temp;
}

ListNode *SinglyLinkedList::GetIthPointer(int i)//i > 0
{
  ListNode *temp = head_;

  while(i != 1)
  {
    temp = temp->next;
    i--;
  }
  return temp;
}

void SinglyLinkedList::print()
{
  ListNode *temp = head_;
  std::cout <<'{';
  while(temp->next != nullptr)
  {
    std::cout << temp->val << ',';
    temp = temp->next;
  }
  std::cout << temp->val<<'}';
}