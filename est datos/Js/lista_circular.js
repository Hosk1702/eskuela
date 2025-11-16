const readline = require('readline');

// Configura la interfaz de readline
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

// Función auxiliar para hacer preguntas
function askQuestion(query) {
  return new Promise(resolve => rl.question(query, resolve));
}

class Nodo {
  constructor(data) {
    this.data = data;
    this.siguiente = null;
  }
}

class ListaCircular {
  constructor() {
    this.head = null;
    this.tail = null;
  }

  async begininsert() {
    let item;
    try {
      item = parseInt(await askQuestion('\nIngrese valor\n'));
      if (isNaN(item)) throw new Error();
    } catch (e) {
      console.log("Entrada inválida");
      return;
    }

    const puntero = new Nodo(item);
    
    if (this.head === null) {
      this.head = puntero;
      this.tail = puntero;
      puntero.siguiente = this.head;
    } else {
      puntero.siguiente = this.head;
      this.head = puntero;
      this.tail.siguiente = this.head;
    }
    console.log("\nNodo insertado");
  }

  async lastinsert() {
    let item;
    try {
      item = parseInt(await askQuestion('\nIngrese valor?\n'));
      if (isNaN(item)) throw new Error();
    } catch (e) {
      console.log("Entrada inválida");
      return;
    }

    const puntero = new Nodo(item);

    if (this.head === null) {
      this.head = puntero;
      this.tail = puntero;
      puntero.siguiente = this.head;
    } else {
      puntero.siguiente = this.head;
      this.tail.siguiente = puntero;
      this.tail = puntero;
    }
    console.log("\nNodo insertado");
  }

  async randominsert() {
    if (this.head === null) {
      console.log("Lista vacía, insertando al principio.");
      await this.begininsert();
      return;
    }
      
    let item, loc;
    try {
      item = parseInt(await askQuestion('\nIntroduzca el valor del elemento: '));
      if (isNaN(item)) throw new Error();
      loc = parseInt(await askQuestion('\nIntroduce la ubicación (índice 0) después de la cual deseas insertar: '));
      if (isNaN(loc)) throw new Error();
    } catch (e) {
      console.log("Entrada inválida");
      return;
    }

    const puntero = new Nodo(item);
    let temp = this.head;

    for (let i = 0; i < loc; i++) {
      temp = temp.siguiente;
      if (temp === this.head) {
        console.log("\nNo se puede insertar (ubicación fuera de rango)");
        return;
      }
    }
    
    puntero.siguiente = temp.siguiente;
    temp.siguiente = puntero;
    if (temp === this.tail) {
      this.tail = puntero;
    }
    console.log("\nNodo insertado");
  }

  begin_delete() {
    if (this.head === null) {
      console.log("\nLa lista está vacía\n");
    } else if (this.head === this.tail) { // Solo un nodo
      this.head = null;
      this.tail = null;
      console.log("\nSolo se eliminó un nodo de la lista ...\n");
    } else {
      let puntero = this.head;
      this.head = puntero.siguiente;
      this.tail.siguiente = this.head;
      // 'puntero' será eliminado por el recolector de basura
      console.log("\nNodo eliminado desde el principio ...\n");
    }
  }

  last_delete() {
    if (this.head === null) {
      console.log("\nLa lista está vacía");
    } else if (this.head === this.tail) { // Solo un nodo
      this.head = null;
      this.tail = null;
      console.log("\nSolo se eliminó un nodo de la lista ...\n");
    } else {
      let puntero = this.head;
      let ptr1 = null;
      while (puntero.siguiente !== this.head) { // O 'while (puntero !== this.tail)'
        ptr1 = puntero;
        puntero = puntero.siguiente;
      }
      // puntero es el tail, ptr1 es el anterior
      ptr1.siguiente = this.head;
      this.tail = ptr1;
      console.log("\nNodo eliminado del último ...\n");
    }
  }

  async random_delete() {
    let loc;
    try {
      loc = parseInt(await askQuestion('\nIntroduzca la ubicación (índice 0) del nodo a eliminar:\n'));
      if (isNaN(loc)) throw new Error();
    } catch (e) {
      console.log("Entrada inválida");
      return;
    }

    if (this.head === null) {
        console.log("\nLa lista está vacía");
        return;
    }

    if (loc === 0) {
      this.begin_delete();
      return;
    }

    let puntero = this.head;
    let ptr1 = null;
    
    for (let i = 0; i < loc; i++) {
      if (puntero.siguiente === this.head && i < loc - 1) {
           console.log("\nNo se puede eliminar (ubicación fuera de rango)");
           return;
      }
      ptr1 = puntero;
      puntero = puntero.siguiente;
    }
    
    // puntero es el nodo a eliminar, ptr1 es el anterior
    ptr1.siguiente = puntero.siguiente;
    if (puntero === this.tail) { // Corrección: Checar si el nodo eliminado era el tail
      this.tail = ptr1;
    }
    console.log(`\nNodo eliminado ${loc}`);
  }

  async search() {
    if (this.head === null) {
      console.log("\nLista vacía\n");
      return;
    }

    let item, i = 0, flag = false;
    let puntero = this.head;

    try {
      item = parseInt(await askQuestion('\nIntroduce el elemento que deseas buscar?\n'));
      if (isNaN(item)) throw new Error();
    } catch (e) {
      console.log("Entrada inválida");
      return;
    }

    do {
      if (puntero.data === item) {
        console.log(`Elemento encontrado en la ubicación ${i + 1}`);
        flag = true;
        break;
      }
      i++;
      puntero = puntero.siguiente;
    } while (puntero !== this.head);

    if (!flag) {
      console.log("Elemento no encontrado\n");
    }
  }

  display() {
    let puntero = this.head;
    if (puntero === null) {
      console.log("Nada que imprimir");
    } else {
      console.log("\nimprimiendo valores . . . .\n");
      do {
        console.log(puntero.data);
        puntero = puntero.siguiente;
      } while (puntero !== this.head);
    }
  }
}

// --- Función Principal (Main) ---
async function main() {
  const lista = new ListaCircular();
  let choice = 0;

  while (choice !== 9) {
    console.log("\n\n*********Menú principal*********\n");
    console.log("\nElige una opción de la siguiente lista ...\n");
    console.log("===============================================\n");
    console.log("\n1. Insertar al principio\n2. Insertar al final\n3. Insertar \n4. Eliminar del principio\n" +
                "5. Eliminar desde el último\n6. Eliminar nodo en ubicación especificada\n7. Buscar un elemento\n8. Mostrar\n9. Salir\n");
    
    try {
      choice = parseInt(await askQuestion('\nIngrese su opción?\n'));
      if (isNaN(choice)) choice = 0;
    } catch(e) {
      choice = 0;
    }

    switch (choice) {
      case 1: await lista.begininsert(); break;
      case 2: await lista.lastinsert(); break;
      case 3: await lista.randominsert(); break;
      case 4: lista.begin_delete(); break;
      case 5: lista.last_delete(); break;
      case 6: await lista.random_delete(); break;
      case 7: await lista.search(); break;
      case 8: lista.display(); break;
      case 9:
        console.log("Saliendo...");
        rl.close();
        process.exit(0);
        break;
      default:
        console.log("Introduzca una opción válida..");
    }
  }
}

main();