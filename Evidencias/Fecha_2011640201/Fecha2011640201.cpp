#include "Fecha2011640201.h"

Fecha::Fecha(int d, int m, int a){          //Indexamos las variables
     dia=d;
     mes=m;
     anio=a;
}
char* DIA[]={"Lunes","Martes","Miercoles","Jueves","Viernes","Sabado","Domingo"};
char* MES[]={"enero","febrero","marzo","abril","mayo","junio","julio","agosto","septiembre","octubre","noviembre","diciembre"};


void copiar(char*,char*);
int calendario(int,int,int);

char *Fecha::nombre_del_dia(){
     int I;
     
     char *R=new char[10];
     I=calendario(dia,mes,anio);
     copiar(DIA[I],R);
     return R;
}

void copiar(char *from, char *to){
     while(*from!='\0'){                                  // \0 significa fin de 'cadena de caracteres'
          *to=*from;
          from++;                                         // incremeta en 1 la localidad de memoria del apuntador FROM
          to++;                                           // incremeta en 1 la localidad de memoria del apuntador TO
     }
     *to='\0';                                             // incrementa en 1 el TO para incluir el FIN_DE_CADENA( \0 )
}

ostream& operator<<(ostream& out, Fecha& f){
     out <<f.nombre_del_dia()<<", "<<f.dia<<" de "<<MES[f.mes-1]<<" del "<<f.anio<<"\n";
     return out;     
}

////////////////////////////////////////////////////////////////

int calendario(int Tdia, int Tmes, int Tanio){
     
     int DiasMes[]={0,31,28,31,30,31,30,31,31,30,31,30,31};//...................Se crea un vector con los dias de cada mes dejando el vector[0]=0 por conveniencia
     int DiasMPas=0, i=0;                                                     //de calculos y para que los indices [XX] coincida con el mes numerico
     int NDia, Vici, Vci;
     
     Vci=Tanio%4;
     if(Vci==0){DiasMes[2]=29;}
     else;
     Vici=(Tanio-1)/4;
     
     
     while(i<Tmes){                   //........................................Se crea el ciclo WHILE para hacer la suma de los dias del año hasta antes del mes
          DiasMPas=DiasMPas+DiasMes[i];                                       //que tenemos como entrada
          i++; 
     }
     
     NDia=(DiasMPas+Vici+Tanio+Tdia+4)%7;  //..............................................Se suman los dias de meses pasados mas los dias del mes de fecha y se busca su
     return NDia;                                                             //para determinar el dia de la semana del que se referencia. Se cpmpensa con un
}                                                                             //+2 porque el dia 1/enero/2015 no fue en lunes asi que hay que compensar esos dias
