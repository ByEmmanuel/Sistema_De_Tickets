#pragma once
#include <iostream>
#include <vector>
#include <iomanip> // para std::setw
#include <set>



using namespace std;

class CalendarioTerminal {
private:
    std::vector<int> calendarioActual;
    std::set<int> diaOcupado;

    // Función que determina si un año es bisiesto
    static bool esBisiesto(int year) {
        return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
    }

    // Función que devuelve el número de días en un mes dado
    static int obtenerDiasEnMes(int mes, int year) {
        std::vector<int> diasPorMes = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (mes == 2 && esBisiesto(year)) {
            return 29;
        }
        return diasPorMes[mes - 1];
    }

    // Función para calcular el día de la semana del primer día del mes
    static int obtenerPrimerDiaDelMes(int mes, int year) {
        int d = 1, m = (mes < 3) ? mes + 12 : mes, y = (mes < 3) ? year - 1 : year;
        int k = y % 100;
        int j = y / 100;
        int h = (d + (13 * (m + 1)) / 5 + k + k / 4 + j / 4 - 2 * j) % 7;
        return (h + 5) % 7;
    }

public:
    // Función para generar el calendario y marcar el día seleccionado
    std::vector<int> generarCalendario(int seleccionDia, int mes, int year) {
        calendarioActual.clear();  // Limpia el calendario antes de generarlo
        std::vector<std::string> diasSemana = {"Dom", "Lun", "Mar", "Mie", "Jue", "Vie", "Sab"};
        int primerDia = obtenerPrimerDiaDelMes(mes, year);
        int diasEnMes = obtenerDiasEnMes(mes, year);

        cout << "Calendario de " << mes << "/" << year << "\n";
        for (const auto& dia : diasSemana) {
            cout << setw(4) << dia;
        }
        cout << "\n";

        // Espacios iniciales antes del primer día del mes
        for (int i = 0; i < primerDia; ++i) {
            calendarioActual.push_back(0); // 0 indica espacio en blanco
        }

        for (int dia = 1; dia <= diasEnMes; ++dia) {
            calendarioActual.push_back(dia); // Agrega el día al vector
            if (seleccionDia == dia) {
                if (diaOcupado.count(dia)) {  // Día ya ocupado
                    cout << "El día " << dia << " ya está ocupado. Por favor, elija otro día." << endl;
                    return {};  // Retorna vacío si el día está ocupado
                }
                diaOcupado.insert(dia);  // Marca el día como ocupado si está disponible
            }
        }
        return calendarioActual;
    }

    // Función para mostrar el calendario guardado con días ocupados marcados
    static void mostrarCalendario(const std:: vector<int>& calendarioGuardado, const std::set<int>& diasOcupados) {
        int diaSemana = 0;
        for (int dia : calendarioGuardado) {
            if (dia == 0) {
                cout << setw(4) << " ";
            } else if (diasOcupados.count(dia)) {
                if (to_string(dia).compare("^\\d{2}$")){
                    cout << setw(5) << dia << "\b\bx"; // Marca el día ocupado con "x"
                }else{
                    cout << setw(3) << dia << "\b x"; // Marca el día ocupado con "x"
                }
            } else {
                cout << setw(4) << dia;
            }
            diaSemana++;

            if (diaSemana % 7 == 0) {
                cout << "\n";
            }
        }
        cout << "\n";
    }

    // Getter para obtener los días ocupados desde fuera de la clase
    const std::set<int>& obtenerDiasOcupados() const {
        return diaOcupado;
    }

        int setNuevaFechaCal(int& diaNuevo, int diaViejo, UsuariosEntity& usuario) {
            try {
                auto it = diaOcupado.find(diaViejo);
                if (it != diaOcupado.end()) {
                    // Si el día viejo existe
                    diaOcupado.erase(it);       // Elimina el valor antiguo
                    diaOcupado.insert(diaNuevo); // Inserta el valor nuevo
                    return diaNuevo;
                }
                cout << "El día " << diaViejo << " no se encontró en los días ocupados." << endl;
            } catch (exception& e) {
                cout << e.what();
            }
            return diaViejo; // Retorna el día viejo si no se encuentra el día ocupado
        }

    void borrarFechaCitaCal(int diaViejo, UsuariosEntity& usuario) {
        try {
            auto it = diaOcupado.find(diaViejo);
            if (it != diaOcupado.end()) {
                // Si el día viejo existe
                diaOcupado.erase(it);       // Elimina el valor antiguo
            }
            cout << "El día " << diaViejo << " no se encontró en los días ocupados." << endl;
        } catch (exception& e) {
            cout << e.what();
        }
    }


    void setCalendarioCctual(const std::vector<int>& calendario_actual){
        calendarioActual = calendario_actual;
    }
};
