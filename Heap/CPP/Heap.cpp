#include <iostream>
#include <cmath>
using namespace std;

class Heap {
private:
    int capacity, current_size, *nodes;

public:
    Heap() {
        this->capacity = 5;
        this->current_size = 0;
        this->nodes = new int[this->capacity];
    }   

    ~Heap() {
        delete[] this->nodes;
    }


    void resizeOrNot() {
        if (this->current_size < this->capacity) return;

        int new_capacity = capacity + 5;

        int *newArray = new int[new_capacity];
        std::copy(this->nodes, this->nodes + this->current_size, newArray);

        delete[] this->nodes;
        this->nodes = newArray;
        this->capacity = new_capacity;
    }

    

    void insert(int data) {
        resizeOrNot();

        int i, parent_index;
        i = this->current_size++;
        parent_index = (i - 1) / 2;

        this->nodes[i] = data;
        while (i != 0 && this->nodes[i] < this->nodes[parent_index]) {
            int temp = this->nodes[i];
            this->nodes[i] = this->nodes[parent_index];
            this->nodes[parent_index] = temp;
            i = parent_index;
            parent_index = (i - 1) / 2;
        }
    }


    void print() {
        string print_data = "";
        for (int x = 0; x < this->current_size -1; x++) {
            print_data += to_string(this->nodes[x]) + " - ";
        }
        cout << print_data;
    }

    int size() {
        return this->current_size;
    }



    void draw() {
        if (this->current_size == 0) return;

        int levels_count = log2(this->current_size) + 1;
        int line_width = pow(2, levels_count - 1);

        int j = 0;

        for (int i = 0; i < levels_count; i++) {
            int nodes_count = pow(2, i);
            int space = ceil((float)(line_width - nodes_count) / 2.0);
            int space_between = ceil((float)levels_count / (float)nodes_count);
            if (space_between < 1) space_between = 1;

            int k = j;
            string str(space + space_between, ' ');

            cout << str;

            for (; j < k + nodes_count; j++) {
                if (j >= this->current_size) {
                    break;
                }

                cout << this->nodes[j];

                cout << string(space_between * 2, ' ');
            }

            cout << endl << endl;
        }
    }



};
