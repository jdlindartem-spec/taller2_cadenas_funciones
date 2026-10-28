#include <iostream>
#include <string>

using namespace std;

void cifradoCes(char a, string c, long long despla)
/*char a: Indica si vamos a Cifrar o Descifrar.
string c: El mensaje o frase a procesar.
long long despla: El número de posiciones que se desplazarán las letras.*/
{
    long long d = despla % 26;
    //El operador % (módulo) se utiliza para obtener el residuo de la división de despla entre 26. Esto asegura que el desplazamiento esté dentro del rango del alfabeto inglés (26 letras).
  
    if (d < 0) {
        d += 26; // Si el usuario introduce un número negativo, le suma 26 para darle la vuelta correctamente al abecedario.
    }

    if (a == 'D' || a == 'd') 
    // Si el usuario eligió descifrar, el desplazamiento se invierte restándoselo a 26 (26 - d), 
    //permitiendo deshacer el cifrado original.
    {
        d = 26 - d;
    }

    for (int i = 0; i < c.length(); i++) // Recorre cada carácter de la cadena c desde el primer carácter hasta el último índice c.length()
    {
        if (c[i] >= 'a' && c[i] <= 'z')
        {
            c[i] = 'a' + (c[i] - 'a' + d) % 26;
        // Si el carácter es una letra minúscula (entre 'a' y 'z'), se aplica la fórmula de desplazamiento para obtener la nueva letra cifrada o descifrada.
        // Convertir la letra en un número de 0 a 25, sumarle el desplazamiento d, y luego tomar el resultado módulo 26 para asegurarse de que se mantenga dentro del rango del alfabeto.
        }
             else if (c[i] >= 'A' && c[i] <= 'Z')
        {
            c[i] = 'A' + (c[i] - 'A' + d) % 26;
        }
    }
    /* lo q paso es que casa valor del abc tiene un valor numero por lo que por ejemplo al cifrar la letra
    C, nos dara D y eso se veria en codigo como C + (2+d) % 26 = posicion C + 3 osea = D, y asi 
    con todas las letras del abecedario.
    */

    cout << "Resultado: " << c << endl;
}


int main ()
{
    char tipo;
    string frase;
    long long k;

    cout << "Cifrar (C) o descifrar (D): ";
    cin >> tipo;
    cin.ignore(); // actua como un "limpiador" del buffer de entrada, eliminando cualquier carácter sobrante (como el salto de línea) que pueda interferir con la lectura de la siguiente entrada.

    if (tipo != 'C' && tipo != 'c' && tipo != 'D' && tipo != 'd')
    {
        cout << "Opcion no valida. Use C para cifrar o D para descifrar." << endl;
        return 1; // señal de advertencia de que el programa terminó con un error debido a una opción no válida.
    }
  

    cout << "Desplazamiento: ";
    cin >> k;
    cin.ignore();
   

    cout << "mensaje: ";
    getline(cin, frase);
    
    cifradoCes(tipo ,frase, k); // Llama a la función cifradoCes() pasando los parámetros tipo, frase y k para realizar el cifrado o descifrado según la elección del usuario.


    return 0;
}