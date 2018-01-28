#pragma once

template <typename T>
class Node {
   public:
    Node() { next = nullptr; }

    T v;
    Node* next;
};