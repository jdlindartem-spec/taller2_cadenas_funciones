#include <iostream>

using namespace std;

void collatz(int a) 
// Declara una función llamada collatz que recibe un número entero a (el límite superior hasta el cual se 
// evaluará) y no retorna ningún valor (void).
{
    long long resultado;
    long long pasos = 0; //Cuenta el número de iteraciones (pasos) que le toma a un número llegar a 1.
    long long valor = 0; // Guarda el número inicial i que generó la secuencia más larga hasta el momento.
    long long pasosmax = 0; // Guarda el número máximo de pasos encontrados hasta ahora.
    long long vmax = 0;    // Guarda el valor máximo alcanzado en la secuencia de Collatz para el número que generó la secuencia más larga.

    for (long long i = 1; i <= a; i++)
    {
        resultado = i;
        pasos = 0;
        long long vmax_local = i;

        while(resultado != 1 && resultado > 0) 
        {
            if ( resultado % 2 == 0)
            {
                resultado = resultado / 2;
                pasos++;
            }else
            {
                resultado = (3 * resultado) + 1;
                pasos++;
            }

            if (resultado > vmax_local) // Comprueba si el valor actual de resultado es mayor que el valor máximo local (vmax_local) para la secuencia actual.
            {
                vmax_local = resultado;
            }
        }

        if (pasos > pasosmax)
        {
            pasosmax = pasos;
            valor = i; // Guarda qué número i generó este nuevo récord.
            vmax = vmax_local;
        }
    }

    cout << "Numero con la secuencia mas larga: " << valor << endl << "Pasos: " << pasosmax << endl << "Valor maximo alcanzado: " << vmax << endl;

}

int main() 
{
    int a;
    cout << "Ingrese N (>= 1): ";
    cin >> a;
    collatz(a);

    return 0;
}