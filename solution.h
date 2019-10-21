#pragma once

typedef int ListItem;
#define INVALID_LIST_ITEM (-1)
#include "solution.h"
#include "iostream"
using namespace std;

//
//  TODO !!!
//

/*
Use this header to declare your classes. Do the actual function implementation in Solution.cpp.
It's not really necessary but it's a good habit for larger projects.
Ideally we'd put each class in its own header and source but these should be pretty simple and short.

NOTES: Do not use any STL collections! Write your own list implementations from scratch.

Your function signatures might require certain other keywords such as const, virtual (hint, hint), etc.
In all classes, make things public, protected, or private as appropriate.
Feel free to create helper functions or whatever class members you might need.
*/

class List
{
    //
    //  TODO !!!
    //

    /*
    This is the abstract class from which our list implementations will derive.
    1) add a destructor
    2) the following functions should be pure virtual:
        bool AppendItem(ListItem) - adds the passed-in item to the end of the list. Returns true if the append succeeded, false otherwise.
        bool PrependItem(ListItem) - adds the passed-in item to the beginning of the list. Returns true if the append succeeded, false otherwise.
        ListItem GetItemAt(unsigned int) - returns the list item at the passed-in index or INVALID_LIST_ITEM for an invalid index
        void DeleteItemAt(unsigned int) - deletes the list item at the passed-in index
    3) the following functions are actually implemented in the List class:
        unsigned int GetSize() - this function returns the size of the list and is actually implemented here in List.
        void Print() - prints out each item in the list from first to last.
                     - this function has the partial implementation described below, although being an abstract class, has no actual list to print.
                     - It should print out "I'm a list. My size is #", where '#' is the size of the list, followed by a newline.
        void ReversePrint() - prints out each item in the list from last to first.
                     - this function has the partial implementation described below, although being an abstract class, has no actual list to print.
                     - It should print out "I'm a list. My size is #", where '#' is the size of the list, followed by a newline.
    */
public:
   // ~List();
    virtual bool AppendItem(ListItem) = 0;
    virtual bool PrependItem(ListItem) = 0;
    virtual ListItem GetItemAt(unsigned int) = 0;
    virtual void DeleteItemAt(unsigned int) = 0;
    unsigned int GetSize();
    void Print();
    void ReversePrint();
protected:
    unsigned int size = 0;
    
};

class ArrayList : public List
{
    //
    //  TODO !!!
    //

    /*
    ArrayList derives from List and implements it using a static array.
    The constructor should take an unsigned int specifying the capacity of the array.
    AppendItem and PrependItem should fail (i.e. return false) if the array is full.
    Print (cout) should first call the List class Print function and then print the contents of the list in the format "\t[0, 1, 2, 3]"
        ('\t' is the tab character in case there's some other crazy, C++ way to do that and you're not familiar with my terminology).
        Even though ListItem is typedef'd to be easy to change, you can assume for the print function that it's going to stay int.
    ReversePrint should call the List class ReversePrint function and then print the contents of the list in the format "\t[3, 2, 1, 0]"
    */
public:
    ArrayList(unsigned int capacity);
     bool AppendItem(ListItem) override;
     bool PrependItem(ListItem) override;
    virtual ListItem GetItemAt(unsigned int)override;
    virtual void DeleteItemAt(unsigned int) override;
    ListItem *array;
private:
    unsigned int _capacity;
    
};


class DoublyLinkedList
{
    //
    //  TODO !!!
    //

    /*
    DoublyLinkedList derives from List and implements it using a doubly linked list.
    The constructor takes no arguments.
    AppendItem and PrependItem really shouldn't fail unless you run out of memory or an asteroid destroys the earth.
    Print should first call the List class Print function and then print the contents of the list in the format "\t[0, 1, 2, 3]"
        ('\t' is the tab character in case there's some other crazy, C++ way to do that and you're not familiar with my terminology).
        Even though ListItem is typedef'd to be easy to change, you can assume for the print function that it's going to stay int.
    ReversePrint should call the List class ReversePrint function and then print the contents of the list in the format "\t[3, 2, 1, 0]"
    */
public:
    ~DoublyLinkedList();
    bool AppendItem(ListItem) ;
    bool PrependItem(ListItem) ;
};
