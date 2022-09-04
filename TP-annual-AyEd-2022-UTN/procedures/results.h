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
           if (parties[i]->data.seats > 0) cout << "\t lista: " <<parties[i]->data.lista << " " << parties[i]->data.name <<" \n\t " << parties[i]->data.seats << " " << "\n";
        }
    };
        
    void printResults(linkList<politicalParty> parties) {
        cout << "\n";
        for (int i = 0; i < parties.getSize(); i++) {
            cout << "\t" << parties[i]->data.name << " - " << parties[i]->data.getVotes() << " votos" << "\n";
        }
    };

    struct seat {
        int partyId = 0;
        int num = 0;
    };

public:
    void update(linkList<politicalParty>& parties) {
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
            temp->data.percentage = (temp->data.getVotes() * 100) / totalVotes;
            temp = temp->next;
        };
        temp = parties.first;
        //get seats d'hont
        int i = 0;
        while (temp != nullptr) {
            //d'hont
            DHontProgram dhont;
            dhont.asignSeats(parties);
            temp = temp->next;
        }
    };

    void run(linkList<politicalParty>& parties, fileManager<politicalParty>& file) {
        update(parties);
        linkList<politicalParty>::node* temp = parties.first;
        if(temp!=nullptr){
            file.reWrite(temp->data);
            while (temp!=nullptr){
                file.write(temp->data);
                temp = temp->next;   
            }
        }
        string options[] ={
            "start"
            "Mostrar resultados por partido",
            "Ver ganadores de sillas",
            "Salir"
        };
        menuC menu;
        const int cantoptions = sizeof(options) / sizeof(options[0]);
        menu.declare("Resultados", options,cantoptions);
        while (menu.w != menu.exit) {
            menu.menu();
            wait();
            cls();
            switch (menu.w) {
            case 1:
                printResults(parties);
                break;
            case 2:
                printWinners(parties);
                break;
            case cantoptions:
                break;
            default:
                errormens();
                break;
            }
        }
    }
};