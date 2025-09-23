def selection(arr):
    for i in range(0, len(arr)):
        peque = i
        for j in range(i+1, len(arr)):
            if arr[peque] > arr[j]:
                peque = j
        arr[i], arr[peque] = arr[peque], arr[i]
        printarr(arr)

def printarr(arr):
    for i in range(len(arr)):
        print(arr[i], end = " ")

    print('\n')

arr = [70,15,2,51,60,32]

print("Arreglo sin ordenar")
printarr(arr)
selection(arr)
print("\nArreglo ordenado")
printarr(arr)