#pragma once

#include "../CppLibrary/include.h"
#include "../CppLibrary/dynamicTypes.h"
#include "../classes/date.h"
#include "../classes/party.h"

#include <sstream>



struct voteProgram {
private:
    bool verify(date data) {
        // if its ferbuary
        if (data.day > 29 && data.month == 2)
            return true;
        // if the month have 31 days
        else if (data.day > 31 && data.month == (3, 6, 9, 11))
            return true;
        //if the month have 30 days
        else if (data.day > 30)
            return true;
        // if its out of value
        else return false;
    };
    void inputData(date data) {
        cout << "\n";
        while (1) {
            cout << "\t ingrese el anio de nacimiento: ";
            cin >> data.year;
            if (data.year < 1) {
                cls();
                cout << "\n\t (ingrese un valor valido)";
            }
            else break;
        }
        while (1) {
            cout << "\t ingrese el mes de nacimiento en numero: ";
            cin >> data.month;
            if (data.month < 1 || data.month > 12) {
                cls();
                cout << "\n\t (ingrese un valor valido)";
            }
            else break;
        }
        while (1) {
            cout << "\t ingrese el dia de nacimiento: ";
            cin >> data.day;
            if (data.day < 1 || verify(data)) {
                cls();
                cout << "\n\t (ingrese un valor valido)";
            }
            else break;
        }
    };
public:
    void run(linkList<politicalParty> parties){
        menuC menu;
        string tempStr = "";
        string title = "Votar por un partido\n";
        linkList<string> options;
        linkList<politicalParty>::node* temp = parties.first;
        std::ostringstream s;
        while (temp != nullptr) {
            s << temp->data.lista;
            tempStr = "lista: " + s.str() + " : " + temp->data.name;
            options.addToEnd(tempStr);
            temp = temp->next;
        };
        long int dni, i = 0;
        date birthday,age, today;
        today.getToday();
        const int cantOptions = parties.getSize()+1;
        menu.declare(title,options,cantOptions);
        while (menu.w != menu.exit) {
            menu.menu();
            wait();
            cls();
            if ((menu.w > 0 && menu.w < menu.exit)) {
                inputData(birthday);
                age.year = today.year - birthday.year;
                if (age.year < 16) {
                    cout << "\n\t" << "No puede votar" << "\n";
                    wait();
                    break;
                }
                else {
                    while (1) {
                        cout << "\n\t" << "Ingrese DNI: ";
                        cin >> dni;
                        if (!(dni < 0 || dni > 99999999)) break;
                        else {
                            cls();
                            cout << "\n\t" << "DNI invalido" << "\n";
                        }
                    }
                    parties[menu.w - 1]->data.votes++;
                    if (age.year >= 16 && age.year<18) {
                        parties[menu.w - 1]->data.teenVotes++;
                    }
                    else if (age.year >= 18 && age.year<65) {
                        parties[menu.w - 1]->data.adultVotes++;
                    }
                    else if (age.year >= 65) {
                        parties[menu.w - 1]->data.elderVotes++;
                    }

                }
            }
        }
    };
};