from collections import deque  # Importar deque para BFS

# Función para mostrar el padre de cada nodo
def display_parent(node, adj, parent):  # Recursivo
    if parent == 0:  # Nodo raíz
        print(f"{node} -> Root")  # Indicar que es la raíz
    else:  # Nodo no raíz
        print(f"{node} -> {parent}")  # Mostrar el padre
    for child in adj[node]:  # Recorrer los hijos
        if child != parent:  # Evitar volver al padre
            display_parent(child, adj, node)  # Llamada recursiva

# Función para mostrar los hijos de cada nodo
def display_children(root, adj):  # BFS
    q = deque([root])  # Cola para BFS
    visited = [0] * len(adj)  # Lista de visitados
    while q:  # Mientras haya nodos en la cola
        node = q.popleft()  # Sacar el nodo de la cola
        visited[node] = 1  # Marcar como visitado
        print(f"{node} -> ", end="")  # Mostrar el nodo actual
        for child in adj[node]:  # Recorrer los hijos
            if not visited[child]:  # Si no ha sido visitado
                print(f"{child} ", end="")  # Mostrar el hijo
                q.append(child)  # Añadir a la cola
        print()  # Nueva línea después de los hijos

# Función para mostrar los nodos hoja
def display_leaf(root, adj):  # BFS
    for i in range(1, len(adj)):  # Recorrer todos los nodos
        if len(adj[i]) == 1 and i != root:  # Si es hoja y no es la raíz
            print(i, end=" ")  # Mostrar el nodo hoja
    print()  # Nueva línea después de los nodos hoja

# Función para mostrar el grado de cada nodo
def display_degrees(root, adj):  # Grado = número de conexiones
    for i in range(1, len(adj)):  # Recorrer todos los nodos
        print(f"{i}: ", end="")  # Mostrar el nodo
        if i == root:  # Si es la raíz
            print(len(adj[i]))  # Mostrar grado completo
        else:  # Si no es la raíz
            print(len(adj[i]) - 1)  # Mostrar grado menos el padre

# Ejemplo de uso
if __name__ == "__main__":  # Programa principal
    N = 9  # Número de nodos
    root = 1  # Nodo raíz
    adj = [[] for _ in range(N + 1)]  # Lista de adyacencia
    
    # Definir las aristas del árbol
    edges = [(1,2), (1,3), (1,4), (2,5), (2,6), (4,7), (3,8), (8,9)]  # Lista de aristas
    for u, v in edges:  # Añadir aristas a la lista de adyacencia
        adj[u].append(v)  # Añadir arista bidireccional
        adj[v].append(u)  # Añadir arista bidireccional
        
    print("El padre de cada nodo:")  # Mostrar padres
    display_parent(root, adj, 0)  # Llamada inicial con padre 0
    
    print("Los hijos de cada nodo:")  # Mostrar hijos
    display_children(root, adj)  # Llamada inicial
    
    print("Nodos hoja del árbol:")  # Mostrar nodos hoja
    display_leaf(root, adj)  # Llamada inicial
    
    print("El grado de cada nodo:")  # Mostrar grados
    display_degrees(root, adj)  # Llamada inicial