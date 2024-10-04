module.exports = class Stack {
    #data_list;
    #top_index;
    constructor() {
        this.#data_list = [];
        this.#top_index = -1;
    }

    push(data) {
        this.#data_list.push(data);
        this.#top_index++;
    }

    pop() {
        if (this.#top_index == -1) return;

        var head_data = this.#data_list.splice(this.#top_index, 1)[0];
        this.#top_index--;
        return head_data;
    }

    peek() {
        return this.#data_list[this.#top_index];
    }

    size() {
        return this.#data_list.length;
    }

    isEmpty() {
        return this.#data_list.length <= 0;        
    }

    print() {
        for (var x = this.#data_list.length - 1; x >= 0; x--) {
            console.log(this.#data_list[x], '\n');
        }
    }
}
