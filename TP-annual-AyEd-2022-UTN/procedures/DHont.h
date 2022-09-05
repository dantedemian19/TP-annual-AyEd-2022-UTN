#pragma once

# include "./../CppLibrary/consoleComands.h"
# include "./../classes/party.h"
# include "./../CppLibrary/dynamicTypes.h"

#define maxSeats 5

struct DHontProgram {
private:
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
    void dhont(linkList<politicalParty>& party, linkList<mult> values[]) {
        linkList<mult> ordered;
        linkList<mult>::node* cursor,* cursorOrder;
        mult temp;
        for (int i = 0; i < maxSeats; i++) {
            cursor = values[i].first;
            while (cursor != nullptr) {
                ordered.addToEnd(cursor->data);
                cursor = cursor->next;
            };
            values[i].purgeAll();
        }
        ordered.quickSort();
        cursorOrder = ordered.first;
        for (int i = 0; i < maxSeats; i++) {
            values[i].addTofirst(cursorOrder->data);
            cursorOrder = cursorOrder->next;
        };
    };

public:
    void asignSeats(linkList<politicalParty>& parties) {
        linkList<politicalParty>::node* temp = parties.first;
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
        dhont(parties,values);
        for (int i = 0; i < maxSeats; i++) {
            parties[values[i][0]->data.partyId]->data.seats += 1;
            values[i].purgeAll();
        };
    };
    
};

