 #include <iostream>

 using namespace std;
 void par_impar(){
    cout << "Ingrese un numero: \n";
    int num;
    cin >> num;

    int resultado;
    resultado = num % 2;

    if (resultado != 0){
        cout << "El numero " << num << " es impar. \n";
    }else {
        cout << "El numero " << num << " es par. \n";
    }
 }

 void dia_semana(){
    int dia;

    do{
    cout << "Ingrese un numero del 1 al 7 (lunes-domingo) \n";
    cin >> dia;

    switch (dia)
    {
    case 1:
        cout << "El dia " << dia << " de la semana es el lunes. \n";
        continue;
       
    case 2:
        cout << "El dia " << dia << " de la semana es el martes. \n";
        continue;
       
    case 3:
        cout << "El dia " << dia << " de la semana es el miercoles. \n";
        continue;
        
    case 4:
        cout << "El dia " << dia << " de la semana es el jueves. \n";
        continue;
    
    case 5:
        cout << "El dia " << dia << " de la semana es el viernes. \n";
        continue;
        
    case 6:
        cout << "El dia " << dia << " de la semana es el sabado. \n";
        continue;
        
    case 7:
        cout << "El dia " << dia << " de la semana es el domingo. \n";
        continue;
        
    default:
        cout << "El num " << dia << " no corresponde a un dia de la semana \n";
        
    }
    }while (dia > 7 || dia < 1 );
 }

 void meses(){
    int mes;

    do{
    cout << "Ingrese un numero del 1 al 12 (Enero-Diciembre) \n";
    cin >> mes;

    switch (mes)
    {
    case 1:
        cout << "El mes # " << mes << " es el mes de enero. \n";
        continue;
    case 2:
        cout << "El mes # " << mes << " es el mes de febrero. \n";
        continue;
    case 3:
        cout << "El mes # " << mes << " es el mes de marzo. \n";
            continue;
    case 4:
        cout << "El mes # " << mes << " es el mes de abril. \n";
        continue;
        
    case 5:
        cout << "El mes # " << mes << " es el mes de mayo. \n";
        continue;
        
    case 6:
        cout << "El mes # " << mes << " es el mes de junio. \n";
        continue;
        
    case 7:
        cout << "El mes # " << mes << " es el mes de julio. \n";
        continue;
        
    case 8:
        cout << "El mes # " << mes << " es el mes de agosto. \n";
        continue;
        
    case 9:
        cout << "El mes # " << mes << " es el mes de septiembre. \n";
        continue;
        
    case 10:
        cout << "El mes # " << mes << " es el mes de octubre. \n";
        continue;
        
    case 11:
        cout << "El mes # " << mes << " es el mes de noviembre. \n";
        continue;
        
    case 12:
        cout << "El mes # " << mes << " es el mes de diciembre. \n";
        continue;
        
    default:
        cout << "El num # " << mes << " no corresponde a un mes del año \n";
        
    }
    }while (mes > 12 || mes < 1 );
 }

 void positivo_negativo(){
    cout << "Ingrese un numero: \n";
    int num;
    cin >> num;

    if (num < 0){
        cout << "El numero " << num << " es negativo.";

    } else {
        cout << "El numero " << num << " es positivo.";
    }
 }

 void mayor_100(){
     cout << "Ingrese un numero: \n";
    int num;
    cin >> num;

    if (num > 100){
        cout << "El numero " << num << " es mayor que 100. \n";

    } else {
        cout << "El numero " << num << " es menor que 100. \n";
    }
 }

 void letra(){
    cout << "Ingrese una letra: \n";
    char letra;
    cin >> letra;
    
    if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u'){
        cout << "Tu letra es una vocal \n";
    } else {
        cout << "Tu letra no es una vocal \n";
    }
 }

 void suma_numeros(){
    int num1, num2, num3;
    cout << "Ingrese el primer numero: \n";
    cin >> num1;
    cout << "Ingrese el segundo numero: \n";
    cin >> num2;
    cout << "Ingrese el tercer numero: \n";
    cin >> num3;

    if (num3 == (num1 + num2))
    {
        cout << "felicitaciones, el tercer numero es igual a la suma de los dos primeros\n";
        cout << num3 << " = " << num1 << "+" << num2 << "\n";
    }else {
        cout << "El tercer numero no es igual a la suma de los dos primeros\n";
        cout << num3 << " != " << num1 << "+" << num2 << "\n";
    }
 }

  void mul_numeros(){
    int num1, num2, num3;
    cout << "Ingrese el primer numero: \n";
    cin >> num1;
    cout << "Ingrese el segundo numero: \n";
    cin >> num2;
    cout << "Ingrese el tercer numero: \n";
    cin >> num3;

    if (num3 == (num1 * num2))
    {
        cout << "felicitaciones, el tercer numero es igual a la multiplicacion de los dos primeros\n";
        cout << num3 << " = " << num1 << "*" << num2 << "\n";
    } else {
        cout << "El tercer numero no es igual a la multiplicacion de los dos primeros\n";
        cout << num3 << " != " << num1 << "*" << num2 << "\n";
    }
 }


 int main(int argc, char const *argv[])
 {
    int volver_a_menu;
    int opcion;

    do{ // ciclo para volver al menu principal
    do // ciclo para validar la opcion del menu
    {
    
    cout << "1. Par o impar \n";
    cout << "2. Dia de la semana \n";
    cout << "3. Mes del año \n";
    cout << "4. Positivo o negativo \n";
    cout << "5. Mayor que 100? \n";
    cout << "6. Letra vocal? \n";
    cout << "7. Suma de numeros \n";
    cout << "8. Multiplicacion de numeros \n";
    cout << "9. Salir \n";
    cin >> opcion;


    switch (opcion)
    {
    case 1:
        par_impar();
        cout << "*************************\n";
        break;;
    case 2:
        dia_semana();
        cout << "*************************\n";
        break;
    case 3:
        meses();
        cout << "*************************\n";
        break;
    case 4:
        positivo_negativo();
        cout << "*************************\n";
        break;
    case 5:
        mayor_100();
        cout << "*************************\n";
        break;
    case 6:
        letra();
        cout << "*************************\n";
        break;
    case 7:
        suma_numeros();
        cout << "*************************\n";
        break;
    case 8:
        mul_numeros();
        cout << "*************************\n";
        break;
    case 9:
        cout << "Saliendo... \n";
        break;
    default:
        cout << "Opcion no valida, intente de nuevo \n";
        cout << "*************************\n";
    }
    } while (opcion < 1 || opcion > 9);
        if (opcion == 9){
            break;
        }
        
        do{ // ciclo para validar la opcion de volver al menu
        cout << "Desea realizar otra operacion (1.SI/2.NO)? \n";
        cin >> volver_a_menu;
        
        if (volver_a_menu != 1 && volver_a_menu != 2){
            cout << "Ingrese una opcion valida (1.SI/2.NO) \n";
        } else if (volver_a_menu == 2) {
            cout << "Saliendo... \n";
            break;
        }
        }while(volver_a_menu != 1 && volver_a_menu != 2);

    } while (volver_a_menu = 1);
    return 0;
 }
 
