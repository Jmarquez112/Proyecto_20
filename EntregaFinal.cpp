#include <iostream>
using namespace std;
const int MaxCamiones = 4;
struct Camiones {
    string Matricula;
    float PesoMax;
    float ConsumoGasolina;
    float PesoActual;
    void registrarCamion() {
        cout<<"Ingrese matrícula: ";
        cin>>Matricula;
        do {
            cout<<"Ingrese capacidad de carga (kg): ";
            cin>>PesoMax;
            if (PesoMax <= 0) 
                cout<<"Debe ser mayor que cero.\n";
        }while (PesoMax <= 0);
        do {
            cout<<"Ingrese consumo de gasolina (gal/km): ";
            cin>>ConsumoGasolina;
            if (ConsumoGasolina <= 0) 
                cout<<"Debe ser mayor que cero.\n";
        }while (ConsumoGasolina <= 0);
        do {
            cout<<"Ingrese carga actual (kg): ";
            cin>>PesoActual;
            if (PesoActual < 0 || PesoActual > PesoMax)
                cout<<"La carga actual debe estar entre 0 y "<<PesoMax<<" kg.\n";
        } while(PesoActual < 0 || PesoActual > PesoMax);
    }
    void mostrarCamion() {
        cout<<"\nMatrícula: "<<Matricula;
        cout<<"\nCapacidad Máxima: "<<PesoMax<<" kg";
        cout<<"\nConsumo de Gasolina: "<<ConsumoGasolina<<" gal/km";
        cout<<"\nCarga Actual: "<<PesoActual<<" kg\n";
    }
};
int main() {
    Camiones flota[MaxCamiones];
    float historialCargas[MaxCamiones][100];
    int numCargas[MaxCamiones];
    
    for (int i = 0; i < MaxCamiones; ++i) {
        numCargas[i] = 0;
        for (int j = 0; j < 100; ++j) {
            historialCargas[i][j] = 0.0;
        }
    }
    int cantidadCamiones = 0;
    int opcion;
    do {
        cout<<"\n--- MENÚ ---\n";
        cout<<"1. Registrar camión\n";
        cout<<"2. Consultar camión\n";
        cout<<"3. Cargar camión\n";
        cout<<"4. Descargar camión\n";
        cout<<"5. Encontrar mejor camión\n";
        cout<<"6. Ver historial de cargas por camión\n";
        cout<<"7. Eliminar camión\n";
        cout<<"8. Salir\n";
        cout<<"Selecciona una opción: ";
        cin>>opcion;
        switch (opcion) {
            case 1: {
                if (cantidadCamiones < MaxCamiones) {
                    flota[cantidadCamiones].registrarCamion();
                    cantidadCamiones++;
                    cout<<"Camión registrado con éxito.\n";
                    cout<<"\nCamión #"<<cantidadCamiones<<" registrado como: "<<flota[cantidadCamiones - 1].Matricula<<"\n";
                } else {
                    cout<<"Límite de camiones alcanzado.\n";
                }
                break;
            }
            case 2: {
                if (cantidadCamiones == 0) {
                    cout<<"No hay camiones registrados.\n";
                }
                else {
                    int subopcion;
                    cout<<"\nConsultar:\n";
                    cout<<"1. Ver todos los camiones\n";
                    cout<<"2. Buscar camión por matrícula\n";
                    cout<<"Seleccione una opción: ";
                    cin>>subopcion;
                    if (subopcion == 1) {
                        for (int i = 0; i < cantidadCamiones; ++i) {
                            cout<<"\nCamión #"<<(i + 1);
                            flota[i].mostrarCamion();
                        }
                    } else if (subopcion == 2) {
                        string mat;
                        cout<<"Ingrese la matrícula del camión: ";
                        cin>>mat;
                        int encontrado = 0; // 0 = no encontrado, 1 = encontrado
                        for (int i = 0; i < cantidadCamiones; ++i) {
                            if (flota[i].Matricula == mat) {
                                cout<<"\nCamión encontrado:\n";
                                flota[i].mostrarCamion();
                                encontrado = 1;
                                break;
                            }
                        }
                        if (encontrado == 0) {
                            cout<<"Camión no encontrado.\n";
                        }
                    } else {
                        cout<<"Opción no válida.\n";
                    }
                }
                break;
            }
            case 3: {
                if (cantidadCamiones == 0) {
                    cout<<"No hay camiones registrados.\n";
                    break;
                }
                int indice;
                float carga;
                cout<<"Seleccione un camión:\n";
                for (int i = 0; i < cantidadCamiones; ++i) {
                    cout<<"Camión #"<<(i + 1)<<": "<<flota[i].Matricula<<"\n";
                }
                cin>>indice;
                if (indice < 1 || indice > cantidadCamiones) {
                    cout<<"Número de camión inválido.\n";
                    break;
                }
                do{
                    cout<<"Ingrese el peso de la carga: ";
                    cin>>carga;
                    if (carga<=0)
                        cout<<"El peso de la carga debe ser mayor que cero.\n";
                }while(carga<=0);
                if (carga <= 0) {
                    break;
                }
                Camiones &camion = flota[indice - 1];
                if (camion.PesoActual + carga <= camion.PesoMax) {
                    camion.PesoActual += carga;
                    cout<<"Carga añadida con éxito.\n";
                    if (numCargas[indice - 1] < 100) {
                        historialCargas[indice - 1][numCargas[indice - 1]] = carga;
                        numCargas[indice - 1]++;
                    } else {
                        cout<<"Historial de cargas lleno para este camión.\n";
                    }
                } else {
                    cout<<"No se puede cargar: supera el límite de peso.\n";
                }
                break;
            }
            case 4: {
                if (cantidadCamiones == 0) {
                    cout << "No hay camiones registrados.\n";
                    break;
                }
                string mat;
                cout << "Ingrese la matrícula del camión que desea descargar: ";
                cin >> mat;
                int indice = -1;
                for (int i = 0; i < cantidadCamiones; ++i) {
                    if (flota[i].Matricula == mat) {
                        indice = i;
                        break;
                    }
                }
                if (indice == -1) {
                    cout << "Camión no encontrado.\n";
                    break;
                }
                float descarga;
                do {
                    cout << "Ingrese el peso a descargar: ";
                    cin >> descarga;
                    if (descarga <= 0)
                        cout << "El peso debe ser mayor que cero.\n";
                } while (descarga <= 0);
                Camiones &camion = flota[indice];
                if (descarga <= camion.PesoActual) {
                    camion.PesoActual -= descarga;
                    cout << "Descarga realizada con éxito.\n";
                } 
                else {
                    cout << "No se puede descargar más del peso actual del camión.\n";
                }
                break;
            }
            case 5: {
                if (cantidadCamiones == 0) {
                    cout<<"No hay camiones registrados.\n";
                    break;
                }
                float PesoOptimo;
                do{
                    cout<<"Ingrese el peso de la carga a transportar (kg): ";
                    cin>>PesoOptimo;
                    if (PesoOptimo<=0)
                        cout<<"El peso de la carga debe ser mayor que cero.\n";
                }while(PesoOptimo<=0);
                if (PesoOptimo <= 0) {
                    break;
                }
                int mejorIndice = -1;
                float menorConsumo = -1;
                for (int i = 0; i < cantidadCamiones; ++i) {
                    float disponible = flota[i].PesoMax - flota[i].PesoActual;
                    if (disponible >= PesoOptimo) {
                        if (mejorIndice == -1 || flota[i].ConsumoGasolina < menorConsumo) {
                            mejorIndice = i;
                            menorConsumo = flota[i].ConsumoGasolina;
                        }
                    }
                }
                if (mejorIndice == -1) {
                    cout<<"No hay camiones con capacidad suficiente.\n";
                } else {
                    cout<<"Camión óptimo: #"<<(mejorIndice + 1)<<"\n";
                    flota[mejorIndice].mostrarCamion();
                    char OpcionCarga;
                    cout<<"¿Desea cargar este camión con "<<PesoOptimo<<" kg? (s/n): ";
                    cin>>OpcionCarga;
                    if (OpcionCarga == 's' || OpcionCarga == 'S') {
                        flota[mejorIndice].PesoActual += PesoOptimo;
                        cout<<"Carga añadida con éxito.\n";
                        if (numCargas[mejorIndice] < 100) {
                            historialCargas[mejorIndice][numCargas[mejorIndice]] = PesoOptimo;
                            numCargas[mejorIndice]++;
                        } else {
                            cout<<"Historial de cargas lleno para este camión.\n";
                        }
                    } else {
                        cout<<"Carga cancelada.\n";
                    }
                }
                break;
            }
            case 6: {
                if (cantidadCamiones == 0) {
                    cout<<"No hay camiones registrados.\n";
                    break;
                }
                int indice;
                cout<<"Seleccione un camión para ver su historial:\n";
                for (int i = 0; i < cantidadCamiones; ++i) {
                    cout<<"Camión #"<<(i + 1)<<": "<<flota[i].Matricula<<"\n";
                }
                cin>>indice;
                if (indice < 1 || indice > cantidadCamiones) {
                    cout<<"Número de camión inválido.\n";
                    break;
                }
                cout<<"Historial de cargas para camión #"<<indice
                    <<" ("<<flota[indice - 1].Matricula<<"):\n";
                if (numCargas[indice - 1] == 0) {
                    cout<<"No se han registrado cargas.\n";
                } else {
                    for (int j = 0; j < numCargas[indice - 1]; ++j) {
                        cout<<"- Carga #"<<(j + 1)<<": "<<historialCargas[indice - 1][j]<<" kg\n";
                    }
                }
                break;
            }
            case 7: {
                if (cantidadCamiones == 0) {
                    cout << "No hay camiones registrados.\n";
                    break;
                }
                string matriculaBorrar;
                cout << "Ingrese la matrícula del camión a eliminar: ";
                cin >> matriculaBorrar;
                int encontrado = -1;
                for (int i = 0; i < cantidadCamiones; ++i) {
                    if (flota[i].Matricula == matriculaBorrar) {
                        encontrado = i;
                        break;
                    }
                }
                if (encontrado == -1) {
                    cout << "Camión no encontrado.\n";
                } 
                else {
                    cout << "\nCamión encontrado:\n";
                    flota[encontrado].mostrarCamion();
                    char confirmar;
                    cout << "¿Está seguro que desea eliminar este camión? (s/n): ";
                    cin >> confirmar;
                    if (confirmar == 's' || confirmar == 'S') {
                        for (int i = encontrado; i < cantidadCamiones - 1; ++i) {
                            flota[i] = flota[i + 1];
                            numCargas[i] = numCargas[i + 1];
                            for (int j = 0; j < 100; ++j) {
                                historialCargas[i][j] = historialCargas[i + 1][j];
                            }
                        }
                        cantidadCamiones--;
                        cout << "Camión eliminado con éxito.\n";
                    } 
                    else {
                        cout << "Eliminación cancelada.\n";
                    }
                }
                    break;
            }
            case 8: {
                cout<<"Saliendo del programa.\n";
                break;
            }
            default:{
                cout<<"Opción no válida. Intente de nuevo.\n";
                break;
            }
        }
    }while(opcion != 8);
    return 0;
}
