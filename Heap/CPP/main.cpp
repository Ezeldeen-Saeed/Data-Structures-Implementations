#include <iostream>
#include "./Heap.cpp"
using namespace std;

int main() {

    Heap* heap = new Heap();

    heap->insert(5);
    heap->insert(1);
    heap->insert(52);
    heap->insert(68);
    heap->insert(18);
    heap->insert(25);
    heap->insert(35);

    heap->draw();
    heap->print();


    return 0;
}
