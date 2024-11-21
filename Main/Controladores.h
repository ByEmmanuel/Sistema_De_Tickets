#pragma once
#include <iostream>
#include <string>
#include <list>

#include <vector>


//#include "Controladores.h"
#include "UsuariosEntity.h"
#include "CalendarioTerminal.h"
#include "RegistroDAO.h"


using namespace std;
CalcularTiempo* tiempo = new CalcularTiempo;
CalendarioTerminal* calendario = new CalendarioTerminal; // Crear instancia de Calendario
RegistroDAO* registroDao = new RegistroDAO;
UsuariosEntity* usuario = new UsuariosEntity;

// La lista guarda en su momento los valores que se guardaron primero, los valores alterados (cambiados,
// no se actualizan de la lista ya que es un usuario y esto simula ser la base de datos)
list<UsuariosEntity> listaUsuarios;  // Cambiado pmr::list a std::list


//pmr::vector<int> arrayCalendario;
vector<int> calendarioDB;
int opcDia;
int diaCambCita;

class Controladores{
private:

public:
        /*Controladores(CalendarioTerminal* calendario): calendario(calendario) {

        };*/
    Controladores();



    static int reservarCita(int opcion ){
        cout << "Pulse 1 para cerrar la app, \nPulse 2 para continuar" << endl;
        cin >> opcion;
        cout << "opcion escogida : " << opcion << endl;
        string primerNombre, segundoNombre, primerApellido, segundoApellido, codigoALumno, correoAlumno;

        switch (opcion){
            case 1:
                return 0;
            case 2:
            for (int i = 0; i <= 6; i++){
                switch (i){
                    case 0:
                        cout << "Ingrese Primer Nombre\n" << endl;
                        cin >> primerNombre;
                        break;
                    case 1:
                        cout << "Ingrese Segundo Nombre, En caso de no tener dar enter\n" << endl;
                        cin >> segundoNombre;
                        break;
                    case 2:
                        cout << "Ingrese Primer Apellido\n" << endl;
                        cin >> primerApellido;
                        break;
                    case 3:
                        cout << "Ingrese Segundo Apellido\n" << endl;
                        cin >> segundoApellido;
                        break;
                    case 4:
                        cout << "Ingrese Codigo Alumno\n" << endl;
                        cin >> codigoALumno;
                        break;
                    case 5:
                        cout << "Ingrese Correo Alumno\n" << endl;
                        cin >> correoAlumno;
                        break;
                    case 6:
                        cout << "Ingrese Fecha para Cita\n" << endl;

                        cin >> opcDia;

                    calendarioDB = calendario->generarCalendario(opcDia, 11, 2024);
                    if (!calendarioDB.empty()) {
                        CalendarioTerminal::mostrarCalendario(calendarioDB, calendario->obtenerDiasOcupados());
                    }

                        break;
                    default:
                        cout << "Error" << endl;
                        break;
                }
            }

            tiempo->init();

            if (primerNombre.empty() || segundoNombre.empty() || primerApellido.empty() || segundoApellido.empty()){
                cout << "Nombre vacio" << endl;
            } else if (primerNombre.length() > 20 || segundoNombre.length() > 20 || primerApellido.length() > 20 || segundoApellido.length() > 20){
                cout << "Nombre muy largo" << endl;
            } else if (primerNombre.length() < 3 || segundoNombre.length() < 3 || primerApellido.length() < 3 || segundoApellido.length() < 3){
                cout << "Nombre muy corto" << endl;
            }



            string nombreCompletoUsuario = primerNombre + " " + segundoNombre + " " + primerApellido + " " +  segundoApellido + "\n";
            //Validar si el nombre contiene numeros
            for (int i = 0; i < nombreCompletoUsuario.length(); i++){
                if (isdigit(nombreCompletoUsuario[i])){
                    cout << "Nombre no puede contener numeros" << endl;
                }
            }

            usuario->setNombre(nombreCompletoUsuario);
            usuario->setCodigo(codigoALumno);
            usuario->setCorreo(correoAlumno);
            usuario->setDiaCita(opcDia);


            listaUsuarios.push_front(*usuario);


            UsuariosEntity usuarioEncontrado =  registroDao->buscarUsuarioPorNombre(nombreCompletoUsuario,listaUsuarios);
            //cout << usuarioEncontrado;
            cout << "La lista esta conformada por ; " << usuarioEncontrado.getNombre() ;

            tiempo->end();
            tiempo->retornarTiempo("Tiempo desde la clase Controladores");

            return 1;

            }

    }
    static int consultarCita(){
        cout << "Ingrese correo alumno" << endl;
        string correo;
        cin >> correo;
        UsuariosEntity usuario = registroDao->buscarUsuarioPorCorreo(correo, listaUsuarios);
        CalendarioTerminal::mostrarCalendario(calendarioDB, calendario->obtenerDiasOcupados());

        /*
            *Esta funcion apaga el programa si el objeto devuelto esta vacio
            *if (usuario.getNombre().empty()){
                return 0;
            }
            */
        return 1;

    }

    static int modificarCita(){
        cout << "Ingrese correo alumno" << endl;
        string correo;
        cin >> correo;
        cout << "¿Por cual dia quieres cambiarlo?";

        cin >> diaCambCita;
        UsuariosEntity nuevoUsuario = registroDao->buscarCitaYmodificar(correo,listaUsuarios,diaCambCita, *calendario);
        for (UsuariosEntity& usuario : listaUsuarios) {
            if (usuario.getCorreo() == correo) {
                usuario = nuevoUsuario;
                break;
            }
        }
        for (const auto& usuario : listaUsuarios ){
            cout << "Estos son los usuarios y sus caracteristicas en la base de datos; \n";
            cout << "\n Nombre Usuario: " << usuario.getNombre();
            cout << "\n Codigo Usuario: " << usuario.getCodigo();
            cout << "\n Cita Usuario: " << usuario.getCita();
            cout << "\n Correo Usuario: " << usuario.getCorreo() << "\n";
        }
        return 1;
    }

    static int eliminarCita(){
        cout << "Ingrese correo alumno" << endl;
        string correo;
        cin >> correo;
        UsuariosEntity usuarioDAO = registroDao->buscarUsuarioPorCorreo(correo, listaUsuarios);

        // Eliminar el usuario con la cita correspondiente
        auto it = remove_if(listaUsuarios.begin(), listaUsuarios.end(),
                                 [&](UsuariosEntity& usuario) {
                                     calendario->borrarFechaCitaCal(usuario.getCita(), usuario);
                                     return usuario.getCita() == usuarioDAO.getCita();
                                 });
        if (it != listaUsuarios.end()) {

            listaUsuarios.erase(it, listaUsuarios.end());
            cout << "Cita eliminada exitosamente." << endl;

            CalendarioTerminal::mostrarCalendario(calendarioDB, calendario->obtenerDiasOcupados());
            return 1;
        } else {
            cout << "No se encontró ninguna cita para eliminar." << endl;
            return -1; // operación fallida
        }
    }

    ~Controladores();
};

Controladores::Controladores(/* args */){


}

Controladores::~Controladores(){

}
