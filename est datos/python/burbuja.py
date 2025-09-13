import random

tam = int(input("Ingrese el tamaño del arreglo: "))

arreglo = []

for i in range(tam):
    arreglo.append(random.randint(1, 100))

print("Arreglo original:", arreglo)

swapped = True
while swapped:
    swapped = False
    for i in range(1, len(arreglo)):
        if arreglo[i - 1] > arreglo[i]:
            arreglo[i - 1], arreglo[i] = arreglo[i], arreglo[i - 1]
            swapped = True

print("Arreglo ordenado:", arreglo)