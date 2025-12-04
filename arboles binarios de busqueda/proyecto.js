const fs = require('fs');
const readline = require('readline');

// ==========================================
// Clase Nodo
// Estructura básica: dato, izquierda, derecha
// ==========================================
class Nodo {
    constructor(dato) {
        this.dato = dato;       // El valor del nodo
        this.izq = null;        // Apuntador al hijo izquierdo
        this.der = null;        // Apuntador al hijo derecho
    }
}

// ==========================================
// Clase BST (Árbol Binario de Búsqueda)
// Implementa inserción, búsqueda, eliminación y recorridos
// ==========================================
class BST {
    constructor() {
        this.raiz = null;
    }

    // --- Inserción ---
    // Complejidad: O(log n) promedio
    insert(dato) {
        let nuevo = new Nodo(dato);

        if (this.raiz === null) {
            this.raiz = nuevo;
        } else {
            this._insertarNodo(this.raiz, nuevo);
        }
        console.log(`> Número ${dato} insertado.`);
    }

    _insertarNodo(nodo, nuevo) {
        // Si el nuevo dato es menor, va a la izquierda
        if (nuevo.dato < nodo.dato) {
            if (nodo.izq === null) {
                nodo.izq = nuevo;
            } else {
                this._insertarNodo(nodo.izq, nuevo);
            }
        } 
        // Si el nuevo dato es mayor o igual, va a la derecha
        else {
            if (nodo.der === null) {
                nodo.der = nuevo;
            } else {
                this._insertarNodo(nodo.der, nuevo);
            }
        }
    }

    // --- Búsqueda ---
    // Complejidad: O(log n) promedio
    search(dato) {
        let ruta = [];
        let actual = this.raiz;
        let encontrado = false;

        // Recorremos el árbol mientras "actual" no sea nulo
        while (actual !== null) {
            ruta.push(actual.dato); // Guardamos el camino

            if (dato === actual.dato) {
                encontrado = true;
                break;
            }

            if (dato < actual.dato) {
                actual = actual.izq;
            } else {
                actual = actual.der;
            }
        }

        if (encontrado) {
            console.log(`> Encontrado. Ruta: ${ruta.join(' -> ')}`);
        } else {
            console.log(`> El número ${dato} no existe.`);
        }
    }

    // --- Eliminación ---
    // Complejidad: O(log n) promedio
    delete(dato) {
        this.raiz = this._eliminarNodo(this.raiz, dato);
    }

    _eliminarNodo(nodo, dato) {
        // Caso base: si el nodo es nulo, no hay nada que borrar
        if (nodo === null) {
            console.log("> Dato no encontrado para eliminar.");
            return null;
        }

        // Buscamos el nodo a eliminar recursivamente
        if (dato < nodo.dato) {
            nodo.izq = this._eliminarNodo(nodo.izq, dato);
            return nodo;
        } else if (dato > nodo.dato) {
            nodo.der = this._eliminarNodo(nodo.der, dato);
            return nodo;
        } else {
            // --- Encontramos el nodo a eliminar ---
            
            // Caso 1: Es una hoja (sin hijos)
            if (nodo.izq === null && nodo.der === null) {
                nodo = null;
                return nodo;
            }

            // Caso 2: Tiene un solo hijo (izquierdo o derecho)
            if (nodo.izq === null) {
                nodo = nodo.der;
                return nodo;
            } else if (nodo.der === null) {
                nodo = nodo.izq;
                return nodo;
            }

            // Caso 3: Tiene dos hijos
            // Buscamos el nodo más pequeño del lado derecho (sucesor)
            let aux = this._encontrarMinimo(nodo.der);
            
            // Reemplazamos el valor del nodo actual con el del sucesor
            nodo.dato = aux.dato;

            // Eliminamos el sucesor duplicado del subárbol derecho
            nodo.der = this._eliminarNodo(nodo.der, aux.dato);
            return nodo;
        }
    }

    _encontrarMinimo(nodo) {
        // Viajamos todo lo posible a la izquierda
        if (nodo.izq === null) {
            return nodo;
        } else {
            return this._encontrarMinimo(nodo.izq);
        }
    }

    // --- Recorridos ---
    
    // Inorder: Izquierda -> Raíz -> Derecha
    inorder() {
        let resultado = [];
        this._inorder(this.raiz, resultado);
        console.log("Inorder:", resultado.join(" "));
        return resultado;
    }

    _inorder(nodo, lista) {
        if (nodo !== null) {
            this._inorder(nodo.izq, lista);
            lista.push(nodo.dato);
            this._inorder(nodo.der, lista);
        }
    }

    // Preorder: Raíz -> Izquierda -> Derecha
    preorder() {
        let resultado = [];
        this._preorder(this.raiz, resultado);
        console.log("Preorder:", resultado.join(" "));
    }

