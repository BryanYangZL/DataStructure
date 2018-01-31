#include "queue.hpp"
#include <iostream>

using namespace std;

void dump_queue(Queue<int>& q) {
    cout << "queue dump: ";
    while (!q.empty()) {
        cout << q.dequeue() << " ";
    }
    cout << endl;
}

int main(int argc, char* args[]) {
    Queue<int> q(3);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    dump_queue(q);

    q.enqueue(1);
    q.enqueue(2);
    q.dequeue();
    q.enqueue(3);
    dump_queue(q);

    q.enqueue(1);
    q.enqueue(2);
    q.dequeue();
    q.dequeue();
    q.enqueue(3);
    dump_queue(q);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.enqueue(4);
    dump_queue(q);

    return 0;
}