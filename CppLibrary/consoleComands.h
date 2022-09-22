#pragma once
#include "include.h"




void pause() {
    int cha = 0;
    cout << "\t pulse a enter to continue";
    while (cha != 13) {
        cha = _getch();
    }
};
void cls() {
#if defined _WIN32
    //cout << "\033c";
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = { 0, 0 };
    DWORD count;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hStdOut, &csbi);
    FillConsoleOutputCharacter(hStdOut, ' ', csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
    SetConsoleCursorPosition(hStdOut, coord);
#elif (__LINUX__) || defined(__gnu_linux__) || defined(__linux__) 
    cout << "\x1B[2J\x1B[H";
#endif
};
void wait(int time = 2) {// hace esperar al usuario 2 segundos
    time *= 1000;
    int passed = 0;
    int i = 5;
    while (passed < time) {
        if (i > 5) { i = 0;  cls(); cout << "\n\t loading"; }
        Sleep(200);
        passed += 200;
        cout << ".";
        i += 1;
    }
};
void errormens() {
    cout << " an error was ocurred, please be alarmed and run to a safe place  \n"; // not an easter egg
};