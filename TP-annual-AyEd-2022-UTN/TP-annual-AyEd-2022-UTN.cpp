#include "../cppLibrary/menu.h";
#include "../cppLibrary/dynamicTypes.h";
#include "../cppLibrary/fileManager.h";
#include "./classes/party.h";
#include "./procedures/vote.h";
#include "./procedures/results.h";

struct application {
    voteProgram vote;
    resultsProgram results;
};
application app;

void writefile(fileManager<politicalParty> file, linkList<politicalParty> parties) {
    linkList<politicalParty>::node* temp = parties.first;
    if(temp!=nullptr){
        file.reWrite(temp->data);
        while (temp!=nullptr){
            file.write(temp->data);
            temp = temp->next;   
        }
    }
};



int main() {
        linkList<politicalParty> parties;
        fileManager<politicalParty> file;
            file.declare("parties","txt");
            file.readToMemory();
            parties = file.inMemoryFile;

        menuC menu;
        string menuTitle = "\n\t Programa Trabajo practico \n";
        string menuText[] = {
            "start",
            " votar por un partido",
            " Resultados",
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
                    app.vote.run(parties);
                    wait();
                break;
                case 2:
                    app.results.run(parties,file);
                    pause();
                    wait();
                break;
                case menuOptions:
                    writefile(file,parties);
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