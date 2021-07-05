#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

typedef struct sDate
{
    int day;
    int month;
    int year;
}sDate;

#endif // DATE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

int date_newDate(sDate* new, int day, int month, int year);

int date_setDay(sDate* this, int day);
int date_setMonth(sDate* this, int month);
int date_setYear(sDate* this, int year);

int date_getDay(sDate* this, int* day);
int date_getMonth(sDate* this, int* month);
int date_getYear(sDate* this, int* year);

int date_print(sDate* this);

sDate date_nullDate();
int date_compare(sDate* firstDate, sDate* secondDate);
