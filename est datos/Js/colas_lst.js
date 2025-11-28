const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin, output: process.stdout
});

class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
    }
}

let front = null;
let rear = null;

function insertar() {
    rl.question('\nIngrese el elemento: ', (input) => {
        let val = parseInt(input);
        let newNode = new Node(val);

        if (front === null) {
            front = rear = newNode;
        } else {
            rear.next = newNode;
            rear = newNode;
        }
        console.log("\nElemento insertado correctamente.");
        menu();
    });
}

function eliminar() {
    if (front === null) {
        console.log("\nSUBDESBORDAMIENTO (La cola esta vacia)");
    } else {
        console.log("\nElemento eliminado: " + front.data);
        if (front === rear) {
            front = rear = null;
        } else {
            front = front.next;
        }
    }
    menu();
}

function mostrar() {
    if (front === null) {
        console.log("\nLa cola está vacía.");
    } else {
        let temp = front;
        console.log("\nElementos en la cola:");
        while (temp !== null) {
            console.log(temp.data);
            temp = temp.next;
        }
    }
    menu();
}

function menu() {
    console.log("\n*** MENÚ COLA (LISTA ENLAZADA) ***");
    console.log("1. Insertar\n2. Eliminar\n3. Mostrar\n4. Salir");
    rl.question('Opción: ', (opc) => {
        switch (opc) {
            case '1': insertar(); break;
            case '2': eliminar(); break;
            case '3': mostrar(); break;
            case '4': console.log("Saliendo..."); rl.close(); break;
            default: menu(); break;
        }
    });
}
menu();