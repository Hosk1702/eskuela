class Pila {
  constructor() {
    this.MAX = 100;
    this.stack = new Array(this.MAX);
    this.top = -1;
  }

  push(item) {
    if (this.isFull()) {
      console.log("Stack Overflow");
      return;
    }
    this.stack[++this.top] = item;
  }

  pop() {
    if (this.isEmpty()) {
      console.log("Stack Underflow");
      return -1; // Coincidiendo con la lógica de C++
    }
    return this.stack[this.top--];
  }

  peek() {
    if (this.isEmpty()) {
      console.log("Stack is empty");
      return -1; // Coincidiendo con la lógica de C++
    }
    return this.stack[this.top];
  }

  isEmpty() {
    return this.top === -1;
  }

  isFull() { // Nota: Nombres de función en JS suelen usar camelCase
    return this.top === this.MAX - 1;
  }
}

// --- Main ---
function main() {
  const pila = new Pila();
  pila.push(10);
  pila.push(20);
  pila.push(30);

  console.log(`Elemento superior: ${pila.peek()}`);
  console.log(`Extrae el elemento: ${pila.pop()}`);
  console.log(`Elemento superior despues de pop: ${pila.peek()}`);
}

main();