#include "../cppLibrary/menu.h" 
#include "./classes/party.h"

void main() {
        menuClass menu;
        string menuTitle = "\n\t Programa Trabajo practico \n";
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

/* 
    #include <iostream>
namespace std;

int main() {
  std::cout << "Hello World!\n";
}

(Matias)
//TOTALES
//EL 3%

(David)
//SACAR DE LA LISTA LOS QUE NO SUPERAN EL 3%
//DIVISIONES
  voit qYg(){
	int n1,n2,quitarV,GuardarV;
	float tresP;
	
	suma=n1+n2;
	tresP=3*(suma/100);
	if (n1<treP){
		quitarV=n1;
		GuardarB=n2;
		cout<<n2;
	}else{
		if (n2<tresP){
			quitarV=n2;
			GuardarV=n1;
			cout<<n1;
		}
	}
	return 0;
}

int main(){
	
}

(Gaston)
//BUSCAR LOS 5 VALORES MAS GRANDES DE LA LISTA

*/