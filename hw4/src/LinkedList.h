//
// Created by Timothy Goon, Patrick Houlihan on 2/15/2020.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Room.h"

typedef Room Payload;

class LinkedList {
private:
    // Doubly linked list node object.
    class Node{
    public:
        Node();
        ~Node();
        void setNext(Node* next);
        void setPrev(Node* prev);
        void setPayload(Payload* payload);
        Node* getNext();
        Node* getPrev();
        Payload* getPayload();

    private:
        Node* _prev = nullptr;
        Node* _next = nullptr;
        Payload* _payload = nullptr;
    };

public:
    LinkedList();
    ~LinkedList();
    Payload* getFirst();
    Payload* get(int index);
    bool removeFromList(Payload* payload);
    void savePayload(Payload* payload);
    bool isEmpty();
    void printHistory();
    void fPrintHistory();
    Payload* dequeueFIFO();
    int size();

private:
    Node* _head;
    int _size = 0;

};




#endif //LINKEDLIST_H
