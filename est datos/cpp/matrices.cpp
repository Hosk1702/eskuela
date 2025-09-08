#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    cout << "Ingrese el numero de columnas de la matriz: " << '\n';
    int columnas;
    cin >> columnas;
    cout << "Ingrese el numero de filas de la matriz: " << '\n';
    int filas;
    cin >> filas;

    int matriz[filas][columnas];

    cout << "Vamos a llenar la matriz!" << '\n';

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            cout << "Ingrese el valor para la posicion [" << i+1 << "][" << j+1 << "]: " << '\n';
            int dato;
            cin >> dato;
            matriz[i][j] = dato;
        }
        
    }

        int opcion;
    
    do
    {
        cout << "De que manera desea ver la matriz? (1 para filas y columnas, 0 para columnas y filas)" << '\n';
        cin >> opcion;

        if (opcion != 1 && opcion != 0)
        {
            cout << "Opcion no valida, intente de nuevo" << '\n';
        } else if (opcion == 1){
            for (int i = 0; i< filas ; i++){
                for (int j =0; j< columnas ; j++){
                    cout << matriz[i][j] << " ";
                }
                cout << endl;
            }
        }else if (opcion == 0){
            for (int i = 0; i< columnas ; i++){
                for (int j =0; j< filas ; j++){
                    cout << matriz[j][i] << " ";
                }
                cout << endl;
            }
        }
    } while (opcion != 1 && opcion != 0);

    cout << "Gracias por usar el programa!" << '\n';
    
    



    




    return 0;
}

