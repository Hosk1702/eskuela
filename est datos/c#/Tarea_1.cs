int tam = 0;

Console.WriteLine("Ingresa el tamaño del arreglo: ");
string? input = Console.ReadLine();

if (!int.TryParse(input, out tam) || tam <= 0)
{
    Console.WriteLine("Por favor, ingresa un número entero válido y mayor que cero.");
    return 1;
}

dynamic[] array = new dynamic[tam];

Console.WriteLine("Ingresa los elementos del arreglo: ");

for (int i = 0; i < tam; i++)
{
    Console.WriteLine("Ingrese el elemento # " + (i + 1) + ":");
    array[i] = Console.ReadLine();
}

Console.WriteLine("Los elementos del arreglo son: ");
for (int i=0; i<tam; i++)
{
    Console.WriteLine("El elemento # " + (i + 1) + " es: " + array[i]);
}

return 0;