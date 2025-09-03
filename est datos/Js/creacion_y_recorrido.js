let tam = prompt("Ingrese el tamaño del arreglo:");
let arr = [tam];

alert("Vamos a llenar el arreglo");

for (let i = 0; i< tam; i++){
    let respuesta = prompt("Ingrese el valor para la posicion " + i + ": ");
    arr[i] = respuesta;
}

alert("El contenido del arreglo es: " + arr);