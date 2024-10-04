#include <iostream>
using namespace std;

class Stack {
    private:
        int *data_list, top_index, initial_size, current_size;

    public:
        Stack() {
            this->initial_size = 5;
            this->current_size = initial_size;
            this->top_index = -1;
            this->data_list = new int[this->initial_size];
        }

        void resizeOrNot() {
            if (this->top_index < this->current_size -1) return;
            cout << "Array will be resized!!" << endl;

            int *newArray = new int[this->current_size + this->initial_size];
            std::copy(this->data_list, this->data_list + this->current_size, newArray);

            this->current_size += this->initial_size;
            delete[] this->data_list;
            this->data_list = newArray;
        }

        void push(int _data) {
            resizeOrNot();
            this->data_list[++this->top_index] = _data;
        }

        int pop() {
            if (this->top_index == -1) return 0;

            int head_data = this->data_list[this->top_index];
            this->data_list[this->top_index] = 0;
            this->top_index--;

            return head_data;
        }

        int peek() {
            if (this->top_index == -1) {
                return 0;
            } else {
                return this->data_list[top_index];
            }
        }

        int size() {
            return this->top_index + 1;
        }

        int isEmpty() {
            return this->top_index <= -1;
        }

        void print() {
            for (int x = this->top_index; x > -1; x--) {
                cout << this->data_list[x] << endl;
            }
        }

        
};
