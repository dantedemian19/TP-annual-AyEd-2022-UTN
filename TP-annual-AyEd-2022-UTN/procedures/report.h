#pragma once

#include "../CppLibrary/consoleComands.h"
#include "../CppLibrary/dynamicTypes.h"
#include "../CppLibrary/fileManager.h"
#include "../datastructs/date.h"
#include "../datastructs/party.h"
#include "../datastructs/person.h"

using std::to_string;

void printToFile(linkList<politicalParty> parties, politicalParty defaultParties[2]) {
    fileManager<string> file;
    date today;
    today.getToday();
    linkList<politicalParty>::node* temp = parties.first;
    file.declare("results", "txt");
    file.reWrite("");
    file.write("Los resultados del "+ to_string(today.day)+"/"+ to_string(today.month)+"/"+ to_string(today.year)+" son:");
    file.write("\n");
    while (temp != nullptr) {
        file.write(temp->data.name + " tiene " + std::to_string(temp->data.getVotes()) + " votos.\n");
        file.write("\t Menores de 18: \n");
        file.write("\t\t" + std::to_string(temp->data.before18VotesM) + " votos masculinos \n");
        file.write("\t\t" + std::to_string(temp->data.before18VotesF) + " votos femeninos. \n");
        file.write("\t Entre 18 y 30: \n");
        file.write("\t\t" + std::to_string(temp->data.before30VotesM) + " votos masculinos \n");
        file.write("\t\t" + std::to_string(temp->data.before30VotesF) + " votos femeninos. \n");
        file.write("\t Entre 30 y 50: \n");
        file.write("\t\t" + std::to_string(temp->data.before50VotesM) + " votos masculinos \n");
        file.write("\t\t" + std::to_string(temp->data.before50VotesF) + " votos femeninos. \n");
        file.write("\t Mayores de 50: \n");
        file.write("\t\t" + std::to_string(temp->data.after50VotesM) + " votos masculinos. \n");
        file.write("\t\t" + std::to_string(temp->data.after50VotesF) + " votos femeninos.  \n");
        file.write("\n\t Total de votos: " + std::to_string(temp->data.getVotes()) + " \n");
        file.write("\t Porcentaje de votos: " + std::to_string(temp->data.percentage) + "% \n");
        file.write("\n_______________________________________________________________________________\n");
        temp = temp->next;
    }
    file.write("\n");
    for (int i = 0 ; i>2; i+=1){
        file.write(defaultParties[i].name + " has " + std::to_string(defaultParties[i].getVotes()) + " votos.\n");
        file.write("\t Menores de 18: \n");
        file.write("\t\t" + std::to_string(defaultParties[i].before18VotesM) + " votos masculinos \n");
        file.write("\t\t" + std::to_string(defaultParties[i].before18VotesF) + " votos femeninos. \n");
        file.write("\t Entre 18 y 30: \n");
        file.write("\t\t" + std::to_string(defaultParties[i].before30VotesM) + " votos masculinos \n");
        file.write("\t\t" + std::to_string(defaultParties[i].before30VotesF) + " votos femeninos. \n");
        file.write("\t Entre 30 y 50: \n");
        file.write("\t\t" + std::to_string(defaultParties[i].before50VotesM) + " votos masculinos \n");
        file.write("\t\t" + std::to_string(defaultParties[i].before50VotesF) + " votos femeninos. \n");
        file.write("\t Mayores de 50: \n");
        file.write("\t\t" + std::to_string(defaultParties[i].after50VotesM) + " votos masculinos. \n");
        file.write("\t\t" + std::to_string(defaultParties[i].after50VotesF) + " votos femeninos.  \n");
        file.write("\n\t Total de votos: " + std::to_string(defaultParties[i].getVotes()) + " \n");
        file.write("\t Porcentaje de votos: " + std::to_string(defaultParties[i].percentage) + "% \n");
        file.write("\n_______________________________________________________________________________\n");
    }
    // write seat candidate winners
    file.write("\n");
    file.write("Los ganadores de las elecciones son: \n");
    for (int i = 0; i < parties.getSize(); i++) {
        if (parties[i]->data.seats > 0) { 
            file.write("\t" + parties[i]->data.name + " con " + std::to_string(parties[i]->data.seats) + " escaños. \n");
            file.write("\t\t sus ganadores son \n");
            for (int j = 0; j < parties[i]->data.seats; j++) {
                file.write("\t\t\t" + parties[i]->data.candidates[j].name + " "+ parties[i]->data.candidates[j].surname + "\n");
            }
        }
    }
}
