const linkedList = require('./LinkedList.js');

module.exports = class Stack {
    #data_list;
    constructor() {
        this.#data_list = new linkedList();
    }

    push(data) {
        this.#data_list.insertFirst(data);
    }

    pop() {
        var head_data = this.#data_list.head.data;
        this.#data_list.deleteHead();
        return head_data;
    }

    peek() {
        return this.#data_list.head.data;
    }

    size() {
        return this.#data_list.length;
    }

    isEmpty() {
        return this.#data_list.length <= 0;        
    }

    print() {
        this.#data_list.printList();
    }
}
