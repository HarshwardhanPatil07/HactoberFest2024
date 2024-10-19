/*Create a class by name date with the member data day, month and year.
Perform the following:
 Overload all relational operators <,<=,>,>=,==,!=
 Overload ++ operator to increment a date by one day
 Overload + to add given number of days to find the next date
 Provide the necessary function to use the statement like days=dt;
where days is an int variable and dt is an object of date class. The
statement is intended to assign the number of days elapsed in the
current year of the date to the variable days. Note that this is a case
of conversion from derived type to basic type.*/

#include <iostream>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

    // Helper function to check if a year is a leap year
    bool isLeapYear(int year) const {
        return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    }

    // Helper function to get the number of days in a month
    int getDaysInMonth(int month, int year) const {
        if (month == 2) {
            return isLeapYear(year) ? 29 : 28;
        } else if (month == 4 || month == 6 || month == 9 || month == 11) {
            return 30;
        } else {
            return 31;
        }
    }

public:
    Date(int day, int month, int year) : day(day), month(month), year(year) {}

    // Overload relational operators
    bool operator< (const Date& other) const {
        if (year < other.year) return true;
        if (year == other.year && month < other.month) return true;
        if (year == other.year && month == other.month && day < other.day) return true;
        return false;
    }

    bool operator<= (const Date& other) const {
        return *this < other || *this == other;
    }

    bool operator> (const Date& other) const {
        return !(*this <= other);
    }

    bool operator>= (const Date& other) const {
        return !(*this < other);
    }

    bool operator== (const Date& other) const {
        return year == other.year && month == other.month && day == other.day;
    }

    bool operator!= (const Date& other) const {
        return !(*this == other);
    }

    // Overload ++ operator
    Date& operator++ () {
        day++;
        if (day > getDaysInMonth(month, year)) {
            day = 1;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
        return *this;
    }

    // Overload + operator
    Date operator+ (int days) const {
        Date temp = *this;
        for (int i = 0; i < days; i++) {
            temp.day++;
            if (temp.day > getDaysInMonth(temp.month, temp.year)) {
                temp.day = 1;
                temp.month++;
                if (temp.month > 12) {
                    temp.month = 1;
                    temp.year++;
                }
            }
        }
        return temp;
    }

    // Conversion function to int
    operator int () const {
        int days = 0;
        for (int i = 1; i < month; i++) {
            days += getDaysInMonth(i, year);
        }
        days += day;
        return days;
    }

    // Accessor methods to get the day, month, and year
    int getDay() const {
        return day;
    }

    int getMonth() const {
        return month;
    }

    int getYear() const {
        return year;
    }
};

int main() {
    Date dt1(15, 8, 2022);
    Date dt2(1, 1, 2022);
    Date dt3(31, 12, 2021);
    Date dt4(28, 2, 2020); // Leap year
    Date dt5(1, 3, 2020); // Day after leap day

    // Days elapsed in the current year
    int days1 = dt1;
    int days2 = dt2;
    int days3 = dt3;
    int days4 = dt4;
    int days5 = dt5;

    cout << "Number of days elapsed in the current year for dt1: " << days1 << endl;
    cout << "Number of days elapsed in the current year for dt2: " << days2 << endl;
    cout << "Number of days elapsed in the current year for dt3: " << days3 << endl;
    cout << "Number of days elapsed in the current year for dt4: " << days4 << endl;
    cout << "Number of days elapsed in the current year for dt5: " << days5 << endl;

    // Test addition operator
    Date dt6 = dt1 + 10;
    cout << "Date after adding 10 days to dt1: " << dt6.getDay() << "/" << dt6.getMonth() << "/" << dt6.getYear() << endl;

    // Test increment operator
    ++dt1;
    cout << "Date after incrementing dt1 by one day: " << dt1.getDay() << "/" << dt1.getMonth() << "/" << dt1.getYear() << endl;

    // Test relational operators
    cout << "dt1 < dt2: " << (dt1 < dt2) << endl;
    cout << "dt1 <= dt2: " << (dt1 <= dt2) << endl;
    cout << "dt1 > dt2: " << (dt1 > dt2) << endl;
    cout << "dt1 >= dt2: " << (dt1 >= dt2) << endl;
    cout << "dt1 == dt2: " << (dt1 == dt2) << endl;
    cout << "dt1 != dt2: " << (dt1 != dt2) << endl;

    // Test leap year
    Date leapYearTest(29, 2, 2020);
    ++leapYearTest;
    cout << "Date after incrementing 29/2/2020 by one day: " << leapYearTest.getDay() << "/" << leapYearTest.getMonth() << "/" << leapYearTest.getYear() << endl;

    return 0;
}




