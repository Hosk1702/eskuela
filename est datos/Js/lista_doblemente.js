const readline = require('readline');

// Configura la interfaz de readline
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

// Función auxiliar para hacer preguntas de forma síncrona (simulada con async/await)
function askQuestion(query) {
  return new Promise(resolve => rl.question(query, resolve));
}

class Nodo {
  constructor(data) {
    this.data = data;
    this.siguiente = null;
    this.anterior = null;
  }
}

class ListaDobleEnlazada {
  constructor() {
    this.head = null;
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
    // No hay chequeo de OVERFLOW real como en C, JS arrojará una excepción si se queda sin memoria

    puntero.siguiente = this.head;
    puntero.anterior = null;
    if (this.head !== null) {
      this.head.anterior = puntero;
    }
    this.head = puntero;
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
      puntero.siguiente = null;
      puntero.anterior = null;
      this.head = puntero;
      console.log("\nNodo insertado");
    } else {
      let temp = this.head;
      while (temp.siguiente !== null) {
        temp = temp.siguiente;
      }
      temp.siguiente = puntero;
      puntero.anterior = temp;
      puntero.siguiente = null;
      console.log("\nNodo insertado");
    }
  }

  async randominsert() {
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

    // El bucle original itera 'loc' veces. Si loc=0, inserta después de head.
    for (let i = 0; i < loc; i++) {
      if (temp === null) {
        console.log("\nNo se puede insertar (ubicación fuera de rango)");
        return;
      }
      temp = temp.siguiente;
    }

    // Caso especial: temp es null porque loc es demasiado grande o la lista está vacía
    if (temp === null && loc > 0) { 
        console.log("\nNo se puede insertar (ubicación fuera de rango)");
        return;
    }
    
    // Caso: insertar al principio si loc=0 y lista vacía (no manejado en C++)
    if (temp === null && this.head === null) {
         this.head = puntero;
         console.log("\nNodo insertado (en cabeza)");
         return;
    }

    // Lógica de inserción
    puntero.siguiente = temp.siguiente;
    puntero.anterior = temp;
    if (temp.siguiente !== null) {
      temp.siguiente.anterior = puntero;
    }
    temp.siguiente = puntero;
    console.log("\nNodo insertado");
  }

  begin_delete() {
    if (this.head === null) {
      console.log("\nLa lista está vacía\n");
    } else {
      let puntero = this.head;
      this.head = puntero.siguiente;
      if (this.head !== null) {
        this.head.anterior = null;
      }
      // En JS, el recolector de basura se encarga de 'puntero'
      console.log("\nNodo eliminado desde el principio ...\n");
    }
  }

  last_delete() {
    if (this.head === null) {
      console.log("\nLa lista está vacía");
    } else if (this.head.siguiente === null) {
      this.head = null;
      console.log("\nSolo se eliminó un nodo de la lista ...\n");
    } else {
      let puntero = this.head;
      while (puntero.siguiente !== null) {
        puntero = puntero.siguiente;
      }
      // puntero es ahora el último nodo
      puntero.anterior.siguiente = null;
      console.log("\nNodo eliminado del último ...\n");
    }
  }

  async random_delete() {
    let loc, i;
    try {
      loc = parseInt(await askQuestion('\nIntroduzca la ubicación (índice 0) del nodo a eliminar: '));
      if (isNaN(loc)) throw new Error();
    } catch (e) {
      console.log("Entrada inválida");
      return;
    }

    if (loc === 0) {
      this.begin_delete();
      return;
    }

    let puntero = this.head;

    for (i = 0; i < loc; i++) {
      if (puntero === null) {
        console.log("\nNo se puede eliminar (ubicación fuera de rango)");
        return;
      }
      puntero = puntero.siguiente;
    }
    
    // Si puntero es null aquí, loc estaba fuera de rango
    if (puntero === null) {
        console.log("\nNo se puede eliminar (ubicación fuera de rango)");
        return;
    }

    // puntero es el nodo a eliminar
    puntero.anterior.siguiente = puntero.siguiente;
    if (puntero.siguiente !== null) {
      puntero.siguiente.anterior = puntero.anterior;
    }
    console.log(`\nNodo eliminado en la ubicación ${loc}`);
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

    while (puntero !== null) {
      if (puntero.data === item) {
        console.log(`Elemento encontrado en la ubicación ${i + 1}`);
        flag = true;
        break; // Usamos break en lugar de return para asegurar que 'flag' se evalúe
      }
      i++;
      puntero = puntero.siguiente;
    }

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
      while (puntero !== null) {
        console.log(puntero.data);
        puntero = puntero.siguiente;
      }
    }
  }
}

// --- Función Principal (Main) ---
async function main() {
  const lista = new ListaDobleEnlazada();
  let choice = 0;

  while (choice !== 9) {
    console.log("\n\n*********Menú principal*********\n");
    console.log("\nElige una opción de la siguiente lista ...\n");
    console.log("===============================================\n");
    console.log("\n1. Insertar al principio\n2. Insertar al final\n3. Insertar en ubicación\n4. Eliminar del principio\n" +
                "5. Eliminar desde el último\n6. Eliminar nodo en ubicación especificada\n7. Buscar un elemento\n8. Mostrar\n9. Salir\n");
    
    try {
      choice = parseInt(await askQuestion('\nIngrese su opción?\n'));
      if (isNaN(choice)) choice = 0; // Fuerza el default
    } catch(e) {
      choice = 0;
    }

    switch (choice) {
      case 1:
        await lista.begininsert();
        break;
      case 2:
        await lista.lastinsert();
        break;
      case 3:
        await lista.randominsert();
        break;
      case 4:
        lista.begin_delete();
        break;
      case 5:
        lista.last_delete();
        break;
      case 6:
        await lista.random_delete();
        break;
      case 7:
        await lista.search();
        break;
      case 8:
        lista.display();
        break;
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