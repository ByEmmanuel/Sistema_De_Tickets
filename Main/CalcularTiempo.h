#include <iostream>
#include <chrono>

using namespace std;


    class CalcularTiempo
    {
    private:
        chrono::time_point<chrono::high_resolution_clock> tiempoInicio;
        chrono::time_point<chrono::high_resolution_clock> tiempoFin;

    public:
        // Metodo para registrar el inicio del tiempo
        void init(){
            tiempoInicio = std::chrono::high_resolution_clock::now();
        }

        // Metodo para registrar el final del tiempo
        void end()
        {
            tiempoFin = std::chrono::high_resolution_clock::now();
        }

        // Metodo para calcular y mostrar el tiempo transcurrido
        void retornarTiempo(string mensaje)
        {
            auto tiempoTranscurrido = chrono::duration_cast<chrono::nanoseconds>(tiempoFin - tiempoInicio).
                count();
            cout << mensaje << endl;
            cout << "Tiempo en segundos: " << tiempoTranscurrido / 1e9 << "s" << endl;
            double tiempoMilisegundos = tiempoTranscurrido / 1e6; // Convertir nanosegundos a milisegundos
            cout << "Tiempo transcurrido: " << tiempoMilisegundos << " ms" << endl;
        }
    };


//inline Time::CalcularTiempo* tiempo = new Time::CalcularTiempo;
