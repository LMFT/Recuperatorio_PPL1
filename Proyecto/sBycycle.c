#include "sBycycle.h"

static int lastId = 24;

int bycycle_getLastId()
{
    return lastId;
}
int bycycle_decreaseLastId()
{
    lastId--;
    return lastId;
}
int bycycle_increaseLastId()
{
    lastId++;
    return lastId;
}


int bycycle_newParameters(sBycycle* this, int idBycycle,int idOwner, int wheelSize, char* brand, char* colour)
{
    int newBycycle = -1;

    if(this != NULL)
    {
        if(!bycycle_setBrand(this, brand))
        {
            if(!bycycle_setColour(this, colour))
            {
                if(!bycycle_setIdBycycle(this, idBycycle))
                {
                    if(!bycycle_setIdOwner(this, idOwner))
                    if(!bycycle_setWheelSize(this, wheelSize))
                    {
                        if(!bycycle_setIsEmpty(this, 0))
                        {
                            newBycycle = 0;
                        }
                    }
                }
            }
        }
    }

    return newBycycle;
}

int bycycle_initializeOne(void* this)
{
    int initialization = -1;
    sBycycle* this2;

    if(this != NULL)
    {
        this2 = (sBycycle*)this;
        if(!bycycle_setBrand(this, "\0"))
        {
            if(!bycycle_newParameters(this2, 0, 0, 0,"\0", "\0"))
            {
                if(!bycycle_setIsEmpty(this2, 1))
                {
                    initialization = 0;
                }
            }
        }
    }
    return initialization;
}

int bycycle_setIdBycycle(sBycycle* this, int idBycycle)
{
    int set = -1;

    if(this != NULL)
    {
        this->idBycycle = idBycycle;
        set=0;
    }
    return set;
}

int bycycle_setIdOwner(sBycycle* this, int idOwner)
{
    int set = -1;

    if(this != NULL)
    {
        this->idOwner = idOwner;
        set=0;
    }
    return set;
}

int bycycle_setIsEmpty(sBycycle* this, int isEmpty)
{
    int set = -1;

    if(this != NULL)
    {
        this->isEmpty = isEmpty;
        set=0;
    }
    return set;
}

int bycycle_setWheelSize(sBycycle* this, int wheelSize)
{
    int set = -1;

    if(this != NULL)
    {
        this->wheelSize = wheelSize;
        set=0;
    }
    return set;
}

int bycycle_setBrand(sBycycle* this, char* brand)
{
    int set = -1;

    if(this != NULL)
    {
        strcpy(this->brand, brand);
        set = 0;
    }
    return set;
}

int bycycle_setColour(sBycycle* this, char* colour)
{
    int set = -1;

    if(this != NULL)
    {
        strcpy(this->colour, colour);
        set = 0;
    }
    return set;
}

int bycycle_getIdBycycle(void* this, void* idBycycle)
{
    int get = -1;
    sBycycle* this2;
    int* id2;
    if(this != NULL)
    {
        this2 = (sBycycle*) this;
        id2 = (int*)idBycycle;
        *id2 = this2->idBycycle;
        get = 0;
    }
    return get;
}

int bycycle_getIdOwner(void* this, void* idOwner)
{
    int get = -1;
    sBycycle* this2;
    int* id2;
    if(this != NULL)
    {
        this2 = (sBycycle*) this;
        id2 = (int*)idOwner;
        *id2 = this2->idOwner;
        get = 0;
    }
    return get;
}

int bycycle_getIsEmpty(void* this, void* isEmpty)
{
    int get = -1;
    sBycycle* this2;
    int* isEmpty2;
    if(this != NULL)
    {
        this2 = (sBycycle*) this;
        isEmpty2 = (int*)isEmpty;
        *isEmpty2 = this2->isEmpty;
        get = 0;
    }
    return get;
}

int bycycle_getWheelSize(void* this, void* wheelSize)
{
    int get = -1;
    sBycycle* this2;
    int* wheelSize2;
    if(this != NULL)
    {
        this2 = (sBycycle*) this;
        wheelSize2 = (int*)wheelSize;
        *wheelSize2 = this2->wheelSize;
        get = 0;
    }
    return get;
}

int bycycle_getBrand(void* this, void* brand)
{
    int get = -1;
    sBycycle* this2;
    char* brand2;
    if(this != NULL)
    {
        this2 = (sBycycle*) this;
        brand2 = (char*)brand;
        strcpy(brand2, this2->brand);
        get = 0;
    }
    return get;
}

int bycycle_getColour(void* this, void* colour)
{
    int get = -1;
    sBycycle* this2;
    char* colour2;
    if(this != NULL)
    {
        this2 = (sBycycle*) this;
        colour2 = (char*)colour;
        strcpy(colour2, this2->colour);
        get = 0;
    }
    return get;
}

int bycycle_compareByIdBycycle(void* firstBycycle, void* secondBycycle)
{
    int comparison = -2;
    int firstId;
    int secondId;

    if(firstBycycle != NULL && secondBycycle != NULL)
    {
        if(!bycycle_getIdBycycle(firstBycycle, &firstId))
        {
            if(!bycycle_getIdBycycle(secondBycycle, &secondId))
            {
                if(firstId<secondId)
                {
                    comparison = -1;
                }
                else
                {
                    comparison = 0;
                    if(firstId > secondId)
                    {
                        comparison = 1;
                    }
                }
            }
        }
    }
    return comparison;
}

