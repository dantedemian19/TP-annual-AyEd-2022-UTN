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

    void loadVotes(linkList<politicalParty> parties) {
        int partyid = 0;
        int tempint = 0;
        date today;
        fileManager<person> file;
        linkList<politicalParty>::node* temp = parties.first;
        file.declare("votes","txt");
        file.readToMemory();
        vote = file.inMemoryFile[0]->data;
        vote.age.year = today.year - vote.birthday.year;
        if (!vote.age.year < 16) {
            while (1) {
                if (!(vote.dni < 0 || vote.dni > 99999999)) break;
                else {
                    cls();
                    cout << "\n\t" << "DNI invalido" << "\n";
                }
            }
            temp = parties.first;
            tempint=0;
            while(temp != nullptr){
                if (vote.IDparty == temp->data.lista) {
                    partyid = tempint;
                }
                temp = temp->next;
                tempint += 1;
            }
            if (!partyid == 0) {    
                if (vote.age.year >= 16 && vote.age.year<18) {
                    parties[partyid]->data.teenVotes++;
                }
                else if (vote.age.year >= 18 && vote.age.year<65) {
                    parties[partyid]->data.adultVotes++;
                }
                else if (vote.age.year >= 65) {
                    parties[partyid]->data.elderVotes++;
                }
            }
        }
    };

    void run(linkList<politicalParty> parties){
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
            tempStr = "lista: " + s.str() + " : " + temp->data.name;
            options.addToEnd(tempStr);
            temp = temp->next;
        };
        long int i = 0;
        today.getToday();
        const int cantOptions = parties.getSize()+1;
        menu.declare(title,options,cantOptions);
        while (menu.w != menu.exit) {
            menu.menu();
            wait();
            cls();
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
                    parties[menu.w - 1]->data.votes++;
                    if (vote.age.year >= 16 && vote.age.year<18) {
                        parties[menu.w - 1]->data.teenVotes++;
                    }
                    else if (vote.age.year >= 18 && vote.age.year<65) {
                        parties[menu.w - 1]->data.adultVotes++;
                    }
                    else if (vote.age.year >= 65) {
                        parties[menu.w - 1]->data.elderVotes++;
                    }
                    vote.IDparty = parties[menu.w - 1]->data.lista;
                    file.write(vote);
                }
                
            }
        }
    };
};