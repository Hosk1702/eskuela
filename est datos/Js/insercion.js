let arr = [123,45,67,89,43,12];

alert("El arreglo inicial es: " + arr);

let dato = parseInt(prompt("ingrese el numero a insertar: "));

let pos = parseInt(prompt("ingrese la posicion donde desea insertar el numero: "));

for (let i = arr.length - 1; i>=pos ; i--){
    arr[i] = arr[i-1];
    
}
arr[pos - 1] = dato;

alert("El nuevo arreglo es: " + arr);
