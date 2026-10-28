#include <iostream>

using namespace std;

int factorial(int n)
{
    
    int fact = 1;
    while (n > 0)
    {
        fact *= n;
        n=n-1;
    }
    return fact;
}

int main()
{
    cout << "hola pascal:" << "\n" << endl;
    int maxfilas, fila, columna, valor;
    cout << "Ingrese el numero de filas para el triángulo de Pascal: ";
    cin >> maxfilas;
    for(fila=0; fila < maxfilas; fila++)
    {
        for(columna=0; columna <= fila; columna++)
        {
            valor = factorial(fila) / (factorial(columna) * factorial(fila - columna));
            cout << "(" << fila << " , "<<  columna << ") = " << valor << "";
        }
        cout << endl;
    }
}