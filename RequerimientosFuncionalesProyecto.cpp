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
    int opcion;
   
    do{
    cout << "\n--- MENU ---\n";
    cout << "1. Registrar camión\n";
    cout << "2. Consultar camión\n";
    cout << "3. Cargar camión\n";
    cout << "4. Descargar camión\n";
    cout << "5. Encontrar mejor camión\n";
    cout << "6. Salir\n";
    cin>>opcion;
        switch(opcion){
            case 1: {
                if (cantidadCamiones < MaxCamiones) {
                    flota[cantidadCamiones].registrarCamion();
                    cantidadCamiones++;
                    cout << "Camión registrado con éxito.\n";
                    cout << "\nCamión #" << cantidadCamiones << " registrado como: " << flota[cantidadCamiones - 1].Matricula << "\n";
                } 
                else{
                    cout << "Límite de camiones alcanzado. No puedes registrar más.\n";
                }break;
            }
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
                if (cantidadCamiones == 0){
                    cout<<"No se encuentran camiones registrados.\n";
                    break;
                }
                int indice;
                float carga;
                cout<<"Ingrese número de camión\n";
                for (int i = 0; i < cantidadCamiones; ++i) {
                        cout << "\nCamión #" << (i + 1)<<"\n";
                    }
                cin>>indice;
                
                if (indice < 1 || indice > cantidadCamiones){
                    cout<<"Número de camión inválido.\n";
                    break;
                }
                cout<<"Ingrese el peso de la carga: ";
                cin>>carga;
                Camiones &camion = flota[indice - 1];
                if (camion.PesoActual + carga <= camion.PesoMax){
                    camion.PesoActual += carga;
                    cout<<"Carga añadida con éxito.\n";
                }
                else{
                    cout<<"No se puede cargar debido a que supera el limite de peso del camión.\n";
                }
            }break;
            case 4:{
                if (cantidadCamiones == 0) {
                    cout<<"No se encuentran camiones registrados.\n";
                    break;
                }
                int indice;
                int descarga;
                cout<<"Ingrese número de camión\n";
                for (int i = 0; i < cantidadCamiones; ++i) {
                        cout << "\nCamión #" << (i + 1)<<"\n";
                    }
                cin>>indice;
                if (indice < 1 || indice > cantidadCamiones){
                    cout<<"Numero de camión inválido.\n";
                    break;
                }
                cout<<"Ingrese el pes oa descargar: ";
                cin>>descarga;
                
                Camiones &camion = flota[indice - 1];
                if (descarga <= camion.PesoActual){
                    camion.PesoActual -= descarga;
                    cout<<"Proceso de descarga realizado con exito";
                }
                else{
                    cout<<"No se puede descargar más peso del que tiene el camión.\n";
                }
                break;
            }
            case 5:{
                if (cantidadCamiones == 0) {
                  cout<<"No se encuentran camiones registrados.\n";
                  break;
                }
                float PesoOptimo;
                cout<<"Ingrese el peso de la carga a transportar: ";
                cin>>PesoOptimo;
                
                int mejorIndice = -1;
                float menorConsumo = -1;
                
                for (int i =0; i < cantidadCamiones; i++){
                    float capacidadDisponible = flota[i].PesoMax - flota[i].PesoActual;
                    if (capacidadDisponible >= PesoOptimo) {
                        if (mejorIndice == -1 || flota[i].ConsumoGasolina < menorConsumo){
                            mejorIndice = i;
                            menorConsumo = flota[i].ConsumoGasolina;
                        }
                    }
                }
                if (mejorIndice == -1){
                    cout<<"No hay camiones disponibles con la capacidad para transportar esa carga.\n";
                }
                else{
                    cout<<"El mejor camión para transportar "<< PesoOptimo <<" kg es: ";
                    cout<<"Camión #"<<(mejorIndice + 1)<<endl;
                    flota[mejorIndice].mostrarCamion();
                    
                    char OpciónCarga;
                    cout<<"\n¿Deseas cargar este camión con los "<<PesoOptimo<<" kg? (s/n)";
                    cin>>OpciónCarga;
                    if (OpciónCarga == 's' || OpciónCarga == 'S'){
                        flota[mejorIndice].PesoActual += PesoOptimo;
                        cout<<"Carga añadida con exito.\n";
                    }
                    else{
                        cout<<"Carga no realizada.\n";
                    }
                }
                break;
            }
            case 6:{
                cout<<"Saliendo de la App.\n";
            }break;
            default:{
                cout<<"\nSelecciona una opción valida.\n";
            }break;
        }
    }while (opcion != 6);
}