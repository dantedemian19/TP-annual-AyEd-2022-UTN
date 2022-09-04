#pragma once

#include "../CppLibrary/include.h"
#include "../CppLibrary/dynamicTypes.h"
#include "../classes/date.h"
#include "../classes/party.h"


struct resultsProgram {
private:
    void printResults(linkList<politicalParty> parties) {
        cout << "\n";
        for (int i = 0; i < parties.getSize(); i++) {
            cout << "\t" << parties[i]->data.name << " - " << parties[i]->data.getVotes() << " votos" << "\n";
        }
    };

public:
    void run(linkList<politicalParty> parties) {
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
        while (temp != nullptr) {
            //d'hont
            
            temp = temp->next;
        };


        printResults(parties);
    };
};