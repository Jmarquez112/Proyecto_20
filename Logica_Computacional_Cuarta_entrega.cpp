#include<iostream>

using namespace std;

struct Carga{
    
    //atributos
    float Carga;
    //métodos o funciones
    void registrarCarga();
};

struct GestorFlota{
    //atributos
    int Camiones = 4;
    //métodos o funciones
    void consultarCamion();
    void cargarCamion();
};

struct Camion{
    //atributos
    string Matricula;
    float PesoMax;
    float ConsumoGasolina;
    float PesoActual;
    //métodos o funciones
    void registrarCamion();
};

void registrarCamion() {
    
    string Matricula;
    float PesoMax, ConsumoGasolina, PesoActual;

    cout << "Ingrese matrícula: ";
    cin >> Matricula;
    cout << "Ingrese capacidad de carga (kg): ";
    cin >> PesoMax;
    cout << "Ingrese consumo de gasolina (gal/km): ";
    cin >> ConsumoGasolina;
    cout << "Ingrese carga actual (kg): ";
    cin >> PesoActual;
}


int main(){
    cout<<"Buenos días. Bienvenido, por favor escoja una opción:\n";
    cout<<"\nSelecciona una opción"<<endl;
    int opción;
   
    do{
    cout << "\n--- MENU ---\n";
    cout << "1. Registrar camión\n";
    cout << "2. Consultar camión\n";
    cout << "3. Cargar camión\n";
    cout << "4. Descargar camión\n";
    cout << "5. Encontrar mejor camión\n";
    cout << "6. Salir\n";
    cin>>opción;
        switch(opción){
            case 1:{
                cout<<"Ha decidido registrar un camión.\n";
            }break;
            case 2:{
                cout<<"Ha decidido Consultar camión.\n";
            }break;
            case 3:{
                cout<<"Ha decidido cargar camión.\n";
            }break;
            case 4:{
                cout<<"Ha decidido descargar camión.\n";
            }break;
            case 5:{
                cout<<"Ha decidido Encontrar mejor camión.\n";
            }break;
            case 6:{
                cout<<"Saliendo de la App.\n";
            }break;
            default:{
                cout<<"\nSelecciona una opción valida.\n";
            }break;
        }
    }while (opción != 6);
}