#Funcion para hacer la peticion del arreglo
def  swap(a,j,k):
    a[j],a[k] = a[k],a[j]

def particion(a,l,h):
    pivote = a[h]

    j = l-1

    for k in range(l,h):
        
        if a[k] <= pivote:
            j+=1
            swap(a,j,k)
        
    swap(a,j+1,h)
    return j+1

 

def quicksort(a,l,h):
    if l < h:
        pivote = particion(a,l,h)

        quicksort(a,l,pivote-1)
        quicksort(a,pivote+1,h)

if __name__ == "__main__":
    a = [10,7,8,9,1,5]
    size = len(a)

    print("Arreglo antes del ordenamiento:")
    for v in a:
        print(v, end=" ")
    print()
    quicksort(a,0,size-1)

    print("Arreglo despues del ordenamiento:")
    for v in a:
        print(v, end=" ")