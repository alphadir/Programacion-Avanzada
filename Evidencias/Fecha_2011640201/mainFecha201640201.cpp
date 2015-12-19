#include <cstdlib>
#include <iostream>
#include "Fecha2011640201.h"

using namespace std;

int main(int argc, char *argv[])
{
    //Indstanciar un objeto de la clase Fecha
    Fecha F(2,10,2015);
    //cout << F.nombre_del_dia() << "\n";
    cout<< F <<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
