using namespace std;

class Boleto{   
  public:
    vector<double> consecutivos;
    vector<int> vendidos;
    vector<int> disponibles;
    int Neventos;
    
    void AddEvento(int dispo, int vend, double folio){
      disponibles.push_back(dispo);   
      vendidos.push_back(vend);  
      consecutivos.push_back(folio);  
    }
    
    void SetEvento(int event, int dispo, int vend, double folio){
      disponibles[event]=dispo;   
      vendidos[event]=vend;  
      consecutivos[event]=folio;  
    }
    
    int NumDEventos(){
      Neventos=disponibles.size();
      return Neventos;
    }
};
