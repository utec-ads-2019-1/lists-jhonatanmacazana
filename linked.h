#ifndef LINKED_H
#define LINKED_H

#include "list.h"
#include "iterators/bidirectional_iterator.h"

template <typename T>
class LinkedList : public List<T> {
public:
    LinkedList() : List<T>() {}

    /*
    * Aquí no deberías retornar false, sino botar una excepción
    */
    T front() {
        return (empty() ? false : this->head->data);
    }

    /*
    * Aquí no deberías retornar false, sino botar una excepción
    */
    T back() {
        return (empty() ? false : this->tail->data);
    }

    void push_front(T value) {
        Node<T> *tempNode = new Node<T>();
        if (empty())
        {
            this->head = tempNode;
            this->tail = tempNode;
        }
        else
        {
            tempNode->next = this->head;
            this->head->prev = tempNode;
            this->head = tempNode;
        }
        tempNode->data = value;
        ++this->nodes;
    }

    void push_back(T value) {
        Node<T> *tempNode = new Node<T>();
        if (empty())
        {
            this->head = tempNode;
            this->tail = tempNode;
        }
        else
        {
            this->tail->next = tempNode;
            tempNode->prev = this->tail;
            this->tail = tempNode;
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
            this->head->prev = NULL;
            --this->nodes;
        }
    }

    void pop_back() {
        if (!empty())
        {
            Node<T> *tempNode = this->tail->prev;
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
        Node<T> *prevNode = NULL;
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
        return "Linked List";
    }

    BidirectionalIterator<T> begin() {
        return BidirectionalIterator<T> (this->head);
    }

    BidirectionalIterator<T> end() {
        return BidirectionalIterator<T> (NULL);
    }

     /*
    * Está bien, perdo deberías agregar los elementos para no tener los elementos originales de la segunda lista
    * */
    void merge(LinkedList<T> &list) {
        if (list.empty()) return;
        if (size() == 0)
            this->head = list.head;
        else
        {
            this->tail->next = list.head;
            list.head->prev = this->tail;
        }
        this->tail = list.tail;
        this->nodes += list.nodes;
    }
};

#endif
