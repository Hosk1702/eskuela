print("ingresa la cantidad de elementos:")
elementos = int(input())

arr = []

print ("llena el arreglo con ", elementos, "cosas!")
for i in range(elementos):
    print ("ingrese el elemento numero ", i + 1, ":")
    cosa = input()
    
    arr.append(cosa)
    
print ("Los elementos del arreglo son:  ")
print(arr)