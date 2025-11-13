#include <iostream>
#include <fstream>
using namespace std;

int main() {
  string text;  
  fstream MyFile("./archivos/filename.txt");

  MyFile << "Pokemon no es el mejor jeugo del mundo";

  ifstream MyreadFile("./archivos/filename.txt");
    
  while (getline(MyreadFile,text))
  {
    cout << text << '\n';
  }
  
  MyFile.close();
}