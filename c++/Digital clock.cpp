#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include<conio.h>
#include<windows.h>
using namespace std;

int c_Code(int c_year)
{
    if (c_year % 4 == 0 && c_year % 100 != 0 || c_year % 400 == 0)
        return 0;
    else if (c_year == 1700 || c_year == 2100 || c_year == 2500)
        return 5;
    else if (c_year == 1800 || c_year == 2200)
        return 3;
    else if (c_year == 1900 || c_year == 2300)
        return 1;
}
int dayCode(int day, int month, int year) {
    int i, c_year, ccode, ycode, lyear, days = 0, dayCode;
    int monthCode[] = { 31,year % 4 == 0 && year % 100 != 0 || year % 400 == 0 ? 29 : 28,31,30,31,30,31,31,30,31,30,31 };
    ycode = (year - 1) % 100;
    c_year = (year - 1) - ycode;
    lyear = ycode / 4;
    ccode = c_Code(c_year);
    for (i = 0; i < month - 1; i++) {
        days += monthCode[i];
    }
    days = days + day;
    dayCode = (ccode + ycode % 7 + lyear % 7 + days % 7) % 7;
    return dayCode;
}
void printMon(int dayc, int mon) {
    int i, j, k = 1;
    cout << "   ---------------------------------"<<endl;;
    cout << "   Sun\tMon  Tue  Wed  Thu  Fri  Sat"<<endl;
    cout << "   ---------------------------------"<<endl;
    for (i = 1; i <= 6; i++) {
        for (j = 0; j < 7 && k <= mon; j++)
        {
            if (i == 1 && j < dayc)
                cout << "     ";
            else
                printf("%5d", k++);
        }
        cout << endl;
    }
    cout << ("   ---------------------------------");
}
void print_calendar(int year)
{
    if (year > 0) {
        char month[][20] = { "JANUARY","FEBRUARY","MARCH","APRIL","MAY","JUNE","JULY","AUGUST","SEPTEMBER","OCTOBER","NOVEMBER","DECEMBER" };
        int monthCode[] = { 31,year % 4 == 0 && year % 100 != 0 || year % 400 == 0 ? 29 : 28,31,30,31,30,31,31,30,31,30,31 };
        for (int m = 0; m < 12; m++) {
            cout << "\n\t ***** " << month[m] << " *****" << endl;
            printMon(dayCode(1, m + 1, year), monthCode[m]);
        }
    }
    else
        cout << "Invalid year...";
}



int main()
{

    int op;
    cout << "Press 1 for calendar" << endl;
    cout << "Press 2 for time- set in form of HH MM SS " << endl;
    cout << "Press 3 for stopwatch" << endl;
    cin >> op;

    switch (op) {
    case 1:
        int year;
        cout << "Enter year : ";
        cin >> year;
        print_calendar(year);
        return 0;
        break;


    case 2:

        cout << "SET YOUR TIME" << endl;

        int hr, min, sec;

        cin >> hr >> min >> sec;

        while (true) {


            system("cls");
            cout << hr << "  :" << min << "  :" << sec << "  pm" << endl;
            sec++;
            if (sec == 60) {
                min++;
                sec = 0;
                if (min == 60) {
                    hr++;
                    min = 0;
                    if (hr == 12) {
                        hr = 0;
                    }
                }
            }
            sleep(1);
        }
        break;


    case 3: {

        int hour = 0;
        int minute = 0;
        int second = 0;


        while (! _kbhit()) {


          system("cls");
          //clrscr();
            cout << hour << "  hr: " << minute << "  min: " << second << " sec" << endl;
            second++;
            if (second > 59) {
                minute++;
                second = 0;
                if (minute > 59) {
                    hour++;
                    minute = 0;



                }
            }
            _sleep(1000);
            // cout << "Stopwatch stopped at " << hour << minute << second << endl;

        }
        _getch();
        cout << "Stopwatch stopped at " << hour <<" :"<< minute <<": "<< second << endl;
        break;
    }

    default:
    {
        cout << "CHOOSE A NUMBER FROM 1-3" << endl;

    }





    }


}
