#include "stack.hpp"

int main(int argc, char *argv[]) {
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.pop();
    s.push(4);
    s.pop();
    s.push(5);

    s.dump();

    return 0;
}