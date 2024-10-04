class LinkedListNode {
    constructor(data) {
        this.data = data;
        this.next = null;
    }
}

class LinkedListIterator {
    constructor(head) {
        this.currentNode = head;
    }

    data() {
        return this.currentNode ? this.currentNode.data : null;
    }

    next() {
        if (this.currentNode) {
            this.currentNode = this.currentNode.next;
        }
    }

    current() {
        return this.currentNode;
    }
}

class LinkedList {
    constructor() {
        this.head = null;
        this.tail = null;
        this.length = 0;
        this.uniqueValues = new Set();
    }

    begin() {
        return new LinkedListIterator(this.head);
    }

    printList() {
        let current = this.head;
        while (current) {
            console.log(current.data);
            current = current.next;
        }
    }

    find(data) {
        let current = this.head;
        while (current) {
            if (current.data === data) {
                return current;
            }
            current = current.next;
        }
        return null;
    }

    findParent(node) {
        let current = this.head;
        while (current && current.next !== node) {
            current = current.next;
        }
        return current;
    }

    insertLast(data) {
        const newNode = new LinkedListNode(data);
        if (!this.head) {
            this.head = newNode;
            this.tail = newNode;
        } else {
            this.tail.next = newNode;
            this.tail = newNode;
        }
        this.length++;
        this.uniqueValues.add(data);
    }

    insertAfter(existingData, newData) {
        const existingNode = this.find(existingData);
        if (existingNode) {
            const newNode = new LinkedListNode(newData);
            newNode.next = existingNode.next;
            existingNode.next = newNode;
            if (this.tail === existingNode) {
                this.tail = newNode;
            }
            this.length++;
            this.uniqueValues.add(newData);
        }
    }

    insertFirst(data) {
        if (!this.canInsert(data)) return;
        const newNode = new LinkedListNode(data);  // Corrected the class name
        if (this.head == null) {
            this.head = newNode;
            this.tail = newNode;
        } else {
            newNode.next = this.head;
            this.head = newNode;
        }
        this.length++;
        this.uniqueValues.add(data);  // Ensure to track the new node in uniqueValues
    }

    insertBefore(existingData, newData) {
        if (this.head && this.head.data === existingData) {
            const newNode = new LinkedListNode(newData);
            newNode.next = this.head;
            this.head = newNode;
            this.length++;
            this.uniqueValues.add(newData);
            return;
        }
        const existingNode = this.find(existingData);
        if (existingNode) {
            const parentNode = this.findParent(existingNode);
            const newNode = new LinkedListNode(newData);
            newNode.next = existingNode;
            parentNode.next = newNode;
            this.length++;
            this.uniqueValues.add(newData);
        }
    }

    deleteNode(data) {
        if (!this.head) return;

        if (this.head.data === data) {
            this.head = this.head.next;
            this.length--;
            this.uniqueValues.delete(data);
            return;
        }

        let current = this.head;
        while (current.next) {
            if (current.next.data === data) {
                current.next = current.next.next;
                if (current.next === null) {
                    this.tail = current;
                }
                this.length--;
                this.uniqueValues.delete(data);
                return;
            }
            current = current.next;
        }
    }

    deleteHead() {
        if (this.head == null) return;
        this.head = this.head.next;
        this.length--;
    }

    isExist(data) {
        return this.uniqueValues.has(data);
    }

    canInsert(data) {
        return !this.isExist(data);
    }
}



module.exports = LinkedList;
