// P015_Batalla_Pokemon.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//JULIO CESAR ESPINOZA VASQUEZ

#include <iostream> 
#include <string> 
#include <cstdlib> 
#include <ctime> 

// Estructura para representar a un Pokémon 
struct Pokemon
{
    std::string nombre;
    int hp;
    std::string habilidades[4];
};

int main() {
    setlocale(LC_ALL, "es_MX.UTF-8");
    // Semilla para generar numeros aleatorios 
    srand(time(0));

    //  Arreglo de estructuras para el Pokémon 
    Pokemon pokemones[5];

    // Información de cada Pokémon 
    pokemones[0] = { "Pikachu", 100, {"Impactrueno", "Rayo", "Chispazo", "Trueno\n"} };
    pokemones[1] = { "Charizard", 120, {"Lanzallamas", "Garra Dragón", "Llamarada", "Ascuas\n"} };
    pokemones[2] = { "Rhydon", 110, {"Golpe roca", "Terratemblor", "Pisoton", "Bofeton lodo\n"} };
    pokemones[3] = { "Bulbasaur", 110, {"Látigo Cepa", "Bomba lodo", "Terremoto", "Bomba germen\n"} };
    pokemones[4] = { "Nidorino\n", 100, {"Puya toxica", "Bomba lodo", "Excavar", "Cornada\n"} };

    std::cout << " \tHola Bienvenido a Pokemon 10\n ";
    std::cout << " -----------------------------------------\n";

    // Lista de Pokémones disponibles 
    std::cout << "Selecciona tu Pokémon: " << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << i + 1 << ". " << pokemones[i].nombre << std::endl;
    }

    // Solicitar al usuario que seleccione un Pokémon 
    int seleccion;
    std::cout << "Ingresa el número correspondiente al Pokémon que deseas: ";
    std::cin >> seleccion;

    // Guardar el Pokéomon del usuario 
    if (seleccion >= 1 && seleccion <= 5) {
        Pokemon miPokemon = pokemones[seleccion - 1];

        // Generar el Pokémon enemigo  
        int POponente;
        do {
            POponente = rand() % 5;
        } while (POponente == seleccion - 1);

        Pokemon pokemonOponente = pokemones[POponente];

        std::cout << "\n¡Comienza la batalla!" << std::endl;
        std::cout << "Tu " << miPokemon.nombre << " vs " << pokemonOponente.nombre << std::endl;
        std::cout << "-------------------------" << std::endl;

        // Batalla 
        while (miPokemon.hp > 0 && pokemonOponente.hp > 0) {
            // Turno del jugador 
            std::cout << "\n¡Tu turno!" << std::endl;
            std::cout << "Elige una habilidad para atacar: " << std::endl;
            for (int i = 0; i < 4; i++) {
                std::cout << i + 1 << ". " << miPokemon.habilidades[i] << std::endl;
            }
            int habilidadSeleccionada;
            std::cout << "Ingresa el número correspondiente a la habilidad que deseas utilizar: ";
            std::cin >> habilidadSeleccionada;

            // Validar la selección de habilidad del jugador 
            if (habilidadSeleccionada >= 1 && habilidadSeleccionada <= 4) {
                // Turno del oponente 
                int habilidadOponente = rand() % 4;

                // Realizar el ataque 
                int ataqueJugador = habilidadSeleccionada - 1;
                int ataqueOponente = habilidadOponente;

                // Calcular el daño 
                int danioJugador = rand() % 20 + 10;
                int danioOponente = rand() % 20 + 10;

                // Aplicar el daño 
                pokemonOponente.hp -= danioJugador;
                miPokemon.hp -= danioOponente;

                // Mostrar resultados del turno 
                std::cout << "\nAtacaste a " << pokemonOponente.nombre << " con " << miPokemon.habilidades[ataqueJugador] << std::endl;
                std::cout << "Causaste " << danioJugador << " de daño." << std::endl;
                std::cout << pokemonOponente.nombre << " te atacó con " << pokemonOponente.habilidades[ataqueOponente] << std::endl;
                std::cout << "Recibiste " << danioOponente << " de daño." << std::endl;

                // Mostrar estado de los Pokémon 
                std::cout << "\nEstado actual:" << std::endl;
                std::cout << "Tu " << miPokemon.nombre << " - HP: " << miPokemon.hp << std::endl;
                std::cout << pokemonOponente.nombre << " - HP: " << pokemonOponente.hp << std::endl;
            }
            else {
                std::cout << "Habilidad inválida. Selecciona un número válido." << std::endl;
            }
        }

        // Mostrar el resultado de la batalla 
        if (miPokemon.hp <= 0) {
            std::cout << "\n¡Perdiste la batalla! Mejor suerte la próxima vez." << std::endl;
        }
        else {
            std::cout << "\n¡Ganaste la batalla!" << std::endl;
        }
    }
    else {
        std::cout << "Selección inválida. Selecciona un número válido." << std::endl;
    }

    // Pregunta al usuario si desea jugar nuevamente 
    char opcion;
    std::cout << "\n¿Deseas jugar nuevamente? (S/N): ";
    std::cin >> opcion;

    // Validar la respuesta del usuario 
    if (opcion == 'S' || opcion == 's') {
        // Reiniciar el programa 
        main();
    }
    else {
        std::cout << "¡Gracias por jugar! ¡Hasta la proxima!" << std::endl;
    }

}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
