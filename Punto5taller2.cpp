#include <iostream>
#include <string> // Permite usar el tipo de dato string para almacenar texto.
#include <cctype>
// Incluye funciones de manipulación de caracteres, como tolower() para convertir a minúsculas.

using namespace std; //Evita tener que escribir std:: antes de cada objeto estándar como cout o cin.

int main()
{
    string frase;
    cout << "Ingrese una frase: ";
    getline(cin, frase); 
    // Permite leer una línea completa de texto, incluyendo espacios, y almacenarla en la variable 'frase'.
    for (char& c : frase) 
    /*
    Recorre cada carácter de la frase de uno en uno. El símbolo & (referencia) significa que 
    modificaremos el carácter original directamente dentro de la variable frase.
     */
    {
     c = static_cast<char>(tolower(static_cast<unsigned char>(c))); 
    /*Convierte cada carácter a minúscula usando tolower() para 
    asegurar que la comparación sea insensible a mayúsculas y minúsculas.*/
    }
    
    bool esPalin = true; // Creamos una bandera (interruptor) booleana que parte asumiendo que la frase sí es un palíndromo, hasta que se demuestre lo contrario.

    for (int i = 0, k = frase.length() - 1; i < k; i++, k--)
    // i empieza en 0, k empieza en la ultima y se comparan al mismo tiempo hasta encontrar error o ser iguales.
    {
        for (; i < k && frase[i] == ' '; i++)
        {
        }

        for (; i < k && frase[k] == ' '; k--)
        {
        }
        /*Primer bucle interno: Si el carácter en la posición i es un espacio (' '), avanza i hacia la 
        derecha ignorándolo (sin hacer nada dentro de las llaves).
        Segundo bucle interno: Si el carácter en la posición k es un espacio (' '), retrocede k hacia la 
        izquierda ignorándolo.*/

        if (i < k && frase[i] != frase[k])
        // Compara los caracteres limpios de espacios. Si las letras no coinciden...
        {
            esPalin = false; // Cambia la bandera a falso porque ya no es un palíndromo.
            break;
        }
    }

    if (esPalin){
        cout << "Es palindromo.";

    }else 
        cout << "No es palindromo.";

    return 0;

}