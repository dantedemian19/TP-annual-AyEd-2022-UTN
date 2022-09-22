#pragma once

#include "../CppLibrary/include.h"
#include "../CppLibrary/dynamicTypes.h"
#include "../classes/date.h"
#include "../classes/party.h"
#include "../classes/person.h"

#include <sstream>



struct voteProgram {
private:
    person vote;

    
public:
    void countVote(politicalParty& temp) {
        if (vote.age.year >= 16 && vote.age.year < 18) {
            temp.teenVotes++;
        }
        else if (vote.age.year >= 18 && vote.age.year < 65) {
            temp.adultVotes++;
        }
        else if (vote.age.year >= 65) {
            temp.elderVotes++;
        }
    };

    void loadVotes(linkList<politicalParty> parties, politicalParty defaultParties[2]) {
        date today;
        fileManager<person> file;
        linkList<politicalParty>::node* temp = parties.first;
        file.declare("votes", "txt");
        file.readToMemory();
        today.getToday();
        for (int i = 0; file.inMemoryFile[i] != nullptr; i += 1) {
            vote = file.inMemoryFile[i]->data;
            vote.age.year = today.year - vote.birthday.year;
            if (!(vote.age.year < 16)) {
                temp = parties.first;
                while (temp != nullptr) {
                    if (vote.IDparty == temp->data.lista){
                        countVote(temp->data);
                    break;
                }
                temp = temp->next;
                if(temp==nullptr)
                    countVote(defaultParties[0]);
                }
            }
            else countVote(defaultParties[1]);
        }
    };

    void run(linkList<politicalParty> parties, politicalParty defualtParties[2]){
        menuC menu;
        string tempStr = "";
        string title = "Votar por un partido\n";
        linkList<string> options;
        linkList<politicalParty>::node* temp = parties.first;
        fileManager<person> file;
        std::ostringstream s;
        date today;

        file.declare("votes", "txt");

        while (temp != nullptr) {
            s << temp->data.lista;
            tempStr = " lista: " + s.str() + " : " + temp->data.name;
            s.str("");
            s.clear();
            options.addToEnd(tempStr);
            temp = temp->next;
        };
        options.addToEnd(defualtParties[0].name);
        long int i = 0;
        today.getToday();
        const int cantOptions = options.getSize()+1;
        menu.declare(title,options,cantOptions);
        while (menu.w != menu.exit) {
            menu.menu();
            wait();
            cls();
            today.getToday();
            if ((menu.w > 0 && menu.w < menu.exit)) {
                vote.inputBirthday();
                vote.age.year = today.year - vote.birthday.year;
                if (vote.age.year < 16) {
                    cout << "\n\t" << "No puede votar" << "\n";
                    wait();
                    break;
                }
                else {
                    while (1) {
                        cout << "\n\t" << "Ingrese DNI: ";
                        cin >> vote.dni;
                        if (!(vote.dni < 0 || vote.dni > 99999999)) break;
                        else {
                            cls();
                            cout << "\n\t" << "DNI invalido" << "\n";
                        }
                    }
                    if (menu.w < menu.exit - 1)
                    {
                        linkList<politicalParty>::node* temp = parties[menu.w - 1];
                        countVote(temp->data);
                        vote.IDparty = parties[menu.w - 1]->data.lista;
                    }
                    else {
                        vote.IDparty = defualtParties[0].lista;
                        countVote(defualtParties[0]);
                    }
                    file.write(vote);
                }
                
            }
        }
    };
};