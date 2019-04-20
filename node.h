#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;

    void killSelf(int counter) {
        if (counter > 1) next->killSelf(counter-1);
        delete this;
    }
};

#endif
