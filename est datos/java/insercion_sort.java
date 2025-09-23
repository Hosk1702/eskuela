
public class insercion_sort {

    public static void imprimir(int arr[]){
        for (int i = 0; i < arr.length ; i++){
            System.out.print(arr[i] + " ");
        }
    }

    public static void insercion(int arr[]){
         for (int i = 1; i < arr.length; i++){
            int temp = arr[i];
            int j= i-1;
            
            while (j>= 0 && temp < arr[j]) {
                arr[j+1] = arr[j];
                j=j-1;    
            }
            arr[j+1] = temp;
         }
    }

    
    

    public static void main(String[] args) {
    int arr[] = {70,15,2,51,60,32};
        
    System.out.println("El arreglo sin ordenar es: ");
    imprimir(arr);    
    insercion(arr);
    System.out.println("\nEl arreglo ordenado es: ");
    imprimir(arr);
}
    
}
