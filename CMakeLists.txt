cmake_minimum_required(VERSION 3.29)
project(Creador_de_codigos_AEROPUERTOS)

set(CMAKE_CXX_STANDARD 14)

add_executable(Creador_de_codigos_AEROPUERTOS
    Main/ProyectoFund.cpp
    Main/RegistroDAO.h
    Main/Controladores.h
    Main/UsuariosEntity.h
    Main/CalendarioTerminal.h

)
# Configuración básica de empaquetado
include(CPack)

# Información del paquete
set(CPACK_PACKAGE_NAME "Creador_de_codigos_AEROPUERTOS")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_GENERATOR "ZIP;TGZ")
