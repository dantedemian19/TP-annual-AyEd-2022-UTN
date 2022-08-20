#include "../cppLibrary/menu.h" 
#include "./classes/party.h"

int main() {
        menuClass menu;
        string menuTitle = "\n\t Programas: Algoritmos y Estructura de Datos 2022 K1091 Dante Alfonso \n";
        string menuText[] = {
            "start",
            " programa 1: ejercicio de promedios",
            "end"
        };
        const int menuOptions = sizeof(menuText) / sizeof(menuText[0]) - 1;
        menu.declare(menuTitle, menuText[],menuOptions);
        while (menu.w != menu.exit) {
            menu.menu();
            wait();
            switch (menu.w)
            {
                case 1:

                    break;
                default:
                    errormens();
                    break;
            }
        }
}