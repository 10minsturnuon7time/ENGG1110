/**
 * ENGG1110 Problem Solving by Programming
 * Lab 07 Exercise 3
 * Days Calculator: Days Between Two Dates
 */

#define VERSION 4


#if VERSION == 1
#include <stdio.h>

int g(int d, int m, int y) {
    m = (m + 9) % 12;
    y = y - m/10;
    return 365 * y + y/4 - y/100 + y/400 + (m * 306 + 5)/10 + (d - 1);
}

// Get the days between two dates
int GetDaysInterval(int Date1[], int Date2[]) {
    int Days = g(Date2[0], Date2[1], Date2[2]) - g(Date1[0], Date1[1], Date1[2]);
    if (Days < 0)
        Days = -Days;
    return Days;
}

int main(void)
{
    int Date1[3], Date2[3];

    // Read two dates.
    scanf("%d %d %d", &Date1[0], &Date1[1], &Date1[2]);
    scanf("%d %d %d", &Date2[0], &Date2[1], &Date2[2]);

    printf("Days: %d days\n", GetDaysInterval(Date1, Date2));

    return 0;
}
#endif



#if VERSION == 2
#include <stdio.h>

// Check if the current year is a Leap Year
int CheckLeapYear(int Date)
{
    int isLeap;
    isLeap = (!(Date % 4) && (Date % 100)) || !(Date % 400) ? 1 : 0;
    return isLeap;
}

