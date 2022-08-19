#pragma once
#include "./person.h"

#define cantCandidates 25

struct candidatestruct{
    public:
    string name = "";



};

struct politicalParty{
    private: 
        candidatestruct candidates[cantCandidates];
        int votes=0;
        string name;
        
    public:
        void addCandidate(candidatestruct candidate, int i=0 ){
            candidates[i] = candidate;
        };
        void addVote(){
            votes++;
        }; 
        void printCandidates(){
            for(int i=0; i<cantCandidates; i+=1){
                cout<<"\t"<<i+1<<") "<<candidates[i].name<<"\n";
            }
        };
        void printVotes(){
            cout <<votes<<" votos\n";
        };
        void print(){
            cout<<"\t"<<name<<"\n";
            cout<<"\t"<<" candidatos"<<"\n";
            printCandidates();
            printVotes();
        };
};