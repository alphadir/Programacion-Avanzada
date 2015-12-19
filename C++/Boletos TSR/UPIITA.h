#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <ostream>
#include "Boleto.h"

using namespace std;

class UPIITA: public Boleto{     
     public:
     vector<string> NombEvento;
    
     void AddNombEvento(string nombre){
          NombEvento.push_back(nombre);
     }
     
     void VentaEvento(int evento){
          int venta;
          string nombre;
          fflush(stdin);
          cout<<"\n\n\n"<<endl;
          cout<<"   A nombre de:\n\t";
          fflush(stdin);
          getline(cin,nombre);
          cout<<"\n   Cantidad:\n\t";
          cin>>venta;
          //getline(cin,nombre);
          cout<<"\n\n\n"<<endl;
          
          if(venta+vendidos[evento]<disponibles[evento]){
               consecutivos[evento]+=venta;
               vendidos[evento]+=venta;
               cout<<"Venta concretada con exito.\n"<<endl;
               cout<<" ------------------------------------------"<<endl;
               cout<<"  Evento:  "<<NombEvento[evento]<<endl;
               cout<<" ------------------------------------------"<<endl;
               cout<<"\n   Nombre:\n\t"<<nombre<<endl;
               cout<<"\n   Cantidad:\n\t"<<venta<<endl;
               cout<<"\n   Fecha:\n\t2/Nov/2015\n"<<endl;
               cout<<" ------------------------------------------"<<endl;
               cout<<"\n\n\n";
               system("pause");
          }
          else{
          }
     }
};

