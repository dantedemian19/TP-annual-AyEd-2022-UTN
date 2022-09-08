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
        temp = temp->next;
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
            " ver resultados",
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
                    app.vote.run(parties);
                break;
                case 2:
                    app.results.run(parties,file);
                break;
                case menuOptions:
                    writefile(file,parties);
                    break;
                default:
                    errormens();
                    break;
            }
        }
};