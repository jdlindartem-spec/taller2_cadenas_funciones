#include <iostream>
#include <cctype> // clasificar o modificar caracteres individuales, como isalpha() para verificar si un carácter es alfabético, isdigit() para verificar si es un dígito, ispunct() para verificar si es un símbolo de puntuación, etc.
#include <string>

using namespace std;

void verPassw(string c) //con void le estás indicando al compilador que la función realiza una tarea, pero NO devuelve ningún valor al finalizar.
{ // dice el void a fin de la funcion si la contra es valida solo con hacer la tarea.
    bool largo = false;
    bool mayus = false;
    bool minus = false;
    bool digit = false;
    bool simbol = false;
/*que empiezan en false. Funcionan como "interruptores" o banderas: cada una cambiará a true únicamente 
si el programa encuentra la característica correspondiente en la contraseña.*/

    if (c.length() >= 8)
    {
        largo = true;
    }else{
        cout << "- Contener minimo 8 caracteres." << endl;
    }

    for (int i = 0; i < c.length() ; i++)
    {
        if (isalpha(c[i])) // isalpha() verifica si el carácter es alfabético (letra). Si lo es, entra en este bloque.
        {
            if (isupper(c[i])) // isupper() verifica si el carácter es una letra mayúscula. Si lo es, cambia la bandera mayus a true.
            {
                mayus = true;
            }else
            {
                minus = true;
            }
        }else if (isdigit(c[i])) // isdigit() verifica si el carácter es un dígito. Si lo es, cambia la bandera digit a true.
        {
            digit = true;
        }else if (ispunct(c[i])) // ispunct() verifica si el carácter es un símbolo de puntuación. Si lo es, cambia la bandera simbol a true.
        {
            simbol = true;
        }
    }
   
    if (!mayus) 
    {
        cout << "- Contener al menos una mayuscula." << endl;
    }
    if (!minus) 
    {
        cout << "- Contener al menos una minuscula." << endl;
    }
    if (!digit) 
    {
        cout << "- Falta un digito al menos." << endl;
    }
    if (!simbol) 
    {
        cout << "- Contener al menos un simbolo." << endl;
    } 
    if (largo && mayus && minus && digit && simbol)
    {
        cout << "Contrasena valida." << endl;
    } else 
    {
        cout << "Contrasena invalida." << endl;
    }
}


int main ()
{
    string password;
    getline(cin, password);
    verPassw(password);

    return 0;
}