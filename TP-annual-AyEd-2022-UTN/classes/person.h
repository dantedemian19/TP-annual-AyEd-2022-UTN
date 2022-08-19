#pragma once
#include "./date.h"

using std::istream; using std::ostream;

struct person {
    public:
        date birthday;
        date age;
        string name;
        void update() {
            age.getToday();
            age.year -= birthday.year;
            age.month -= birthday.month;
            age.day -= birthday.day;
            if (age.month < 0) {
                age.month += 12;
                age.year -= 1;
            }
            if (age.day < 0) {
                if (age.month == 2) {
                    age.day += 29;
                }
                else if (age.month == (3, 6, 9, 11)) {
                    age.day += 31;
                }
                else age.day += 30;
                age.month -= 1;
            }
        };
        void print() {
            cout << "\t nombre: " << name << "\n";
            cout << "\t fecha de nacimiento: "; birthday.print(); cout << "\n";
            cout << "\t desde que nacio: \n";
            cout << "\t\t\t " << age.year << " anios" << "\n";
            cout << "\t\t\t " << age.month << " meses" << "\n";
            cout << "\t\t\t " << age.day << " dias" << "\n";
        }
        bool isYoungerThan(person comparable) {
            return (age < comparable.age);
        };
        bool isOlderThan(person comparable) {
            return (age > comparable.age);
        };
        friend istream& operator>> (istream& in, person& data) {// to read from file
            in >> data.name;
            in >> data.birthday.day;
            in >> data.birthday.month;
            in >> data.birthday.year;
            return in;
        };
        friend ostream& operator << (ostream& out, person& data) { // to write into a file
            out << data.name << " " << data.birthday.day << " " << data.birthday.month << " " << data.birthday.year << "\n";
            return out;
        };

        bool operator <= (person comparable) {
            return (age <= comparable.age);
        };
        bool operator >= (person comparable) {
            return (age <= comparable.age);
        };
        bool operator < (person comparable) {
            return (age < comparable.age);
        };
        bool operator > (person comparable) {
            return (age < comparable.age);
        };
    };