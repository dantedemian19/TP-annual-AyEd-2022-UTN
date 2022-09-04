#pragma once

# include "./../CppLibrary/consoleComands.h"
# include "./../classes/party.h"
# include "./../CppLibrary/dynamicTypes.h"

#define maxSeats 5

struct DHontProgram {
    struct mult {
        int partyId;
        int num;

        friend bool operator > (mult data, mult comparable) {
            if (data.num > comparable.num)  return true;
            else                            return false;
        };
        friend bool operator < (mult data, mult comparable) {
            if (data.num < comparable.num)  return true;
            else                            return false;
        };
        friend bool operator == (mult data, mult comparable) {
            return (data.num == comparable.num);
        };
        friend bool operator != (mult data, mult comparable) {
            return (data != comparable);
        };
        friend bool operator <= (mult data, mult comparable) {
            return (comparable == data || comparable < data);
        };
        friend bool operator >= (mult data, mult comparable) {
            return (comparable == data || comparable > data);
        };
    };

    void asignSeats(linkList<politicalParty>& party) {
        linkList<politicalParty>::node* temp = party.first;
        linkList<mult> values[maxSeats];
        mult mulTemp ;
        int j = 0;
        while (temp != nullptr) {
            if(temp->data.percentage > 3)
            for (int i = 0; i < maxSeats; i++) {
                mulTemp.partyId = j;
                mulTemp.num = temp->data.votes / (i + 1);
                values[i].addToEnd(mulTemp);
            }
            j += 1;  
            temp = temp->next;
        };
        for (int i = 0; i < maxSeats; i++) {
            values[i].quickSort();
        };
        for (int i = 0; i < maxSeats; i++) {
            party[values[i][0]->data.partyId]->data.seats += 1;
            values[i].purgeAll();
        };
    };
    
};

