#include "./../CppLibrary/include.h"
#pragma once

#define cantCandidates 25

using std::istream; using std::ostream;

struct candidatestruct{
    public:
    string name = "";
    string surname = "";

    void print(){
        cout << "Nombre: " << name << "\n\t\t";
        cout << "Apellido: " << surname << "\n";
    }

    friend istream& operator>> (istream& in, candidatestruct& data) {// to read from file
        in >> data.name >> data.surname;
        return in;
    };
    friend ostream& operator << (ostream& out, candidatestruct& data) { // to write into a file
        out << data.name <<' '<<data.surname<< "\n";
        return out;
    };
    
};

struct politicalParty{
    candidatestruct candidates[cantCandidates];
        string name;
        int lista = 0;
        int votes=0;
        int teenVotes = 0;
        int adultVotes = 0;
        int elderVotes = 0; 

        //temp variables for results
        int seats = 0;
        float percentage = 0;

        //methods
        void addCandidate(candidatestruct candidate, int i=0 ){
            candidates[i] = candidate;
        };
        void addVote(){
            votes++;
        }; 
        void printCandidates(){
            for(int i=0; i<cantCandidates; i+=1){
                cout << "\t\t" << i + 1 << ") ";
                candidates[i].print();
            }
        };
        void printVotes(){
            cout << "\t\tVotos de menores de 18: " << teenVotes << "\n";
            cout << "\t\tVotos de entre 18 a 65: " << adultVotes << "\n";
            cout << "\t\tVotos de mayores de 65: " << elderVotes << "\n";
            cout << " votos:"<< getVotes() <<"\n";
        };
        void print(){
            cout << "\n\t lista: " << lista<< "\n";
            cout<<"\t\t"<<name<<"\n";
            cout<<"\t"<<" candidatos"<<"\n";
            printCandidates();
            cout << "\t";
            printVotes();
        };
        int getVotes(){
            return (teenVotes + adultVotes + elderVotes);
        };

        bool operator <= (politicalParty comparable) {
        return (percentage <= comparable.percentage);
        };
        bool operator >= (politicalParty comparable) {
        return (percentage >= comparable.percentage);
        };
        bool operator < (politicalParty comparable) {
        return (percentage < comparable.percentage);
        };
        bool operator > (politicalParty comparable) {
        return (percentage > comparable.percentage);
        };

        friend istream& operator>> (istream& in, politicalParty& data) {// to read from file
            in >> data.name>>data.lista;
            for (int i = 0; i < cantCandidates; i += 1) in >> data.candidates[i];
            return in;
        };
        friend ostream& operator << (ostream& out, politicalParty& data) { // to write into a file
            out << data.name << " " << data.lista <<"\n";
            for (int i = 0; i < cantCandidates; i += 1) out << data.candidates[i];
            return out;
        };
};