#pragma once

#include "../CppLibrary/include.h"
#include "../CppLibrary/dynamicTypes.h"
#include "../datastructs/date.h"
#include "../datastructs/party.h"
#include "../procedures/DHont.h"


struct resultsProgram {
private:
    void printWinners(linkList<politicalParty> parties) {
        for (int i = 0; i < parties.getSize(); i++) {
            if (parties[i]->data.seats > 0) { 
                cout << "\t lista: " << parties[i]->data.lista << " " << parties[i]->data.name << " \n\t escanios: " << parties[i]->data.seats << " " << "\n"; 
                for (int j = 0; j < parties[i]->data.seats; j += 1) { cout << "\t\t"; parties[i]->data.candidates[j].print(); cout << "\n"; }
            }
        }
    };

    DHontProgram dhont;

    void showByParty(politicalParty party) {
        menuC menu;
        string tempStr = "";
        string title = "Partido: " + party.name;
        string options[] = {
            "start",
            " ver partido y votos",
            " ver votos por genero y edad", 
            "end"
        };
        const int cantOptions = sizeof(options)/sizeof(options[0])-1;
        menu.declare(title, options, cantOptions);
        while(menu.w != menu.exit){
            menu.menu();
            switch (menu.w) {
                case 1:
                    party.print();
                    pause();
                    break;
                case 2:
                    party.printByGender();
                    pause();
                    break;
                case cantOptions:
                    break;
            };
        };
    };
    
    void filterByParty(linkList<politicalParty> parties) {
        menuC menu;
        string tempStr = "";
        string title = "mostrar partido\n";
        linkList<string> options;
        linkList<politicalParty>::node* temp = parties.first;
        std::ostringstream s; // used to convert integer to string
        while (temp != nullptr) {
            s.str("");
            s << temp->data.lista;
            tempStr = "lista: " + s.str() + " : " + temp->data.name;
            options.addToEnd(tempStr);
            temp = temp->next;
        };
        const int cantOptions = options.getSize()+1;
        menu.declare(title,options,cantOptions);
        while (menu.w != menu.exit) {
            menu.menu();
            wait();
            cls();
            if ((menu.w > 0 && menu.w < menu.exit)) {
                showByParty(parties[menu.w-1]->data);
            }
        };
    };

    void update(linkList<politicalParty> parties) { // calculate the seats
        linkList<politicalParty>::node* temp = parties.first;
        //count total votes
        int totalVotes = 0;
        while (temp != nullptr) {
            totalVotes += temp->data.getVotes();
            temp = temp->next;
        };
        temp = parties.first;
        //get percentage of votes
        while (temp != nullptr) {
            temp->data.percentage = ((temp->data.getVotes() * static_cast<float>(100)) / totalVotes);
            temp = temp->next;
        }

        temp = parties.first;
        //get seats d'hont
        parties.quickSort(0, parties.getSize() - 1);
        int i = 0;
        while (temp != nullptr) {
            //d'hont
            temp->data.seats = 0;
            temp = temp->next;
        }
    };

    void showVotes( linkList<politicalParty> parties) {
        politicalParty temp;
        int totalVotes = 0;
        update(parties);
        for (int i = 0; parties[i]!=nullptr; i+=1) {
            temp.before18VotesM += parties[i]->data.before18VotesM;
            temp.before18VotesF += parties[i]->data.before18VotesF;
            temp.before30VotesM += parties[i]->data.before30VotesM;
            temp.before30VotesF += parties[i]->data.before30VotesF;
            temp.before50VotesM += parties[i]->data.before50VotesM;
            temp.before50VotesF += parties[i]->data.before50VotesF;
            temp.after50VotesM  += parties[i]->data.after50VotesM;
            temp.after50VotesF  += parties[i]->data.after50VotesF;
            totalVotes += parties[i]->data.getVotes();
            cout << "\t lista: " << parties[i]->data.lista << " " << parties[i]->data.name << " \n\t votos: " << parties[i]->data.getVotes() << " " << "\n";
        }
        cout << "\t\tvotos de hombres"<< "\n";
        cout << "\t\t hay "<<temp.before18VotesM<<" votos de hombres menores a 18 \n";
        cout << "\t\t hay "<<temp.before30VotesM<<" votos de hombres menores a 30 \n";
        cout << "\t\t hay "<<temp.before50VotesM<<" votos de hombres menores a 50 \n";
        cout << "\t\t hay "<<temp.after50VotesM<<" votos de hombres mayores a 50 \n";

        cout<< "\t\tvotos de mujeres \n";
        cout << "\t\t hay "<<temp.before18VotesF<<" votos de mujeres menores a 18 \n";
        cout << "\t\t hay "<<temp.before30VotesF<<" votos de mujeres menores a 30 \n";
        cout << "\t\t hay "<<temp.before50VotesF<<" votos de mujeres menores a 50 \n";
        cout << "\t\t hay "<<temp.after50VotesF<<" votos de mujeres mayores a 50 \n";
        cout << "\n\n\t\tvotos totales: " << totalVotes << "\n";
    };

public:
    

    void run(linkList<politicalParty>& parties, fileManager<politicalParty>& file , politicalParty defaultParties[2]) {
        try { update(parties); }
        catch (...) {
            cout << "\n\t error! no hay votos ingresados \n";
            pause();
            return;
        };
        //parties.quickSort(0,parties.getSize() - 1);
        string menuText[] = {
            "start",
            "Mostrar resultados por partido",
            "Mostrar Cantidades de votos",
            "Ver ganadores de sillas",
            "end"
        };
        menuC menu;
        const int cantOptions = sizeof(menuText) / sizeof(menuText[0]) - 1;
        menu.declare("Resultados", menuText, cantOptions);
        while (menu.w != menu.exit) {
            menu.menu();
            wait();
            cls();
            switch (menu.w) {
            case 1:
                filterByParty(parties);
                break;
            case 2:
                showVotes(parties);
                pause();
                break;
            case 3:
                update(parties);
                dhont.printTable(parties);
                for (int j = 0; j < 2; j += 1) cout <<"\n\t"<<defaultParties[j].name<< "\t|\t" << defaultParties[j].getVotes()<<"\n\n";
                printWinners(parties);
                pause();
                break;
            case cantOptions:
                break;
            default:
                errormens();
                break;
            }
        }
    }
};