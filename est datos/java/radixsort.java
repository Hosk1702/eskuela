import java.util.Arrays;

public class radixsort {

    static void countingSort(int arr[], int exp1) {
        int n = arr.length;
        int output[] = new int[n]; 
        int count[] = new int[10]; 
        
        for (int i = 0; i < n; i++) {
            int index = arr[i] / exp1;
            count[index % 10]++;
        }

        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        for (int i = n - 1; i >= 0; i--) {
            int index = arr[i] / exp1;
            output[count[index % 10] - 1] = arr[i];
            count[index % 10]--;
        }

        for (int i = 0; i < n; i++) {
            arr[i] = output[i];
        }
    }

    static void radixSort(int arr[]) {
        if (arr.length == 0) return;
        
        int max1 = Arrays.stream(arr).max().getAsInt();

        for (int exp = 1; max1 / exp > 0; exp *= 10) {
            countingSort(arr, exp);
        }
    }

    public static void main(String[] args) {
        int arr[] = {10, 34, 21, 45, 78, 12, 90, 34};
        System.out.println("Antes de ordenar: " + Arrays.toString(arr));
        radixSort(arr);
        System.out.println("Despues de ordenar: " + Arrays.toString(arr));
    }
}