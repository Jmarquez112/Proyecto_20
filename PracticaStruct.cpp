#include<iostream>
using namespace std;
struct Camiones {
    //Atributos
    string Matricula;
    float PesoMax;
    float ConsumoGasolina;
    float PesoActual;
    //Métodos o funciones
};
int main(){
    string control;
    Camiones listaCamiones[4];
    cout<<"Información de los caniones:\n";
    
    
    for (int x=0; x<4; x++)
    {
        cout<<"Matricula:";
        cin>>listaCamiones[x].Matricula;
        cout<<"Capacidad de carga (kg):";
        cin>>listaCamiones[x].PesoMax;
        cout<<"Consumo de gasolina (gal/km):";
        cin>>listaCamiones[x].ConsumoGasolina;
        cout<<"Ingrese carga actual (kg):";
        cin >>listaCamiones[x].PesoActual;
        cout<<"Desea registra otro camion\nSi\nNo";
        cin>>control;
        if ( control=="Si")
        {}
        else
        {
            break;
        }
    }
    
    
}