    _preorder(nodo, lista) {
        if (nodo !== null) {
            lista.push(nodo.dato);
            this._preorder(nodo.izq, lista);
            this._preorder(nodo.der, lista);
        }
    }

    // Postorder: Izquierda -> Derecha -> Raíz
    postorder() {
        let resultado = [];
        this._postorder(this.raiz, resultado);
        console.log("Postorder:", resultado.join(" "));
    }

    _postorder(nodo, lista) {
        if (nodo !== null) {
            this._postorder(nodo.izq, lista);
            this._postorder(nodo.der, lista);
            lista.push(nodo.dato);
        }
    }

    // --- Altura y Tamaño ---
    
    height() {
        let h = this._calcularAltura(this.raiz);
        console.log(`Altura del árbol: ${h}`);
        return h;
    }

    _calcularAltura(nodo) {
        if (nodo === null) {
            return 0;
        }
        let altIzq = this._calcularAltura(nodo.izq);
        let altDer = this._calcularAltura(nodo.der);
        // Retornamos la mayor altura + 1 (por el nodo actual)
        return Math.max(altIzq, altDer) + 1;
    }

    size() {
        let cantidad = this._contarNodos(this.raiz);
        console.log(`Número de nodos: ${cantidad}`);
        return cantidad;
    }

    _contarNodos(nodo) {
        if (nodo === null) {
            return 0;
        }
        return 1 + this._contarNodos(nodo.izq) + this._contarNodos(nodo.der);
    }

    // --- Exportar ---
    export_inorder(nombreArchivo) {
        let datos = [];
        this._inorder(this.raiz, datos);
        
        try {
            // Guardamos el array unido por espacios
            fs.writeFileSync(nombreArchivo, datos.join(" "));
            console.log(`> Archivo '${nombreArchivo}' guardado con éxito.`);
        } catch (error) {
            console.log("> Error al guardar archivo:", error);
        }
    }
}

// ==========================================
// Interfaz de Consola (Menú Principal)
// ==========================================
const miArbol = new BST();

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

console.log("=== Gestor de Árbol Binario de Búsqueda ===");
console.log("Escribe 'help' para ver la lista de comandos.\n");

function iniciarConsola() {
    rl.question('BST> ', (linea) => {
        // Convertimos la entrada en array. Ej: "insert 10" -> ["insert", "10"]
        let partes = linea.trim().split(/\s+/);
        let comando = partes[0].toLowerCase();
        let valor = parseInt(partes[1]);

        // Medimos el tiempo (Requisito: complejidad temporal)
        console.time("TiempoEjecucion");

        switch (comando) {
            case 'insert':
                if (!isNaN(valor)) {
                    miArbol.insert(valor);
                } else {
                    console.log("Error: Debes ingresar un número válido. Ej: insert 45");
                }
                break;

            case 'search':
                if (!isNaN(valor)) {
                    miArbol.search(valor);
                } else {
                    console.log("Error: Debes ingresar un número. Ej: search 20");
                }
                break;

            case 'delete':
                if (!isNaN(valor)) {
                    miArbol.delete(valor);
                    console.log("> Operación de eliminación completada.");
                } else {
                    console.log("Error: Debes ingresar un número. Ej: delete 90");
                }
                break;

            case 'inorder':
                miArbol.inorder();
                break;

            case 'preorder':
                miArbol.preorder();
                break;

            case 'postorder':
                miArbol.postorder();
                break;

            case 'height':
                miArbol.height();
                break;

            case 'size':
                miArbol.size();
                break;

            case 'export':
                // Si el usuario no pone nombre, usamos 'salida.txt'
                let nombre = partes[1];
                if (!nombre) {
                    nombre = 'salida.txt';
                }
                miArbol.export_inorder(nombre);
                break;

            case 'help':
                console.log(`
                --- Comandos Disponibles ---
                insert <num>   : Insertar un número al árbol
                search <num>   : Buscar un número y ver su ruta
                delete <num>   : Eliminar un número del árbol
                inorder        : Mostrar recorrido Inorden
                preorder       : Mostrar recorrido Preorden
                postorder      : Mostrar recorrido Postorden
                height         : Ver la altura del árbol
                size           : Ver el número total de nodos
                export <file>  : Guardar recorrido en archivo
                exit           : Salir del programa
                `);
                break;

            case 'exit':
                console.log("Saliendo del programa...");
                console.timeEnd("TiempoEjecucion");
                rl.close();
                return; // Importante para detener el bucle

            default:
                if (comando !== '') {
                    console.log("Comando desconocido. Escribe 'help' para ayuda.");
                }
                break;
        }

        console.timeEnd("TiempoEjecucion");
        iniciarConsola(); // Volvemos a llamar a la función para pedir otro comando
    });
}

// Iniciamos la aplicación
iniciarConsola();