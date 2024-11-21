//
// Created by Jesus Emmanuel Garcia on 11/09/24.
//

#pragma once
#ifndef REGISTRODAO_H
#define REGISTRODAO_H
#include <string>
#include <list>

#include "Controladores.h"


using namespace std;
using namespace std::pmr;

//Linea generada por IA que no se que hace, segun es para el operador ' == '
//bool operator==(const string& lhs, const string& rhs);

class RegistroDAO{

    /*De la Creacion del proyecto, CRUD
     * CREATE
     * READ
     * UPDATE
     * DELET
     */

public:

    // FUNCION READ
    // Función para buscar un usuario por nombre

    static UsuariosEntity buscarUsuarioPorNombre(const string& nombreBuscado, list<UsuariosEntity> listaUsuarios) {
         //Lo ponemos dentro de un try catch por si no se encuentra el usuario, devolver un error (Excepcion)
         try {
             // Iteramos sobre la lista de usuarios
             for (UsuariosEntity& usuario : listaUsuarios) {

                 // Si el nombre coincide, retornamos un puntero al usuario
                 if (usuario.getNombre() == nombreBuscado) {
                     //cout << "El ususario buscado desde DAO es " << &usuario;
                     cout << "El ususario buscado desde DAO es " << usuario.getNombre()
                            << "\n Codigo: " << usuario.getCodigo() << "\n Correo: " << usuario.getCorreo() << "\n";
                     return usuario;  // Retornamos la dirección del objeto encontrado
                 }
             }
         }
         catch (const runtime_error& e) {
             cerr << "Usuario NO Encontrado: " << e.what() << endl;
         }
         return {};
    }

    static UsuariosEntity buscarUsuarioPorCorreo(const string& correo, list<UsuariosEntity> listaUsuarios) {
        try {
            for (UsuariosEntity& usuario : listaUsuarios) {

                // Si el nombre coincide, retornamos un puntero al usuario
                if (usuario.getCorreo() == correo) {
                    //cout << "El ususario buscado desde DAO es " << &usuario;
                    cout << "El ususario buscado desde DAO es " << usuario.getNombre()
                           << "\n Codigo: " << usuario.getCodigo() << "\n Correo: " << usuario.getCorreo() << "\n "
                            << "Y tu cita es el dia: " << usuario.getCita() << "\n\n";
                    return usuario;  // Retornamos la dirección del objeto encontrado
                }
            }
            cout << "\n     Cita o Usuario no encontrado\n\n";
        }
        catch (const runtime_error& e) {
            cerr << "Usuario NO Encontrado: " << e.what() << endl;
        }
        return {};
    }

    // FUNCION UPDATE
    static UsuariosEntity buscarCitaYmodificar(const string& correo, list<UsuariosEntity>& listaUsuarios,
                                /*int& diaViejo,*/ int& diaNuevo, CalendarioTerminal& calendario){
        for (UsuariosEntity& usuario : listaUsuarios) { // nota el uso de `&` aquí
            if(usuario.getCorreo() == correo) {
                cout << "\nTu cita es el dia: " << usuario.getCita() << "\n";

                int diaNuevaCita = calendario.setNuevaFechaCal(diaNuevo, usuario.getCita(), usuario);
                usuario.setDiaCita(diaNuevaCita); // Ahora modificará el objeto original
                cout << "Tu nuevo día de cita es el: " << usuario.getCita() << endl;
                return usuario;
            }
        }
        cout << "Usuario no encontrado o no tiene cita\n";
    }

};


#endif //REGISTRODAO_H
