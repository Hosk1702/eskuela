#include <iostream>
#include <string>


using namespace std;
int main(int argc, char const *argv[])
{
    double imce;
    int continuar;
    cout << "CALCULADORA DE IMC \n";
    do{
    cout << "Ingrese su primer apellido: \n";
    string ap1,ap2,name;
    cin >> ap1;
    cout << "Ingrese su segundo apellido: \n";
    cin >> ap2;
    cout << "Ingrese su primer nombre: \n";
    cin >> name;

    cout << "Ingrese su estatura: (ej: 1.76) \n";
    float estatura,peso;
    cin >> estatura;
    cout << "Ingrese su peso corporal: (ej 87.5) \n";
    cin >> peso;

    imce = peso/(estatura*estatura);

    cout << "Paciente: " << ap1 << ' ' << ap2 << ' ' << name << '\n' ;
    if (imce < 18.5){
        cout << "Tu imc es de " << imce << "\n Tienes bajo peso.";
    } else if (imce >= 18.5 && imce < 25){
        cout << "Tu imc es de " << imce << "\n Tienes peso normal.";
    } else if (imce >= 25 && imce <30){
        cout << "Tu imc es de " << imce << "\n Tienes sobre peso.";
    } else {
        cout << "Tu imc es de " << imce << "\n Tienes obesidad.";
    }

    do{
    cout << "Desea hacer otra consulta? (1.SI. 2.NO.)";
    cin >> continuar;
        if (continuar != 1 && continuar !=2){
            cout << "Ingrese una opcion valida";
        }

    }while (continuar != 1 && continuar != 2);



    } while(continuar == 1);
    return 0;
}


