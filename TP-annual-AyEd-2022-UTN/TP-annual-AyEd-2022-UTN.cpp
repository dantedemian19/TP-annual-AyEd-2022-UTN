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

politicalParty defaultParties[2];

void inicializateDefault() {
    defaultParties[0].name = "votos en blanco";
    defaultParties[0].lista = -1;
    defaultParties[1].name = "votos nulos";
    defaultParties[1].lista = -2;
};

int main() {
        linkList<politicalParty> parties;
        fileManager<politicalParty> file;
            file.declare("parties","txt");
            file.readToMemory();
            parties = file.inMemoryFile;
            app.vote.loadVotes(parties,defaultParties);
            inicializateDefault();
        menuC menu;
        string menuTitle = "\n\t Programa Trabajo practico \n";
        string menuText[] = {
            "start",
            " votar por un partido",
            " ver resultados",
            " aniadir partido",
            "end"
        };
        const int menuOptions = sizeof(menuText) / sizeof(menuText[0])-1;
        menu.declare(menuTitle, menuText,menuOptions,0);
        while (menu.w != menu.exit) {
            menu.menu();
            wait();
            cls();
            switch (menu.w)
            {
                case 1:
                    app.vote.run(parties,defaultParties);
                break;
                case 2:
                    app.results.run(parties, file,defaultParties);
                break;
                case 3:
                    
                break;
                case menuOptions:
                    break;
                default:
                    errormens();
                    break;
            }
        }
};