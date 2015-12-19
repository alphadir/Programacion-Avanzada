#include <iostream>
#include <string>
#include <vector>
#include <ostream>
#include <conio.h>

using namespace std;
void MainMenu();
void CompraMenu();
void AnadirMenu();
void ResumenMenu();

void CompraMenu(){
     char chr=0;
     while(chr!=27){
          fflush(stdin);
          system("cls");
          cout<<" ------------------------------------------"<<endl;
          cout<<"|  CENTRO DE TAQILLA/ Comprar Boleto       |"<<endl;
          cout<<" ------------------------------------------"<<endl;
          cout<<"\n\n\n"<<endl;
          for(int i;i<Loc.Neventos;i++){
               cout<<"\t    "<<i<<") "<<Loc.NombEvento[i]<<"\n"<<endl;
          }
          cout<<"\n\n\n"<<endl;
          cout<<"\t\t  ESC) Atras"<<endl;
          chr=getch();
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
     char chr=0;
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
          cout<<"\n\n\n\n\n\n\t\t\t\tby TSR SilverRank."<<endl;
          chr=getch();
          
          if(chr=='a'){CompraMenu(); break;}
          else if(chr=='A'){CompraMenu(); break;}
          else if(chr=='b'){AnadirMenu(); break;}
          else if(chr=='B'){AnadirMenu(); break;}
          else if(chr=='c'){ResumenMenu(); break;}
          else if(chr=='C'){ResumenMenu(); break;}
     } 
}
