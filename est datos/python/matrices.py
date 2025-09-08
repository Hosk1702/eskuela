print("Ingresa el numero de filas:")
filas = int(input())
print("Ingresa el numero de columnas:")
columnas = int(input())

matriz = []

for i in range(filas):
    fila = []
    for j in range(columnas):
        print("Ingresa el elemento " + "[" + str(i+1) + "][" + str(j+1) + "]" + ":")
        elemento = int(input())
        fila.append(elemento)
    matriz.append(fila)

print("De que manera quiere recorrer la matriz? (1. filas y columnas, 2. columnas y filas)")
opcion = int(input())

if opcion == 1:
    print("Recorriendo por filas:")
    for fila in matriz:
        print(fila)
elif opcion == 2:
    print("Recorriendo por columnas:")
    for j in range(columnas):
        for i in range(filas):
            print(matriz[i][j], end=' ')
        print()

print("Gracias por usar el programa.")



