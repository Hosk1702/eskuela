
function heapify(arr, n, i) {
    let masGrande = i;
    let izquierda = 2 * i + 1; // índice del hijo izquierdo
    let derecha = 2 * i + 2;   // índice del hijo derecho

    // Si el hijo izquierdo existe y es mayor que la raíz
    if (izquierda < n && arr[izquierda] > arr[masGrande]) {
        masGrande = izquierda;
    }

    // Si el hijo derecho existe y es mayor que el más grande hasta ahora
    if (derecha < n && arr[derecha] > arr[masGrande]) {
        masGrande = derecha;
    }

    // Si el mayor no es la raíz, intercambiamos y seguimos ajustando recursivamente
    if (masGrande !== i) {
        // Intercambio (Swap) usando desestructuración (la forma moderna en JS)
        [arr[i], arr[masGrande]] = [arr[masGrande], arr[i]];
        
        heapify(arr, n, masGrande);
    }
}


function heapsort(arr) {
    let n = arr.length;

    // Paso 1: Construir un heap máximo
    // Itera desde el último nodo no hoja hacia la raíz
    for (let i = Math.floor(n / 2) - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Paso 2: Extraer elementos uno por uno del heap
    for (let i = n - 1; i > 0; i--) {
        // Mover la raíz (el elemento más grande) al final del array
        // Intercambio de arr[0] con arr[i]
        [arr[0], arr[i]] = [arr[i], arr[0]];

        // Llamar a heapify en el heap reducido (el tamaño es 'i')
        heapify(arr, i, 0);
    }
    // El array 'arr' ahora está ordenado
}

// Bloque de ejecución principal
let lista = [12, 11, 13, 5, 6, 7];

alert("Array antes del ordenamiento: " + lista)
heapsort(lista)
alert("Array despues del ordenamiento: " + lista)