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
           if (parties[i]->data.seats > 0) cout << "\t lista: " <<parties[i]->data.lista << " " << parties[i]->data.name <<" \n\t escanios: " << parties[i]->data.seats << " " << "\n";
        }
    };

    struct seat {
        int partyId = 0;
        int num = 0;
    };

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

    void update(linkList<politicalParty>& parties) { // calculate the seats
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
            temp->data.seats = 0;
            temp = temp->next;
        };
        DHontProgram dhont;
        dhont.asignSeats(parties);
    };

public:
    

    void run(linkList<politicalParty>& parties, fileManager<politicalParty>& file) {
        update(parties);
        linkList<politicalParty>::node* temp = parties.first;
        if(temp!=nullptr){
            file.reWrite(temp->data);
            temp = temp->next;
            while (temp!=nullptr){
                file.write(temp->data);
                temp = temp->next;   
            }
        }
        string menuText[] = {
            "start",
            "Mostrar resultados por partido",
            "Ver ganadores de sillas",
            "end"
        };
        menuC menu;
        const int cantOptions = sizeof(menuText) / sizeof(menuText[0])-1;
        menu.declare("Resultados", menuText,cantOptions);
        while (menu.w != menu.exit) {
            menu.menu();
            wait();
            cls();
            switch (menu.w) {
            case 1:
                showByParty(parties);
                break;
            case 2:
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