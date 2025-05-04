#include<iostream>
using namespace std;

int MaxCamiones = 4;

struct Carga{
    
    //atributos
    float Carga;
    //métodos o funciones
    void registrarCarga();
};
struct GestorFlota{
    //atributos
    //métodos o funciones
    void consultarCamion();
    void cargarCamion();
};
struct Camiones{
    //Atributos
    string Matricula;
    float PesoMax;
    float ConsumoGasolina;
    float PesoActual;
    //Métodos o funciones
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
    void mostrarCamion() {
        cout << "\nMatrícula: " << Matricula
             << "\nCapacidad Máxima: " << PesoMax << " kg"
             << "\nConsumo de Gasolina: " << ConsumoGasolina << " gal/km"
             << "\nCarga Actual: " << PesoActual << " kg\n";
    }
};


int main(){
    cout<<"Buenos días. Bienvenido, por favor escoja una opción:\n";
    cout<<"\nSelecciona una opción"<<endl;
    Camiones flota[MaxCamiones];
    int cantidadCamiones = 0;
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
            case 1: {
                if (cantidadCamiones < MaxCamiones) {
                    flota[cantidadCamiones].registrarCamion();
                    cantidadCamiones++;
                    cout << "Camión registrado con éxito.\n";
                } else {
                    cout << "Límite de camiones alcanzado. No puedes registrar más.\n";
                }
                break;
            }break;
            case 2: {
                if (cantidadCamiones == 0) {
                    cout << "No hay camiones registrados.\n";
                } else {
                    cout << "\n--- Camiones Registrados ---\n";
                    for (int i = 0; i < cantidadCamiones; ++i) {
                        cout << "\nCamión #" << (i + 1);
                        flota[i].mostrarCamion();
                    }
                }
                break;
            }
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