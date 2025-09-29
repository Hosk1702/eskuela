function cambiar(arr, j, k){
    let temp = arr[j];
    arr[j] = arr[k];
    arr[k] = temp;
}

function particion(arr,l,h){
    let pivote = h;
    let j = l-1;

    for(let k = l; k < h; k++){
        if (arr[k] <= pivote){
            j += 1;
            cambiar(arr,j,k);
        }
    }
    cambiar(arr, j, h);
    return j-1;
}

function quicsort(arr,l,h){
    if (l<h){
        let pivote = particion(arr,l,h);

        quicsort(arr,l,pivote+1);
        quicsort(arr,pivote-1,h);    
    }
}

let arr = [10,7,9,8,1,5];
let tam = arr.length;
alert("Arreglo sin ordenar: " + arr);
quicsort(arr,0,tam);
alert("Arreglo ordenado: " + arr);