#include <iostream>
#include <vector>
#include <string>
#include <sstream> // Para unir el arreglo en un string para imprimir

// Función para imprimir el vector (similar a join en Python/JS)
std::string joinVector(const std::vector<float>& arr) {
    std::ostringstream oss;
    for (size_t i = 0; i < arr.size(); ++i) {
        oss << arr[i];
        if (i < arr.size() - 1) {
            oss << ", ";
        }
    }
    return oss.str();
}

// Función de ordenamiento por inserción
void insertionSort(std::vector<float>& bukt) {
    for (int j = 1; j < bukt.size(); ++j) { // Iterar desde el segundo elemento
        float val = bukt[j]; // Elemento actual a insertar
        int k = j - 1; // Índice del elemento anterior
        // Mover elementos mayores hacia la derecha
        while (k >= 0 && bukt[k] > val) {
            bukt[k + 1] = bukt[k]; // Desplazar elemento
            k -= 1; // Mover al siguiente elemento a la izquierda
        }
        bukt[k + 1] = val; // Insertar el elemento en su posición correcta
    }
}

// Función principal de ordenamiento bucket
void bucketSort(std::vector<float>& inputArr) {
    int s = inputArr.size(); // Número de buckets
    // Crear lista de buckets vacíos
    std::vector<std::vector<float>> bucketArr(s);

    // Colocar cada elemento en su bucket correspondiente
    for (float j : inputArr) { // Iterar sobre cada elemento del arreglo
        int bi = static_cast<int>(s * j); // Índice del bucket
        // Asegurar que el índice no se salga (en caso de que j sea 1.0)
        if (bi == s) {
            bi = s - 1;
        }
        bucketArr[bi].push_back(j); // Añadir elemento al bucket
    }

    // Ordenar cada bucket individualmente
    for (auto& bukt : bucketArr) { // Iterar sobre cada bucket
        insertionSort(bukt); // Ordenar el bucket
    }

    // Concatenar todos los buckets ordenados en el arreglo original
    int idx = 0; // Índice para el arreglo original
    for (const auto& bukt : bucketArr) { // Iterar sobre cada bucket
        for (float j : bukt) { // Iterar sobre cada elemento del bucket
            inputArr[idx] = j; // Colocar elemento en el arreglo original
            idx += 1; // Mover al siguiente índice
        }
    }
}

// Ejemplo de uso
int main() {
    std::vector<float> inputArr = {0.77f, 0.16f, 0.38f, 0.25f, 0.71f, 0.93f, 0.22f, 0.11f, 0.24f, 0.67f};
    
    std::cout << "Arreglo antes de ordenar:" << std::endl;
    std::cout << joinVector(inputArr) << std::endl;
    
    bucketSort(inputArr);
    
    std::cout << "Arreglo después de ordenar:" << std::endl;
    std::cout << joinVector(inputArr) << std::endl;
    
    return 0;
}