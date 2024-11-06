//
// Created by lenovo on 2024/11/5.
//

#include "Date.h"
#include <iostream>
using std::cout;
using std::endl;
using std::min;

void Date::print() const {
    cout << year << '-' << month << '-' << day << endl;
}

int Date::numofDayInMonth() const {
    static int sNumofDayInMonth[13] = {0, 31, -1, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (this->month != 2) return sNumofDayInMonth[this->month];
    else {
        if ((this->year % 4 == 0 || this->year % 100) && this->year % 400 != 0) return 29;
        else return 28;
    }
}

int Date::numofMonthInYear() const {
    return 12;
}

void Date::plusDays(int nDays) {
    this->day += nDays;
    if (this->day > this->numofDayInMonth()) {
        this->day -= this->numofDayInMonth();
        this->month++;
    }
    if (this->month > this->numofMonthInYear()) {
        this->month -= this->numofMonthInYear();
        this->year++;
    }
}

void Date::plusMonths(int nMonths) {
    int numofMonth = this->numofMonthInYear();
    this->month = (this->month + nMonths) % numofMonth + numofMonth % numofMonth;
    this->day = min(this->day, this->numofDayInMonth());
}
