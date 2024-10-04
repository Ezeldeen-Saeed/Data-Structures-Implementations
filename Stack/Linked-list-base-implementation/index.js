const Stack = require('./Stack.js');

var stack = new Stack();

console.log("Is empty: ", stack.isEmpty());

stack.push(2);
stack.push(8);
stack.push(1);
stack.push(3);
stack.push(6);


stack.print();

console.log("Is empty: ", stack.isEmpty());
console.log("Head: ", stack.peek());
console.log("Stack size: ", stack.size());

stack.pop();

stack.print();

console.log("Is empty: ", stack.isEmpty());
console.log("Head: ", stack.peek());
console.log("Stack size: ", stack.size());
