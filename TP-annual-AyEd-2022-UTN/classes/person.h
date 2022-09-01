#pragma once

using std::istream; using std::ostream;

struct person {
    public:
        string name;
        void print() {
            cout << "\t nombre: " << name << "\n";
            cout << "\t fecha de nacimiento: "; birthday.print(); cout << "\n";
            cout << "\t desde que nacio: \n";
            cout << "\t\t\t " << age.year << " anios" << "\n";
            cout << "\t\t\t " << age.month << " meses" << "\n";
            cout << "\t\t\t " << age.day << " dias" << "\n";
        }
        
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
    };