#pragma once

#include <iostream>
#include <vector>

using namespace std;

// WARNING: not thread safe

template <typename T>
class stack {
   public:
    stack(int reserve = 100) { v.reserve(reserve); }
    bool empty() { return v.empty(); }

    T pop() {
        if (empty()) {
            return T(NULL);
        }

        T value = v.back();
        v.pop_back();

        return value;
    }

    void push(const T& value) { v.push_back(value); }

    int size() { return v.size(); }

    void dump() {
        cout << "cap: " << v.capacity() << "  size: " << v.size() << endl;
        for (auto value : v) {
            cout << value << endl;
        }
    }

   private:
    vector<T> v;
};