import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class bucketsort {

    // Función de ordenamiento por inserción
    public static void insertionSort(List<Float> bukt) {
        for (int j = 1; j < bukt.size(); j++) { // Iterar desde el segundo elemento
            float val = bukt.get(j); // Elemento actual a insertar
            int k = j - 1; // Índice del elemento anterior
            // Mover elementos mayores hacia la derecha
            while (k >= 0 && bukt.get(k) > val) {
                bukt.set(k + 1, bukt.get(k)); // Desplazar elemento
                k -= 1; // Mover al siguiente elemento a la izquierda
            }
            bukt.set(k + 1, val); // Insertar el elemento en su posición correcta
        }
    }

    // Función principal de ordenamiento bucket
    public static void bucketSort(List<Float> inputArr) {
        int s = inputArr.size(); // Número de buckets
        // Crear lista de buckets vacíos
        List<List<Float>> bucketArr = new ArrayList<>(s);
        for (int i = 0; i < s; i++) {
            bucketArr.add(new ArrayList<>());
        }

        // Colocar cada elemento en su bucket correspondiente
        for (float j : inputArr) { // Iterar sobre cada elemento del arreglo
            int bi = (int) (s * j); // Índice del bucket
            // Asegurar que el índice no se salga (en caso de que j sea 1.0)
            if (bi == s) {
                bi = s - 1;
            }
            bucketArr.get(bi).add(j); // Añadir elemento al bucket
        }

        // Ordenar cada bucket individualmente
        for (List<Float> bukt : bucketArr) { // Iterar sobre cada bucket
            insertionSort(bukt); // Ordenar el bucket
        }

        // Concatenar todos los buckets ordenados en el arreglo original
        int idx = 0; // Índice para el arreglo original
        for (List<Float> bukt : bucketArr) { // Iterar sobre cada bucket
            for (float j : bukt) { // Iterar sobre cada elemento del bucket
                inputArr.set(idx, j); // Colocar elemento en el arreglo original
                idx += 1; // Mover al siguiente índice
            }
        }
    }

    // Helper para imprimir la lista
    private static String joinList(List<Float> list) {
        return list.stream()
                   .map(String::valueOf)
                   .collect(Collectors.joining(", "));
    }

    // Ejemplo de uso
    public static void main(String[] args) {
        List<Float> inputArr = new ArrayList<>(Arrays.asList(
            0.77f, 0.16f, 0.38f, 0.25f, 0.71f, 0.93f, 0.22f, 0.11f, 0.24f, 0.67f
        ));

        System.out.println("Arreglo antes de ordenar:");
        System.out.println(joinList(inputArr));

        bucketSort(inputArr);

        System.out.println("Arreglo después de ordenar:");
        System.out.println(joinList(inputArr));
    }
}