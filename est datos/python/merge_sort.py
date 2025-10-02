def merge(a,l,m,r):
    a1 = m - l + 1 #tamaño del primer sub array
    a2 = r - m #tamaño del segundo sub array
    L = [0] * (a1) # arrays temporales
    R = [0] * (a2)

    #copiar los datos a los arrays temporales L y R
    for j in range(0,a1):
        L[j] = a[l + j]
    for k in range(0,a2):
        R[k] = a[m+1+k]
    
    i=0 #indice del primer sub array
    j=0 #indice del segundo sub array
    k=l #indice inicial del subarray mezclado

    while i < a1 and j<a2: #recorrer ambos arrays
        if L[i] <= R[j]:   #comparar los elementos de ambos arrays
            a[k] = L[i]    #copiar el elemento mas pequeño del array orignial
            i = i + 1       #incrementar el indice del primer array
        else:   # si el elemento del segundo array es mas pequeño
            a[k] = R[j] #copiar el elemento al array original
            j = j+1 # incrementar el indice del segundo array
        k=k+1 #incrementar el indice del array original
    #copiar los elementos restantes de L[] en caso de haber alguno
    while i < a1:
        a[k] = L[i] #copiar el elemento al array
        i = i+1
        k = k+1
     #copiar los elementos restantes de R[] en caso de haber alguno
    while i < a2:
        a[k] = R[i] #copiar el elemento al array
        j = j+1
        k = k+1

def mergesort(a,l,r):
    if l < r:
        #evita el desbordamiento para valores grandes del arreglo
        m = l + (r-l)//2
        #ordenar la primera y segunda mitad del arreglo
        mergesort(a,l,m)
        mergesort(a,m+1,r)
        merge(a,l,m,r) #mezclar las dos mitades
#divide el arreglo en dos mitades, las ordena y luego las mezcla
#codigo para probar la funcionalidad de mergesort

a = [39,28,44,11,53,21,1,5,12,3]
s = len(a)
print("Antes de ordenar el arreglo: ")
for j in range(s):
    print("%d" % a[j], end=" ")
mergesort(a,0,s-1)
print("\nDespues de ordenar el arreglo: ")
for j in range(s):
    print("%d" % a[j], end=" ")