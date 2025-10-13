class Shellsort {
    static display(arr, message) {
        let arrayContent = arr.join(" ");
        alert(message + "\n" + arrayContent);
    }

    sort(arr) {
        let size = arr.length;
        let gapsize = Math.floor(size / 2);

        while (gapsize > 0) {
            for (let j = gapsize; j < size; j++) {
                let temp = arr[j];
                let k = j;

                while (k >= gapsize && arr[k - gapsize] > temp) {
                    arr[k] = arr[k - gapsize];
                    k -= gapsize;
                }
                arr[k] = temp;
            }
            gapsize = Math.floor(gapsize / 2);
        }
        return 0;
    }
}


let arr = [12, 34, 54, 2, 3];
Shellsort.display(arr, "Arreglo antes del ordenamiento:");

let obj = new Shellsort();
obj.sort(arr);

Shellsort.display(arr, "Arreglo despues del ordenamiento:");
