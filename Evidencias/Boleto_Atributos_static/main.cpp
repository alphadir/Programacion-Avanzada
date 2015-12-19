#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Boleto_2011640201.h"
 
using namespace std;

Boleto::Boleto(const string e){
                     consecutivo++;
                     numdbol=consecutivo;
    evento=e;
}

/*
Como ejercicio escribir una funcion analoga a swap2
que utilice dos referencias a string y probar si funciona
de forma analoga al caso de swap2.
*/

/*
"En el laboratorio el fracaso es positivo, si siempre
haces lo que sabes que funciona eres demasiado
conservador" James Gosling
*/

const string upiita="UPIITA S.A. DE C.V.";
string evento1="Guerra de Robots";
string evento2="Eleccion de Representantes al CTCE";

/* La variable de clase (static) se debe inicializar 
   en alcance de archivo. */

string Boleto::empresa=upiita;
int Boleto::consecutivo=0;

void myswap(int a, int b){
     int tmp=a;a=b;b=tmp;
}

void swap1(int *, int *);
void swap2(int&, int&);//Usamos referencias
void swap3(string&, string&);

void mostrar_datos_boleto(Boleto *);
void mostrar_vector(vector<Boleto*>);

vector<Boleto*> VecG;
vector<Boleto*> VecE;
       
int main(int argc, char *argv[])
{
    //Boleto::empresa=upiita; //Esto se DEBE hacer en alcance de archivo!!
                              //(vease la sentencias previas a main())

    /* para llevar la cuenta de boletos emitidos */
    //Boleto::consecutivo=0;  //Esto tambien se DEBE hacerse en alcance de archivo!!
    int A1=10, B1=20;
    myswap(A1,B1); //Paso de argumentos por valor
    cout << "A1=" << A1 << ", B1=" << B1 << endl;
    //swap(A1,B1);//¿Por que esto no produce error?
    //Por que la funcion SWAP ya existe. Donde esta?
    //#include cstdlib.h
    //int tmp=A1;A1=B1;B1=tmp;
    swap1(&A1, &B1);//Paso de argumentos por referencia
    cout << "A1=" << A1 << ", B1=" << B1 << endl;
    cout << "Se restauran A1 y B1 a sus valores originales"
         << "antes de llamar a swap2()" << endl;
    int tmp=A1;A1=B1;B1=tmp;
    swap2(A1,B1);
    cout << "A1=" << A1 << ", B1=" << B1 << endl;
    string A2="Noobs";
    string B2="Hola";
    swap3(A2,B2);
    cout <<" Aqui se efectua el ejercicio 3 de la funcion swap3 "<< 
    "con variables string " <<"A2=" << A2 << ", B2=" << B2 << endl;
    
    
    
    Boleto C;
    Boleto D=Boleto();
    Boleto A(evento1);
    Boleto B(evento1);
    /*
    cout << A.consecutivo << " "
         << B.consecutivo << "\n"
         << Boleto::empresa << endl;
    cout << "Objeto A " << A.empresa << endl
         << A.evento << endl
         << A.numdbol << endl << endl;
    cout << "Objeto B " << B.empresa <<endl
         << B.evento << endl
         << B.numdbol << endl;
    */
    
    cout << B << endl;
    cout << A << endl;
    cout << D << endl;
    cout << C << endl;
    
    C.set_evento(evento1);
    Boleto *p=&D;p->set_evento(evento1);
    Boleto *ARR[4]; cout << "VecG.size()= " << VecG.size() << endl;
    ARR[0]=&C; C.set_numdbol(VecG.size()+1); VecG.push_back(&C);
    ARR[1]=&D; D.set_numdbol(VecG.size()+1); VecG.push_back(&D);
    ARR[2]=&A; A.set_numdbol(VecG.size()+1); VecG.push_back(&A);
    ARR[3]=&B; B.set_numdbol(VecG.size()+1); VecG.push_back(&B);
    
    for(int i=0; i<4; ++i)
            mostrar_datos_boleto(ARR[i]);
            
    Boleto *p1=new Boleto(evento2);
    p1->set_numdbol(VecE.size()+1); VecE.push_back(p1);
    Boleto *p2=new Boleto(evento2);
    p2->set_numdbol(VecE.size()+1); VecE.push_back(p2);
    Boleto *p3=new Boleto(evento2);
    p3->set_numdbol(VecE.size()+1); VecE.push_back(p3);
    Boleto *p4=new Boleto(evento2);
    p4->set_numdbol(VecE.size()+1); VecE.push_back(p4);
    cout << endl << "/------------------------/"
         << endl;
    mostrar_vector(VecG);
    cout << endl;
    mostrar_vector(VecE);
    cout << endl << endl;
    cout << "Cantidad total de boletos: "
         << Boleto::consecutivo << endl;
    
#ifdef _WIN32
    system("PAUSE");
#endif
    return EXIT_SUCCESS;
}//end main()

void swap1(int *a, int *b){
     int tmp=*a;*a=*b;*b=tmp;
}

void swap2(int& x, int& y){
     int tmp=x;x=y;y=tmp;
}
void swap3(string& x, string& y){
     string tmp=x;x=y;y=tmp;
}


ostream& operator<<(ostream& out, Boleto& f){
     out <<f.empresa<<" Numero de boleto: "<<f.numdbol<<" para " <<f.evento<<"\n";
     return out;     
}

void mostrar_datos_boleto(Boleto *bol){
     cout << bol->numdbol << " " << bol->evento << endl;
}

void Boleto::set_evento(string evt){
     evento=evt;
}

void Boleto::set_numdbol(int N){
     numdbol=N;
}

void mostrar_vector(vector<Boleto*> Vec){
     for(int i=0; i<Vec.size();++i)
             mostrar_datos_boleto(Vec[i]);
}
