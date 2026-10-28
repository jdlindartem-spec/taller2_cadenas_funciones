// Biblioteca estandar de C++.
#include <iostream>
// Biblioteca para usar variables de texto.
#include <string>
// Biblioteca para distinguir o modificar caracteres.
#include <cctype>

/* 
Esto lo uso para evitar escribir ::std antes de cualquier cosa, por ejemplo:
si no estuviera usandolo cada vez que quiera usar cout o cin deberia ponerle ::std asi

std::cin
 o 
std::cout 

simplemente lo hago por comodidad pero en proyectos mas largos no se recomienda.
*/

using namespace std;

// Funcion principal del codigo, todo lo que se vaya a ejecutar en el programa debe estar aqui.
int main() 
{
    /*
    Defino una variable string con el nombre palabra y uso getline para que la computadora 
    lea los espacios, y en su defecto, una frase completa.

    Porque no se usa cin en este caso? cin se detiene al primer espacio y eso
    no nos sirve. 
    */
    string palabra;
    cout << "Escribe una frase: ";
    getline(cin, palabra);

    // Declaro las variables para hacer los conteos.
    int consonante = 0;
    int vocal = 0;
    int digitos = 0;
    int espacios = 0; 
    int simbolos = 0;

    /*
    Concepto clave es que en un string cada caracter tiene su posicion desde el cero 
    hasta donde termine la frase o lo que escriba el usuario con lo cual si alguien escribe la 
    palabra "Sol" en un string llamado palabra.

    palabra[0] = S
    palabra[1] = o
    palabra [2] = l

    Y asi para cualquier largo de palabra o frase.
    */


    /*
    Hago un bucle for que empieze desde 0 y uso la funcion .length() para saber el largo 
    del string y ese es mi limite superior.
    Adentro del mismo bucle puedo declarar la variable i.
    El i++ es para decirle a la computadora que vaya subiendo de valor i desde 0 hasta el limite superior.
    */
    for (int i = 0; i < palabra.length() ; i++)
    {   
        // Este bloque hace que cada caracter se haga minuscula para no generar problemas.
        palabra[i] = static_cast<char>
        (
            tolower(static_cast<unsigned char>(palabra[i]))
        );
    

       // isdigit es una funcion que me permite saber si el carater que esta en la posicion palabra[i] es un digito.
        if (isdigit(palabra[i]))
            // Si el if es verdad se añade +1 al contador de digitos.
            digitos++;


         // isalpha permite saber si el caracter en la posicion palabra [i] es una letra.
        else if (isalpha(palabra[i]))

            // Si el caracter es una letra, este if va a comparar al caracter con cada vocal. Si coincide con una de las vocales se añade al contador de vocales y si no se da por entendido que es una consonante.
           if (palabra[i] == 'a' || palabra[i] == 'e' || palabra[i] == 'i' || palabra[i] == 'o' || palabra[i] == 'u' )
                vocal++;
           else 
                consonante++;   
                
         // isspace permite saber si el caracter en la posicion palabra[i] es un espacio.
        else if (isspace(palabra[i]))   
            espacios++;

         // ispunct permite saber si el caracter en la posicion palabra[i] es un signo de puntuacion.   
        else if (ispunct(palabra[i]))
            simbolos++;
    
    }

    // Entonces cada uno de estos lo que va a hacer es imprimir cada contador y su respectiva categoria.
    cout << "Vocales: " << vocal << endl; // El endl se usa para que la funcion cout termine la linea y pase a la siguiente.
    cout << "Consonantes: "<< consonante << endl;
    cout << "Digitos: " << digitos << endl;
    cout << "Espacios " << espacios << endl;
    cout << "Otros simbolos: " << simbolos << endl;

    // Y finalmente el return 0 es para indicarle a la computadora que el programa termino correctamente.
    return 0;

}