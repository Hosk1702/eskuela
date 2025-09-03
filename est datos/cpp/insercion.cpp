#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int arr[] = {5,8,2,6,1};

    int pos = 3;

    int dato = 10;

    for (int i = 5; i>= pos; i--){
        arr[i] = arr[i-1];
    }

    arr[pos-1] = dato;

    for (int i=0 ; i<sizeof(arr)/sizeof(arr[0]);i++){
        cout << arr[i] << endl;
    }



    return 0;
}
