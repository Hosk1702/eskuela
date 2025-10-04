def heapify(arr,n,i):
    #arr: lista a ordenar
    #n tamaño del heap
    #i: indice de la raiz del sub arbol

    mas_grande = i
    izquierda = 2 * i + 1 #indice del hijo izquierdo
    derecha = 2 * i + 2 # indice del hijo derecho
    #si el hizo izquierdo esxiste y es mayor que la raiz
    if izquierda < n and arr[izquierda] > arr [mas_grande]:
        mas_grande = izquierda
    #si el hijo derecho existe y es mayor que la raiz
    if derecha < n and arr[derecha] > arr [mas_grande]:
        mas_grande = derecha
    #si el mayor no es la raiz, intercambiamso y seguimos ajustando recursivamente
    if mas_grande != i:
        arr[i], arr[mas_grande] = arr[mas_grande], arr[i]
        heapify(arr,n,mas_grande)

def heapsort(arr):
    n = len(arr)
    #paso 1 construir un heap maximo
    for i in range(n // 2 - 1,-1,-1):
        heapify(arr,n,i)
    #paso 2 extraer elementos uno por uno del heap
    for i in range(n-1,0,-1):
        #mover a la raiz al final
        arr[0], arr[i] = arr[i], arr[0]
        heapify(arr,i,0) #llamar a heapify en el heap reducido

#ejemplo de uso
if __name__ == "__main__":
    lista = [12,11,13,5,6,7]
    print("Array antes del ordenamiento: ", lista)
    heapsort(lista)
    print("\nArray despues del ordenamiento: ", lista)


    