import sys

class Nodo:
    def __init__(self, data):
        self.data = data
        self.siguiente = None

head = None

def begininsert():
    global head
    item = int(input("\nIngrese valor\n"))
    puntero = Nodo(item)
    puntero.siguiente = head
    head = puntero
    print("\nNodo insertado")

def lastinsert():
    global head
    item = int(input("\nIngrese valor?\n"))
    puntero = Nodo(item)
    
    if head is None:
        puntero.siguiente = None
        head = puntero
        print("\nNodo insertado")
    else:
        temp = head
        while temp.siguiente is not None:
            temp = temp.siguiente
        temp.siguiente = puntero
        puntero.siguiente = None
        print("\nNodo insertado")

def randominsert():
    global head
    item = int(input("\nIntroduzca el valor del elemento: "))
    puntero = Nodo(item)
    
    loc = int(input("\nIntroduce la ubicación después de la cual deseas insertar: "))
    
    temp = head
    for i in range(loc):
        temp = temp.siguiente
        if temp is None:
            print("\nNo se puede insertar\n")
            return
            
    puntero.siguiente = temp.siguiente
    temp.siguiente = puntero
    print("\nNodo insertado")

def begin_delete():
    global head
    if head is None:
        print("\nLa lista está vacía\n")
    else:
        puntero = head
        head = puntero.siguiente
        # El recolector de basura se encarga de 'delete'
        print("\nNodo eliminado desde el principio ...\n")

def last_delete():
    global head
    if head is None:
        print("\nLa lista está vacía")
    elif head.siguiente is None:
        head = None
        print("\nSolo se eliminó un nodo de la lista ...\n")
    else:
        puntero = head
        ptr1 = None
        while puntero.siguiente is not None:
            ptr1 = puntero
            puntero = puntero.siguiente
        ptr1.siguiente = None
        print("\nNodo eliminado del último ...\n")

def random_delete():
    global head
    ptr1 = None
    loc = int(input("\nIntroduzca la ubicación del nodo después del cual desea realizar la eliminación.\n"))
    puntero = head
    for i in range(loc):
        ptr1 = puntero
        puntero = puntero.siguiente
        if puntero is None:
            print("\nNo se puede eliminar")
            return
            
    ptr1.siguiente = puntero.siguiente
    print(f"\nNodo eliminado {loc + 1}")

def search():
    puntero = head
    i = 0
    flag = 0
    if puntero is None:
        print("\nLista vacía\n")
    else:
        item = int(input("\nIntroduce el elemento que deseas buscar?\n"))
        while puntero is not None:
            if puntero.data == item:
                print(f"Elemento encontrado en la ubicación {i + 1}")
                flag = 0
            else:
                flag = 1
            i += 1
            puntero = puntero.siguiente
            
        if flag == 1:
            print("Elemento no encontrado\n")

def display():
    puntero = head
    if puntero is None:
        print("Nada que imprimir")
    else:
        print("\nimprimiendo valores . . . .\n")
        while puntero is not None:
            print(f"\n{puntero.data}")
            puntero = puntero.siguiente

# Lógica principal (main)
if __name__ == "__main__":
    choice = 0
    while choice != 9:
        print("\n\n*********Menú principal*********\n")
        print("\nElige una opción de la siguiente lista ...\n")
        print("===============================================\n")
        print("\n1. Insertar al principio\n2. Insertar al final\n3. Insertar \n4. Eliminar del principio\n"
              + "5. Eliminar desde el último\n6. Eliminar nodo después de la ubicación especificada\n7. Buscar un elemento\n8. Mostrar\n9. Salir\n")
        print("\nIngrese su opción?\n")
        
        try:
            choice = int(input())
        except ValueError:
            print("Introduzca una opción válida..")
            continue

        if choice == 1:
            begininsert()
        elif choice == 2:
            lastinsert()
        elif choice == 3:
            randominsert()
        elif choice == 4:
            begin_delete()
        elif choice == 5:
            last_delete()
        elif choice == 6:
            random_delete()
        elif choice == 7:
            search()
        elif choice == 8:
            display()
        elif choice == 9:
            sys.exit(0)
        else:
            print("Introduzca una opción válida..")