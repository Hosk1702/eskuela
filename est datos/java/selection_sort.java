public class selection_sort {

    public static void imprimir(int arr[]){
        for (int i = 0; i < arr.length ; i++){
            System.out.print(arr[i] + " ");
        }
    }

    public static void seleccion(int arr[]){
         for (int i = 0; i < arr.length; i++){
            int peque = i;
            for (int j = i+1 ; j < arr.length; j++){
                if(arr[peque] > arr[j]){
                    peque = j;
                }
            }
            int temp = arr[peque];
            arr[peque] = arr[i];
            arr[i] = temp;
         }
    }

    
    

    public static void main(String[] args) {
    int arr[] = {70,15,2,51,60,32};
        
    System.out.println("El arreglo sin ordenar es: ");
    imprimir(arr);    
    seleccion(arr);
    System.out.println("\nEl arreglo ordenado es: ");
    imprimir(arr);
}
    

}
