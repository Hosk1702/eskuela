function CrearMatriz(filas, columnas) {
    let matriz = new Array(filas);
    for (let i = 0; i < filas; i++) {
        matriz[i] = new Array(columnas);
    }
    return matriz;
}


let filas = parseInt(prompt("Ingrese el numero de filas:"));
let columnas = parseInt(prompt("Ingrese el numero de columnas:"));

let matriz = CrearMatriz(filas, columnas);

for (let i = 0; i < filas; i++) {
    for (let j = 0; j < columnas; j++) {

        matriz[i][j] = prompt(`Ingrese el valor para la posicion [${i+1}][${j+1}]:`);
    }

}
do{
let opcion = parseInt(prompt("De que manera quiere ver la matriz? (1: filas y columnas, 2: columnas y filas)"));
if (opcion == 1) {
    console.log("Matriz por filas y columnas:");
    for (let i = 0; i < filas; i++) {
    for (let j = 0; j < columnas; j++) {
        console.log(`matriz[${i+1}][${j+1}] = ${matriz[i][j]}`);
}}
} else if (opcion == 2) {
    console.log("Matriz por columnas y filas:");
    for (let i = 0; i < columnas; i++) {
    for (let j = 0; j < filas; j++) {
        console.log(`matriz[${j+1}][${i+1}] = ${matriz[j][i]}`);
}}
} else {
    console.log("Opcion no valida.");
}
}while (opcion != 1 && opcion != 2);


