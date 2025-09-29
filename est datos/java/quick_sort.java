public class quick_sort {
public static void imprimir(int arr[], int tam){
    for (int i = 0; i< tam; i++){
        System.out.print(arr[i] + " ");
    }

}

public static void cambiar(int arr[], int j, int k){
    int temp = arr[j];
    arr[j] = arr[k];
    arr[k] = temp;
}

public static int particion(int arr[],int l, int h){
    int pivote = arr[h];
    int j = l-1;

    for(int k = l; k < h ; k++){
        if(arr[k] <= pivote){
            j+=1;
            cambiar(arr, j, k);
        }

    }
    cambiar(arr, j+1, h);
    return j+1;
}

public static void quicksort(int arr[],int l, int h){
    if (l<h){
        int pivote = particion(arr, l, h);
        quicksort(arr, l, pivote - 1);
        quicksort(arr, pivote+1 , h);
    }
}
public static void main(String[] args) {
 int arr[] = {10,8,9,7,1,5};
 int tam = arr.length;
 
 System.out.println("Arreglo antes del ordenamiento:");
 imprimir(arr,tam);
 quicksort(arr, 0, tam-1);
 System.out.println("\nArreglo despues del ordenamiento:");
 imprimir(arr, tam);
}

    
}