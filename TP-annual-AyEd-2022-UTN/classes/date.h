#pragma once
#include "../CppLibrary/include.h"
#include <ctime>

struct date {
    public:
        long int day = 0;
        long int month = 0;
        long int year = 0;
        void getToday() {
            tm today;
            time_t now = time(0);
            localtime_s(&today, &now);
            day = today.tm_mday;
            month = today.tm_mon + 1;
            year = today.tm_year + 1900;
        };
        void print() {
            cout << day << "/" << month << "/" << year << " ";
        };

        friend istream& operator>> (istream& in, date& data) {// to read from file
            in >> data.day >> data.month >> data.year;
            return in;
        };
        friend ostream& operator << (ostream& out, date& data) { // to write into a file
            out << data.day << " " << data.month << " " << data.year;
            return out;
        };

        friend bool operator > (date data,date comparable) {
            if (data.year > comparable.year)          return true;
            else if (data.month > comparable.month && data.year == comparable.year)    return true;
            else if (data.day > comparable.day && data.year == comparable.year && data.month == comparable.month)       return true;
            else                                        return false;
        };
        friend bool operator < (date data,date comparable) {
            if (data.year < comparable.year)          return true;
            else if (data.month < comparable.month && data.year == comparable.year)    return true;
            else if (data.day < comparable.day && data.year == comparable.year && data.month == comparable.month)       return true;
            else                                        return false;
        };
        friend bool operator == (date data, date comparable) {
            return (data.day == comparable.day && data.month == comparable.month && data.year == comparable.year);
        };
        friend bool operator != (date data, date comparable) {
            return (data != comparable);
        };
        friend bool operator <= (date data, date comparable) {
            return (comparable == data || comparable < data);
        };
        friend bool operator >= (date data,date comparable) {
            return (comparable == data || comparable > data);
        };
    };