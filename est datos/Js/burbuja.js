let tam = prompt("Ingrese el tamaño del arreglo: ");
let arr = new Array(tam);

for (let i = 0; i < tam; i++) {
  arr[i] = Math.floor(Math.random() * 100);
}

alert("Arreglo original: " + arr);

let swapped = true;

while (swapped == true) {
    swapped = false;
    for (let i=0; i < tam-1; i++) {
        if (arr[i]> arr[i+1]){
            let temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
            swapped = true;
        }
    }
}

alert("Arreglo ordenado: " + arr);