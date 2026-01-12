#include "unidad1.h"
#include "utils.h"
#include <iostream>
#include <cstdlib>
#include <cctype>

using namespace std;

void unidad1::Menu_unidad_1(){
    int opcion{0};
    do{
        system("cls"); // Limpia pantalla
        cout << "\n========================================" << endl;
        cout << "            MENU UNIDAD 1              " << endl;
        cout << "========================================" << endl;
        cout << "1. Practica No. 1" << endl;
        cout << "2. Practica No. 2" << endl;
        cout << "3. Actividad No. 3" << endl;
        cout << "4. Actividad No. 4" << endl;
        cout << "5. Actividad No. 5" << endl;
        cout << "6. Actividad No. 6" << endl;
        cout << "0. Regresar al Menu Principal" << endl;
        cout << "========================================" << endl;
        opcion = pedirOpcion(0,7);

        switch (opcion)
        {
        case 1:
            act1();
            break;
        case 2:
            practica2();
            break;
        case 3:
            actividad3();
            break;
        case 4:
            act4();
            break;
        case 5:
            act5();
            break;
        case 6:
            act6();
            break;
        default:
            break;
        }


    }while (opcion != 0);

}

void unidad1::act6(){
        int ca = 0,ce = 0,ci = 0,co = 0,cu = 0 ;
    string palabra;
    
    cout << "=== RECORRIDO DE STRINGS ===" << endl;
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
}

void unidad1::act5(){
    int num;
    cout << "=== CALCULADORA DE FIBONACCI ===" << endl;
    cout << "Ingrese la cantidad de numeros que desea ver de la sucesion: \n";
    cin >> num;

    for (int i=0; i < num;i++){
        cout << act5_fib(i) << " ";
    }
}

int unidad1::act5_fib(int n){
    if(n <= 1){
        return n;
    }
    return act5_fib(n-1) + act5_fib(n-2);
}

void unidad1::act4(){
    int ancho, alto;
    cout << "DIBUJAR UN RECTANGULO DE X Y Y DIMENSIONES" << endl;
    cout << "Ingrese el ancho del rectangulo: ";
    cin >> ancho;
    cout << "Ingrese el alto del rectangulo: ";
    cin >> alto;
    a4_drawline(ancho);
    a4_drawlat(ancho, alto);
    a4_drawline(ancho);
    system("pause");
}

// --- Métodos Auxiliares de Practica 4 ---

void unidad1::a4_drawline(int ancho){
    for (int i = 0; i < ancho; i++){
        cout << "*";
    }
    cout << endl;
}

void unidad1::a4_drawlat(int ancho, int alto){
    for (int i = 0; i < alto -2; i++){
        cout << "*";
        for (int j = 0; j < ancho -2; j++){
            cout << " ";
        }
        cout << "*" << endl;
    }
}

void unidad1::actividad3() {
    double imce;
    int continuar;
    string ap1, ap2, name;
    float estatura, peso;

    do {
        system("cls");
        cout << "=== CALCULADORA DE IMC ===" << endl;
        
        // Limpiamos el buffer antes de pedir strings para evitar saltos
        cin.ignore(); 
        
        cout << "Ingrese su primer apellido: ";
        getline(cin, ap1); // Usamos getline para leer apellidos compuestos si los hay
        cout << "Ingrese su segundo apellido: ";
        getline(cin, ap2);
        cout << "Ingrese su primer nombre: ";
        getline(cin, name);

        cout << "Ingrese su estatura en metros (ej: 1.76): ";
        cin >> estatura;
        cout << "Ingrese su peso corporal en kg (ej 87.5): ";
        cin >> peso;

        // Validación básica para evitar división por cero
        if (estatura <= 0) {
            cout << "La estatura debe ser mayor a 0." << endl;
        } else {
            imce = peso / (estatura * estatura);

            cout << "\n-----------------------------------" << endl;
            cout << "Paciente: " << ap1 << ' ' << ap2 << ' ' << name << endl;
            cout << "IMC Calculado: " << imce << endl;
            
            if (imce < 18.5) {
                cout << "Diagnostico: Tienes BAJO PESO." << endl;
            } else if (imce >= 18.5 && imce < 25) {
                cout << "Diagnostico: Tienes PESO NORMAL." << endl;
            } else if (imce >= 25 && imce < 30) {
                cout << "Diagnostico: Tienes SOBREPESO." << endl;
            } else {
                cout << "Diagnostico: Tienes OBESIDAD." << endl;
            }
            cout << "-----------------------------------" << endl;
        }

        cout << "\n? Desea hacer otra consulta?" << endl;
        cout << "1. SI" << endl;
        cout << "2. NO" << endl;
        // Reutilizamos tu logica de validacion con pedirOpcion
        continuar = pedirOpcion(1, 2);

    } while (continuar == 1);
}

void unidad1::practica2() {
    int opcion;
    do {
        system("cls");
        cout << "\n--- PRACTICA 2: CONDICIONALES ---" << endl;
        cout << "1. Par o impar" << endl;
        cout << "2. Dia de la semana" << endl;
        cout << "3. Mes del anio" << endl;
        cout << "4. Positivo o negativo" << endl;
        cout << "5. Mayor que 100?" << endl;
        cout << "6. Letra vocal?" << endl;
        cout << "7. Suma de numeros" << endl;
        cout << "8. Multiplicacion de numeros" << endl;
        cout << "0. Regresar" << endl; // Cambié 9 por 0 para ser consistente

        opcion = pedirOpcion(0, 8); // Usamos tu función utils para validar del 0 al 8

        switch (opcion) {
            case 1: p2_par_impar(); break;
            case 2: p2_dia_semana(); break;
            case 3: p2_meses(); break;
            case 4: p2_positivo_negativo(); break;
            case 5: p2_mayor_100(); break;
            case 6: p2_letra(); break;
            case 7: p2_suma_numeros(); break;
            case 8: p2_mul_numeros(); break;
            case 0: cout << "Regresando al menu de unidad..." << endl; break;
        }
        if(opcion != 0) system("pause"); // Pausa para ver el resultado antes de limpiar
    } while (opcion != 0);
}

