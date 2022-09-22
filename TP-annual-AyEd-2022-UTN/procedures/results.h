#pragma once

#include "../CppLibrary/include.h"
#include "../CppLibrary/dynamicTypes.h"
#include "../classes/date.h"
#include "../classes/party.h"
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

    void showByParty(linkList<politicalParty> parties) {
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
        const int cantOptions = parties.getSize()+1;
        menu.declare(title,options,cantOptions);
        while (menu.w != menu.exit) {
            menu.menu();
            wait();
            cls();
            if ((menu.w > 0 && menu.w < menu.exit)) {
                cout <<"\n";
                parties[menu.w-1]->data.print();
                pause();
            }
        }
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
                showByParty(parties);
                break;
            case 2:
                dhont.printTable(parties);
                for (int j = 0; j < 2; j += 1) cout <<"\n\t"<<defaultParties[j].name<< "\t|\t" << defaultParties[j].getVotes()<<"\n";
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