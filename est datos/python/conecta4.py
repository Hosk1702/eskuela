import sys
filas = 6
columnas = 7
def crear_tablero():
    tablero = []
    for i in range (filas):
        tablero.append([' '] * columnas)
    
    return tablero


def imprimir_tablero(tablero):
    print ("------------------------------")
    print("| 1 | 2 | 3 | 4 | 5 | 6 | 7 |")
    print("------------------------------")
    for fila in tablero:
        print("| " + " | ".join(fila) + " |")
        print("------------------------------")

def buscar_ganador(tablero,player):
    for i in range(filas):
        for j in range(columnas-3):
                if all(tablero[i][j+k] == player for k in range(4)):
                    return True

    for i in range(filas-3):
        for j in range(columnas):
                if all(tablero[i+k][j] == player for k in range(4)):
                    return True
                
    for i in range(3,filas):
        for j in range(columnas-3):
                if all(tablero[i-k][j+k] == player for k in range(4)):
                    return True

    for i in range(filas-3):
        for j in range(columnas-3):
                if all(tablero[i+k][j+k] == player for k in range(4)):
                    return True




if __name__ == "__main__":
    tablero = crear_tablero()
    terminar_juego = False
    movimientos = 1
    jugador = "X"
    
    while not terminar_juego:
        imprimir_tablero(tablero)

        if (movimientos % 2 != 0):
            jugador = "X"
            num_jugador = "1"
        else:
            jugador = "O"
            num_jugador = "2"

        print("Es turno del jugador " + num_jugador + ". Ficha " + jugador)
        columna = int(input("Ingrese la columna donde va a caer su ficha: \n"))
        if columna < 1 or columna >7:
            print("Ingrese una columna valida")
            continue

        colocado = False
        for i in range (filas-1,-1,-1):
            if(tablero[i][columna-1] == ' '):
                tablero[i][columna-1] = jugador
                movimientos+=1
                colocado = True
                break
        if colocado== False:
            print("Columna llena intente con otra.")
            continue

        if buscar_ganador(tablero,jugador):
            imprimir_tablero(tablero)
            print("El jugador " + jugador + " es el ganador")

            while True:
                respuesta = str(input("Desea jugar de nuevo? (S/N)"))
                if respuesta.upper() == "S":
                    tablero = crear_tablero()
                    terminar_juego = False
                    movimientos = 1
                    break
                elif respuesta.upper() == "N":
                    terminar_juego = True
                    break
                else:
                    print("Ingrese una respuesta valioda") 
                    continue
        
    
    print("Gracias por jugar!!")






