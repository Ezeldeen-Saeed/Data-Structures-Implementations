#include <iostream>
using namespace std;

class linkedListNode {
public:
    int data;
    linkedListNode *next;
    linkedListNode(int _data) {
        this->data = _data;
        this->next = NULL;
    }
};

class linkedListIterator {
private:
    linkedListNode *currentNode;

public:
    linkedListIterator() { currentNode = NULL; }
    linkedListIterator(linkedListNode *node) { currentNode = node; }
    int data() { return currentNode->data; }
    linkedListIterator next() {
        currentNode = currentNode->next;
        return *this;
    }

    linkedListNode *current() { return currentNode; }
};

class linkedList {
private:
    int length;

public:
    linkedListNode *head = NULL;
    linkedListNode *tail = NULL;

    void addHead(linkedListNode *node) {
        this->head = node;
        this->tail = node;
    }

    void insertLast(int _data) {
        linkedListNode *newNode = new linkedListNode(_data);
        if (this->head == NULL) {
            this->head = newNode;
            this->tail = newNode;
        } else {
            this->tail->next = newNode;
            this->tail = newNode;
        }
        this->length++;
    }

    void insertFirst(int _data) {
        linkedListNode *newNode = new linkedListNode(_data);
        if (this->head == NULL) {
            this->head = newNode;
            this->tail = newNode;
        } else {
            newNode->next = this->head;
            this->head = newNode;
        }
        this->length++;
    }

    void insertAfter(linkedListNode *node, int _data) {
        linkedListNode *newnode = new linkedListNode(_data);
        newnode->next = node->next;
        node->next = newnode;
        if (newnode->next == NULL) {
            this->tail = newnode;
        }
        this->length++;
    }

    void deleteNode(linkedListNode *node) {
        if (this->head == this->tail) {
            this->head = NULL;
            this->tail = NULL;
        } else if (this->head == node) {
            this->head = node->next;
        } else {
            linkedListNode *parentNode = this->findParent(node);
            if (this->tail == node) {
                this->tail = parentNode;
            } else {
                parentNode->next = node->next;
            }
        }
        delete node;
        this->length--;
    }

    void deleteNode(int _data) {
        linkedListNode *node = this->find(_data);
        if (node == NULL) {
            return;
        }
        this->deleteNode(node);
    }

    void deleteHead() {
        if (this->head == NULL) {
            return;
        }
        this->deleteNode(this->head);
    }

    void insertBefore(linkedListNode *node, int _data) {
        linkedListNode *newnode = new linkedListNode(_data);
        newnode->next = node;

        linkedListNode *parentNode = this->findParent(node);

        if (parentNode == NULL) {
            this->head = newnode;
        } else {
            parentNode->next = newnode;
        }
        this->length++;
    }

    linkedListNode *find(int _data) {
        for (auto itr = this->begin(); itr.current() != NULL; itr.next()) {
            if (itr.data() == _data) {
                return itr.current();
            }
        }
        return NULL;
    }

    linkedListNode *findParent(linkedListNode *node) {
        for (auto itr = this->begin(); itr.current() != NULL; itr.next()) {
            if (itr.current()->next == node) {
                return itr.current();
            }
        }
        return NULL;
    }

    int getLengthItr() {
        int count = 0;
        for (auto itr = this->begin(); itr.current() != NULL; itr.next()) {
            count++;
        }
        return count;
    }

    int Length() { return this->length; }

    void printList() {
        for (auto itr = this->begin(); itr.current() != NULL; itr.next()) {
            cout << itr.data() << " -> ";
        }
        cout << "\n";
    }

    int sum() {
        int sum = 0;
        for (auto itr = this->begin(); itr.current() != NULL; itr.next()) {
            sum += itr.data();
        }
        return sum;
    }

    linkedListIterator begin() {
        linkedListIterator itr(this->head);
        return itr;
    }
};