// Get the days between two dates
int GetDaysInterval(int Date1[], int Date2[]) {

    if ( Date1[2] * 10000 + Date1[1] * 100 + Date1[0] >
        Date2[2] * 10000 + Date2[1] * 100 + Date2[0] ) {
        for (int i=0; i<3; i++) {
            int tmp = Date2[i];
            Date2[i] = Date1[i];
            Date1[i] = tmp;
        }
    }

    int dpm[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int Days = 0;
    int d = Date1[0], m = Date1[1], y = Date1[2];

    while (d != Date2[0] || m != Date2[1] || y != Date2[2]) {
        Days++;
        d++;
        dpm[2] = 28 + CheckLeapYear(y);
        if (d > dpm[m]) {
            d = 1;
            m++;
        }
        if (m > 12) {
            m = 1;
            y++;
        }
    }
    return Days;
}

int main(void)
{
    int Date1[3], Date2[3];

    // Read two dates.
    scanf("%d %d %d", &Date1[0], &Date1[1], &Date1[2]);
    scanf("%d %d %d", &Date2[0], &Date2[1], &Date2[2]);

    printf("Days: %d days\n", GetDaysInterval(Date1, Date2));

    return 0;
}
#endif



#if VERSION == 3
#include <stdio.h>
#include <stdlib.h>

// Check if the current year is a Leap Year
int CheckLeapYear(int Date1[] )
{
    int isLeap;
    isLeap = (!(Date1[2] % 4) && (Date1[2] % 100)) || !(Date1[2] % 400) ? 1 : 0;
    return isLeap;
}

int GetDaysSince1900(int Date[])
{
    int DaysPerMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    int RefDate[3] = { 1, 1, 1900 };
    int Days = 0;

    // count no. of years between the input date and ref date
    for ( ; RefDate[2] < Date[2]; RefDate[2]++)
        Days += 365 + CheckLeapYear(RefDate);

    // count no. of months between the input date and ref date
    for ( ; RefDate[1] < Date[1]; RefDate[1]++) {
        Days += DaysPerMonth[ RefDate[1] - 1 ];
        if (2 == RefDate[1] && CheckLeapYear(Date)) // February
            Days++;
    }

    // count no. of days in the month of the end date
    Days += Date[0];

    return Days;
}

// Get the days between two dates
int GetDaysInterval(int Date1[], int Date2[])
{
    int Days1, Days2;
    Days1 = GetDaysSince1900(Date1);
    Days2 = GetDaysSince1900(Date2);
    return abs(Days2 - Days1);
}

int main(void)
{
    int Date1[3], Date2[3];

    // Read two dates.
    scanf("%d %d %d", &Date1[0], &Date1[1], &Date1[2]);
    scanf("%d %d %d", &Date2[0], &Date2[1], &Date2[2]);

    printf("Days: %d days\n", GetDaysInterval(Date1, Date2));

    return 0;
}
#endif



#if VERSION == 4
#include <stdio.h>

// Check if the current year is a Leap Year
int CheckLeapYear(int Date1[] )
{
    int isLeap;
    isLeap = (!(Date1[2] % 4) && (Date1[2] % 100)) || !(Date1[2] % 400);  // yields 1 or 0
    return isLeap;
}

// Get Number Of Days In Month m where m is from 1 to 12
int NumberOfDaysInMonth(int m)
{
    // days[0] is unused; assume 28 days in Feb
    int days[] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return days[m];
}

// Find number of days since 1899 Dec 31
int DaysSince1899Dec31(int Date[])
{
    int day   = Date[0];
    int month = Date[1];
    int year  = Date[2];
    int nYear = year - 1900;

    // every 4 years has Feb 29, i.e., one more day
    // 1900 is an exception
    int DaysSince1899Dec31 = nYear * 365;
    if (year > 1900)
        DaysSince1899Dec31 += (nYear - 1) / 4;

    // add total number of days since Jan
    for (int m = 1; m < month; m++)
        DaysSince1899Dec31 += NumberOfDaysInMonth(m);

    DaysSince1899Dec31 += day;

    // add one more day if this is leap year
    if (CheckLeapYear(Date) && month > 2)
        DaysSince1899Dec31++;

    return DaysSince1899Dec31;
}

// Get the number of days between two dates
int GetDaysInterval(int Date1[], int Date2[])
{
    int Days = DaysSince1899Dec31(Date1) - DaysSince1899Dec31(Date2);
    if (Days < 0)
        Days = -Days;
    return Days;
}

int main(void)
{
    int Date1[3], Date2[3];

    // Read two dates.
    scanf("%d%d%d", Date1+0, Date1+1, Date1+2);
    scanf("%d%d%d", Date2+0, Date2+1, Date2+2);

    printf("Days: %d days\n", GetDaysInterval(Date1, Date2));

    return 0;
}
#endif



#if VERSION == 5
#include <stdio.h>

typedef struct {
    int day, month, year;
} Date;

// Check if the current year is a Leap Year
int CheckLeapYear(Date date)
{
    int y = date.year;
    return (!(y % 4) && (y % 100)) || !(y % 400);  // yields 1 or 0
}

// Get Number Of Days In Month m where m is from 1 to 12
int NumberOfDaysInMonth(int m)
{
    // days[0] is unused; assume 28 days in Feb
    int days[] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return days[m];
}

// Find number of days since 1899 Dec 31
int DaysSince1899Dec31(Date date)
{
    int nYear = date.year - 1900;

    // every 4 years has Feb 29, i.e., one more day
    // 1900 is an exception
    int DaysSince1899Dec31 = nYear * 365;
    if (date.year > 1900)
        DaysSince1899Dec31 += (nYear - 1) / 4;

    // add total number of days since Jan
    for (int m = 1; m < date.month; m++)
        DaysSince1899Dec31 += NumberOfDaysInMonth(m);

    DaysSince1899Dec31 += date.day;

    // add one more day if this is leap year
    if (CheckLeapYear(date) && date.month > 2)
        DaysSince1899Dec31++;

    return DaysSince1899Dec31;
}

// Get the number of days between two dates
int GetDaysInterval(Date date1, Date date2)
{
    int Days = DaysSince1899Dec31(date1) - DaysSince1899Dec31(date2);
    if (Days < 0)
        Days = -Days;
    return Days;
}

int main(void)
{
    Date date1, date2;

    // Read two dates.
    scanf("%d%d%d", &date1.day, &date1.month, &date1.year);
    scanf("%d%d%d", &date2.day, &date2.month, &date2.year);

    printf("Days: %d days\n", GetDaysInterval(date1, date2));

    return 0;
}
#endif

