#include "single_linked_list.hpp"
#include <iostream>

using namespace std;

void dump_list(SingleLinkedList<int> &list) {
    cout << "dump(" << list.size() << "): ";
    for (int i = 0; i < list.size(); i++) {
        cout << list.get(i) << " ";
    }
    cout << endl;
}

int main(int argc, char *argv[]) {
    SingleLinkedList<int> list;

    // add
    list.add(1);
    list.add(2);
    dump_list(list);

    // remove
    list.remove(1);
    list.add(3);
    dump_list(list);
    list.remove(0);
    dump_list(list);
    list.remove(0);
    dump_list(list);

    // insert
    list.add(1);
    list.add(2);
    list.insert(1, 4);
    list.insert(1, 5);
    list.insert(0, 6);
    list.add(7);
    dump_list(list);

    // clear
    list.clear();
    dump_list(list);

    return 0;
}