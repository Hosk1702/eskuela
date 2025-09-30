#include <iostream>

using namespace std;
int detectar_billete(int op){
    int b1000,b500,b200,b100,b50,b20;
    switch (op){
    case 1:
        cout << "ingrese la cantidad de billetes de $1000: \n";
        cin >> b1000;
        return 1000* b1000;
    case 2:
        cout << "ingrese la cantidad de billetes de $500: \n";
        cin >> b500;
        return 500 * b500;
    case 3:
        cout << "ingrese la cantidad de billetes de $200: \n";
        cin >> b200;
        return 200 * b200;
    case 4:
        cout << "ingrese la cantidad de billetes de $100: \n";
        cin >> b100;
        return 100 * b100;
    case 5:
        cout << "ingrese la cantidad de billetes de $50: \n";
        cin >> b50;
        return 50 * b50;
    case 6:
        cout << "ingrese la cantidad de billetes de $20: \n";
        cin >> b20;
        return 20 * b20;

    }
}

int detectar_monedas(int op){
    int m1,m2,m5,m10;
    float m50;
    switch (op){
    case 1:
        cout << "ingrese la cantidad de monedas de $0.50: \n";
        cin >> m50;
        return 0.50 * m50;
    case 2:
        cout << "ingrese la cantidad de monedas de $1: \n";
        cin >> m1;
        return 1 * m1;
    case 3:
        cout << "ingrese la cantidad de monedas de $2: \n";
        cin >> m2;
        return 2 * m2;
    case 4:
        cout << "ingrese la cantidad de monedas de $5: \n";
        cin >> m5;
        return 5 * m5;
    case 5:
        cout << "ingrese la cantidad de monedas de $10: \n";
        cin >> m10;
        return 10 * m10;
    }
}

int convertir_divisa(int op, float dinero){
    if (op==1){
        cout << "La cantidad " << dinero <<" en dolares es: \n" << (dinero/18.36);
    } else {
        cout << "La cantidad " << dinero <<" en euros es: \n" << (dinero/21.54);
    }
}
int main()
{
    int total_billetes{0},again {0};
    float total_monedas{0};

    do{
    cout << "Que billete desea ingresar?" << endl;
    cout << "1.$1000 \n" << "2.$500 \n" << "3.$200 \n" << "4.$100 \n" << "5.$50 \n" << "6.$20 \n";
    int op_billetes{0};
    cin >> op_billetes;

    total_billetes = total_billetes + detectar_billete(op_billetes);

    cout << "Desesa ingresar otro billete? (1.Si, 2.No) \n";
    cin >> again;
    } while(again == 1);

    cout << "TOTAL DE BILLETES: " << total_billetes << '\n';

     do{
    cout << "Que moneda desea ingresar?" << endl;
    cout << "1.$0.50 \n" << "2.$1 \n" << "3.$2 \n" << "4.$5 \n" << "5.$10 \n";
    int op_monedas{0};
    cin >> op_monedas;

    total_monedas = total_monedas + detectar_monedas(op_monedas);

    cout << "Desesa ingresar otra moneda? (1.Si, 2.No) \n";
    cin >> again;
    } while(again == 1);

    float total_dinero{total_billetes + total_monedas};

    cout << "TOTAL DE BILLETES: " << total_billetes << '\n';
    cout << "TOTAL DE MONEDAS: " << total_monedas << '\n';
    cout << "TOTAL:" << total_dinero << '\n';

    cout << "Desea convertir a alguna divisa? (1.Si, 2.No) \n";
    int op_convertir;
    cin >> op_convertir;
    if(op_convertir == 1){
        cout << "A que divisa desea convertir? (1.Dolar, 2.Euro) \n";
        int op_divisa;
        cin >> op_divisa;
    } else {
        cout << "Gracias por usar el programa!!";
    }
    return 0;
}
