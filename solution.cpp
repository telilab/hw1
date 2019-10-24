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
void List::ReversePrint(){
    cout << "I'm a list. My size is " << size << "\n";
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
    cout << "I'm a list. My size is " << size << "\n";
}

void ArrayList::Print(){
    List::Print();
    string comma = ", ";
    cout << "[";
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

// fix this make the loop do the next part

void ArrayList::ReversePrint(){
    List::ReversePrint();
    string comma = ", ";
    cout << "[";
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

void DoublyLinkedList::Print(){
    List::Print();
    string comma = ", ";
    cout << "[";
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
void DoublyLinkedList::ReversePrint(){
    List::ReversePrint();
    string comma = ", ";
    cout << "[";
    for ( int i = size -1; i > -1; i-- ){
        if(size > i - 1) {
            cout << GetItemAt(i) << comma;
        }
        else{
            cout << GetItemAt(i);
        }
        
    }
    cout << "]" << endl;
}
ArrayList::~ArrayList(){
    delete[] array;
}

DoublyLinkedList::~DoublyLinkedList(){
    Node* temp;
    temp = head_;
    while (temp->next != nullptr ) {
        head_ = temp->next;
        temp->next = nullptr;
        head_->prev = nullptr;
        delete temp;
    }
    //delete temp;
    delete head_;
}
DoublyLinkedList::DoublyLinkedList(){
    head_ = nullptr;
    tail_ = nullptr;
    size = 0;
}
bool DoublyLinkedList::AppendItem(ListItem item) {
    Node* myNode = new Node;
    if (size == 0) {
        myNode->data = item;
        head_ = myNode;
        tail_ = myNode;
        myNode->next = nullptr;
        myNode->prev = nullptr;
        size++;
        return true;
    }
    else if (size >= 1 ){
        myNode->data = item;
        myNode->next = nullptr;
        tail_->next = myNode;
        myNode->prev = tail_;
        tail_ = myNode;
        size++;
        return true;
    }
    
    return false;
}
bool DoublyLinkedList::PrependItem(ListItem item) {
    Node* myNode = new Node;
    if ( size == 0 ) {
        myNode->data = item;
        head_ = myNode;
        tail_ = myNode;
        myNode->next = nullptr;
        myNode->prev = nullptr;
        size++;
        return true;
    }
    else if (size >= 1 ){
        head_->prev = myNode;
        myNode->next = head_;
        myNode->data = item;
        head_ = myNode;
        myNode->prev = nullptr;
        size++;
        return true;
    }
    
    return false;
}
ListItem DoublyLinkedList::GetItemAt(unsigned int item){
    if ( head_ == nullptr){
        return INVALID_LIST_ITEM;
    }
    
    else{
        Node* newNode = head_;
        for ( int i = 0; i < size; i++){
            if(item == i){
                return newNode->data;
            }
            newNode = newNode->next;
        }
    }
    
    return INVALID_LIST_ITEM;
}
void DoublyLinkedList::DeleteItemAt(unsigned int item){
    Node* temp;
    if (size >= 1){
        temp = head_;
        for ( int i = 0; i < size; i++){
            if(item == i){
                if ( temp->prev != nullptr){
                    temp->prev->next = temp->next;
                }
                else{
                    head_ = temp->next;
                }
                if ( temp->next != nullptr){
                    temp->next->prev = temp->prev;
                }
                else {
                    tail_ = temp->prev;
                }
                delete temp;
            }
            temp = temp->next;
        }
        
    }
    
}
