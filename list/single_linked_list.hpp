#pragma once

#include "node.hpp"

// WARNING: not thread safe
template <typename T>
class SingleLinkedList {
   public:
    SingleLinkedList();

    ~SingleLinkedList();

    T get(int index);
    void add(const T& v);
    void insert(int index, const T& v);
    void remove(int index);
    bool empty();
    int size();
    void clear();

   private:
    Node<T>& get_node(int index);

    Node<T>* head;
    int list_size;
};

#include "single_linked_list.cpp"