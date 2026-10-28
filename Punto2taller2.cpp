#include <iostream> 

using namespace std; 

// Defino una funcion que me saque todos los divisores de un numero entero.
int divisoresNum (int c) 
{
    // Defino una variable que me lleve la suma de los divisores.
    int sumDivisores = 0;

    /*
    Hago un bucle for y defino adentro una variable i que es la que me va a 
    decir quienes son los divisores del numero.
    Como necesito que solo me busque los divisores menor que el, el limite superior va a ser 
    el numero restado uno y el inferior va a ser hasta que i sea igual a uno.
    el i-- para indicarle que debe ir decreciendo.
    */
    for (int i = c - 1; i >= 1; i--){
        
        //Compruebo si son divisores y si lo son, los sumo, si no, los descarto.
        if (c % i == 0)  
            sumDivisores = sumDivisores + i;

    }    
    // Le digo a la funcion que me entregue el valor de la suma. No necesito ningun dato mas.   
    return sumDivisores;
}       

int main ()
{
    // Defino las variables que guarden los numeros que pide el ejercicio.
    int a;
    int b;
    cout << "ingrese un numero a (>=1): ";
    cin >> a;
    cout << "Ingrese un numero b (>=a): ";
    cin >> b;

    // Verifico si los numeros estan bien puestos.
    if ( a > b )
    {
        cout << "Rango no permitido. El segundo numero debe ser mayor que el primero.";
    }    
    

    // Inicio los contadores que me clasifican los numeros.
    int perfectos = 0;
    int abundantes = 0;
    int deficientes = 0;


    // Creo otro bucle for con otra variable k que empiece desde a y termine en b y vaya creciendo.
    for (int k = a; k <= b; k++)
    {
        cout << k << ": ";
        
        // Creo una variable que me guarde la suma de los divisores del numero que se encuentre en el bucle.
        int sumDiv = divisoresNum(k);

        // Aqui reviso si el numero es igual a la suma de sus divisores usando la funcion que ya habiamos definido arriba.
        if (k == divisoresNum(k))
        {
            cout << "Perfecto " << "(Suma de divisores = " << sumDiv << ")" << endl;
            perfectos++;

        } 
        // Aqui reviso si el numero es mayor a la suma de sus divisores.
        else {
            if (k > divisoresNum(k)){

                cout << "Deficiente " << "(Suma de divisores = " << sumDiv << ")" << endl;
                deficientes++;

            } 
            // Aqui reviso si el numero es menor a la suma de sus divisores.
            else {

                cout << "Abundante " << "(Suma de divisores = " << sumDiv << ")" << endl;
                abundantes++;

            }


        } 

    }

    // Se imprimen los resultados de los contadores, ya que arriba en el bucle for se imprimieron los numeros y la suma de sus divisores ya.
    cout << "Perfectos: " << perfectos << ", Abundantes: " << abundantes << ", Deficientes: " << deficientes << endl;

    return 0;
    
}