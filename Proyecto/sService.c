#include "sService.h"

static int lastId = 19999;

int service_getLastId()
{
    return lastId;
}
int service_decreaseLastId()
{
    lastId--;
    return lastId;
}
int service_increaseLastId()
{
    lastId++;
    return lastId;
}

int service_newParameters(sService* new, int id, char* description, float price)
{
    int newService = -1;

    if(new != NULL)
    {
        if(!service_setId(new, id))
        {
            if(!service_setDescription(new, description))
            {
                if(!service_setPrice(new, price))
                {
                    if(!service_setIsEmpty(new, 0))
                    {
                        newService = 0;
                    }
                }
            }
        }
    }
    return newService;
}

int service_initializeOne(void* this)
{
    int initialization = -1;
    sService* this2;

    if(this != NULL)
    {
        this2 = (sService*)this;
        if(!service_newParameters(this2, 0, "\0", 0))
        {
            if(!service_setIsEmpty(this2, 1))
            {
                initialization = 0;
            }
        }
    }
    return initialization;
}

int service_setId(sService* this, int id)
{
    int set = -1;

    if(this != NULL)
    {
        this->id = id;
        set = 0;
    }
    return set;
}

int service_setIsEmpty(sService* this, int isEmpty)
{
    int set = -1;

    if(this != NULL)
    {
        this->isEmpty = isEmpty;
        set = 0;
    }
    return set;
}

int service_setDescription(sService* this, char* description)
{
    int set = -1;

    if(this != NULL)
    {
        strcpy(this->description, description);
        set = 0;
    }
    return set;
}

int service_setPrice(sService* this, float price)
{
    int set = -1;

    if(this != NULL)
    {
        this->price = price;
        set = 0;
    }
    return set;
}

int service_getId(void* this, void* id)
{
    int get = -1;
    sService* this2;
    int* id2;
    if(this != NULL)
    {
        this2 = (sService*) this;
        id2 = (int*)id;
        *id2 = this2->id;
        get = 0;
    }
    return get;
}

int service_getIsEmpty(void* this, void* isEmpty)
{
    int get = -1;
    sService* this2;
    int* isEmpty2;
    if(this != NULL)
    {
        this2 = (sService*) this;
        isEmpty2 = (int*)isEmpty;
        *isEmpty2 = this2->isEmpty;
        get = 0;
    }
    return get;
}

int service_getDescription(void* this, void* description)
{
    int get = -1;
    sService* this2;
    char* description2;
    if(this != NULL)
    {
        this2 = (sService*) this;
        description2 = (char*)description;
        strcpy(description2, this2->description);
        get = 0;
    }
    return get;
}

int service_getPrice(void* this, void* price)
{
    int get = -1;
    sService* this2;
    float* price2;
    if(this != NULL)
    {
        this2 = (sService*) this;
        price2 = (float*)price;
        *price2 = this2->price;
        get = 0;
    }
    return get;
}

int service_compareById(void* firstService, void* secondService)
{
    int comparison = -2;
    int firstId;
    int secondId;

    if(firstService != NULL && secondService != NULL)
    {
        if(!service_getId(firstService, &firstId))
        {
            if(!service_getId(secondService, &secondId))
            {
                if(firstId < secondId)
                {
                    comparison = 1;
                }
                else
                {
                    comparison=0;
                    if(firstId>secondId)
                    {
                        comparison = 1;
                    }
                }
            }
        }
    }
    return comparison;
}

int service_compareByDescription(void* firstService, void* secondService)
{
    int comparison = -2;
    char firstDescription[26];
    char secondDescription[26];

    if(firstService != NULL && secondService != NULL)
    {
        if(!service_getDescription(firstService, firstDescription))
        {
            if(!service_getDescription(secondService, secondDescription))
            {
                comparison = strcmp(firstDescription, secondDescription);
                if(comparison>0)
                {
                    comparison = 1;
                }
                else
                {
                    if(comparison<0)
                    {
                        comparison = -1;
                    }
                }
            }
        }
    }
    return comparison;
}

int service_compareByPrice(void* firstService, void* secondService)
{
    int comparison = -2;
    float firstPrice;
    float secondPrice;

    if(firstService != NULL && secondService != NULL)
    {
        if(!service_getPrice(firstService, &firstPrice))
        {
            if(!service_getPrice(secondService, &secondPrice))
            {
                if(firstPrice < secondPrice)
                {
                    comparison = 1;
                }
                else
                {
                    comparison=0;
                    if(firstPrice>secondPrice)
                    {
                        comparison = 1;
                    }
                }
            }
        }
    }
    return comparison;
}

int service_hardcode(sService* this)
{
    char description[4][26] = {{"Limpieza"},{"Parche"},{"Centrado"},{"Cadena"}};
    float price[4] = {250, 300, 400, 350};
    int createdElements = -1;

    if(this != NULL)
    {
        createdElements = 0;
        for(int i=0;i<4;i++)
        {
            if(!service_newParameters(this+i, service_increaseLastId(), description[i], price[i]))
            {
                createdElements++;
            }
        }
    }
    return createdElements;
}

int service_printOne(void* this)
{
    int printedService = -1;
    int id;
    char description[26];
    float price;

    if(this != NULL)
    {
        if(!service_getAll(this, &id, description, &price))
        {
            printf("\n%8d %15s %11.2f", id, description, price);
            printedService = 0;
        }
    }
    return printedService;
}

int service_checkEmptySpace(void* this)
{
    int returnAux = -2;

    if(this  != NULL)
    {
        service_getIsEmpty(this, &returnAux);
    }
    return returnAux;
}

int service_getAll(void* this, int* id, char* description, float* price)
{
    int get = -1;
    if(this != NULL && id != NULL && description != NULL && price != NULL)
    {
        if(!service_checkEmptySpace(this))
        {
            if(!service_getDescription(this, description))
            {
                if(!service_getId(this, id))
                {
                    if(!service_getPrice(this, price))
                    {
                        get = 0;
                    }
                }
            }
        }
    }
    return get;
}
