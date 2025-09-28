#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(int argc, char const *argv[])
{   
    int ca = 0,ce = 0,ci = 0,co = 0,cu = 0 ;
    string palabra;
    cout << "Ingrese una palabra: " << '\n';
    getline(cin >> ws, palabra);

    for (char c : palabra)
    {
        c = (char)tolower(c);
        switch (c)
        {
        case 'a':
            ca += 1;
            break;
        case 'e':
            ce += 1;
            break;
        case 'i':
            ci += 1;
            break;
        case 'o':
            co += 1;
            break;
        case 'u':
            cu += 1;
            break;
        default:
            break;
        }
    }

    cout << "Total de letras: " << palabra.length() << '\n';
    cout << "Total de vocales: " << (ca+ce+ci+co+cu) << '\n';
    cout << "Letras A:" << ca << '\n';
    cout << "Letras E:" << ce << '\n';
    cout << "Letras I:" << ci << '\n';
    cout << "Letras O:" << co << '\n';
    cout << "Letras U:" << cu << '\n';
    return 0;
}
