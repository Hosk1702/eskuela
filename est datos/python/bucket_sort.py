def insertion_sort(bukt): # Función de ordenamiento por inserción
    for j in range(1, len(bukt)): # Iterar desde el segundo elemento
        val = bukt[j]            # Elemento actual a insertar
        k = j - 1                # Índice del elemento anterior
        while k >= 0 and bukt[k] > val: # Mover elementos mayores hacia la derecha
            bukt[k + 1] = bukt[k]     # Desplazar elemento
            k -= 1                    # Mover al siguiente elemento a la izquierda
        bukt[k + 1] = val # Insertar el elemento en su posición correcta
def bucket_sort(inputArr): # Función principal de ordenamiento bucket
    s = len(inputArr)      # Número de buckets
    bucketArr = [[] for _ in range(s)] # Crear lista de buckets vacíos
    # Colocar cada elemento en su bucket correspondiente
    for j in inputArr: # Iterar sobre cada elemento del arreglo
        bi = int(s * j) # Índice del bucket
        # Asegurar que el índice del bucket no exceda el tamaño
        bucketArr[bi].append(j) # Añadir elemento al bucket
    # Ordenar cada bucket individualmente usando ordenamiento por inserción
    for bukt in bucketArr: # Iterar sobre cada bucket
        insertion_sort(bukt) # Ordenar el bucket
    # Concatenar todos los buckets ordenados en el arreglo original
    idx = 0 # Índice para el arreglo original
    for bukt in bucketArr: # Iterar sobre cada bucket
        for j in bukt: # Iterar sobre cada elemento del bucket
            inputArr[idx] = j # Colocar elemento en el arreglo original
            idx += 1 # Mover al siguiente índice

# Ejemplo de uso
inputArr = [0.77, 0.16, 0.38, 0.25, 0.71, 0.93, 0.22, 0.11, 0.24, 0.67] # Arreglo de entrada
print("Arreglo antes de ordenar:")     # Imprimir arreglo antes de ordenar
print(", ".join(map(str, inputArr))) # Imprimir elementos del arreglo
bucket_sort(inputArr) # Llamar a la función de ordenamiento bucket
print("Arreglo después de ordenar:")   # Imprimir arreglo después de ordenar
print(", ".join(map(str, inputArr))) # Imprimir elementos del arreglo ordenado