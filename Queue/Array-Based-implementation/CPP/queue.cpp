#include <iostream>
using namespace std;

template <typename T>
class Queue {
    private:
        T* data_list; 
        int front_index, rear_index, initial_size, current_size;

    public:
        Queue() {
            this->initial_size = 5;
            this->current_size = initial_size;
            this->rear_index = -1;
            this->front_index = 0;
            this->data_list = new T[this->initial_size];
        }

        void resizeOrNot() {
            if (this->rear_index < this->current_size -1) return;
            
            cout << "Array will be resized!!" << endl;

            int *newArray = new T[this->current_size + initial_size];
            std::copy(this->data_list, this->data_list + this->current_size, newArray);

            this->current_size += this->initial_size;
            delete[] this->data_list;
            this->data_list = newArray;
        }

        void enqueue(T _data) {
            resizeOrNot();
            this->data_list[++this->rear_index] = _data;
        }

        bool isEmpty() {
            if (rear_index <= -1) {
                return true;
            } else {
                return false;
            }
        }

        T dequeue() {
            if (isEmpty()) return T();
            
            int front_data = this->data_list[front_index];
            this->data_list[this->front_index++] = T();

            return front_data;
        }

        int peek() {
            if (isEmpty()) return T();

            return this->data_list[this->front_index];
        }

        int size() {
            if (isEmpty()) return 0;
            return this->rear_index - this->front_index + 1;
        }

        void print() {
            for (int x = this->front_index; x <= rear_index; x++) {
                cout << this->data_list[x] << endl;
            }
        }
};