int bycycle_compareByIdOwner(void* firstBycycle, void* secondBycycle)
{
    int comparison = -2;
    int firstId;
    int secondId;

    if(firstBycycle != NULL && secondBycycle != NULL)
    {
        if(!bycycle_getIdOwner(firstBycycle, &firstId))
        {
            if(!bycycle_getIdOwner(secondBycycle, &secondId))
            {
                if(firstId<secondId)
                {
                    comparison = -1;
                }
                else
                {
                    comparison = 0;
                    if(firstId > secondId)
                    {
                        comparison = 1;
                    }
                }
            }
        }
    }
    return comparison;
}

int bycycle_compareByWheelSize(void* firstBycycle, void* secondBycycle)
{
    int comparison = -2;
    int firstWheelSize;
    int secondWheelSize;

    if(firstBycycle != NULL && secondBycycle != NULL)
    {
        if(!bycycle_getWheelSize(firstBycycle, &firstWheelSize))
        {
            if(!bycycle_getWheelSize(secondBycycle, &secondWheelSize))
            {
                if(firstWheelSize<secondWheelSize)
                {
                    comparison = -1;
                }
                else
                {
                    comparison = 0;
                    if(firstWheelSize > secondWheelSize)
                    {
                        comparison = 1;
                    }
                }
            }
        }
    }
    return comparison;
}


int bycycle_compareByBrand(void* firstBycycle, void* secondBycycle)
{
    int comparison = -2;
    char firstBrand[26];
    char secondBrand[26];

    if(firstBycycle != NULL && secondBycycle != NULL)
    {
        if(!bycycle_getBrand(firstBycycle, firstBrand))
        {
            if(!bycycle_getBrand(secondBycycle, secondBrand))
            {
                comparison = strcmp(firstBrand, secondBrand);
                if(comparison<0)
                {
                    comparison = -1;
                }
                else
                {
                    if(comparison>0)
                    {
                        comparison = 1;
                    }
                }
            }
        }
    }
    return comparison;
}

int bycycle_compareByColour(void* firstBycycle, void* secondBycycle)
{
    int comparison = -2;
    char firstColour[26];
    char secondColour[26];

    if(firstBycycle != NULL && secondBycycle != NULL)
    {
        if(!bycycle_getColour(firstBycycle, firstColour))
        {
            if(!bycycle_getColour(secondBycycle, secondColour))
            {
                comparison = strcmp(firstColour, secondColour);
                if(comparison<0)
                {
                    comparison = -1;
                }
                else
                {
                    if(comparison>0)
                    {
                        comparison = 1;
                    }
                }
            }
        }
    }
    return comparison;
}

int bycycle_hardcode(sBycycle* this)
{
    int wheelSize[5] = {20, 24, 18, 21, 22};
    int ownerId[5] = {1,4,2,3,3};
    char brand[5][26] = {{"Shimano"},{"Olmo"},{"Vairo"},{"Raleigh"},{"Trinx"}};
    char colour[5][26] = {{"Rojo"},{"Negro"},{"Verde"},{"Violeta"},{"Azul"}};
    int createdElements = -1;

    if(this != NULL)
    {
        createdElements = 0;
        for(int i=0;i<5;i++)
        {
            if(!bycycle_newParameters(this+i, bycycle_increaseLastId(), ownerId[i], wheelSize[i], brand[i], colour[i]))
            {
                createdElements++;
            }
        }
    }
    return createdElements;
}

int bycycle_printOne(void* this)
{
    int printedElement = -1;
    int idBycycle;
    int idOwner;
    int wheelSize;
    char brand[26];
    char colour[26];


    if(this != NULL)
    {
        if(!bycycle_getAll(this, &idBycycle, &idOwner,&wheelSize, brand, colour))
        {
            printf("\n%8d %10d %12s %9s %8d", idBycycle, idOwner,brand, colour, wheelSize);
            printedElement = 0;
        }

    }
    return printedElement;
}

int bycycle_checkEmptySpace(void* this)
{
    int returnAux = -2;

    if(this  != NULL)
    {
        bycycle_getIsEmpty(this, &returnAux);
    }
    return returnAux;
}

int bycycle_getAll(void* this, int* idBycycle, int* idOwner,int* wheelSize,char* brand,char* colour)
{
    int get = -1;
    if(this!=NULL&&idBycycle!=NULL&&idOwner!=NULL&&wheelSize!=NULL&&brand!=NULL&&colour!=NULL)
    {
        if(!bycycle_checkEmptySpace(this))
        {
            if(!bycycle_getBrand(this, brand))
            {
                if(!bycycle_getColour(this, colour))
                {
                    if(!bycycle_getIdBycycle(this, idBycycle))
                    {
                        if(!bycycle_getWheelSize(this, wheelSize))
                        {
                            if(!bycycle_getIdOwner(this, idOwner))
                            get = 0;
                        }
                    }
                }
            }
        }
    }
    return get;
}
