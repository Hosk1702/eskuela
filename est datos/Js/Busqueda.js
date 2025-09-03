function busqueda(arr, dato,tam){
    for (let i = 0; i<tam ; i++){
        if (arr[i] == dato){
            return i;
        }
    }
    return -1;

}

let tam = parseInt(prompt("Ingrese el tamaño del arreglo"));

let arr = new Array(tam);

for (let i = 0 ; i<tam ; i++){
    arr[i] = Math.floor(Math.random()*100)+1;
}

alert("El arreglo es: " + arr);

alert("Se lleno el arreglo de numeros random entre 1 y 100");

let j;

do {
    let dato = prompt("Ingrese el numero a buscar en el arreglo: ");
    let resultado = busqueda(arr,dato,tam);

    if (resultado != -1){
        alert("El numero " + dato + " se encuentra en la posicion " + (resultado+1))
    } else {
        alert("El numero " + dato + " no se encuentra en el arreglo")
    }

    j = parseInt(prompt("Desea buscar otro numero? 1.Si 2.No"));

}while (j==1)

    alert("Gracias por usar el programa");