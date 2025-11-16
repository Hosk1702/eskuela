import sys

class Nodo:
    def __init__(self, data):
        self.data = data
        self.siguiente = None
        self.anterior = None

class ListaDobleEnlazada:
    def __init__(self):
        self.head = None

    def begininsert(self):
        try:
            item = int(input('\nIngrese valor\n'))
            puntero = Nodo(item)
        except ValueError:
            print("Entrada inválida.")
            return
        except MemoryError:
            # Equivalente a la comprobación de OVERFLOW de malloc
            print("\nOVERFLOW")
            return

        puntero.siguiente = self.head
        puntero.anterior = None
        if self.head is not None:
            self.head.anterior = puntero
        self.head = puntero
        print("\nNodo insertado")

    def lastinsert(self):
        try:
            item = int(input('\nIngrese valor?\n'))
            puntero = Nodo(item)
        except ValueError:
            print("Entrada inválida.")
            return
        except MemoryError:
            print("\nOVERFLOW")
            return

        if self.head is None:
            puntero.siguiente = None
            puntero.anterior = None
            self.head = puntero
            print("\nNodo insertado")
        else:
            temp = self.head
            while temp.siguiente is not None:
                temp = temp.siguiente
            temp.siguiente = puntero
            puntero.anterior = temp
            puntero.siguiente = None
            print("\nNodo insertado")

    def randominsert(self):
        try:
            item = int(input('\nIntroduzca el valor del elemento: '))
            loc = int(input('\nIntroduce la ubicación (índice 0) después de la cual deseas insertar: '))
            puntero = Nodo(item)
        except ValueError:
            print("Entrada inválida.")
            return
        except MemoryError:
            print("\nOVERFLOW")
            return
            
        temp = self.head

        for i in range(loc):
            if temp is None:
                print("\nNo se puede insertar (ubicación fuera de rango)")
                return
            temp = temp.siguiente

        if temp is None: # Caso especial si loc=0 y lista vacía
             if self.head is None:
                 self.head = puntero
                 print("\nNodo insertado (en cabeza)")
                 return
             print("\nNo se puede insertar (ubicación fuera de rango)")
             return

        puntero.siguiente = temp.siguiente
        puntero.anterior = temp
        if temp.siguiente is not None:
            temp.siguiente.anterior = puntero
        temp.siguiente = puntero
        print("\nNodo insertado")

    def begin_delete(self):
        if self.head is None:
            print("\nLa lista está vacía\n")
        else:
            puntero = self.head
            self.head = puntero.siguiente
            if self.head is not None:
                self.head.anterior = None
            # El recolector de basura de Python se encarga de 'puntero'
            print("\nNodo eliminado desde el principio ...\n")

    def last_delete(self):
        if self.head is None:
            print("\nLa lista está vacía")
        elif self.head.siguiente is None:
            self.head = None
            print("\nSolo se eliminó un nodo de la lista ...\n")
        else:
            puntero = self.head
            while puntero.siguiente is not None:
                puntero = puntero.siguiente
            puntero.anterior.siguiente = None
            print("\nNodo eliminado del último ...\n")

    def random_delete(self):
        try:
            loc = int(input('\nIntroduzca la ubicación (índice 0) del nodo a eliminar.\n'))
        except ValueError:
            print("Entrada inválida.")
            return

        if loc == 0:
            self.begin_delete()
            return

        puntero = self.head
        for i in range(loc):
            if puntero is None:
                print("\nNo se puede eliminar (ubicación fuera de rango)")
                return
            puntero = puntero.siguiente

        if puntero is None:
            print("\nNo se puede eliminar (ubicación fuera de rango)")
            return

        # puntero es el nodo a eliminar
        puntero.anterior.siguiente = puntero.siguiente
        if puntero.siguiente is not None:
            puntero.siguiente.anterior = puntero.anterior
        print(f"\nNodo eliminado {loc}")

    def search(self):
        if self.head is None:
            print("\nLista vacía\n")
            return

        try:
            item = int(input('\nIntroduce el elemento que deseas buscar?\n'))
        except ValueError:
            print("Entrada inválida.")
            return

        i = 0
        flag = False
        puntero = self.head

        while puntero is not None:
            if puntero.data == item:
                print(f"Elemento encontrado en la ubicación {i + 1}")
                flag = True
                break
            i += 1
            puntero = puntero.siguiente

        if not flag:
            print("Elemento no encontrado\n")

    def display(self):
        puntero = self.head
        if puntero is None:
            print("Nada que imprimir")
        else:
            print("\nimprimiendo valores . . . .\n")
            while puntero is not None:
                print(puntero.data)
                puntero = puntero.siguiente

# --- Función Principal (Main) ---
if __name__ == "__main__":
    lista = ListaDobleEnlazada()
    choice = 0

    while choice != 9:
        print("\n\n*********Menú principal*********\n")
        print("\nElige una opción de la siguiente lista ...\n")
        print("===============================================\n")
        print("\n1. Insertar al principio\n2. Insertar al final\n3. Insertar en ubicación\n4. Eliminar del principio\n" +
              "5. Eliminar desde el último\n6. Eliminar nodo en ubicación especificada\n7. Buscar un elemento\n8. Mostrar\n9. Salir\n")
        print("\nIngrese su opción?\n")

        try:
            choice = int(input())
        except ValueError:
            print("Introduzca una opción válida..")
            continue

        if choice == 1:
            lista.begininsert()
        elif choice == 2:
            lista.lastinsert()
        elif choice == 3:
            lista.randominsert()
        elif choice == 4:
            lista.begin_delete()
        elif choice == 5:
            lista.last_delete()
        elif choice == 6:
            lista.random_delete()
        elif choice == 7:
            lista.search()
        elif choice == 8:
            lista.display()
        elif choice == 9:
            print("Saliendo...")
            sys.exit(0)
        else:
            print("Introduzca una opción válida..")