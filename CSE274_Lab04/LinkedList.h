//DO NOT CHANGE THIS FILE
//Author: Bo Brinkman
//Date: 2013/07/11
#include "List.h"

template <class T>
class LinkedList : public List <T>
{
    
 private:
    
    // A doubly-linked list (has next and previous addresses)
    struct Node
    {
        T data;
        Node* next;
        Node* prev;
    };

 public:
    //See List.h for documentation of these methods
    //Return the number of items currently in the List
    virtual unsigned long size();

    //Get the value at index i, and return it.
    // If list does not contain at least i+1 items, throw a string exception
    virtual T get(unsigned long i);

    //Set the value at index i to x
    // If list does not contain at least i+1 items, throw a string exception
    virtual void set(unsigned long i, T x);

    //Add a new item, x, at position i. All items that were originally
    // at position i or higher get moved forward 1 to make room.
    // If list does not contain at least i items, throw a string exception
    virtual void add(unsigned long i, T x);

    //Remove the item at position i. All items that were originally
    // at position i+1 or higher get moved backwards 1 to fill the gap.
    // If list does not contain at least i+1 items, throw a string exception
    virtual void remove(unsigned long i);

    //Optional, but may be useful in the Shuffle project
    //Remove all items from src, and add them to the end of the current list, in the
    // same order that they started. So if the current list is {4, 1, 2} and src
    // is {3, 5}, the result should be that the current list is {4, 1, 2, 3, 5} and src is
    // empty
    //Note: This should be O(1) time. Use pointer manipulations to graft the lists together.
//virtual void takeAll(LinkedList<T>& src);

    //Initialize all private member variables.
    // Be sure to create the dummy node using "new"
    LinkedList();
    //Delete any dynamically allocated memory. You will need to loop
    // through all your nodes, deleting them one at a time
    virtual ~LinkedList();

 private:
    //Pointer to the dummy node.
    Node* dummyNode;

    //Return a pointer to item i.
    //Special cases: If i == numItems, return a pointer to the dummyNode
    //If i is an invalid number, throw a string exception
    Node* find(unsigned long i);
  
    //Number of items in the list
    unsigned long numItems;
};

// You will need this so you can make a string to throw in
// remove
#include <string>

//Syntax note: C++ is not very good at figuring out which methods belong
// to which classes. That is why we have to use the scope operator to
// tell the compiler that this LinkedList() method belongs to the
// LinkedList<T> class.
template <class T>
LinkedList<T>::LinkedList()
{
    dummyNode = new Node();
    
    // Because the dummyNode variable holds the address of dummyNode...
    // (These next two statements are exactly the same)
    dummyNode->next = dummyNode;
    (*dummyNode).prev = dummyNode;
    
    numItems = 0;
}

template <class T>
LinkedList<T>::~LinkedList() {
    // Get rid of all the normal nodes.
    while (numItems > 0)
    {
        remove(0);
    }
    
    // Get rid of the dummy node.
    delete dummyNode;
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::find(unsigned long i)
{
    if (i == numItems)
        return dummyNode;
    else if (i > numItems)
        throw std::string("Index is larger than number of items in find()");
    else
    {
        Node* ret = dummyNode->next;
        
        while (i > 0)
        {
            ret = ret->next
            i--;
        }
        
        return ret;
    }
}

template <class T>
void LinkedList<T>::set(unsigned long i, T x)
{
    //TODO
}

template <class T>
void LinkedList<T>::add(unsigned long i, T x)
{
    //TODO
}

template <class T>
void LinkedList<T>::remove(unsigned long i)
{
    // TODO - Remove the node at address i, and shift everything down so there are no "empty spaces."
}

template <class T>
T LinkedList<T>::get(unsigned long i)
{
    Node* myNode = find(i);
    if (myNode == dummyNode) // These are comparable because they are both pointers.
        throw std::string("Index was too large in get()");
    else
        return myNode->data;
}

template <class T>
unsigned long LinkedList<T>::size()
{
    //TODO
    return 0;
}
