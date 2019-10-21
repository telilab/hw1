#include "solution.h"
#include "iostream"
using namespace std;
//
//  TODO !!!
//

/*
 Put your actual implemetation in this file. See solution.h for details.
 */


unsigned int List::GetSize(){
    return size;
}
ArrayList::ArrayList(unsigned int capacity){
    array = new ListItem[capacity];
    _capacity = capacity;
}
bool ArrayList::AppendItem(ListItem item) {
    if (size >= _capacity){
        return false;
    }
    array[size] = item;
    size++;
    return true;
}
bool ArrayList::PrependItem(ListItem item) {
    
    if (size >= _capacity ){
        return false;
    }
    
    for ( int i = size; i > 0; i-- ){
        array[i] = array[i-1];
    }
    array[0]= item;
    size++;
    return true;
}
ListItem ArrayList::GetItemAt(unsigned int index){
    if (index >= size){
        return INVALID_LIST_ITEM;
    }
    else {
        return array[index];
    }
}
void ArrayList::DeleteItemAt(unsigned int index){
    for (int i = index; i < size; i++ ){
        array[i] = array[i+1];
    }
    size--;
}


void List::Print(){
    string comma = ", ";
    
    cout << "I'm a list. My size is\t[";
    for (  int i = 0; i < size; i ++ ){
        if(i < size-1){
            cout << GetItemAt(i) << comma;
        }
        else{
            cout << GetItemAt(i);
        }
    }
    cout << "]" << endl;
}
void List::ReversePrint(){
    string comma = ", ";
    cout << "I'm a list. My size is\t[";
    for ( int i = size -1; i > -1; i-- ){
        if(size > i-1) {
            cout << GetItemAt(i) << comma;
        }
        else{
            cout << GetItemAt(i);
        }
        
    }
    cout << "]" << endl;
}
