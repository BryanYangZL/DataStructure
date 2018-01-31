#pragma once

#include <iostream>

template <typename T>
class Queue {
   public:
    Queue(int max) {
        _tail = _head = 0;
        _size = 0;

        if (max <= 0) {
            max = 100;
        }
        _max = max;

        data = new T[_max];
    }

    ~Queue() {
        if (data != nullptr) {
            delete[] data;
        }
    }

    void enqueue(const T& v) {
        if (full()) {
            throw std::overflow_error("queue is full");
        }

        data[_head] = v;
        inc_head();
    }

    T dequeue() {
        if (empty()) {
            throw std::underflow_error("queue is empty");
        }

        T& v = data[_tail];
        inc_tail();

        return v;
    }

    bool full() { return _max == _size; }
    bool empty() { return _size == 0; }
    int size() { return _size; }

   private:
    T* data = nullptr;
    int _head = 0;
    int _tail = 0;
    int _size = 0;
    int _max = 0;

    int inc_head() {
        _size++;
        _head = (_head + 1) % _max;
        return _head;
    }

    int inc_tail() {
        _size--;
        _tail = (_tail + 1) % _max;
        return _tail;
    }
};