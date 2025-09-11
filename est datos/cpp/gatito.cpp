#include <iostream>
#include <string>
using namespace std;

bool validaciones(int fila, int columna, char gatito[3][3]){
if (fila < 1 || fila > 3 || columna < 1 || columna > 3){ // verificamos si la posicion ya esta ocupada
        cout << "Posicion no valida, intente de nuevo \n";
        return true;
    }
    else if (gatito[fila-1][columna-1] != ' '){ // verificamos si la posicion es valida
        cout << "Esa posicion ya esta ocupada, intente de nuevo \n";
        return true;
    }
    else{
        return false;
    }

}

bool ganador(char gatito[3][3], char jugador){
    for (int i = 0; i < 3 ;i++){
        if (gatito[i][0] == jugador && gatito[i][1] == jugador && gatito[i][2] == jugador){ // verificamos filas
            return true;
        }
        if (gatito[0][i] == jugador && gatito[1][i] == jugador && gatito[2][i] == jugador){ // verificamos columnas
            return true;
        }
    }

    if (gatito[0][0] == jugador && gatito[1][1] == jugador && gatito[2][2] == jugador){ // verificamos diagonal hacia abajo
        return true;
    }else if(gatito[0][2] == jugador && gatito[1][1] == jugador && gatito[2][0] == jugador ){ // verificamos diagonal hacia arriba
        return true;
    }
    return false;
}

void imprimir_tablero(char gatito[3][3]){
for (int i = 0 ; i<3; i++){ // imprimimos la matriz con los limites del gatito
        for (int j = 0; j<3 ; j++){
            cout << " " << gatito[i][j] << " ";
            if (j<2){
                cout << "|";
            }
        }
        cout << endl;
        if (i<2){
        cout << "---+---+--- \n";}
    }


}


int main(int argc, char const *argv[])
{
    bool ganador_jugador1, ganador_jugador2; // variables para verificar si algun jugador ha ganado
    char gatito[3][3]; // matriz para representar el tablero del gato
    string jugar_de_nuevo; // variable para almacenar la respuesta del usuario si desea jugar de nuevo

    do{// ciclo para jugar de nuevo
    for (int i = 0; i < 3; i++) // llenamos la matriz de vacios para evitar caracteres basura
    {
        for (int j = 0; j < 3; j++)
        {
            gatito[i][j] = ' ';
        }
    }

    int movimientos{0}; // contador para llevar el control de los turnos

    cout << "Bienvenido al juego del gato \n";
    cout << "Jugador 1 es X y Jugador 2 es O \n";
    
    do{// ciclo principal del juego
    
    imprimir_tablero(gatito); // imprimimos el tablero en cada turno mediante la funcion imprimir_tablero

    movimientos = movimientos + 1;
    int turno{movimientos % 2}; // si el contador es par es el turno del jugador 2, si es impar es el turno del jugador 1
    int fila, columna;

    if (turno == 1){
        cout << "Es turno del jugador 1 (X) \n";
        cout << "Ingrese la fila donde quiere poner la X \n";
        cin >> fila;
        cout << "Ingrese la columna donde quiere poner la X \n";
        cin >> columna;

        if (validaciones(fila,columna,gatito) == true){ // verificamos si la posicion ya esta ocupada o si es valida
            movimientos = movimientos - 1;
            continue;
        }else{
            gatito[fila-1][columna-1] = 'X'; // añadimos la X en la posicion indicada
            ganador_jugador1 = ganador(gatito, 'X'); // verificamos si el jugador 1 ha ganado
        }
    } else {
        cout << "Es turno del jugador 2 (O) \n";
        cout << "Ingrese la fila donde quiere poner la O \n";
        cin >> fila;
        cout << "Ingrese la columna donde quiere poner la O \n";
        cin >> columna;

        if (validaciones(fila,columna,gatito) == true){ // verificamos si la posicion ya esta ocupada o si es valida
            movimientos = movimientos - 1;
            continue;
        }else{
            gatito[fila-1][columna-1] = 'O'; // añadimos la O en la posicion indicada
            ganador_jugador1 = ganador(gatito, 'O'); } // verificamos si el jugador 2 ha ganado
        }

    if (ganador_jugador1 == true){ // verificamos si algun jugador ha ganado o si el juego ha terminado en empate
        cout << "Felicidades jugador 1, has ganado! \n";
    } else if (ganador_jugador2 == true){
        cout << "Felicidades jugador 2, has ganado! \n";
    } else if (movimientos == 9){
        cout << "El juego ha terminado en empate! \n";
    }
}while (ganador_jugador1 == false && ganador_jugador2 == false && movimientos < 9);

    imprimir_tablero(gatito); // imprimimos el tablero final

    do{ // ciclo para validar la respuesta del usuario
    cout << "Desea jugar de nuevo? (si/no) \n";
    cin >> jugar_de_nuevo;
    if (jugar_de_nuevo != "si" | jugar_de_nuevo != "no"){ // si la respuesta no es valida, se le pide al usuario que intente de nuevo
        cout << "Respuesta no valida, intente de nuevo \n";
    }
    movimientos = 0;
    }while (jugar_de_nuevo != "si" && jugar_de_nuevo != "no");

}while (jugar_de_nuevo == "si");
    return 0;
}
