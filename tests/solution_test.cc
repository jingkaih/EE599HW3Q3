#include "src/lib/solution.h"
#include "gtest/gtest.h"
#include <vector>
#include <string>
TEST(LinkedListShould, BeAcyclic) {
  std::vector<int> myvect = {1,3,5,9};
  SinglyLinkedList mylist(myvect,0);
  testing::internal::CaptureStdout();
  mylist.print();
  std::string actual = testing::internal::GetCapturedStdout();
  std::string expected = "{1,3,5,9}";
  EXPECT_EQ(actual, expected);
}

TEST(PushBackShould, AddANodeAtTheEnd) {
  std::vector<int> myvect = {1,3,5,9};
  SinglyLinkedList mylist(myvect,0);
  mylist.push_back(16);
  testing::internal::CaptureStdout();
  mylist.print();
  std::string actual = testing::internal::GetCapturedStdout();
  std::string expected = "{1,3,5,9,16}";
  EXPECT_EQ(actual, expected);
}

TEST(EmptyShould, ReturnFalse) {
  std::vector<int> myvect = {1,3,5,9};
  SinglyLinkedList mylist(myvect,0);
  bool actual = mylist.empty();
  bool expected = false;
  EXPECT_EQ(actual, expected);
}

TEST(EmptyShould, ReturnTrue) {
  std::vector<int> myvect = {};
  SinglyLinkedList mylist(myvect,0);
  bool actual = mylist.empty();
  bool expected = true;
  EXPECT_EQ(actual, expected);
}

TEST(SizeShould, ReturnSize) {
  std::vector<int> myvect = {1,4,11,5,3};
  SinglyLinkedList mylist(myvect,-1);
  int actual = mylist.size();
  int expected = 5;
  EXPECT_EQ(actual, expected);
}

TEST(PushFrontShould, AddANodeAtTheTop) {
  std::vector<int> myvect = {1,3,5,9};
  SinglyLinkedList mylist(myvect,0);
  mylist.push_front(16);
  testing::internal::CaptureStdout();
  mylist.print();
  std::string actual = testing::internal::GetCapturedStdout();
  std::string expected = "{16,1,3,5,9}";
  EXPECT_EQ(actual, expected);
}

TEST(InsertAfterShould, AddANodeAfterANode) {
  std::vector<int> myvect = {1,3,5,9};
  SinglyLinkedList mylist(myvect,0);
  mylist.insert_after(mylist.head_->next,16);
  testing::internal::CaptureStdout();
  mylist.print();
  std::string actual = testing::internal::GetCapturedStdout();
  std::string expected = "{1,3,16,5,9}";
  EXPECT_EQ(actual, expected);
}

TEST(InsertAfterShould, AddANodeAfterTheLastNode) {
  std::vector<int> myvect = {1,3,5,9};
  SinglyLinkedList mylist(myvect,0);
  mylist.insert_after(mylist.head_->next->next->next,16);
  testing::internal::CaptureStdout();
  mylist.print();
  std::string actual = testing::internal::GetCapturedStdout();
  std::string expected = "{1,3,5,9,16}";
  EXPECT_EQ(actual, expected);
}

TEST(EraseShould, DeleteTheFirstNode) {
  std::vector<int> myvect = {1,3,5,9};
  SinglyLinkedList mylist(myvect,0);
  mylist.erase(mylist.head_);
  testing::internal::CaptureStdout();
  mylist.print();
  std::string actual = testing::internal::GetCapturedStdout();
  std::string expected = "{3,5,9}";
  EXPECT_EQ(actual, expected);
}

TEST(EraseShould, DeleteANode) {
  std::vector<int> myvect = {1,3,5,9};
  SinglyLinkedList mylist(myvect,0);
  mylist.erase(mylist.head_->next->next);
  testing::internal::CaptureStdout();
  mylist.print();
  std::string actual = testing::internal::GetCapturedStdout();
  std::string expected = "{1,3,9}";
  EXPECT_EQ(actual, expected);
}

TEST(PopFrontShould, DeleteTheFirstNode) {
  std::vector<int> myvect = {1,3,5,9};
  SinglyLinkedList mylist(myvect,0);
  mylist.pop_front();
  testing::internal::CaptureStdout();
  mylist.print();
  std::string actual = testing::internal::GetCapturedStdout();
  std::string expected = "{3,5,9}";
  EXPECT_EQ(actual, expected);
}

TEST(PopBackShould, DeleteTheLastNode) {
  std::vector<int> myvect = {1,3,5,9};
  SinglyLinkedList mylist(myvect,0);
  mylist.pop_back();
  testing::internal::CaptureStdout();
  mylist.print();
  std::string actual = testing::internal::GetCapturedStdout();
  std::string expected = "{1,3,5}";
  EXPECT_EQ(actual, expected);
}

TEST(BackShould, ReturnTheLastOne) {
  std::vector<int> myvect = {1,4,11,5,3};
  SinglyLinkedList mylist(myvect,-1);
  int actual = mylist.back();
  int expected = 3;
  EXPECT_EQ(actual, expected);
}

TEST(FrontShould, ReturnTheFirstOne) {
  std::vector<int> myvect = {1,4,11,5,3};
  SinglyLinkedList mylist(myvect,-1);
  int actual = mylist.front();
  int expected = 1;
  EXPECT_EQ(actual, expected);
}

TEST(GetBackPointerShould, ReturnTheLastPointer) {
  std::vector<int> myvect = {1,4,11,5,3};
  SinglyLinkedList mylist(myvect,-1);
  ListNode *ptr_ = mylist.GetBackPointer();
  int actual = ptr_->val;
  int expected = 3;
  EXPECT_EQ(actual, expected);
}

TEST(GetIthPointerShould, ReturnAnyPointer) {
  std::vector<int> myvect = {1,4,11,5,3};
  SinglyLinkedList mylist(myvect,-1);
  ListNode *ptr_ = mylist.GetIthPointer(4);
  int actual = ptr_->val;
  int expected = 5;
  EXPECT_EQ(actual, expected);
}
