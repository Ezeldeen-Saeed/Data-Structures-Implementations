#include <iostream>
#include "stack.cpp"
using namespace std;

int main() {
    Stack *stack = new Stack();

    cout << "isEmpty: " << stack->isEmpty() << endl;
    cout << "Size: " << stack->size() << endl;

    stack->push(15);
    stack->push(25);
    stack->push(45);
    stack->push(58);
    stack->push(83);
    stack->push(34);

    stack->print();
    cout << "isEmpty: " << stack->isEmpty() << endl;

    stack->pop();
    cout << "Size: " << stack->size() << endl;
    stack->print();

}
