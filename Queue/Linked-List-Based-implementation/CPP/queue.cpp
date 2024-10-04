#include <iostream>
#include <optional>
#include "./linkedList.cpp"
using namespace std;

class Queue {
    private:
        linkedList *data_list;

    public:
        Queue() {
            this->data_list = new linkedList();
        } 

        void enqueue(int data) {
            this->data_list->insertLast(data);
        }

        int dequeue() {
            int head_data = this->data_list->head->data;
            this->data_list->deleteHead();
            return head_data;
        }
        // Return zero if head equals NULL (Not valid)
        //int peek() {
        //    if (this->data_list->head == NULL) { return 0; }
        //    return this->data_list->head->data;
        //}

        // Return a null pointer
        int* peek() {
            if (this->data_list->head == NULL) {
                return nullptr;
            }
            return &(this->data_list->head->data);
        }   

        // Return nullopt using optional library but nullopt dereferncing value integer byself
        //optional<int> peek() {
        //    if (this->data_list->head == NULL) {
        //        return nullopt;
        //    }
        //    return this->data_list->head->data;
        //}

        //int peek() {
        //    if (this->data_list->head == NULL) {
        //        throw runtime_error("Queue is empty, nothing to peek.");
        //    }
        //    return this->data_list->head->data;
        //}


        int size() {
            return this->data_list->Length();
        }

        bool isEmpty() {
            return this->data_list->Length() <= 0;
        }

        void print() {
            this->data_list->printList();
        }
};
