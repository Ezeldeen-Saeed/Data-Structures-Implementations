#include <iostream>
#include "./queue.cpp"
using namespace std;

int main() {
    Queue *queue = new Queue();

    cout << "isEmpty: " << queue->isEmpty() << endl;

    queue->enqueue(13);
    queue->enqueue(29);
    queue->enqueue(49);
    queue->enqueue(97);
    queue->enqueue(33);
    queue->enqueue(21);
    queue->enqueue(14);
    
    queue->print();
    cout << "isEmpty: " << queue->isEmpty() << endl;
    cout << "Size: " << queue->size() << endl;

    cout << "Peek: " << *queue->peek() << endl;

    queue->dequeue();
    queue->dequeue();

    
    queue->print();
    cout << "Size: " << queue->size() << endl;

    cout << "Peek: " << *queue->peek() << endl;

    
    queue->dequeue();
    queue->dequeue();
    queue->dequeue();
    queue->dequeue();
    queue->dequeue();

    queue->print();
    cout << "isEmpty: " << queue->isEmpty() << endl; 
    cout << "Size: " << queue->size() << endl;
    cout << "Peek: " << *queue->peek();
}
