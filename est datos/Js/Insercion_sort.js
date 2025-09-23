let arr = [32,1,42,5,6,65];

function insercion(arr){
    for(let i = 1 ; i < arr.length ; i++){
        let temp = arr[i];
        let j = i-1;

        while(j>=0 && temp < arr[j]){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = temp
    }
    return arr;
}

alert("El contenido del arreglo desordenado es: " + arr)
let ordenado = insercion(arr);
alert("El contenido del arreglo ordenado es: " + ordenado)