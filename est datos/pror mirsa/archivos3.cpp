#include<iostream>
#include<conio.h>
#include<fstream>

using namespace std;

struct persona
{
    string nombre;
    int edad;
};



int main(){
    persona paciente;
    string text;
    char tecla;

    do{
        system("cls");
        cout << "Nombre del paciente: ";
        getline(cin,paciente.nombre);
        cout << "Edad: ";
        cin >> paciente.edad;
        cin.ignore();

        ofstream patientfile("./archivos/patient.txt",ios::app);
        if(patientfile.is_open()){
            patientfile << paciente.nombre << "," << paciente.edad << endl;
            patientfile.close();
            cout << "Paciente guardado correctamente. \n";
        }else{
            cout << "No se puede guardar el archivo txt. \n";

        }
        cout << "\nPresione ESC para salir o cualquier otra tecla para continuar.";
        tecla = _getch();
    }while(tecla!=27);

    system("cls");
    ifstream read_patientfile("./archivos/patient.txt");

    while(getline(read_patientfile, text)){
        cout << text << endl;
    }

    read_patientfile.close();
    return 0;
}