#include <iostream>
#include <string>
#include <list>
#include <array>
#include "CalcularTiempo.h"
#include "UsuariosEntity.h"

#include "Controladores.h"

using namespace std;

bool bandera = true;
int opcion;
Controladores* controlador = new Controladores;
//CalcularTiempo* tiempo = new CalcularTiempo();  // Inicializado `tiempo`

inline void sistema() {
    bool banderaAuxiliar;
    while (bandera) {
        array<string, 4> tramite = {"Crear Cita", "Consultar una Cita", "Modificar Una Cita", "Cancelar Una Cita"};

        cout << "Seleccione una opción (1-4):" << endl;
        for (int i = 0; i < tramite.size(); ++i) {
            cout << i + 1 << ". " << tramite[i] << endl;
        }

        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Eligió Crear Cita" << std::endl;
                banderaAuxiliar = controlador->reservarCita(opcion);
                if (!banderaAuxiliar) {
                    bandera = false;
                }
                break;
            case 2:
                cout << "Eligió Consultar una Cita" << endl;
                banderaAuxiliar = controlador->consultarCita();
                if (!banderaAuxiliar) {
                    bandera = false;
                }
                break;
            case 3:
                cout << "Eligió Modificar Una Cita" << endl;
                //Logica para modificar una cita
                banderaAuxiliar = controlador -> modificarCita();
                if (!banderaAuxiliar) {
                    bandera = false;
                }
                break;
            case 4:
                cout << "Eligió Eliminar Una Cita" << endl;
                //Logica para Eliminar una cita
                banderaAuxiliar = controlador -> eliminarCita();
                if (!banderaAuxiliar) {
                    bandera = false;
                }
                break;
            default:
                cout << "Opción no válida" << endl;
                bandera = false;
                break;
        }
    }
}

int main() {
    tiempo->init();

    sistema();

    tiempo->end();
    tiempo->retornarTiempo("Tiempo en clase principal");

    //delete dao;          // Liberar memoria asignada
    delete controlador;   // Liberar memoria asignada
    delete tiempo;        // Liberar memoria asignada

    return 0;
}