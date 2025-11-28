class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

front = None
rear = None

def insertar():
    global front, rear
    try:
        val = int(input("\nIngrese el elemento: "))
        new_node = Node(val)

        if front is None:
            front = rear = new_node
        else:
            rear.next = new_node
            rear = new_node
        print("\nElemento insertado correctamente.")
    except ValueError:
        print("Error: Ingrese numero válido")

def eliminar():
    global front, rear
    if front is None:
        print("\nSUBDESBORDAMIENTO (La cola esta vacia)")
        return
    
    print(f"\nElemento eliminado: {front.data}")
    
    if front == rear:
        front = rear = None
    else:
        front = front.next

def mostrar():
    global front
    if front is None:
        print("\nLa cola está vacía.")
    else:
        temp = front
        print("\nElementos en la cola:")
        while temp is not None:
            print(temp.data)
            temp = temp.next

def main():
    opcion = 0
    while opcion != 4:
        print("\n*** MENÚ COLA (LISTA ENLAZADA) ***")
        print("1. Insertar\n2. Eliminar\n3. Mostrar\n4. Salir")
        try:
            opcion = int(input("Opción: "))
        except:
            opcion = 0
            
        if opcion == 1: insertar()
        elif opcion == 2: eliminar()
        elif opcion == 3: mostrar()
        elif opcion == 4: print("Saliendo...")
        else: print("Opción inválida.")

if __name__ == "__main__":
    main()