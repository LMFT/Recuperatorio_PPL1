#include "Date.h"

int date_newDate(sDate* new, int day, int month, int year)
{
    int newDate = -1;
    int amountOfDays;

    if(new != NULL && month < 13 && month > 0 && day >0 && day<31)
    {
        if(!date_setYear(new, year))
        {
            if(!date_setMonth(new, month))
            {
                switch(month)
                {
                    case 1:
                    case 3:
                    case 5:
                    case 7:
                    case 8:
                    case 10:
                    case 12:
                        amountOfDays = 31;
                        break;
                    case 4:
                    case 6:
                    case 9:
                    case 11:
                        amountOfDays = 30;
                    case 2:
                        amountOfDays = 28;
                        if(year%4 == 0)
                        {
                            amountOfDays = 29;
                        }
                        break;
                }
                if(day<amountOfDays)
                {
                    if(!date_setDay(new, day))
                    {
                        newDate = 0;
                    }
                }
            }
        }
    }
    return newDate;
}

int date_setDay(sDate* this, int day)
{
    int set = -1;

    if(this != NULL)
    {
        this->day = day;
        set = 0;
    }
    return set;
}

int date_setMonth(sDate* this, int month)
{
    int set = -1;

    if(this != NULL)
    {
        this->month = month;
        set = 0;
    }
    return set;
}

int date_setYear(sDate* this, int year)
{
    int set = -1;

    if(this != NULL)
    {
        this->year = year;
        set = 0;
    }
    return set;
}

int date_getDay(sDate* this, int* day)
{
    int get = -1;

    if(this != NULL)
    {
        *day = this->day;
        get = 0;
    }
    return get;
}

int date_getMonth(sDate* this, int* month)
{
    int get = -1;

    if(this != NULL)
    {
        *month = this->month;
        get = 0;
    }
    return get;
}

int date_getYear(sDate* this, int* year)
{
    int get = -1;

    if(this != NULL)
    {
        *year = this->year;
        get = 0;
    }
    return get;
}

int date_print(sDate* this)
{
    int day;
    int month;
    int year;
    int printedDate = -1;

    if(this != NULL)
    {
        if(!date_getDay(this, &day))
        {
            if(!date_getMonth(this, &month))
            {
                if(!date_getYear(this, &year))
                {
                    printf("%d/%d/%d", day, month, year);
                    printedDate = 0;
                }
            }
        }
    }
    return printedDate;
}

sDate date_nullDate()
{
    sDate nullDate = {0, 0, 0};
    return nullDate;
}

int date_compare(sDate* firstDate, sDate* secondDate)
{
    int day;
    int month;
    int year;
    int day2;
    int month2;
    int year2;
    int comparison = -2;

    if(!date_getDay(firstDate, &day))
    {
        if(!date_getDay(secondDate, &day2))
        {
            if(!date_getMonth(firstDate, &month))
            {
                if(!date_getMonth(secondDate, &month2))
                {
                    if(!date_getYear(firstDate, &year))
                    {
                        if(!date_getYear(secondDate, &year2))
                        {
                            if(year<year2)
                            {
                                comparison = -1;
                            }
                            else
                            {
                                if(year>year2)
                                {
                                    comparison = 1;
                                }
                                else
                                {
                                    if(month<month2)
                                    {
                                        comparison = -1;
                                    }
                                    else
                                    {
                                        if(month>month2)
                                        {
                                            comparison = 1;
                                        }
                                        else
                                        {
                                            if(day<day2)
                                            {
                                                comparison = -1;
                                            }
                                            else
                                            {
                                                comparison = 0;
                                                if(day>day2)
                                                {
                                                    comparison = 1;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return comparison;
}

