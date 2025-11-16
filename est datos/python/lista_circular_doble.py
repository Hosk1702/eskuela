import sys

class Nodo:
    def __init__(self, data):
        self.data = data
        self.siguiente = None
        self.anterior = None

class ListaDobleCircular:
    def __init__(self):
        self.head = None
        self.tail = None

    def _leer_entero(self, mensaje):
        """Función auxiliar para leer un entero de forma segura."""
        while True:
            try:
                return int(input(mensaje))
            except ValueError:
                print("Entrada inválida. Por favor, ingrese un número.")

    def begininsert(self):
        item = self._leer_entero('\nIngrese valor\n')
        puntero = Nodo(item)
        
        if self.head is None:
            self.head = puntero
            self.tail = puntero
            puntero.siguiente = self.head
            puntero.anterior = self.tail
        else:
            puntero.siguiente = self.head
            puntero.anterior = self.tail
            self.head.anterior = puntero
            self.head = puntero
            self.tail.siguiente = self.head
        print("\nNodo insertado")

    def lastinsert(self):
        item = self._leer_entero('\nIngrese valor?\n')
        puntero = Nodo(item)

        if self.head is None:
            self.head = puntero
            self.tail = puntero
            puntero.siguiente = self.head
            puntero.anterior = self.tail
        else:
            puntero.siguiente = self.head
            puntero.anterior = self.tail
            self.head.anterior = puntero
            self.tail.siguiente = puntero
            self.tail = puntero
        print("\nNodo insertado")

    def randominsert(self):
        if self.head is None:
            print("Lista vacía, insertando al principio.")
            self.begininsert()
            return

        item = self._leer_entero('\nIntroduzca el valor del elemento: ')
        # Inserta DESPUÉS de la ubicación (índice 0)
        loc = self._leer_entero('\nIntroduce la ubicación (índice 0) después de la cual deseas insertar: ')
        puntero = Nodo(item)
        temp = self.head

        for i in range(loc):
            temp = temp.siguiente
            if temp == self.head and i < loc - 1: # Verificación de vuelta
                print("\nNo se puede insertar (ubicación fuera de rango)")
                return

        puntero.siguiente = temp.siguiente
        puntero.anterior = temp
        temp.siguiente.anterior = puntero
        temp.siguiente = puntero
        
        if temp == self.tail:
            self.tail = puntero
        print("\nNodo insertado")

    def begin_delete(self):
        if self.head is None:
            print("\nLa lista está vacía\n")
        elif self.head == self.tail: # Solo un nodo
            self.head = None
            self.tail = None
            print("\nSolo se eliminó un nodo de la lista ...\n")
        else:
            puntero = self.head
            self.head = puntero.siguiente
            self.head.anterior = self.tail
            self.tail.siguiente = self.head
            print("\nNodo eliminado desde el principio ...\n")

    def last_delete(self):
        if self.head is None:
            print("\nLa lista está vacía")
        elif self.head == self.tail: # Solo un nodo (Lógica corregida)
            self.head = None
            self.tail = None
            print("\nSolo se eliminó un nodo de la lista ...\n")
        else:
            puntero = self.tail
            self.tail = puntero.anterior
            self.tail.siguiente = self.head
            self.head.anterior = self.tail
            print("\nNodo eliminado del último ...\n")

    def random_delete(self):
        # Asumiré "Eliminar EN la ubicación loc"
        loc = self._leer_entero('\nIntroduzca la ubicación (índice 0) del nodo a eliminar.\n')

        if self.head is None:
            print("\nLa lista está vacía")
            return

        if loc == 0:
            self.begin_delete()
            return

        puntero = self.head
        for i in range(loc):
            puntero = puntero.siguiente
            if puntero == self.head:
                 print("\nNo se puede eliminar (ubicación fuera de rango)")
                 return
        
        # puntero es el nodo a eliminar
        puntero.anterior.siguiente = puntero.siguiente
        puntero.siguiente.anterior = puntero.anterior

        if puntero == self.tail: # Lógica corregida
            self.tail = puntero.anterior
        print(f"\nNodo eliminado {loc}")

    def search(self):
        if self.head is None:
            print("\nLista vacía\n")
            return

        item = self._leer_entero('\nIntroduce el elemento que deseas buscar?\n')
        i = 0
        flag = False
        puntero = self.head

        while True:
            if puntero.data == item:
                print(f"Elemento encontrado en la ubicación {i + 1}")
                flag = True
                break
            i += 1
            puntero = puntero.siguiente
            if puntero == self.head: # Termina el ciclo
                break

        if not flag:
            print("Elemento no encontrado\n")

    def display(self):
        puntero = self.head
        if puntero is None:
            print("Nada que imprimir")
        else:
            print("\nimprimiendo valores . . . .\n")
            while True:
                print(puntero.data)
                puntero = puntero.siguiente
                if puntero == self.head:
                    break

# --- Función Principal (Main) ---
if __name__ == "__main__":
    lista = ListaDobleCircular()
    choice = 0

    while choice != 9:
        print("\n\n*********Menú principal*********\n")
        print("\nElige una opción de la siguiente lista ...\n")
        print("===============================================\n")
        print("\n1. Insertar al principio\n2. Insertar al final\n3. Insertar \n4. Eliminar del principio\n" +
              "5. Eliminar desde el último\n6. Eliminar nodo en ubicación especificada\n7. Buscar un elemento\n8. Mostrar\n9. Salir\n")

        try:
            choice = int(input('\nIngrese su opción?\n'))
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