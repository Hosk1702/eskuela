let arr = [32,1,42,5,6,65];

function seleccion(arr){
    for(let i = 0 ; i < arr.length ; i++){
        peque = i
        for(let j=i+1 ; j < arr.length ; j++ ){
            if (arr[peque] > arr[j]){
                peque = j
            } 
        }
        let temp = arr[peque]
        arr[peque] = arr [i]
        arr[i] = temp 
    }
    return arr;
}

alert("El contenido del arreglo desordenado es: " + arr)
let ordenado = seleccion(arr);
alert("El contenido del arreglo ordenado es: " + ordenado)