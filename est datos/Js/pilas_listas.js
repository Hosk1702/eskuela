class Nodo {
  constructor(data) {
    this.data = data;
    this.siguiente = null;
  }
}

class PilaConLista {
  constructor() {
    this.top = null; 
  }

  isEmpty() {
    return this.top === null;
  }

  push(item) {
    const puntero = new Nodo(item);
    
    puntero.siguiente = this.top; 
    
    this.top = puntero;
  }

  pop() {
    if (this.isEmpty()) {
      console.log("Stack Underflow");
      return -1; 
    }

    const puntero = this.top;
    
    const item = puntero.data;

    this.top = this.top.siguiente;

    return item;
  }

  peek() {
   
    if (this.isEmpty()) {
      console.log("Stack is empty");
      return -1; 
    }

    return this.top.data;
  }
}

function main() {
  const pila = new PilaConLista();

  pila.push(10);
  pila.push(20);
  pila.push(30);

  console.log(`Elemento superior: ${pila.peek()}`);
  console.log(`Extrae el elemento: ${pila.pop()}`);
  console.log(`Elemento superior despues de pop: ${pila.peek()}`);

  console.log(`Extrae el elemento: ${pila.pop()}`);
  console.log(`Extrae el elemento: ${pila.pop()}`);
  console.log(`Extrae el elemento: ${pila.pop()}`); 
}


main();