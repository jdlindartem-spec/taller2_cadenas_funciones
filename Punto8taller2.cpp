#include <iostream>

using namespace std;

void collatz(int a)
{
    long long resultado;
    long long pasos = 0;
    long long valor = 0;
    long long pasosmax = 0;
    long long vmax = 0;


    for (long long i = 1; i <= a; i++)
    {
        resultado = i;
        pasos = 0;
        int vmax_local = i;

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

            if (resultado > vmax_local)
            {
                vmax_local = resultado;
            }
        }

        if (pasos > pasosmax)
        {
            pasosmax = pasos;
            valor = i;
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