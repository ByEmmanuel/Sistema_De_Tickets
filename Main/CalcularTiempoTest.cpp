//
// Created by Jesus Emmanuel Garcia on 25/09/24.
//

#include "CalcularTiempo.h"

int main()
{
    CalcularTiempo timer;

    // Iniciar el temporizador
    timer.init();

    // Código cuyo tiempo deseas medir
    for (int i = 0; i < 10000000; i++){
        // Simulación de algún proceso
        std::cout << "Proceso " << i << " Hola " << std::endl;
    }

    // Finalizar el temporizador
    timer.end();

    // Mostrar el tiempo transcurrido
    timer.retornarTiempo("");

    return 0;
}
