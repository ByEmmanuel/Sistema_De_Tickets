
# ¡Bienvenido al Proyecto de Generador de Tickets de Citas! ✈️

Este proyecto tiene como objetivo crear un sistema simple y eficiente para la generación de tickets de vuelos de aerolíneas, proporcionando una experiencia rápida y automatizada tanto para los pasajeros como para las aerolíneas.

---

## 🚀 **Características principales**
- **Automatizacion** para la ejecucion del programa usando python

- **Interfaz intuitiva** para la selección de fechas y gestión de datos.

- **Validación de días disponibles** para evitar conflictos de horarios.

- **Manejo de errores** causables por parte del usuario o del sistema


- **Gestión de citas escolares**:
  - Los usuarios pueden generar tickets para agendar citas.
  - Posibilidad de seleccionar un día específico para la reunión con el representante.
- **Funcionalidades CRUD**:
  - **Crear**: Registro de nuevas citas o tickets.
  - **Leer**: Consulta de citas ya programadas.
  - **Actualizar**: Modificación de datos de una cita existente.
  - **Eliminar**: Cancelación de citas.


---

## Tecnologías utilizadas 💻
- **Lenguaje**: C++, Cmake y Python para la automatizacion de ejecucion 

### Tecnologias para el proyecto de manera escalable 🪜
- **Base de datos**: MySQL para almacenar los detalles de los tickets y Usuarios.
- **Interfaz gráfica**: Posibilidad de integrar con frameworks como Qt para una interfaz gráfica amigable.

## Estructura del Proyecto 📂
El proyecto está organizado de la siguiente manera:

```
/generador-de-tickets
│
├── /Main       # Código fuente del generador
│   ├── CalcularTiempo.h
│   ├── CalcularTiempoTest.cpp
│   ├── CalandarioTerminal.h
│   ├── Controladores.h
│   ├── ProyectoFund.cpp
│   ├── RegistroDAO.h
│   ├── UsuariosEntity.h
└── README.md   # Archivo de bienvenida y documentación
```

## 📂 **Explicacion De La Estructura Del Proyecto**
El sistema está diseñado con una arquitectura clara para facilitar su mantenimiento y escalabilidad. La estructura principal incluye:
- **Gestor del tiempo**:
  - Gestión del tiempo del sistema.
  Esto sirve para que no exceda tiempos una solicitud y no este siempre abierta esta misma
- **Funciones para operaciones CRUD**:
  - Esto incuye entidades para el modelaje de usuarios en una posible base de datos
- **Patron de diseño de software**:
  - El patron de diseño esta basado en la arquitectura MVC 
  Modelo - Vista - Controlador

  - *Modelo: Incluye el famoso Data Acces Object (DAO)*
  - *Vista: Lo que es visible ante el usuario*
  - *Controlador: El usuario escoje sus preferencias para la cita*


## Cómo usar el generador 🚀

1. **Instalación**: Clona el repositorio:
    ```bash
    git clone https://github.com/ByEmmanuel/Sistema_De_Tickets.git
    ```

2. **Compilación**:
    ```bash
    python3 AutoCompletions.py  
    ```

3. **Ejecución**:
    ```bash
    ./generador_de_tickets
    ```

## PARA WINDOWS AQUI
  1. **Primer paso Copia el repositorio**: Clona el repositorio:
    ```bash
    git clone https://github.com/ByEmmanuel/Sistema_De_Tickets.git
    ```

2. **Compilación**:
    ```bash
    
    ```



## Conclusiones 🤝
**¡Proyecto para la materia fundamentos de programacion!** 

*Colaboraciones Y Participaciones*

@ByEmmanuel      - Jesus Emmanuel - Leader

@javpulmez       - Javier Pulido

@Abr16Jin        - Abraham Rodrigez

@Oscar-Eddy360   - Oscar 




## Contacto 📧
@ByEmmanuelYT En X (Antes Twitter)

¡Gracias por usar el Generador de Tickets de Citas! ✈️
