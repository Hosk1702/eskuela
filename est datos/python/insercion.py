if __name__ == "__main__":
    arr = [34,6,123,54,12]
    print(arr)
    
    print("Ingrese un numero a insertar")
    num = int(input())
    print("Ingrese la posicion donde desea insertarlo (1 a 5)")
    pos = int(input())

    for i in range(4, pos-1, -1):
        arr[i] = arr[i-1]
    arr[pos-1] = num

    print("Arreglo despues de la insercion:")
    print(arr)


