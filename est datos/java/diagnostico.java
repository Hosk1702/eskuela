/******************************************************************************

                            Online Java Compiler.
                Code, Compile, Run and Debug java program online.
Write your code in this editor and press "Run" button to execute it.

*******************************************************************************/
import java.util.Scanner;
public class Main
{
	public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);        
		
		int[] arr = new int [10];
		
		for (int i = 0; i < 10 ; i++){
		    System.out.println("Ingrese el numero para la posicion " + (i+1) + ": " + '\n');
            int num= sc.nextInt();
            arr[i] = num;
           
		}
		
		int par = 0;
		int impar = 0;
		int prom = 0;
		
		for (int i = 0; i < 10 ; i++){
		    if ((arr[i] % 2) == 1){
		        impar += 1;
		    } else {
		        par += 1;
		    }
		    prom = prom + arr[i];
		}
		
		prom = prom/10;
		
		System.out.println("El total de numeros pares es de: " + par + '\n');
		System.out.println("El total de numeros impares es de: " + impar + '\n');
		System.out.println("El promedio de los numeros es de: " + prom + '\n');
	}
}