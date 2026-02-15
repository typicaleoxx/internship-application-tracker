/*
doublylinkedlist.h

this file defines a templated doubly linked list class. it can store any type of data (like Application objects) in nodes. 
each node has pointers to the next and previous nodes. 
the class provides functions to insert, remove, search, and display elements, while managing memory automatically. 
it handles the structure and traversal of the list, while the data itself is defined elsewhere.
*/

#include<iostream>
#include<cstdlib>

// node class represents a single node in the doubly linked list, storing data and pointers to previous and next nodes
// template typename T allows the node to store any data type
template <typename T>
class Node{
public:
    T data;  // stores the actual data
    Node <T>*next;  // pointer to the next node
    Node <T>*prev;  // pointer to the previous node

    // default constructor sets data to 0 and pointers to null
    Node(){
        this->data = 0;
        this->prev = nullptr;
        this->next = nullptr;
    }

    // parameterized constructor stores the provided value and initializes pointers to null
    Node (T& value){
        this->data = value;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

// doubly linked list class manages a collection of nodes, providing operations to insert, remove, and traverse data
// template typename T allows the list to store nodes with any data type
template <typename T>
class DoublyLinkedList
{
public:
    Node<T> *head;  // pointer to the first node in the list
    Node<T>*tail;  // pointer to the last node in the list

    // constructor initializes empty list with head and tail as null
    DoublyLinkedList(){
        this->head = nullptr;
        this->tail = nullptr;
    }

    // destructor deletes all nodes and frees memory when the list is destroyed
    ~DoublyLinkedList(){
        Node <T>*curr = head;
        // delete all nodes
        while(curr!= nullptr){
            Node <T>*next = curr->next;
            delete (curr);
            curr = next;
        }
    }
};
