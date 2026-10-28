#include <iostream>

using namespace std;

int altura;
char caracter;

void dibujaRombo (int c, char d)
{
    int mitad = c / 2;

    for (int i = 0; i <= mitad; i++) 
    {
        for (int k = 0; k < mitad - i; k++)
        {
            cout << " ";

        }
        for (int k = 0; k < (2 * i + 1); k++)
        {
            cout << d;

        }

        cout << endl;
    }
    for (int i = mitad - 1; i >= 0; i--) 
    {
        
        for (int j = 0; j < mitad - i; j++) {
            cout << " ";
        }
        
        for (int j = 0; j < (2 * i + 1); j++) {
            cout << d;
        }
        cout << endl;
    }


}

int main()
{
    do
    {
        cout << "Ingrese la altura del rombo (entero impar positivo): ";
        cin >> altura;
        if (altura < 0 || altura % 2 == 0)
        {
            cout << "Numero invalido, intente de nuevo." << endl;
        }

    } while (altura < 0 || altura % 2 == 0);


    cout << "Ingrese el caracter con el que se hara el rombo: ";
    cin >> caracter;
    
    
    dibujaRombo(altura, caracter);

    return 0; 

}