#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year) {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

void addDays(int &day, int &month, int &year, int daysToAdd) {
    day += daysToAdd;
    while (day > daysInMonth(month, year)) {
        day -= daysInMonth(month, year);
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
    while (day <= 0) {
        month--;
        if (month == 0) {
            month = 12;
            year--;
        }
        day += daysInMonth(month, year);
    }
}

int main() {
    string dateStr;
    getline(cin, dateStr);

    int day, month, year;
    stringstream ss(dateStr);
    char dash;
    ss >> day >> dash >> month >> dash >> year;

    int k;
    while (true) {
        cin >> k;
        if (k == 0)
            break;

        addDays(day, month, year, k);
        cout << setw(2) << setfill('0') << day << "-" << setw(2) << setfill('0') << month << "-" << year << endl;
    }

    return 0;
}
