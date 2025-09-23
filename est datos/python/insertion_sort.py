def insercion(arr):
    for i in range(1, len(arr)):
        temp = arr[i]
        j = i-1

        while j >= 0 and temp < arr[j]:
            arr[j+1] = arr[j]
            j= j-1
        arr[j+1] = temp

def printarr(arr):
    for i in range(len(arr)):
        print(arr[i], end = " ")

arr = [70,15,2,51,60,32]
print("Arreglo sin ordenar")
printarr(arr)
insercion(arr)
print("\nArreglo ordenado")
printarr(arr)