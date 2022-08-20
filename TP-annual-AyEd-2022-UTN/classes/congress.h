#pragma once

using std::istream; using std::ostream;

struct seats{
    public:
        int id;
        int partyId;
        int votes;
        void print() {
            cout << "\t id: " << id << "\t";
            cout << "\t partyId: " << partyId << "\t";
            cout << "\t votes: " << votes << "\t";
        }
        
        friend istream& operator>> (istream& in, seats& data) {// to read from file
            in >> data.id;
            in >> data.partyId;
            in >> data.votes;
            return in;
        };
        friend ostream& operator << (ostream& out, seats& data) { // to write into a file
            out << data.id << "\n";
            out << data.partyId << "\n";
            out << data.votes << "\n";
            return out;
        };
};
}

struct elections{
    public:
        string name;
        
    };

}