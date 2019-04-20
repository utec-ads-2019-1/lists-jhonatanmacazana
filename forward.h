#ifndef FORWARD_H
#define FORWARD_H

#include "list.h"
#include "iterators/forward_iterator.h"

template <typename T>
class ForwardList : public List<T> {
    public:
        ForwardList() : List<T>() {}

        T front() {
            return (empty()?false:this->head->data);
        }

        T back() {
            return (empty()?false:this->tail->data);
        }

        void push_front(T value) {
            Node<T> *temp = new Node<T>();
            if (empty())
                this->tail = temp;

            temp->data = value;
            temp->next = this->head;
            this->head = temp;
            ++this->nodes;
        }

        void push_back(T value) {
            Node<T> *temp = new Node<T>();
            if (empty())
                this->head = temp;

            this->tail = temp;
            temp->data = value;
            temp->next = NULL;
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
                Node<T> *temp = this->head;
                while(temp->next != this->tail)
                    temp = temp->next;
                delete this->tail;
                this->tail = temp;
                this->tail->next = NULL;
                --this->nodes;
            }
        }

        T operator[](int index) {
            Node<T> *temp = new Node<T>();
            temp = this->head;
            for (int i = 0; i < index; i++)
            {
                if (temp->next == NULL)
                    throw;
                temp ->next = temp;
            }
            std::cout << temp << std::endl;
        }

        bool empty() {
            return (this->head == NULL ? true: false);
        }

        int size() {
            return this->nodes;
        }

        void clear() {
            Node<T> *temp = new Node<T>();
            temp = this->tail;
            for (int i = 0; i < size(); i++)
            {
                temp->next = temp;
                delete temp;
            }
        }

        void sort() {
            // TODO
        }

        void reverse() {
            // TODO
        }

        std::string name() {
            return "Forward List";
        }

        ForwardIterator<T> begin() {
            // TODO
        }

	    ForwardIterator<T> end() {
            // TODO
        }

        void merge(ForwardList<T> list) {
            // TODO
        }
};

#endif