// --- Métodos Auxiliares de Practica 2 ---

void unidad1::p2_par_impar(){
    cout << "\n[Par o Impar] Ingrese un numero: ";
    int num;
    cin >> num;
    if (num % 2 != 0) cout << "El numero " << num << " es impar." << endl;
    else cout << "El numero " << num << " es par." << endl;
}

void unidad1::p2_dia_semana(){
    cout << "\n[Dia de la Semana]" << endl;
    // Usamos pedirOpcion para validar automáticamente entre 1 y 7
    int dia = pedirOpcion(1, 7); 

    switch (dia) {
        case 1: cout << "Lunes" << endl; break;
        case 2: cout << "Martes" << endl; break;
        case 3: cout << "Miercoles" << endl; break;
        case 4: cout << "Jueves" << endl; break;
        case 5: cout << "Viernes" << endl; break;
        case 6: cout << "Sabado" << endl; break;
        case 7: cout << "Domingo" << endl; break;
    }
}

void unidad1::p2_meses(){
    cout << "\n[Meses del Anio]" << endl;
    int mes = pedirOpcion(1, 12); // Validación automática

    switch (mes) {
        case 1: cout << "Enero" << endl; break;
        case 2: cout << "Febrero" << endl; break;
        case 3: cout << "Marzo" << endl; break;
        case 4: cout << "Abril" << endl; break;
        case 5: cout << "Mayo" << endl; break;
        case 6: cout << "Junio" << endl; break;
        case 7: cout << "Julio" << endl; break;
        case 8: cout << "Agosto" << endl; break;
        case 9: cout << "Septiembre" << endl; break;
        case 10: cout << "Octubre" << endl; break;
        case 11: cout << "Noviembre" << endl; break;
        case 12: cout << "Diciembre" << endl; break;
    }
}

void unidad1::p2_positivo_negativo(){
    cout << "\n[Positivo o Negativo] Ingrese un numero: ";
    int num;
    cin >> num;
    if (num < 0) cout << "Es negativo." << endl;
    else cout << "Es positivo." << endl;
}

void unidad1::p2_mayor_100(){
    cout << "\n[Mayor que 100] Ingrese un numero: ";
    int num;
    cin >> num;
    if (num > 100) cout << "Es mayor que 100." << endl;
    else cout << "Es menor o igual a 100." << endl;
}

void unidad1::p2_letra(){
    cout << "\n[Vocal o Consonante] Ingrese una letra: ";
    char letra;
    cin >> letra;
    letra = tolower(letra); // Convertir a minuscula para facilitar comparacion
    if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u'){
        cout << "Es una vocal." << endl;
    } else {
        cout << "No es una vocal." << endl;
    }
}

void unidad1::p2_suma_numeros(){
    int n1, n2, n3;
    cout << "\n[Verificar Suma]" << endl;
    cout << "Ingrese numero 1: "; cin >> n1;
    cout << "Ingrese numero 2: "; cin >> n2;
    cout << "Ingrese numero 3 (resultado esperado): "; cin >> n3;

    if (n3 == (n1 + n2)) cout << "Correcto: " << n3 << " = " << n1 << " + " << n2 << endl;
    else cout << "Incorrecto: " << n3 << " != " << n1 << " + " << n2 << endl;
}

void unidad1::p2_mul_numeros(){
    int n1, n2, n3;
    cout << "\n[Verificar Multiplicacion]" << endl;
    cout << "Ingrese numero 1: "; cin >> n1;
    cout << "Ingrese numero 2: "; cin >> n2;
    cout << "Ingrese numero 3 (resultado esperado): "; cin >> n3;

    if (n3 == (n1 * n2)) cout << "Correcto: " << n3 << " = " << n1 << " * " << n2 << endl;
    else cout << "Incorrecto: " << n3 << " != " << n1 << " * " << n2 << endl;
}

void unidad1::act1(){
    cout << "Actividad 1 de la unidad 1" << endl;
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
    }
    else
    {
        // si es valida pide los numeros
        int num1, num2;
        cout << "Ingresa el primer numero: " << endl;
        cin >> num1;
        cout << "Ingresa el segundo numero: " << endl;
        cin >> num2;
        int result{0};
        switch (op) //switch para determinar la operacion a realizar
        {
        case '+': // suma
            result=num1 + num2;
            break;
        case '-': // resta
            result=num1 - num2;
            break;
        case '*': // multiplicacion
            result=num1 * num2;
            break;
        case '/': // division
            if (num2 == 0) // verifica que no se divida entre 0
            {
                cout << "No se puede dividir entre 0" << endl;
                result = 0;
            }
            else // si no es 0 realiza la division
            {
                result=num1 / num2;
            }
        default: 
            break;
        }
        cout << "El resultado es: " << result << endl;
        cout << "------------------------" << endl;
        // pregunta si desea realizar otra operacion
        do{
        cout << "Desea realizar otra operacion? (s/n)" << endl;
        cin >> resp;
            // verifica la respuesta
        if (resp == 'n')
        {
            cout << "Saliendo..." << endl;
        }
        else if (resp != 's')
        {
            cout << "Respuesta no valida" << endl; // si no es valida muestra mensaje de error
        }} while (resp != 's' && resp != 'n' );
    
    }
 } while (resp == 's'); // si la respuesta es si, vuelve a iniciar el ciclo
    
}
