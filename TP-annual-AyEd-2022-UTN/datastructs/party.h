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
        int before18VotesM = 0;
        int before30VotesM = 0;
        int before50VotesM = 0; 
        int after50VotesM = 0;
        int before18VotesF = 0;
        int before30VotesF = 0;
        int before50VotesF = 0; 
        int after50VotesF = 0;
        //temp variables for results
        int seats = 0;
        float percentage = 0;

        //methods
        void addCandidate(candidatestruct candidate, int i=0 ){
            candidates[i] = candidate;
        };
        void printCandidates(){
            for(int i=0; i<cantCandidates; i+=1){
                cout << "\t\t" << i + 1 << ") ";
                candidates[i].print();
            }
        };
        void printVotes(){
            cout << "\t\tVotos de menores de 18: " << before18VotesM + before18VotesF << "\n";
            cout << "\t\tVotos de entre 18 a 30: " << before30VotesM + before30VotesF << "\n";
            cout << "\t\tVotos de entre 30 a 50: " << before50VotesM + before50VotesF << "\n";
            cout << "\t\tVotos de mayores de 50: " << after50VotesM  + after50VotesF  << "\n";
            cout << "\t\tTotal votos:"<< getVotes() <<"\n";
        };
        void printByGender(){
            cout << "\t\tVotos de hombres " << "\n";
            cout << "\t\t Votos de menores de 18: " << before18VotesM << "\n";
            cout << "\t\t Votos de entre 18 a 30: " << before30VotesM << "\n";
            cout << "\t\t Votos de entre 30 a 50: " << before50VotesM << "\n";
            cout << "\t\t Votos de mayores de 50: " << after50VotesM  << "\n";
            cout << "\t\t Total: \t\t"<< (before18VotesM + before30VotesM + before50VotesM + after50VotesM) <<"\n";
            cout << "\n\t\tVotos de mujeres " << "\n";
            cout << "\t\t Votos de menores de 18: " << before18VotesF << "\n";
            cout << "\t\t Votos de entre 18 a 30: " << before30VotesF << "\n";
            cout << "\t\t Votos de entre 30 a 50: " << before50VotesF << "\n";
            cout << "\t\t Votos de mayores de 50: " << after50VotesF  << "\n";
            cout << "\t\t Total: \t\t"<< (before18VotesF + before30VotesF + before50VotesF + after50VotesF) <<"\n";
            cout << "\n\n\t\tTotal votos:"<< getVotes() <<"\n";
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
            return ((before18VotesM + before18VotesF) + (before30VotesM + before30VotesF) + (before50VotesM + before50VotesF) + (after50VotesM  + after50VotesF));
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