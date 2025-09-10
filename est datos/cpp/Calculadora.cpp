#include <iostream>

using namespace std;

int operaciones(int num1,int num2, char op){ //funcion que realiza las operaciones basicas
    int result;
    switch (op) //switch para determinar la operacion a realizar
    {
    case '+': // suma
        result=num1 + num2;
        return result;
        break;
    case '-': // resta
        result=num1 - num2;
        return result;
        break;
    case '*': // multiplicacion
        result=num1 * num2;
        return result;
        break;
    case '/': // division
        if (num2 == 0) // verifica que no se divida entre 0
        {
            cout << "No se puede dividir entre 0" << endl;
            return 0;
        }
        else // si no es 0 realiza la division
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
    char op, resp; // op es la operacion a realizar, resp es la respuesta para continuar o salir

    do
    {
        cout << "------------------------" << endl;
        // menu de operaciones
        cout << "Ingresa la opracion a realizar: " << endl << "Suma (+)" << endl << "Resta (-)" << endl << "Multiplicacion (*)" << endl << "Division (/)" << endl << "Salir (s)" << endl;
    cin >> op; // lee la operacion a realizar
    // verifica que la operacion sea valida
    if (op != '+' && op != '-' && op != '*' && op != '/' && op != 's')
    {
        cout << "Operacion no valida" << endl; // si no es valida muestra mensaje de error
    }
    else if (op == 's')
    {
        cout << "Saliendo..." << endl; // si es salir termina el programa
        return 0;
    }
    else
    {
        // si es valida pide los numeros
        int num1, num2;
        cout << "Ingresa el primer numero: " << endl;
        cin >> num1;
        cout << "Ingresa el segundo numero: " << endl;
        cin >> num2;
        // llama a la funcion operaciones y muestra el resultado
        int result = operaciones(num1, num2, op);
            cout << "El resultado es: " << result << endl;
        
    }
    
        cout << "------------------------" << endl;
        // pregunta si desea realizar otra operacion
        do{
        cout << "Desea realizar otra operacion? (s/n)" << endl;
        cin >> resp;
            // verifica la respuesta
        if (resp == 'n')
        {
            cout << "Saliendo..." << endl;
            return 0;
        }
        else if (resp != 's')
        {
            cout << "Respuesta no valida" << endl; // si no es valida muestra mensaje de error
        }} while (resp != 's' && resp != 'n' );
    
    } while (resp == 's'); // si la respuesta es si, vuelve a iniciar el ciclo
    
    return 0;
}
