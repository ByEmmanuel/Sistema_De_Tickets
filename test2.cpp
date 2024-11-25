#include <iostream>
#include <string>
#include <vector>

struct Ticket {
    int id;
    std::string nombre;
    std::string tramite;
    int horasRestantes;
};

class SistemaTickets {
private:
    std::vector<Ticket> tickets;
    int contadorTickets = 1;

public:
    void registrarTicket() {
        Ticket nuevoTicket;
        nuevoTicket.id = contadorTickets++;
        std::cout<< "Ingrese su nombre: ";
        std::cin.ignore();
        std::getline(std::cin, nuevoTicket.nombre);
        std::cout<< "Ingrese el trámite: ";
        std::getline(std::cin, nuevoTicket.tramite);
        std::cout<< "Ingrese la duración del ticket en horas: ";
        std::cin>> nuevoTicket.horasRestantes;

        tickets.push_back(nuevoTicket);
        std::cout<< "Ticket registrado exitosamente. ID: " <<nuevoTicket.id << "\n";
    }

    void validarTicket() {
        int id;
        std::cout<< "Ingrese el ID del ticket: ";
        std::cin>> id;

        for (const auto &ticket : tickets) {
            if (ticket.id == id) {
                if (ticket.horasRestantes > 0) {
                    std::cout<< "El ticket es válido. Horas restantes: " << ticket.horasRestantes << "\n";
                } else {
                    std::cout<< "El ticket ha vencido.\n";
                }
                return;
            }
        }
        std::cout << "Ticket no encontrado.\n";
    }

    void renovarTicket() {
        int id, horas;
        std::cout<< "Ingrese el ID del ticket: ";
        std::cin>> id;

        for (auto &ticket : tickets) {
            if (ticket.id == id) {
                std::cout<< "Ingrese la nueva duración del ticket en horas: ";
                std::cin>> horas;
                ticket.horasRestantes = horas;
                std::cout<< "Ticket renovado exitosamente.\n";
                return;
            }
        }
        std::cout<< "Ticket no encontrado.\n";
    }

    void cancelarTicket() {
        int id;
        std::cout<< "Ingrese el ID del ticket: ";
        std::cin>> id;

        for (size_t i = 0; i < tickets.size(); ++i) {
            if (tickets[i].id == id) {
                tickets.erase(tickets.begin() + i);
                std::cout<< "Ticket cancelado exitosamente.\n";
                return;
            }
        }
        std::cout << "Ticket no encontrado.\n";
    }

    void consultarTickets() {
        if (tickets.empty()) {
            std::cout<< "No hay tickets registrados.\n";
            return;
        }

        for (const auto &ticket : tickets) {
            std::cout<< "ID: " <<ticket.id << ", Nombre: " <<ticket.nombre << ", Trámite: " << ticket.tramite << ", Horas restantes: " <<ticket.horasRestantes << "\n";
        }
    }
};

int main() {
    SistemaTickets sistema;
    int opcion;

    do {
        std::cout<< "\n--- Sistema de Tickets ---\n";
        std::cout<< "1. Registrar ticket\n";
        std::cout<< "2. Validar ticket\n";
        std::cout<< "3. Renovar ticket\n";
        std::cout<< "4. Cancelar ticket\n";
        std::cout<< "5. Consultar tickets\n";
        std::cout<< "6. Salir\n";
        std::cout<< "Seleccione una opción: ";
        std::cin>> opcion;

        switch (opcion) {
        case 1:
            sistema.registrarTicket();
            break;
        case 2:
            sistema.validarTicket();
            break;
        case 3:
            sistema.renovarTicket();
            break;
        case 4:
            sistema.cancelarTicket();
            break;
        case 5:
            sistema.consultarTickets();
            break;
        case 6:
            std::cout<< "Saliendo del sistema...\n";
            break;
        default:
            std::cout<< "Opción inválida. Intente de nuevo.\n";
        }
    } while (opcion != 6);

    return 0;
}