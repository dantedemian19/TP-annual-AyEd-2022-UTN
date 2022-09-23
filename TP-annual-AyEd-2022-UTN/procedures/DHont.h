#pragma once

# include "./../CppLibrary/consoleComands.h"
# include "./../datastructs/party.h"
# include "./../CppLibrary/dynamicTypes.h"

#define maxSeats 5

struct DHontProgram {
private:
    struct mult {
        int partyId;
        float num;

        bool operator <= (mult comparable) {
            return (num <= comparable.num);
        };
        bool operator >= (mult comparable) {
            return (num >= comparable.num);
        };
        bool operator < (mult comparable) {
            return (num < comparable.num);
        };
        bool operator > (mult comparable) {
            return (num > comparable.num);
        };
    };
    

    void asignSeats(linkList<politicalParty> parties) {
        mult mulTemp;
        linkList<mult> order;
        order.purgeAll();
        for (int j = parties.getSize()-1; j>=0; j -= 1) {
            if (parties[j]->data.percentage > 3) {
                for (int i = 0; i < maxSeats; i++) {
                    mulTemp.partyId = j;
                    mulTemp.num = (parties[j]->data.percentage / (i + 1));
                    order.addToEnd(mulTemp);
                }
            }
        };
        order.quickSort(0, order.getSize() - 1);// orders the values
        linkList<mult>::node* cursor = order.last;
        for (int i = maxSeats-1; i >=0 ; i-=1) { // show the last values (the higher ones
            parties[cursor->data.partyId]->data.seats += 1;
            if(cursor->previous!=nullptr)cursor = cursor->previous;
        };
        
    };

public:
    
    void printTable(linkList<politicalParty>& parties) {
        asignSeats(parties);
        int size = parties.getSize()-1;
        cout << "\t" << "Lista";
        for (int i = 0; i < maxSeats; i += 1) { cout << "\t|\t" << i+1; }
        for (int i = size; i >= 0; i -= 1) {
                cout << "\n\t" << parties[i]->data.lista;
                if (parties[i]->data.percentage > 3) {
                    for (int j = 0; j < maxSeats; j += 1) cout << "\t|\t" << (parties[i]->data.percentage / (j + 1));
                }
                else cout << "________________less than 3%______________________________\n";
        }
        cout << "\n";
    };
    
};

