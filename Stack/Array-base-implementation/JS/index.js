const Stack = require('./Stack.js');

var stack = new Stack();

console.log("isEmpty: ", stack.isEmpty());

stack.push(14);
stack.push(44);
stack.push(58);
stack.push(95);
stack.push(22);


stack.print();
console.log("isEmpty: ", stack.isEmpty());
console.log("Size: ", stack.size());

stack.pop();
console.log("Peek: ", stack.peek());
stack.print();
console.log("Size: ", stack.size());
