#include "../cppLibrary/menu.h" 
#include "./classes/party.h"

int main() {
        menuClass menu;
        string menuTitle = "\n\t Programas: Algoritmos y Estructura de Datos 2022 K1091 Dante Alfonso \n";
        string menuText[] = {
            "start",
            " votar por un partido",
            " Resultados",
            " administrar",
            "end"
        };
        const int menuOptions = sizeof(menuText) / sizeof(menuText[0]) - 1;
        menu.declare(menuTitle, menuText,menuOptions,0);
        while (menu.w != menu.exit) {
            menu.menu();
            wait();
            cls();
            switch (menu.w)
            {
                case 1:
                    
                    cout << "Votar por un partido" << "\n";
                    wait();
                break;
                case 2:
                    cout << "Resultados" << "\n";
                    wait();
                break;
                case 3:
                    cout << "Administrar" << "\n";
                    wait();
                case menu.exit:
                    
                default:
                    errormens();
                    break;
            }
        }
}