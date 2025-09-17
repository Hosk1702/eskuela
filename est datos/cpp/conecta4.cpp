#include <iostream>

using namespace std;

void imprimir_tablero(char tablero[6][7]){
    cout << "------------------------------" << endl;
    cout << "| 1 | 2 | 3 | 4 | 5 | 6 | 7 |" << endl;
    cout << "------------------------------" << endl;
    for (int i=0; i < 6; i++ ){
        cout << "|";
        for (int j=0 ; j <7; j++){
            cout << " " << tablero[i][j] << " |";
        }
        cout << endl;
        cout << "------------------------------" << endl;
    }


}


int main(int argc, char const *argv[])
{
    char tablero[6][7];

    for (int i=0; i < 6; i++ ){
        for (int j=0 ; j <7; j++){
            tablero[i][j] = ' ';
        }
    }

    imprimir_tablero(tablero);
    return 0;
}
