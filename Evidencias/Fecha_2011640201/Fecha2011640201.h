#ifndef _FECHA_
#define _FECHA_
#include <fstream>
using std::ostream;

class Fecha{
      int dia;
      int mes;
      int anio;

      public: 
           Fecha(int d, int m, int a);
           char *nombre_del_dia();/* "Lunes", "Martes", etc. */
           friend ostream& operator<<(ostream& out, Fecha& f);
};

#endif 
