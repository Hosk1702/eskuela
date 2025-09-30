#include <iostream>

using namespace std;

int fibonacci(int n){
    if(n <= 1){
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

int main(int argc, char const *argv[])
{
    int num;
    cout << "Ingrese la cantidad de numeros que desea ver de la sucesion: \n";
    cin >> num;

    for (int i=0; i < num;i++){
        cout << fibonacci(i) << " ";
    }
    return 0;
}
