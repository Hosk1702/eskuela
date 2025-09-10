#include <iostream>

using namespace std;

int operaciones(int num1,int num2, char op){
    int result;
    switch (op)
    {
    case '+':
        result=num1 + num2;
        return result;
        break;
    case '-':
        result=num1 - num2;
        return result;
        break;
    case '*':
        result=num1 * num2;
        return result;
        break;
    case '/':
        if (num2 == 0)
        {
            cout << "No se puede dividir entre 0" << endl;
            return 0;
        }
        else
        {
            result=num1 / num2;
            return result;
        }
    default:
        break;
    }



}

int main(int argc, char const *argv[])
{
    char op, resp;

    do
    {
        cout << "------------------------" << endl;
        cout << "Ingresa la opracion a realizar: " << endl << "Suma (+)" << endl << "Resta (-)" << endl << "Multiplicacion (*)" << endl << "Division (/)" << endl << "Salir (s)" << endl;
    cin >> op;
    
    if (op != '+' && op != '-' && op != '*' && op != '/' && op != 's')
    {
        cout << "Operacion no valida" << endl;
    }
    else if (op == 's')
    {
        cout << "Saliendo..." << endl;
        return 0;
    }
    else
    {
        int num1, num2;
        cout << "Ingresa el primer numero: " << endl;
        cin >> num1;
        cout << "Ingresa el segundo numero: " << endl;
        cin >> num2;

        int result = operaciones(num1, num2, op);
        if (result != 0)
        {
            cout << "El resultado es: " << result << endl;
        }
    }
    
        cout << "------------------------" << endl;
        do{
        cout << "Desea realizar otra operacion? (s/n)" << endl;
        cin >> resp;

        if (resp == 'n')
        {
            cout << "Saliendo..." << endl;
            return 0;
        }
        else if (resp != 's')
        {
            cout << "Respuesta no valida" << endl;
        }} while (resp != 's' && resp != 'n' );
    
    } while (resp == 's');
    
    return 0;
}
