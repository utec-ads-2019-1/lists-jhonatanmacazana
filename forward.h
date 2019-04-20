#ifndef FORWARD_H
#define FORWARD_H

#include "list.h"
#include <algorithm>
#include "iterators/forward_iterator.h"

template <typename T>
class ForwardList : public List<T> {
public:
    ForwardList() : List<T>() {}

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
            this->tail = tempNode;
            tempNode->next = NULL;
            this->head = tempNode;
        }
        else
        {
            tempNode->next = this->head;
            this->head = tempNode;
        }
        tempNode->data = value;
        ++this->nodes;
    }

    void push_back(T value) {
        Node<T> *tempNode = new Node<T>();
        if (empty())
            this->head = tempNode;
        else
            this->tail->next = tempNode;
        this->tail = tempNode;
        tempNode->data = value;
        tempNode->next = NULL;
        ++this->nodes;
    }

    void pop_front() {
        if (!empty())
        {
            Node<T> *temp = this->head->next;
            delete this->head;
            this->head = temp;
            --this->nodes;
        }
    }

    void pop_back() {
        if (!empty())
        {
            Node<T> *tempNode = this->head;
            while (tempNode->next != this->tail)
                tempNode = tempNode->next;
            delete this->tail;
            this->tail = tempNode;
            this->tail->next = NULL;
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
        this->head->killSelf();
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
        Node<T> *prevNode = NULL;
        Node<T> *currNode = this->head;
        Node<T> *tempNode = new Node<T>();
        for (int i = 0; i < size(); i++)
        {
            tempNode = currNode -> next;
            currNode -> next = prevNode;
            prevNode = currNode;
            currNode = tempNode;
        }
        std::swap(this->head, this->tail);

    }

    std::string name() {
        return "Forward List";
    }

    ForwardIterator<T> begin() {
        return ForwardIterator<T> (this->head);
    }

    ForwardIterator<T> end() {
        return ForwardIterator<T> (NULL);
    }

    void merge(ForwardList<T> &list) {
        if (list.empty()) return;
        if (size() == 0)
            this->head = list.head;
        else
            this->tail->next = list.head;
        this->tail = list.tail;
        this->nodes += list.nodes;
    }
};

#endif
