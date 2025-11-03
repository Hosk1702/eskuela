function countingSort(arr, exp1) {
    let n = arr.length;
    let output = new Array(n).fill(0); 
    let count = new Array(10).fill(0); 

    for (let i = 0; i < n; i++) {
        let index = Math.floor(arr[i] / exp1);
        count[index % 10]++;
    }

    for (let i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (let i = n - 1; i >= 0; i--) {
        let index = Math.floor(arr[i] / exp1);
        output[count[index % 10] - 1] = arr[i];
        count[index % 10]--;
    }

    for (let i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

function radixSort(arr) {
    if (arr.length === 0) return;

    let max1 = Math.max(...arr);

    for (let exp = 1; Math.floor(max1 / exp) > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

let arr = [10, 34, 21, 45, 78, 12, 90, 34];
console.log("Antes de ordenar:", arr);
radixSort(arr);
console.log("Despues de ordenar:", arr);