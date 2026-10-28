#include <iostream>
#include <string>

using namespace std;

bool formatoValido(string a)
{
    int i = 0;
    int largo = a.length();

    if (largo == 0)
    {
        return false;
    }

    while (i < largo)
    {
        if (a[i] >= '0' && a[i] <= '9')
        {
            return false;
        }

        i++;
        int contador = 0;

        while (i < largo && a[i] >= '0' && a[i] <= '9')
        {
            contador = contador * 10 + (a[i] - '0');
            i++;
        }

        if (contador == 0)
        {
            return false;
        }
    }

    return true;
}

string RLE(string a, int b)
{
    string respuesta;
    int largo = a.length();

    if (b == 1)
    {
        int i = 0;

        while (i < largo)
        {
            char caracter = a[i];
            int contador = 0;

            while (i < largo && a[i] == caracter)
            {
                contador++;
                i++;
            }

            respuesta += caracter;
            respuesta += to_string(contador);
        }
    }

    if (b == 2)
    {
        int i = 0;

        while (i < largo)
        {
            char caracter = a[i];
            i++;
            int contador = 0;

            while (i < largo && a[i] >= '0' && a[i] <= '9')
            {
                contador = contador * 10 + (a[i] - '0');
                i++;
            }

            for (int j = 0; j < contador; j++)
            {
                respuesta += caracter;
            }
        }
    }

    return respuesta;
}

int main ()
{

    int opcion;
    cout << "1. Comprimir" << endl << "2. Descomprimir" << endl << "Opcion: ";
    cin >> opcion;
    cin.ignore();

    string caracon;
    cout << "Cadena: ";
    getline(cin, caracon);

    if (opcion == 1)
    {
        cout << "Comprimida: " << RLE(caracon, opcion);
    }
    else if (opcion == 2)
    {
        if (formatoValido(caracon))
        {
            cout << "Descomprimida: " << RLE(caracon, opcion);
        }
        else
        {
            cout << "Formato comprimido invalido." << endl;
            return 1;
        }
    }
    else
    {
        cout << "Opcion no valida." << endl;
        return 1;
    }
    return 0;
}