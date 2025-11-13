#include <iostream>
#include <fstream>
using namespace std;

int main() {
  string text;  
  int op;
  ofstream file("./archivos/filename.txt", ios::app);

    if(!file){
        cerr << "No se pudo abrir el archivo";
    }
    do{
        cout << "Escribe los datos: ";
        getline(cin, text);
        if(text != "salir"){
            file << '\n' << text;
        }
    }while (text != "salir");
    file.close();
    
    ifstream readfile("./archivos/filename.txt");
    while (getline(readfile,text))
    {
      cout << text << '\n';
    }
    readfile.close();
}