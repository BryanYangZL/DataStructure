#include "single_linked_list.hpp"

#include <iostream>

template <typename T>
SingleLinkedList<T>::SingleLinkedList() {
    head = nullptr;
    list_size = -1;
}

template <typename T>
SingleLinkedList<T>::~SingleLinkedList() {
    clear();
}

template <typename T>
Node<T>& SingleLinkedList<T>::get_node(int index) {
    if (list_size < index) {
        throw std::underflow_error("index invalid");
    }

    Node<T>* node = head;
    for (int i = 0; i < index; i++) {
        node = node->next;
    }

    return *node;
}

template <typename T>
T SingleLinkedList<T>::get(int index) {
    Node<T>& node = get_node(index);
    return node.v;
}

template <typename T>
void SingleLinkedList<T>::add(const T& v) {
    Node<T>* new_node = new Node<T>();
    new_node->v = v;

    if (head == nullptr) {
        head = new_node;
    } else {
        Node<T>& last_node = get_node(list_size);
        last_node.next = new_node;
    }
    list_size++;
}

template <typename T>
void SingleLinkedList<T>::insert(int index, const T& v) {
    Node<T>* new_node = new Node<T>();
    new_node->v = v;

    Node<T>& node = get_node(index);
    new_node->next = &node;
    if (index == 0) {
        head = new_node;
    } else {
        Node<T>& pre_node = get_node(index - 1);
        pre_node.next = new_node;
    }
    list_size++;
}

template <typename T>
void SingleLinkedList<T>::remove(int index) {
    Node<T>& node = get_node(index);

    if (index == 0) {
        head = node.next;
    } else {
        Node<T>& pre_node = get_node(index - 1);
        pre_node.next = node.next;
    }

    delete &node;
    list_size--;
}

template <typename T>
bool SingleLinkedList<T>::empty() {
    return head == nullptr;
}

template <typename T>
int SingleLinkedList<T>::size() {
    return list_size + 1;
}

template <typename T>
void SingleLinkedList<T>::clear() {
    while (head != nullptr) {
        remove(list_size);
    }
}