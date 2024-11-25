//
// Created by Jesus Emmanuel Garcia on 08/09/24.
//
#pragma once

#include <set>
#include <string>

#ifndef USUARIOS_H
#define USUARIOS_H


using namespace std;
class UsuariosEntity {

    int id_usuario;
    string nombre;
    int codigo;
    string correo;
    //Variable sin usar
    string llave_acceso;
    int diaCita;
    //Retornar un mini calendario en terminal para que el usuario registre su cita
    //long numero_de_tarjeta;


public:
    UsuariosEntity() = default;

    // Constructor para inicializar los atributos
    UsuariosEntity(string n, int e): id_usuario(0),
                                     nombre(std::move(n)), codigo(e){
    }


    string getNombre() const {
        return nombre;
    }


    void setNombre(string& nuevoNombre) {
        this->nombre = nuevoNombre;
    }


    int getCodigo() const {
        return codigo;
    }


    void setCodigo(string& nuevoCodigo) {
        int codigoInt = stoi(nuevoCodigo);
        if (codigoInt > 0) {  // Validación simple
            this->codigo = codigoInt;
        }
    }

    string getCorreo() const{
        return correo;
    }

    void setCorreo(const string& correo){
        this->correo = correo;
    }

    int getCita() const{
        return diaCita;
    }

    void setDiaCita(int dia_cita){
        this->diaCita = dia_cita;
    }

    //Logica no valida para el proyecto general, solo usos de prueba para el proyecto
    void setUsuario(int id_usuario, string nombre, int codigo, string correo, int diaCita){
        this->id_usuario = id_usuario;
        this->nombre = nombre;
        this->codigo = codigo;
        this->correo = correo;
        this->diaCita = diaCita;
        
    }
};


struct metaDatosUsuarios{
    string nombre;
    int edad;
};


#endif //USUARIOS_H
