import random

def buscar(arr, tam, dato):
    for i in range(tam):
        if arr[i] == dato:
            return i

    
    return -1
    
            
        

if __name__ == "__main__":
    j = 1
    print("Ingresa el tamaño del arreglo:")
    tam = int(input())

    arr = []

    for i in range(tam):
        arr.append(random.randint(1,100))

    print("Se genero el arreglo con numeros aleatorios entre 1 y 100")
    print("Arreglo generado:", arr)
    while j==1:
        print("Ingrese el numero que desea buscar:")
        dato = int(input())

        result = buscar(arr, tam, dato)

        if result != -1:
            print("El numero ", dato," se encuenra en la posicion ", (result+1))
        else :
            print("El numero ", dato," no se encuentra en el arreglo")

        print("Desea buscar otro numero? 1.Si 2.No")
        j = int(input())




        






    
