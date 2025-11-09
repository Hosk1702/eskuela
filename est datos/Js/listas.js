// Se necesita para la entrada síncrona
const prompt = require('prompt-sync')();

class Nodo {
    constructor(data) {
        this.data = data;
        this.siguiente = null;
    }
}

let head = null;

function begininsert() {
    let item;
    console.log("\nIngrese valor\n");
    item = parseInt(prompt());
    let puntero = new Nodo(item);

    puntero.siguiente = head;
    head = puntero;
    console.log("\nNodo insertado");
}

function lastinsert() {
    let puntero, temp;
    let item;
    console.log("\nIngrese valor?\n");
    item = parseInt(prompt());
    puntero = new Nodo(item);

    if (head == null) {
        puntero.siguiente = null;
        head = puntero;
        console.log("\nNodo insertado");
    } else {
        temp = head;
        while (temp.siguiente != null) {
            temp = temp.siguiente;
        }
        temp.siguiente = puntero;
        puntero.siguiente = null;
        console.log("\nNodo insertado");
    }
}

function randominsert() {
    let i, loc, item;
    let puntero, temp;
    
    console.log("\nIntroduzca el valor del elemento");
    item = parseInt(prompt());
    puntero = new Nodo(item);

    console.log("\nIntroduce la ubicación después de la cual deseas insertar ");
    loc = parseInt(prompt());
    
    temp = head;
    for (i = 0; i < loc; i++) {
        temp = temp.siguiente;
        if (temp == null) {
            console.log("\nNo se puede insertar\n");
            return;
        }
    }
    puntero.siguiente = temp.siguiente;
    temp.siguiente = puntero;
    console.log("\nNodo insertado");
}

function begin_delete() {
    let puntero;
    if (head == null) {
        console.log("\nLa lista está vacía\n");
    } else {
        puntero = head;
        head = puntero.siguiente;
        // El recolector de basura se encarga de 'delete'
        console.log("\nNodo eliminado desde el principio ...\n");
    }
}

function last_delete() {
    let puntero, ptr1;
    if (head == null) {
        console.log("\nLa lista está vacía");
    } else if (head.siguiente == null) {
        head = null;
        console.log("\nSolo se eliminó un nodo de la lista ...\n");
    } else {
        puntero = head;
        while (puntero.siguiente != null) {
            ptr1 = puntero;
            puntero = puntero.siguiente;
        }
        ptr1.siguiente = null;
        console.log("\nNodo eliminado del último ...\n");
    }
}

function random_delete() {
    let puntero, ptr1;
    let loc, i;
    console.log("\nIntroduzca la ubicación del nodo después del cual desea realizar la eliminación.\n");
    loc = parseInt(prompt());
    puntero = head;
    for (i = 0; i < loc; i++) {
        ptr1 = puntero;
        puntero = puntero.siguiente;
        if (puntero == null) {
            console.log("\nNo se puede eliminar");
            return;
        }
    }
    ptr1.siguiente = puntero.siguiente;
    console.log("\nNodo eliminado " + (loc + 1));
}

function search() {
    let puntero;
    let item, i = 0;
    let flag;
    puntero = head;
    if (puntero == null) {
        console.log("\nLista vacía\n");
    } else {
        console.log("\nIntroduce el elemento que deseas buscar?\n");
        item = parseInt(prompt());
        while (puntero != null) {
            if (puntero.data == item) {
                console.log("Elemento encontrado en la ubicación " + (i + 1));
                flag = 0;
            } else {
                flag = 1;
            }
            i++;
            puntero = puntero.siguiente;
        }
        if (flag == 1) {
            console.log("Elemento no encontrado\n");
        }
    }
}

function display() {
    let puntero;
    puntero = head;
    if (puntero == null) {
        console.log("Nada que imprimir");
    } else {
        console.log("\nimprimiendo valores . . . .\n");
        while (puntero != null) {
            console.log("\n" + puntero.data);
            puntero = puntero.siguiente;
        }
    }
}

// Lógica principal (main)
let choice = 0;
while (choice != 9) {
    console.log("\n\n*********Menú principal*********\n");
    console.log("\nElige una opción de la siguiente lista ...\n");
    console.log("===============================================\n");
    console.log("\n1. Insertar al principio\n2. Insertar al final\n3. Insertar \n4. Eliminar del principio\n"
            + "5. Eliminar desde el último\n6. Eliminar nodo después de la ubicación especificada\n7. Buscar un elemento\n8. Mostrar\n9. Salir\n");
    console.log("\nIngrese su opción?\n");
    choice = parseInt(prompt());

    switch (choice) {
        case 1:
            begininsert();
            break;
        case 2:
            lastinsert();
            break;
        case 3:
            randominsert();
            break;
        case 4:
            begin_delete();
            break;
        case 5:
            last_delete();
            break;
        case 6:
            random_delete();
            break;
        case 7:
            search();
            break;
        case 8:
            display();
            break;
        case 9:
            process.exit(0);
            break;
        default:
            console.log("Introduzca una opción válida..");
    }
}