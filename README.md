# EE599HW3Q3
In order to get the size of cyclic linked list, I declared a set called str, and it contains a bunch of pointers

Using this set, I can know how many pointers were defined when the linked list was formed.

But this method has a disadvantage that is the size won't be changed when I call functions such as pop_back, erase, and so on.

It was quite difficult for me to remove a element from a set of pointers.

However, I got a common way to get the size of a linked list.

That is using p=p->next

But this way may not be able to handle an cyclic linked list.

>>NOTATIONS

1. for int i in the constructor, I simply assumed i(th) would begin from 1th and end at vector.size(), which I didn't refer to the maximum index of vector.

So, when i equals to -1 or 0 or any number greater than size of vector, we will get an acyclic linked list.

Otherwise, we will get a cyclic one.

2. The erase() method cannot delete the last node. Instead using pop_back() if you want to do so.

3. GetIthPointer must get an i larger than 0.

4. The create() function will only be called when the constructor is called. It doesn't handle the cyclic linked list.

When a cyclic linked list is required, a function named link_back() will be called. It will link the last node backward to somewhere.

>>Time Complexity

Time complexities for each member function were put at comments in solution.cc

Time complexity for constructor is O(n).