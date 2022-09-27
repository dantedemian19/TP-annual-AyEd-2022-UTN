#pragma once

#include "../CppLibrary/include.h"
#include "../CppLibrary/dynamicTypes.h"
#include "../CppLibrary/fileManager.h"
#include "../CppLibrary/menu.h"
#include "../datastructs/date.h"
#include "../datastructs/party.h"

#include <sstream>

class adminProgram {
    private:
        void newparty(fileManager<politicalParty>& file){
            politicalParty temp;
            cout << "lista Numero: ";
            cin >> temp.lista;
            cout << "Nombre del partido: ";
            cin >> temp.name;
            cout << "Nombre de la lista: ";
            cin >> temp.lista;
            file.inMemoryFile.addToEnd(temp);
            file.write(temp);
        };
        void selectCandidate(linkList<politicalParty>::node* party){
            menuC menu;
            string tempStr = "";
            string title = " selecionar un candidatos\n";
            linkList<string> options;
            const int size = sizeof(party->data.candidates)/sizeof(party->data.candidates[0])-1;
            for (int i = 0; i < size; i++) {
                options.addToEnd(party->data.candidates[i].name);
            };
            menu.declare(title, options, options.getSize()+1);
            while(menu.w != menu.exit){
                cls();
                menu.menu();
                cls();
                if (menu.w < menu.exit && menu.w > 0) {
                    party->data.candidates[menu.w-1].print();
                    cout << "\t ingrese nuevo nombre: ";
                    cin >> party->data.candidates[menu.w-1].name;
                    cout << "\t ingrese nuevo apellido: ";
                    cin >> party->data.candidates[menu.w-1].surname;
                    options.purgeAll();
                    for (int i = 0; i < size; i++) {
                        options.addToEnd(party->data.candidates[i].name);
                    };
                    menu.declare(title, options, options.getSize() + 1);
                }else if (menu.w == menu.exit) {
                    break;
                };
            };
        };
        void editParty(linkList<politicalParty>::node* party, fileManager<politicalParty>& file, int w){
            menuC menu;
            string tempStr = "";
            string title = " editar partido\n";
            string options[] = {
                "start",
                " cambiar nombre del partido",
                " cambiar candidatos",
                " borrar partido",
                "end"
            };
            const int cantOptions = sizeof(options)/sizeof(options[0])-1;
            menu.declare(title, options, cantOptions);
            while(menu.w != menu.exit){
                cls();
                menu.menu();
                cls();
                switch (menu.w) {
                    case 1:
                        cout << "\t lista: " << party->data.lista <<") "<< party->data.name << "\n";
                        cout << "\t\tNombre de la lista: ";
                        cout << "Nombre del partido: ";
                        cin >> party->data.name;
                        file.memoryToFile();
                        break;
                    case 2:
                        selectCandidate(party);
                        file.memoryToFile();
                        break;
                    case 3: 
                        file.inMemoryFile.delNode(w);
                        break;
                    case cantOptions:
                        break;
                };
            };
        };
    public:
    void run(linkList<politicalParty>& parties, fileManager<politicalParty>& file) {
        menuC menu;
        string tempStr = "";
        string title = " Administrar partidos \n";
        linkList<string> options;
        linkList<politicalParty>::node* temp = parties.first;
        std::ostringstream s;

        while (temp != nullptr) {
            s << temp->data.lista;
            tempStr = " lista: " + s.str() + " : " + temp->data.name;
            s.str("");
            s.clear();
            options.addToEnd(tempStr);
            temp = temp->next;
        };
        options.addToEnd("Crear nuevo partido");
        int cantOptions = options.getSize()+1;
        menu.declare(title, options, cantOptions);

        while (menu.w != menu.exit) {
            cls();
            menu.menu();
            cls();
            if (menu.w == cantOptions-1) newparty(file);
            else if (menu.w > 0 && menu.w < menu.exit) {
                editParty(parties[menu.w], file, menu.w-1); 
                options.purgeAll();
                while (temp != nullptr) {
                    s.str("");
                    s.clear();
                    s << temp->data.lista;
                    tempStr = " lista: " + s.str() + " : " + temp->data.name;
                    options.addToEnd(tempStr);
                    temp = temp->next;
                }; 
                options.addToEnd("Crear nuevo partido");
                int cantOptions = options.getSize() + 1;
                menu.declare(title, options, cantOptions);
            }
            else if (menu.w == menu.exit) { 
                parties = file.inMemoryFile; 
                break;
                
            }
        };
    };
};