#include <iostream>
#include <limits>
#include <cctype>
using namespace std;

int main(int argc, char const *argv[])
{
    int encontrado{0};
    int dato;
    int pos1{0};
    int pos2{0};
    int pos3{0};
        

    int matriz[3][3][3];
    

   
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++)
        {
            for(int k = 0; k<3;k++){
                
                matriz[i][j][k] = rand() % 10 + 1; 
            }
        }
    }

    cout << "Se llenó la matriz de números random del 1 al 10.\n";

  
    do {
        cout << "Ingrese el valor que desea buscar (1-10): \n";
        cin >> dato;

        
        if (cin.fail()){
            cout << "Error: Por favor, ingrese un número entero.\n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            continue;
        } 
        
        
        encontrado = 0; 
        
       
        for (int i = 0; i < 3 && encontrado == 0; i++) {
            for (int j = 0; j < 3 && encontrado == 0; j++)
            {
                for(int k = 0; k<3;k++){
                    if (matriz[i][j][k] == dato){
                        pos1 = i;
                        pos2 = j;
                        pos3 = k;
                        encontrado = 1;
                        break;
                    } 
                }
            }
        }
        
        if (encontrado == 0) {
            cout << "El dato " << dato << " no se encuentra dentro de la matriz. Intente de nuevo.\n";
        }
        
    } while(encontrado == 0);

   
    if (encontrado == 1){
        cout << "¡Éxito! Su dato " << dato << " se encuentra en la posición: [" << pos1 <<"][" << pos2 <<"]["<< pos3 << "]\n";
    } 
    
    
    return 0;
}
