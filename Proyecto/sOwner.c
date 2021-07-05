#include "sOwner.h"

static int lastId = 0;

int owner_getLastId()
{
    return lastId;
}
int owner_decreaseLastId()
{
    lastId--;
    return lastId;
}
int owner_increaseLastId()
{
    lastId++;
    return lastId;
}

int owner_newParameters(sOwner* new, int id, char* name, int phone)
{
    int newOwner = -1;

    if(new != NULL)
    {
        if(!owner_setId(new, id))
        {
            if(!owner_setName(new, name))
            {
                if(!owner_setPhone(new, phone))
                {
                    if(!owner_setIsEmpty(new, 0))
                    {
                        newOwner = 0;
                    }
                }
            }
        }
    }
    return newOwner;
}

int owner_initializeOne(void* this)
{
    int initialization = -1;
    sOwner* this2;

    if(this != NULL)
    {
        this2 = (sOwner*)this;
        if(!owner_newParameters(this2, 0, "\0", 0))
        {
            if(!owner_setIsEmpty(this2, 1))
            {
                initialization = 0;
            }
        }
    }
    return initialization;
}

int owner_setId(sOwner* this, int id)
{
    int set = -1;

    if(this != NULL)
    {
        this->id = id;
        set = 0;
    }
    return set;
}

int owner_setIsEmpty(sOwner* this, int isEmpty)
{
    int set = -1;

    if(this != NULL)
    {
        this->isEmpty = isEmpty;
        set = 0;
    }
    return set;
}

int owner_setName(sOwner* this, char* name)
{
    int set = -1;

    if(this != NULL)
    {
        strcpy(this->name, name);
        set = 0;
    }
    return set;
}

int owner_setPhone(sOwner* this, int phone)
{
    int set = -1;

    if(this != NULL)
    {
        this->phone = phone;
        set = 0;
    }
    return set;
}

int owner_getId(void* this, void* id)
{
    int get = -1;
    sOwner* this2;
    int* id2;
    if(this != NULL)
    {
        this2 = (sOwner*) this;
        id2 = (int*)id;
        *id2 = this2->id;
        get = 0;
    }
    return get;
}

int owner_getIsEmpty(void* this, void* isEmpty)
{
    int get = -1;
    sOwner* this2;
    int* isEmpty2;
    if(this != NULL)
    {
        this2 = (sOwner*) this;
        isEmpty2 = (int*)isEmpty;
        *isEmpty2 = this2->isEmpty;
        get = 0;
    }
    return get;
}

int owner_getName(void* this, void* name)
{
    int get = -1;
    sOwner* this2;
    char* name2;
    if(this != NULL)
    {
        this2 = (sOwner*) this;
        name2 = (char*)name;
        strcpy(name2, this2->name);
        get = 0;
    }
    return get;
}

int owner_getPhone(void* this, void* phone)
{
    int get = -1;
    sOwner* this2;
    int* phone2;
    if(this != NULL)
    {
        this2 = (sOwner*) this;
        phone2 = (int*)phone;
        *phone2 = this2->phone;
        get = 0;
    }
    return get;
}

int owner_compareById(void* firstOwner, void* secondOwner)
{
    int comparison = -2;
    int firstId;
    int secondId;

    if(firstOwner != NULL && secondOwner != NULL)
    {
        if(!owner_getId(firstOwner, &firstId))
        {
            if(!owner_getId(secondOwner, &secondId))
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

int owner_compareByName(void* firstOwner, void* secondOwner)
{
    int comparison = -2;
    char firstName[26];
    char secondName[26];

    if(firstOwner != NULL && secondOwner != NULL)
    {
        if(!owner_getName(firstOwner, firstName))
        {
            if(!owner_getName(secondOwner, secondName))
            {
                comparison = strcmp(firstName, secondName);
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

int owner_compareByPhone(void* firstOwner, void* secondOwner)
{
    int comparison = -2;
    int firstNumer;
    int secondNumber;

    if(firstOwner != NULL && secondOwner != NULL)
    {
        if(!owner_getPhone(firstOwner, &firstNumer))
        {
            if(!owner_getPhone(secondOwner, &secondNumber))
            {
                if(firstNumer < secondNumber)
                {
                    comparison = 1;
                }
                else
                {
                    comparison=0;
                    if(firstNumer>secondNumber)
                    {
                        comparison = 1;
                    }
                }
            }
        }
    }
    return comparison;
}

int owner_hardcode(sOwner* this)
{
    char name[4][26] = {{"Carlos"},{"Juan"},{"Martin"},{"Rodrigo"}};
    int phone[4] = {42060222, 43531978, 22456138, 45651399};
    int createdElements = -1;

    if(this != NULL)
    {
        createdElements = 0;
        for(int i=0;i<4;i++)
        {
            if(!owner_newParameters(this+i, owner_increaseLastId(), name[i], phone[i]))
            {
                createdElements++;
            }
        }
    }
    return createdElements;
}

int owner_printOne(void* this)
{
    int printedOwner = -1;
    int id;
    char name[26];
    int phone;

    if(this != NULL)
    {
        if(!owner_getAll(this, &id, name, &phone))
        {
            printf("\n%d %s %d", id, name, phone);
            printedOwner = 0;
        }
    }
    return printedOwner;
}

int owner_checkEmptySpace(void* this)
{
    int returnAux = -2;

    if(this  != NULL)
    {
        owner_getIsEmpty(this, &returnAux);
    }
    return returnAux;
}

int owner_getAll(void* this, int* id, char* name, int* phone)
{
    int get = -1;
    if(this != NULL && id != NULL && name != NULL && phone != NULL)
    {
        if(!owner_checkEmptySpace(this))
        {
            if(!owner_getName(this, name))
            {
                if(!owner_getId(this, id))
                {
                    if(!owner_getPhone(this, phone))
                    {
                        get = 0;
                    }
                }
            }
        }
    }
    return get;
}
