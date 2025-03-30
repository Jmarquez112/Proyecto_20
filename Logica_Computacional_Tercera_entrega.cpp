#include<iostream>

using namespace std;

int main(){
    string Placa;
    float PesoMaximo, Gasolina, PesoActual, Carga;
    int Camiones;
    cout<<"Buenos días. Bienvenido, por favor escoja una opción:\n";
    cout<<"\nSelecciona una opción"<<endl;
    int opción;
   
    do{
    cout<<"1. Registrar un camión con su matrícula, capacidad de carga, consumo de gasolina y carga actual.\n";
    cout<<"2. Consultar los datos de un camión a partir de su matrícula.\n";
    cout<<"3. Cargar un camión verificando que no se exceda su capacidad máxima.\n";
    cout<<"4. Descargar un camión reduciendo su carga actual.\n";
    cout<<"5. Determinar el camión con menor consumo de gasolina que tenga capacidad suficiente para una carga dada.\n";
    cout<<"6. Informar cuando no halla un camión disponible.\n";
    cout<<"7. Salir.\n";
    cin>>opción;
        switch(opción){
            case 1:{
                cout<<"Ha decidido registrar un camión con su matrícula, capacidad de carga, consumo de gasolina y carga actual.\n";
            }break;
            case 2:{
                cout<<"Ha decidido consultar los datos de un camión a partir de su matrícula\n";
            }break;
            case 3:{
                cout<<"Ha decidido cargar un camión verificando que no se exceda su capacidad máxima.\n";
            }break;
            case 4:{
                cout<<"Ha decidido descargar un camión reduciendo su carga actual.\n";
            }break;
            case 5:{
                cout<<"Ha decidido determinar el camión con menor consumo de gasolina que tnga capacidad suficiente para una carga dada.\n";
            }break;
            case 6:{
                cout<<"Ha decidido informar cuando no halla un camión disponible.\n";
            }break;
            case 7:{
                cout<<"Saliendo de la App.\n";
            }break;
            default:{
                cout<<"\nSelecciona una opción valida.\n";
            }break;
        }
    }while (opción != 7);
}