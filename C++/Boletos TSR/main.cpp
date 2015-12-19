#include <iostream>
#include <string>
#include <vector>
#include <ostream>
#include <conio.h>
#include "UPIITA.h"
//#include "Menus.h"

using namespace std;

void preset_eventos();
void MainMenu();
void CompraMenu();
void AnadirMenu();
void ResumenMenu();
UPIITA Loc;
int MAX;

int main(){
  preset_eventos();
  MainMenu();
  
  return 0;
}//end main()

void preset_eventos(){
          
     string PRENOMB1="Eleccion de H. comite del CTT";
     string PRENOMB2="Citas x Ayuda";
     double PREFOLIO[]={100000,20000};
     int PREDISP[]={100,700};
     int PREVEND[]={0,0};
     
     Loc.AddEvento(PREDISP[0], PREVEND[0], PREFOLIO[0]);
     Loc.AddEvento(PREDISP[1], PREVEND[1], PREFOLIO[1]);
     Loc.AddNombEvento(PRENOMB1);
     Loc.AddNombEvento(PRENOMB2); 
     MAX=Loc.NumDEventos();
}

void CompraMenu(){
     char chr=0,slc;
     int sel;
     while(chr!=27){
          fflush(stdin);
          system("cls");
          cout<<" ------------------------------------------"<<endl;
          cout<<"|  CENTRO DE TAQILLA/ Comprar Boleto       |"<<endl;
          cout<<" ------------------------------------------"<<endl;
          cout<<"\n\n\n"<<endl;
          for(int i=0;i<MAX;i++){
               slc='a'+i;
               cout<<"\t"<<slc<<") "<<Loc.NombEvento[i]<<"\n"<<endl;
          }
          cout<<"\n\n\n"<<endl;
          cout<<"\t\t  ESC) Atras"<<endl;
          chr=getch();
          
          sel=chr-'a';
          if(sel<MAX){Loc.VentaEvento(sel);}
          else;
          
     }
     MainMenu();
}

void AnadirMenu(){
     char chr=0;
     while(chr!=27){
          fflush(stdin);
          system("cls");
          cout<<" ------------------------------------------"<<endl;
          cout<<"|  CENTRO DE TAQILLA/ Anadir Evento        |"<<endl;
          cout<<" ------------------------------------------"<<endl;
          cout<<"\n\n\n"<<endl;
          cout<<"\t\t  ESC) Atras"<<endl;
          chr=getch();
     }
     MainMenu();
}

void ResumenMenu(){
     char chr=0;
     while(chr!=27){
          fflush(stdin);
          system("cls");
          cout<<" ------------------------------------------"<<endl;
          cout<<"|  CENTRO DE TAQILLA/ Resumen              |"<<endl;
          cout<<" ------------------------------------------"<<endl;
          cout<<"\n\n\n"<<endl;
          cout<<"\t\t  ESC) Atras"<<endl;
          chr=getch();
     }
     MainMenu();
}

void MainMenu(){
     char chr=0,k=169;
     while(chr!=27){
          fflush(stdin);
          system("cls");
          cout<<" ------------------------------------------"<<endl;
          cout<<"|            CENTRO DE TAQILLA             |"<<endl;
          cout<<" ------------------------------------------"<<endl;
          cout<<"\n\n\n"<<endl;
          cout<<"\t    a) Comprar Boleto\n"<<endl;
          cout<<"\t    b) Anadir Evento\n"<<endl;
          cout<<"\t    c) Resumen/Estadistica\n\n\n\n"<<endl;
          cout<<"\t\t  ESC) Salir"<<endl;
          cout<<"\n\n\n\n\n\n\t\t\t\tby TSR SilverRank."<<k<<endl;
          chr=getch();
          
          if(chr=='a'){CompraMenu(); break;}
          else if(chr=='A'){CompraMenu(); break;}
          else if(chr=='b'){AnadirMenu(); break;}
          else if(chr=='B'){AnadirMenu(); break;}
          else if(chr=='c'){ResumenMenu(); break;}
          else if(chr=='C'){ResumenMenu(); break;}
     } 
}
