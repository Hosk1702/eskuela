const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

const MAXSIZE = 5;
let queue = new Array(MAXSIZE);
let front = -1;
let rear = -1;

function insertar() {
    rl.question('\nIngrese el elemento: ', (input) => {
        let elemento = parseInt(input);
        if (rear === MAXSIZE - 1) {
            console.log("\nDESBORDAMIENTO (OVERFLOW)");
        } else {
            if (front === -1 && rear === -1) {
                front = 0;
                rear = 0;
            } else {
                rear++;
            }
            queue[rear] = elemento;
            console.log("\nElemento insertado correctamente.");
        }
        menu(); // Volver al menú
    });
}

function eliminar() {
    if (front === -1 || front > rear) {
        console.log("\nSUBDESBORDAMIENTO (UNDERFLOW)");
    } else {
        let elemento = queue[front];
        if (front === rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
        }
        console.log("\nElemento eliminado: " + elemento);
    }
    menu(); // Volver al menú
}

function mostrar() {
    if (rear === -1 || front === -1 || front > rear) {
        console.log("\nLa cola está vacía.");
    } else {
        console.log("\nElementos en la cola:");
        for (let i = front; i <= rear; i++) {
            console.log(queue[i]);
        }
    }
    menu(); // Volver al menú
}

function menu() {
    console.log("\n**************** MENÚ PRINCIPAL ****************");
    console.log("================================================");
    console.log("1. Insertar un elemento");
    console.log("2. Eliminar un elemento");
    console.log("3. Mostrar la cola");
    console.log("4. Salir");
    
    rl.question('Ingrese su opción: ', (input) => {
        let opcion = parseInt(input);

        switch (opcion) {
            case 1:
                insertar();
                break;
            case 2:
                eliminar();
                break;
            case 3:
                mostrar();
                break;
            case 4:
                console.log("\nSaliendo del programa...");
                rl.close();
                break;
            default:
                console.log("\nOpción inválida. Intente nuevamente.");
                menu();
                break;
        }
    });
}

// Iniciar el programa
menu();