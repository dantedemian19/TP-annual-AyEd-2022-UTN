#pragma once

#include "./date.h"
#include "../CppLibrary/consoleComands.h"

struct person{
    int IDparty = 0;
    int dni = 0;
    date birthday;
    date age;
    char gender = ' ';
    

    bool verify(date data) {
        // if its ferbuary
        if (data.day > 29 && data.month == 2)
            return true;
        // if the month have 31 days
        else if (data.day > 31 && data.month == (3, 6, 9, 11))
            return true;
        //if the month have 30 days
        else if (data.day > 30)
            return true;
        // if its out of value
        else return false;
    };

    void inputBirthday() {
        cout << "\n";
        while (1) {
            cout << "\t ingrese el anio de nacimiento: ";
            cin >> birthday.year;
            if (birthday.year < 1) {
                cls();
                cout << "\n\t (ingrese un valor valido)";
            }
            else break;
        }
        while (1) {
            cout << "\t ingrese el mes de nacimiento en numero: ";
            cin >> birthday.month;
            if (birthday.month < 1 || birthday.month > 12) {
                cls();
                cout << "\n\t (ingrese un valor valido)";
            }
            else break;
        }
        while (1) {
            cout << "\t ingrese el dia de nacimiento: ";
            cin >> birthday.day;
            if (birthday.day < 1 || verify(birthday)) {
                cls();
                cout << "\n\t (ingrese un valor valido)";
            }
            else break;
        }
    };

    friend istream& operator>> (istream& in, person& data) {// to read from file
        in >> data.dni >> data.birthday >> data.IDparty>>data.gender;
        return in;
    };
    friend ostream& operator << (ostream& out, person& data) { // to write into a file
        out << data.dni << ' ' << data.birthday << ' ' << data.IDparty << " " <<data.gender<< "\n";
        return out;
    };

};