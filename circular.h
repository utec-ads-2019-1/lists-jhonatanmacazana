#ifndef CIRCULAR_H
#define CIRCULAR_H

#include "list.h"

template <typename T>
class CircularLinkedList : public List<T> {
public:
    CircularLinkedList() : List<T>() {}

    T front() {
        return (empty() ? false : this->head->data);
    }

    T back() {
        return (empty() ? false : this->tail->data);
    }

    void push_front(T value) {
        Node<T> *tempNode = new Node<T>();
        if (empty())
        {
            tempNode->next = tempNode;
            tempNode->prev = tempNode;
            this->head = tempNode;
            this->tail = this->head;
        }
        else
        {
            tempNode->next = this->head;
            this->head->prev = tempNode;
            this->head = tempNode;
            this->head->prev = this->tail;
            this->tail->next = this->head;
        }
        tempNode->data = value;
        ++this->nodes;
    }

    void push_back(T value) {
        Node<T> *tempNode = new Node<T>();
        if (empty())
        {
            tempNode->next = tempNode;
            tempNode->prev = tempNode;
            this->tail = tempNode;
            this->head = this->tail;
        }
        else
        {
            tempNode->prev = this->tail;
            this->tail->next = tempNode;
            this->tail = tempNode;
            this->head->prev = this->tail;
            this->tail->next = this->head;
        }
        tempNode->data = value;
        ++this->nodes;
    }

    void pop_front() {
        if (!empty())
        {
            Node<T> *tempNode = this->head->next;
            delete this->head;
            this->head = tempNode;
            this->head->prev = this->tail;
            this->tail->next = this->head;
            --this->nodes;
        }
    }

    void pop_back() {
        if (!empty())
        {
            Node<T> *tempNode = this->tail->prev;
            delete this->tail;
            this->tail = tempNode;
            this->head->prev = this->tail;
            this->tail->next = this->head;
            --this->nodes;
        }
    }

    T operator[](int index) {
        if (index >= size())
            throw;
        Node<T> *tempNode = this->head;
        for (int i = 0; i < index; i++)
            tempNode = tempNode->next ;
        return tempNode->data ;
    }

    bool empty() {
        return (this->head == NULL ? true : false);
    }

    int size() {
        return this->nodes;
    }

    void clear() {
        this->head->killSelf(this->nodes);
        this->head = NULL;
        this->tail = NULL;
        this->nodes = 0;
    }

    void sort() {
        Node<T> *tempNode = this->head;
        T* array = new T[size()];
        for (int i = 0; i < size(); i++)
        {
            array[i] = tempNode -> data;
            tempNode = tempNode -> next;
        }
        std::sort(array, array + size());

        tempNode = this -> head;
        for (int i = 0; i < size(); i++)
        {
            tempNode -> data = array[i];
            tempNode = tempNode -> next;
        }
        delete[] array;
    }

    void reverse() {
        if (size() <= 1) return;
        Node<T> *prevNode = this->head->prev;
        Node<T> *currNode = this->head;
        Node<T> *tempNode = new Node<T>();
        for (int i = 0; i < size(); i++)
        {
            tempNode = currNode -> next;
            currNode -> next = prevNode;
            currNode -> prev = tempNode;
            prevNode = currNode;
            currNode = tempNode;
        }
        std::swap(this->head, this->tail);
    }

    string name() {
        return "Circular Linked List";
    }

    BidirectionalIterator<T> begin() {
        return BidirectionalIterator<T> (this->head);
    }

    BidirectionalIterator<T> end() {
        return BidirectionalIterator<T> (this->head);
    }

    void merge(CircularLinkedList<T> &list) {
        if (list.empty()) return;
        if (size() == 0)
            this->head = list.head;
        else
        {
            this->tail -> next = list.head;
            list.head -> prev = this->tail;
            this->tail = list.tail;
            this->tail->prev = this->tail;
            this->tail->next = this->head;
        }
        this->tail = list.tail;
        this->nodes += list.nodes;
    }
};

#endif
