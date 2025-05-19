#include <iostream>
using namespace std;

const int MaxCamiones = 4;

struct Camiones {
    string Matricula;
    float PesoMax;
    float ConsumoGasolina;
    float PesoActual;
    
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
int main() {
    Camiones flota[MaxCamiones];
    float historialCargas[MaxCamiones][10];
    int numCargas[MaxCamiones];

    int cantidadCamiones = 0;
    int opcion;

    do {
        cout << "\n--- MENÚ ---\n";
        cout << "1. Registrar camión\n";
        cout << "2. Consultar camión\n";
        cout << "3. Cargar camión\n";
        cout << "4. Descargar camión\n";
        cout << "5. Encontrar mejor camión\n";
        cout << "6. Ver historial de cargas por camión\n";
        cout << "7. Salir\n";
        cout << "Selecciona una opción: ";
        cin >> opcion;
        switch (opcion) {
            case 1: {
                if (cantidadCamiones < MaxCamiones) {
                    flota[cantidadCamiones].registrarCamion();
                    cantidadCamiones++;
                    cout << "Camión registrado con éxito.\n";
                    cout << "Camión registrado con éxito.\n";
                    cout << "\nCamión #" << cantidadCamiones << " registrado como: " << flota[cantidadCamiones - 1].Matricula << "\n";
                } else {
                    cout << "Límite de camiones alcanzado.\n";
                }
                break;
            }
            case 2: {
                if (cantidadCamiones == 0) {
                    cout << "No hay camiones registrados.\n";
                } else {
                    for (int i = 0; i < cantidadCamiones; ++i) {
                        cout << "\nCamión #" << (i + 1);
                        flota[i].mostrarCamion();
                    }
                }
                break;
            }
            case 3: {
                if (cantidadCamiones == 0) {
                    cout << "No hay camiones registrados.\n";
                    break;
                }
                int indice;
                float carga;
                cout << "Seleccione un camión:\n";
                for (int i = 0; i < cantidadCamiones; ++i) {
                    cout << "Camión #" << (i + 1) << ": " << flota[i].Matricula << "\n";
                }
                cin >> indice;
                if (indice < 1 || indice > cantidadCamiones) {
                    cout << "Número de camión inválido.\n";
                    break;
                }
                cout << "Ingrese el peso de la carga: ";
                cin >> carga;
                Camiones &camion = flota[indice - 1];
                if (camion.PesoActual + carga <= camion.PesoMax) {
                    camion.PesoActual += carga;
                    cout << "Carga añadida con éxito.\n";
                    if (numCargas[indice - 1] < 10) {
                        historialCargas[indice - 1][numCargas[indice - 1]] = carga;
                        numCargas[indice - 1]++;
                    } else {
                        cout << "Historial de cargas lleno para este camión.\n";
                    }
                } else {
                    cout << "No se puede cargar: supera el límite de peso.\n";
                }
                break;
            }
            case 4: {
                if (cantidadCamiones == 0) {
                    cout << "No hay camiones registrados.\n";
                    break;
                }
                int indice;
                float descarga;
                cout << "Seleccione un camión:\n";
                for (int i = 0; i < cantidadCamiones; ++i) {
                    cout << "Camión #" << (i + 1) << ": " << flota[i].Matricula << "\n";
                }
                cin >> indice;
                if (indice < 1 || indice > cantidadCamiones) {
                    cout << "Número de camión inválido.\n";
                    break;
                }
                cout << "Ingrese el peso a descargar: ";
                cin >> descarga;
                Camiones &camion = flota[indice - 1];
                if (descarga <= camion.PesoActual) {
                    camion.PesoActual -= descarga;
                    cout << "Descarga realizada con éxito.\n";
                } else {
                    cout << "No puedes descargar más peso del que tiene el camión.\n";
                }
                break;
            }
            case 5: {
                if (cantidadCamiones == 0) {
                    cout << "No hay camiones registrados.\n";
                    break;
                }
                float PesoOptimo;
                cout << "Ingrese el peso de la carga a transportar (kg): ";
                cin >> PesoOptimo;
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
                    cout << "No hay camiones con capacidad suficiente.\n";
                } else {
                    cout << "Camión óptimo: #" << (mejorIndice + 1) << "\n";
                    flota[mejorIndice].mostrarCamion();
                    char OpcionCarga;
                    cout << "¿Desea cargar este camión con " << PesoOptimo << " kg? (s/n): ";
                    cin >> OpcionCarga;
                    if (OpcionCarga == 's' || OpcionCarga == 'S') {
                        flota[mejorIndice].PesoActual += PesoOptimo;
                        cout << "Carga añadida con éxito.\n";
                        if (numCargas[mejorIndice] < 10) {
                            historialCargas[mejorIndice][numCargas[mejorIndice]] = PesoOptimo;
                            numCargas[mejorIndice]++;
                        } else {
                            cout << "Historial de cargas lleno para este camión.\n";
                        }
                    } else {
                        cout << "Carga cancelada.\n";
                    }
                }
                break;
            }
            case 6: {
                if (cantidadCamiones == 0) {
                    cout << "No hay camiones registrados.\n";
                    break;
                }
                int indice;
                cout << "Seleccione un camión para ver su historial:\n";
                for (int i = 0; i < cantidadCamiones; ++i) {
                    cout << "Camión #" << (i + 1) << ": " << flota[i].Matricula << "\n";
                }
                cin >> indice;
                if (indice < 1 || indice > cantidadCamiones) {
                    cout << "Número de camión inválido.\n";
                    break;
                }
                cout << "Historial de cargas para camión #" << indice
                     << " (" << flota[indice - 1].Matricula << "):\n";
                if (numCargas[indice - 1] == 0) {
                    cout << "No se han registrado cargas.\n";
                } else {
                    for (int j = 0; j < numCargas[indice - 1]; ++j) {
                        cout << "- Carga #" << (j + 1) << ": " << historialCargas[indice - 1][j] << " kg\n";
                    }
                }
                break;
            }
            case 7: {
                cout << "Saliendo del programa.\n";
                break;
            }
            default: {
                cout << "Opción no válida. Intente de nuevo.\n";
                break;
            }
        }

    } while (opcion != 7);

    return 0;
}
