#include "../cppLibrary/menu.h" 
#include "./classes/party.h"

void main() {
        menuClass menu;
        string menuTitle = "\n\t Programa Trabajo practico \n";
        string menuText[] = {
            "start",
            " ",
            "end"
        };
        const int menuOptions = sizeof(menuText) / sizeof(menuText[0]) - 1;
        menu.declare(menuTitle, menuText, menuOptions);
        while (menu.w != menu.exit) {
            menu.menu();
            wait();
            switch (menu.w)
            {
                case 1:
                    menu.showGracia();
                    break;
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