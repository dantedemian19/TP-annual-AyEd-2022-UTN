#pragma once

#include "../CppLibrary/include.h"
#include "../CppLibrary/dynamicTypes.h"
#include "../CppLibrary/fileManager.h"
#include "../CppLibrary/menu.h"
#include "../datastructs/date.h"
#include "../datastructs/party.h"

#include <sstream>

struct adminProgram {
    private:
        void newparty(fileManager<politicalParty>& file){
            politicalParty temp;
            while (1) {
                cout << "lista Numero: ";
                cin >> temp.lista;
                if (temp.lista > 0) break;
                else cout << "lista invalida, intente de nuevo: ";
            }
            while (1) {
                cout << "nombre del partido: ";
                cin >> temp.name;
                if (temp.name != "") break;
                else cout << "nombre invalido, intente de nuevo: ";
            }
            for (int i = 0; i < cantCandidates; i += 1) {
                while (1) {
                    cout <<i<<") " << "nombre del candidato : ";
                    cin >> temp.candidates[i].name;
                    if (temp.candidates[i].name != "") break;
                    else cout << "nombre invalido, intente de nuevo: ";
                }
                while (1) {
                    cout << i << ") " << "apellido del candidato : ";
                    cin >> temp.candidates[i].surname;
                    if (temp.candidates[i].surname != "") break;
                    else cout << "apellido invalido, intente de nuevo: ";
                }
            };
            file.inMemoryFile.addToEnd(temp);
            file.write(temp);
        };
        void selectCandidate(linkList<politicalParty>::node* party){
            menuC menu;
            string tempStr = "";
            string title = " selecionar un candidatos\n";
            linkList<string> options;
            const int size = sizeof(party->data.candidates)/sizeof(party->data.candidates[0])-1;
            for (int i = 0; i < cantCandidates; i++) {
                options.addToEnd(party->data.candidates[i].name);
            };
            menu.declare(title, options, options.getSize()+1);
            while(menu.w != menu.exit){
                cls();
                menu.menu();
                cls();
                if (menu.w < menu.exit && menu.w > 0) {
                    party->data.candidates[menu.w-1].print();
                    cout << "\n\t ingrese nuevo nombre: ";
                    cin >> party->data.candidates[menu.w-1].name;
                    cout << "\t ingrese nuevo apellido: ";
                    cin >> party->data.candidates[menu.w-1].surname;
                    options.purgeAll();
                    for (int i = 0; i < size; i++) { // refresh options
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
                        cout << "\t\t";
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
                        file.memoryToFile();
                        menu.w=menu.exit;
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
            if (menu.w == cantOptions - 1) {
                newparty(file);
                parties = file.inMemoryFile;
                menu.w = menu.exit;
            }
            else if (menu.w > 0 && menu.w < menu.exit) {
                editParty(parties[menu.w], file, menu.w-1); 
                menu.w = menu.exit;
            }
            if (menu.w == menu.exit) { 
                parties = file.inMemoryFile; 
                break;
                
            }
        };
    };
};