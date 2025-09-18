#include <iostream>

using namespace std;

enum Day
{
    SUN = 0,
    MON,
    TUE,
    WED,
    THU,
    FRI,
    SAT
};

enum Month
{
    JAN = 1,
    FEB,
    MAR,
    APR,
    MAY,
    JUN,
    JUL,
    AUG,
    SEP,
    OCT,
    NOV,
    DEC
};

struct Calendar
{
    int date;
    Day day;
    Month month;
    int year;
    int daysInMonth;
};

int dayInMonth(Month m, int year)
{

    if (m == APR || m == JUN || m == SEP || m == NOV)
    {
        return 30;
    }
    else if (m == FEB)
    {
        if (year % 4 == 0)
        {
            if (year % 100 != 0)
            {
                return 29;
            }
            if (year % 400 == 0)
            {
                return 29;
            }
            return 28;
        }
        return 28;
    }
    return 31;
}

int resolve()
{

    Calendar myCalendar;
    myCalendar.date = 1;
    myCalendar.month = JAN;
    myCalendar.year = 1900;
    myCalendar.day = MON;
    myCalendar.daysInMonth = 31;

    int sundays = 0;

    while (myCalendar.year < 2001)
    {

        if (myCalendar.year > 1900 && myCalendar.year < 2001)
        {

            if (myCalendar.day == SUN && myCalendar.date == 1)
            {
                sundays++;
            }
        }

        // cout << "day " << myCalendar.day << " date " << myCalendar.date << "(" << myCalendar.daysInMonth << ")" << " in " << myCalendar.month << " of " << myCalendar.year << endl;

        myCalendar.date++;
        if (myCalendar.day == SAT)
        {
            myCalendar.day = SUN;
        }
        else
        {
            myCalendar.day = static_cast<Day>((myCalendar.day % SAT) + 1);
        }
        if (myCalendar.date > myCalendar.daysInMonth)
        {
            myCalendar.date = 1;
            if (myCalendar.month == DEC)
            {
                myCalendar.year++;
            }
            myCalendar.month = static_cast<Month>((myCalendar.month % DEC) + 1);
            myCalendar.daysInMonth = dayInMonth(myCalendar.month, myCalendar.year);
        }
    }

    return sundays;
}

int main()
{

    int result = resolve();

    cout << "Result = " << result << endl;

    return 0;
}
