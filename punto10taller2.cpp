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
    cout << "Aqui esta pascal:" << "\n" << endl;
    int Nfilas, fila, columna, valor;
    cout << "Ingrese el numero de filas para el triángulo de Pascal: ";
    cin >> Nfilas;
    for(fila=0; fila < Nfilas; fila++)
    {
        for(columna=0; columna <= fila; columna++)
        // Recorre desde 0 hasta el número de la fila actual. Esto se debe a que en la fila 0 hay 1 elemento, en la fila 1 hay 2, y así sucesivamente.
        {
            valor = factorial(fila) / (factorial(columna) * factorial(fila - columna)); // formula factorial
            cout << "(" << fila << " , "<<  columna << ") = " << valor << "";
        }
        cout << endl;
    }
}