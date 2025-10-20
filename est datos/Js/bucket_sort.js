function insertionSort(bukt) {
    // Función de ordenamiento por inserción
    for (let j = 1; j < bukt.length; j++) { // Iterar desde el segundo elemento
        let val = bukt[j]; // Elemento actual a insertar
        let k = j - 1; // Índice del elemento anterior
        // Mover elementos mayores hacia la derecha
        while (k >= 0 && bukt[k] > val) {
            bukt[k + 1] = bukt[k]; // Desplazar elemento
            k -= 1; // Mover al siguiente elemento a la izquierda
        }
        bukt[k + 1] = val; // Insertar el elemento en su posición correcta
    }
}

function bucketSort(inputArr) {
    // Función principal de ordenamiento bucket
    let s = inputArr.length; // Número de buckets
    // Crear lista de buckets vacíos
    let bucketArr = Array.from({ length: s }, () => []);

    // Colocar cada elemento en su bucket correspondiente
    for (let j of inputArr) { // Iterar sobre cada elemento del arreglo
        let bi = Math.floor(s * j); // Índice del bucket
        bucketArr[bi].push(j); // Añadir elemento al bucket
    }

    // Ordenar cada bucket individualmente
    for (let bukt of bucketArr) { // Iterar sobre cada bucket
        insertionSort(bukt); // Ordenar el bucket
    }

    // Concatenar todos los buckets ordenados en el arreglo original
    let idx = 0; // Índice para el arreglo original
    for (let bukt of bucketArr) { // Iterar sobre cada bucket
        for (let j of bukt) { // Iterar sobre cada elemento del bucket
            inputArr[idx] = j; // Colocar elemento en el arreglo original
            idx += 1; // Mover al siguiente índice
        }
    }
}

// Ejemplo de uso
let inputArr = [0.77, 0.16, 0.38, 0.25, 0.71, 0.93, 0.22, 0.11, 0.24, 0.67];
alert("Arreglo antes de ordenar:\n" + inputArr.join(", "));

bucketSort(inputArr);

alert("Arreglo después de ordenar:\n" + inputArr.join(", "));