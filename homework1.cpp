// homework1.cpp : Defines the entry point for the console application.
//

#include "solution.h"

//
//  TODO !!!
//

/*
This is a VERY simple test. Feel free to add more tests if you like but it's not a required part of the assignment.
I only care about Solution.h and Solution.cpp.
*/


int main()
{
    ArrayList a1 = ArrayList(10);
    ArrayList a2 = ArrayList(5);
    DoublyLinkedList l1 = DoublyLinkedList();

    List *lists[] = { 
        &a1, 
        &a2, 
        &l1, 
        nullptr
    };
    int index = 0;
    List *list = lists[0];
    while(list != nullptr)
    {
        printf("GetSize: %d\r\n", list->GetSize());

        printf("AppendItem %s\r\n", list->AppendItem(5) ? "succeeded" : "failed");
        printf("AppendItem %s\r\n", list->AppendItem(3) ? "succeeded" : "failed");
        printf("AppendItem %s\r\n", list->PrependItem(7) ? "succeeded" : "failed");
        printf("GetSize: %d\r\n", list->GetSize());
        printf("AppendItem %s\r\n", list->AppendItem(0) ? "succeeded" : "failed");
        printf("AppendItem %s\r\n", list->PrependItem(6) ? "succeeded" : "failed");
        printf("AppendItem %s\r\n", list->AppendItem(9) ? "succeeded" : "failed");
        printf("AppendItem %s\r\n", list->PrependItem(8) ? "succeeded" : "failed");
        printf("GetSize: %d\r\n", list->GetSize());
        printf("GetItemAt: %d\r\n", list->GetItemAt(4));
        printf("GetItemAt: %d\r\n", list->GetItemAt(8));
        
        list->Print();
        list->ReversePrint();

        list = lists[++index];
    }

    return 0;
}

