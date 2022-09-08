#pragma once
#include "consoleComands.h"
#include "dynamicTypes.h"
#include "include.h"

// keyboard id's
#define space 32
#define up 72
#define down 80
#define entr 13
#define esc 27
#define back 8


struct menuC {
    private:
        string name = "";
        int program = 0;
        bool enter = false;
        string namef = "";
        linkList<string> text;
        string exitText[2] = {
        " exit",
        " back"
        };
    public:
        int w = 1, exit = 0;
        void detection();
        void menu();
        void declare(string nameOfMenu, string menuText[], int numberOfOptions, int numberProgram = 1);
        void declare(string nameOfMenu, linkList<string> menuText, int numberOfOptions, int numberProgram = 1);
};

void advice() {
    //advice for users
    cout << " pulse W o UP para subir y S o DOWN para bajar \n";
    Sleep(1000);
    cout << " pulse ESC or DEL para salir \n";
    Sleep(1000);
    cout << " pulse F o ENTER para acceder o aceptar \n";
    Sleep(500);
    pause();
    cls();
    //advice
};

void menuC::detection() { // mueve el cursor dependiendo la decision del usuario
    int c = 0;
    // keyboard detection
    while (c != 's' && c != 'w' && c != 'f' && c != entr && c != up && c != down && c != esc && c != back) {
        c = _getch();
    }
    if (c == 'w' || c == up) {// if the user press up or W
        if (w > 1) {
            w = w - 1;
        }
        else {
            w = exit;
        }
    }
    if (c == 's' || c == down) {// if the user press down or S
        if (w < exit) {
            w = w + 1;
        }
        else {
            w = 1;
        }
    }
    if (c == 'f' || c == entr) {// if the user press enter or F
        enter = !enter;
    }
    if (c == back || c == esc) {// if the user press DELETE or ESC
        w = exit;
        enter = !enter;
    }
};

void menuC::menu() {// its a easy menu
        enter = false;
        int i = 1;
        while (!enter) {
            i = 1;
            cls();//cursor appears only in selected option 
            cout << " " << name << "  \n";
            while(i<=exit) {
                if (i != exit) {
                    if (w == i) { cout << "  >>"; } cout << "\t" << text[i]->data << "\n";
                }
                else { if (w == i) { cout << "  >>"; } cout << "\t" << exitText[program] << "\n"; }
                 i += 1;
            }
            //detection of the cursor
            detection();
            //detection of the cursor
        }
        cls();
}; 

void menuC::declare(string nameOfMenu, string menuText[], int numberOfOptions, int numberProgram) {
    int i = 0;
    while (numberOfOptions > i) {
        text.addToEnd(menuText[i]);
        i += 1;
    }
    exit    = numberOfOptions;
    program = numberProgram;
    name    = nameOfMenu;
};

void menuC::declare(string nameOfMenu, linkList<string> menuText, int numberOfOptions, int numberProgram) {
    text.addTofirst("enter");
    linkList<string>::node* temp = menuText.first;
    while (temp!=nullptr) {
        text.addToEnd(temp->data);
        temp = temp->next;
    }
    text.addToEnd("back");
    exit = numberOfOptions;
    program = numberProgram;
    name = nameOfMenu;
};
