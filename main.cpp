#include<iostream>

using namespace std;

int main(){
    
    int op;
    cout<<"Buenos días. Bienvenido, por favor escoja una opción:\n";
    cout<<"1. Registrar un camión con su matrícula, capacidad de carga, consumo de gasolina y carga actual.\n";
    cout<<"2. Consultar los datos de un camión a partir de su matrícula.\n";
    cout<<"3. Cargar un camión verificando que no se exceda su capacidad máxima.\n";
    cout<<"4. Descargar un camión reduciendo su carga actual.\n";
    cout<<"5. Determinar el camión con menor consumo de gasolina que tenga capacidad suficiente para una carga dada.\n";
    cin>>op;
    switch(op)
    {
        case 1:
        {
            cout<<"Ha decidido registrar un camión con su matrícula, capacidad de carga, consumo de gasolina y carga actual.";
        }break;
        case 2:
        {
            cout<<"Ha decidido consultar los datos de un camión a partir de su matrícula.";
        }break;
        case 3:
        {
            cout<<"Ha decidido cargar un camión verificando que no se exceda su capacidad máxima.";
        }break;
        case 4:
        {
            cout<<"Ha decidido descargar un camión reduciendo su carga actual.";
        }break;
        case 5:
        {
            cout<<"Ha decidido determinar el camión con menor consumo de gasolina que tnga capacidad suficiente para una carga dada.";
        }break;
    }
    
}