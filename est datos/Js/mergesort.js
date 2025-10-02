/**
 * Función para mezclar dos sub-arrays ordenados.
 *
 * @param {Array<number>} a El array principal a modificar.
 * @param {number} l Índice inicial del primer sub-array.
 * @param {number} m Índice medio (final del primer sub-array).
 * @param {number} r Índice final del segundo sub-array.
 */
function merge(a, l, m, r) {
    let a1 = m - l + 1; // tamaño del primer sub array (Left)
    let a2 = r - m;     // tamaño del segundo sub array (Right)

    // Crear arrays temporales (usando Array.prototype.slice para copiar)
    let L = new Array(a1);
    let R = new Array(a2);

    // copiar los datos a los arrays temporales L y R
    for (let i = 0; i < a1; i++) {
        L[i] = a[l + i];
    }
    for (let j = 0; j < a2; j++) {
        R[j] = a[m + 1 + j];
    }

    let i = 0; // indice del primer sub array (L)
    let j = 0; // indice del segundo sub array (R)
    let k = l; // indice inicial del subarray mezclado (a)

    // recorrer ambos arrays y mezclar
    while (i < a1 && j < a2) {
        if (L[i] <= R[j]) { // comparar los elementos
            a[k] = L[i];
            i++;
        } else {            
            a[k] = R[j];    
            j++;      
        }
        k++; 
    }

    // copiar los elementos restantes de L[]
    while (i < a1) {
        a[k] = L[i]; 
        i++;
        k++;
    }

    // copiar los elementos restantes de R[]
    while (j < a2) { 
        a[k] = R[j]; 
        j++;
        k++;
    }
}


function mergesort(a, l, r) {
    if (l < r) {
        // calcular el punto medio
        let m = Math.floor(l + (r - l) / 2);

        // ordenar la primera y segunda mitad del arreglo
        mergesort(a, l, m);
        mergesort(a, m + 1, r);

        // mezclar las dos mitades
        merge(a, l, m, r); 
    }
}

// --- Código para probar la funcionalidad de mergesort y mostrar el alert ---

let a = [39, 28, 44, 11, 53, 21, 1, 5, 12, 3];
let s = a.length;

console.log("Antes de ordenar el arreglo:", a.join(" "));


alert("Array Original: " + a);

mergesort(a,0,s - 1)

alert("Array Ordenado: " + a);
