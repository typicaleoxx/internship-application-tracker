/*
doublylinkedlist.h

this file defines a templated doubly linked list class. it can store any type of data (like Application objects) in nodes. 
each node has pointers to the next and previous nodes. 
the class provides functions to insert, remove, search, and display elements, while managing memory automatically. 
it handles the structure and traversal of the list, while the data itself is defined elsewhere.
*/

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
#include <cstdlib>

// doubly linked list class manages a collection of nodes, providing operations to insert, remove, and traverse data
// template typename T allows the list to store nodes with any data type
template <typename T>
class DoublyLinkedList
{
private:
    // node class represents a single node in the doubly linked list, storing data and pointers to previous and next nodes
    class Node {
    public:
        T data;  // stores the actual data
        Node* next;  // pointer to the next node
        Node* prev;  // pointer to the previous node

        // default constructor sets data to 0 and pointers to null
        Node() {
            this->data = T();
            this->prev = nullptr;
            this->next = nullptr;
        }

        // parameterized constructor stores the provided value and initializes pointers to null
        Node(const T& value) {
            this->data = value;
            this->prev = nullptr;
            this->next = nullptr;
        }
    };

    Node* head;  // pointer to the first node in the list
    Node* tail;  // pointer to the last node in the list
    int count;  // tracks the number of nodes in the list

public:
    // constructor initializes empty list with head and tail as null and count as zero
    DoublyLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
        this->count = 0;
    }

    // destructor deletes all nodes and frees memory when the list is destroyed
    ~DoublyLinkedList() {
        Node* curr = head;
        // delete all nodes
        while (curr != nullptr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }

    // insert element at the beginning of the list
    void insertAtHead(const T& value) {
        // allocate dynamic memory on heap for the element
        Node* newNode = new Node(value);

        // if the list is empty, make it head and tail
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            count++;
            return;
        }

        // else add it to the head
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        count++;  // increment count after adding node
    }

    // insert value at tail
    void insertAtTail(const T& value) {
        // allocate dynamic memory on heap for new node
        Node* newNode = new Node(value);

        // check if the list is empty
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
            count++;
            return;
        }

        // make our new node as the tail
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        count++;  // increment count after adding node
    }

    // insert at given position
    void insertAtPos(const T& value, int pos) {
        // if position is 1, insert at head
        if (pos == 1) {
            insertAtHead(value);
            return;
        }

        // curr point at head to traverse for position
        Node* curr = head;

        // dynamic memory allocation in heap for new element
        Node* newNode = new Node(value);

        // if list is empty
        if (head == nullptr) {
            delete newNode;
            return;
        }

        // traverse the list to get to given position
        for (int i = 1; i < pos - 1 && curr != nullptr; i++) {
            curr = curr->next;
        }

        // if invalid position
        if (curr == nullptr) {
            delete newNode;
            return;
        }

        newNode->next = curr->next;
        newNode->prev = curr;
        if (curr->next != nullptr) {
            curr->next->prev = newNode;
        } else {
            tail = newNode;
        }
        curr->next = newNode;
        count++;  // increment count after adding node
    }

    // delete element at the head
    void deleteAtHead() {
        // check if list is empty
        if (head == nullptr) {
            return;
        }

        // new curr pointer pointing at head
        Node* curr = head;

        // move head to the next node
        head = head->next;

        // check if list became empty after deletion
        if (head == nullptr) {
            tail = nullptr;
        } else {
            head->prev = nullptr;
        }

        // delete the old head node
        delete curr;
        count--;  // decrement count after removing node
    }

    // delete value at the end
    void deleteAtEnd() {
        // if the list is empty
        if (tail == nullptr) {
            return;
        }

        Node* curr = tail;

        // check if there's only one element in the list
        if (tail->prev == nullptr) {
            head = nullptr;
            tail = nullptr;
            delete curr;
            count--;  // decrement count after removing node
            return;
        }

        // move tail to the previous node
        tail = tail->prev;
        // set new tail's next to null
        tail->next = nullptr;
        // delete the old tail node
        delete curr;
        count--;  // decrement count after removing node
    }

    // delete at position
    void deleteAtPos(int pos) {
        // if position is 1, delete head
        if (pos == 1) {
            deleteAtHead();
            return;
        }

        // check if list is empty
        if (head == nullptr) {
            return;
        }

        // node pointer current to traverse
        Node* curr = head;

        // traverse until the given position
        for (int i = 1; i < pos - 1 && curr != nullptr; i++) {
            curr = curr->next;
        }

        // invalid position
        if (curr == nullptr || curr->next == nullptr) {
            return;
        }

        // point toDelete to the node we want to delete
        Node* toDelete = curr->next;

        // check if we're deleting the last element (tail)
        if (toDelete->next == nullptr) {
            tail = curr;
            tail->next = nullptr;
            delete toDelete;
            count--;  // decrement count after removing node
            return;
        }

        // deleting a node in the middle of the list
        curr->next = toDelete->next;
        toDelete->next->prev = curr;
        delete toDelete;
        count--;  // decrement count after removing node
    }

    // delete first occurrence of a specific value from the list
    bool deleteByValue(const T& value) {
        // check if list is empty
        if (head == nullptr) {
            return false;
        }

        // traverse to find the node with the value
        Node* curr = head;
        while (curr != nullptr && curr->data != value) {
            curr = curr->next;
        }

        // if value not found
        if (curr == nullptr) {
            return false;
        }

        // if node to delete is the head
        if (curr == head) {
            head = head->next;
            if (head == nullptr) {
                tail = nullptr;  // list becomes empty
            } else {
                head->prev = nullptr;
            }
            delete curr;
            count--;  // decrement count after removing node
            return true;
        }

        // if node to delete is the tail
        if (curr == tail) {
            tail = tail->prev;
            tail->next = nullptr;
            delete curr;
            count--;  // decrement count after removing node
            return true;
        }

        // node is in the middle
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;
        count--;  // decrement count after removing node
        return true;
    }

    // traverse and print the whole linked list in order
    void printList() const {
        // curr points to head and helps traverse the list for printing
        Node* curr = head;

        // check if our list is empty
        if (curr == nullptr) {
            std::cout << "List is empty" << std::endl;
            return;
        }

        // traverse and print each node until the end of the list
        while (curr != nullptr) {
            std::cout << curr->data << " <-> ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }

    // print the list in reverse order (from tail to head)
    void printReverse() const {
        // start from tail
        Node* curr = tail;

        // check if list is empty
        if (tail == nullptr) {
            std::cout << "List is empty" << std::endl;
            return;
        }

        // traverse backwards using prev pointers until reaching head
        while (curr != nullptr) {
            std::cout << curr->data << " <- ";
            curr = curr->prev;
        }
        std::cout << std::endl;
    }

    // search element in the list and return pointer to the node
    Node* search(const T& value) const {
        Node* curr = head;

        // traverse until the end of the list to find the value
        while (curr != nullptr) {
            if (curr->data == value) {
                return curr;  // return pointer to node if found
            }
            curr = curr->next;
        }

        // value was not found, return null
        return nullptr;
    }

    // check if list is empty by comparing head to null
    bool isEmpty() const {
        return head == nullptr;
    }

    // get the size of the list in constant time using count variable
    int size() const {
        return count;
    }

    // get reference to head data (for iteration in main)
    T* getHead() const {
        if (head == nullptr) {
            return nullptr;
        }
        return &(head->data);
    }

    // helper method to get node by index (for iteration)
    T* getAt(int index) const {
        if (index < 0 || index >= count) {
            return nullptr;
        }
        Node* curr = head;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        return &(curr->data);
    }
};

#endif
