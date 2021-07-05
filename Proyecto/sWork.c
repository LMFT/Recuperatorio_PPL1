#include "sWork.h"

static int lastId = 0;


int work_getLastId()
{
    return lastId;
}
int work_decreaseLastId()
{
    lastId--;
    return lastId;
}
int work_increaseLastId()
{
    lastId++;
    return lastId;
}

int work_newParameters(sWork* new, int workId, int serviceId, int bycycleId, sDate workDate)
{
    int newWork = -1;

    if(new != NULL)
    {
        if(!work_setWorkId(new, workId))
        {
            if(!work_setServiceId(new, serviceId))
            {
                if(!work_setBycycleId(new, bycycleId))
                {
                    if(!work_setDate(new, workDate))
                    {
                        if(!work_setIsEmpty(new, 0))
                        {
                            newWork = 0;
                        }
                    }
                }
            }
        }
    }
    return newWork;
}

int work_initializeOne(void* this)
{
    int initialization = -1;
    sWork* this2;

    if(this != NULL)
    {
        this2 = (sWork*)this;
        if(!work_newParameters(this2, -1, -1,-1, date_nullDate()))
        {
            if(!work_setIsEmpty(this2, 1))
            {
                initialization = 0;
            }
        }
    }
    return initialization;
}


int work_setWorkId(sWork* this, int id)
{
    int set = -1;

    if(this != NULL)
    {
        this->workId = id;
        set = 0;
    }
    return set;
}

int work_setIsEmpty(sWork* this, int isEmpty)
{
    int set = -1;

    if(this != NULL)
    {
        this->isEmpty = isEmpty;
        set = 0;
    }
    return set;
}

int work_setServiceId(sWork* this, int id)
{
    int set = -1;

    if(this != NULL)
    {
        this->serviceId = id;
        set = 0;
    }
    return set;
}

int work_setBycycleId(sWork* this, int id)
{
    int set = -1;

    if(this != NULL)
    {
        this->bycycleId = id;
        set = 0;
    }
    return set;
}

int work_setDate(sWork* this, sDate date)
{
    int set = -1;

    if(this != NULL)
    {
        this->date = date;
        set = 0;
    }
    return set;
}

int work_getWorkId(void* this, void* id)
{
    int get = -1;
    sWork* this2;
    int* id2;

    if(this != NULL)
    {
        this2 = (sWork*)this;
        id2 = (int*)id;
        *id2 = this2->workId;
        get = 0;
    }
    return get;
}

int work_getIsEmpty(void* this, void* isEmpty)
{
    int get = -1;
    sWork* this2;
    int* isEmpty2;

    if(this != NULL)
    {
        this2 = (sWork*)this;
        isEmpty2 = (int*)isEmpty;
        *isEmpty2 = this2->isEmpty;
        get = 0;
    }
    return get;
}

int work_getServiceId(void* this, void* id)
{
    int get = -1;
    sWork* this2;
    int* id2;

    if(this != NULL)
    {
        this2 = (sWork*)this;
        id2 = (int*)id;
        *id2 = this2->serviceId;
        get = 0;
    }
    return get;
}

int work_getBycycleId(void* this, void* id)
{
    int get = -1;
    sWork* this2;
    int* id2;

    if(this != NULL)
    {
        this2 = (sWork*)this;
        id2 = (int*)id;
        *id2 = this2->bycycleId;
        get = 0;
    }
    return get;
}

int work_getDate(void* this, void* date)
{
    int get = -1;
    sWork* this2;
    sDate* date2;
    if(this != NULL)
    {
        this2 = (sWork*)this;
        date2 = (sDate*)date;
        *date2 = this2->date;
        get = 0;
    }
    return get;
}

int work_compareByWorkId(void* firstWork, void* secondWork)
{
    int firstId;
    int secondId;
    int comparison = -2;

    if(firstWork != NULL && secondWork != NULL)
    {
        if(!work_getWorkId(firstWork, &firstId))
        {
            if(!work_getWorkId(secondWork, &secondId))
            {
                comparison = 0;

                if(firstId < secondId)
                {
                    comparison = -1;
                }
                else
                {
                    if(firstId> secondId)
                    {
                        comparison = 1;
                    }
                }
            }
        }
    }
    return comparison;
}

int work_compareByServiceId(void* firstWork, void* secondWork)
{
    int firstId;
    int secondId;
    int comparison = -2;

    if(firstWork != NULL && secondWork != NULL)
    {
        if(!work_getServiceId(firstWork, &firstId))
        {
            if(!work_getServiceId(secondWork, &secondId))
            {
                comparison = 0;

                if(firstId < secondId)
                {
                    comparison = -1;
                }
                else
                {
                    if(firstId> secondId)
                    {
                        comparison = 1;
                    }
                }
            }
        }
    }
    return comparison;
}

int work_compareByBycycleId(void* firstWork, void* secondWork)
{
    int firstId;
    int secondId;
    int comparison = -2;

    if(firstWork != NULL && secondWork != NULL)
    {
        if(!work_getBycycleId(firstWork, &firstId))
        {
            if(!work_getBycycleId(secondWork, &secondId))
            {
                comparison = 0;

                if(firstId < secondId)
                {
                    comparison = -1;
                }
                else
                {
                    if(firstId> secondId)
                    {
                        comparison = 1;
                    }
                }
            }
        }
    }
    return comparison;
}

int work_compareByDate(void* firstWork, void* secondWork)
{
    sDate firstDate;
    sDate secondDate;
    int comparison = -2;

    if(firstWork != NULL && secondWork != NULL)
    {
        if(!work_getDate(firstWork, &firstDate))
        {
            if(!work_getDate(secondWork, &secondDate))
            {
                comparison = date_compare(&firstDate, &secondDate);
            }
        }
    }
    return comparison;
}

int work_hardcode(sWork* myWorks)
{

    int bycycleId[5] = {25, 26, 27, 28, 29};
    sDate date[5] = {{10,12,2020}, {5,1,2021},{10,1,2021},{21,2,2021},{25,2,2020}};
    int serviceId[5]={20002,20001,20003,20000,20002};

    int createdWorks = -1;

    if(myWorks != NULL)
    {
        createdWorks = 0;
        for(int i=0;i<5;i++)
        {
            if(!work_newParameters(myWorks+i, work_increaseLastId(), serviceId[i], bycycleId[i], date[i]))
            {
                createdWorks++;
            }
        }
    }
    return createdWorks;
}

int work_printOne(void* this)
{
    int idWork;
    int idService;
    int idBycycle;
    sDate date;
    int printedElement = -1;

    if(this != NULL)
    {
        if(!work_getAll(this, &idWork, &date, &idService, &idBycycle))
        {
            printf("\n%6d %11d %12d      ", idWork, idService, idBycycle);
            date_print(&date);
            printedElement = 0;
        }
    }
    return printedElement;
}

int work_checkEmptySpace(void* this)
{
    int returnAux = -2;

    if(this  != NULL)
    {
        work_getIsEmpty(this, &returnAux);
    }
    return returnAux;
}

int work_getAll(void* this, int* idWork, sDate* date, int* idService, int* idBycycle)
{
    int get = -1;
    if(this != NULL && idWork != NULL && idBycycle != NULL && idService != NULL && date != NULL)
    {
        if(!work_checkEmptySpace(this))
        {
            if(!work_getBycycleId(this, idBycycle))
            {
                if(!work_getDate(this, date))
                {
                    if(!work_getServiceId(this, idService))
                    {
                        if(!work_getWorkId(this, idWork))
                        {
                            get = 0;
                        }
                    }
                }
            }
        }
    }
    return get;
}
