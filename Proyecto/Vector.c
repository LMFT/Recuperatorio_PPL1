#include "Vector.h"

Vector vector_new(void* pElement, int len, size_t size)
{
    Vector new = {NULL,0,0};
    if(pElement != NULL && len > 0 && size>0)
    {
        new.pElement = pElement;
        new.elementSize = size;
        new.len = len;
    }
    return new;
}

int vector_len(Vector* this)
{
    int len;

    if(this != NULL)
    {
        len = this->len;
    }
    return len;
}

int vector_getSize(Vector* this, size_t* size)
{
    int get = -1;

    if(this != NULL)
    {
        *size = this->elementSize;
        get = 0;
    }
    return get;
}

void* vector_getElement(Vector* this, int index)
{
    void* pElement = NULL;
    void* pFirstElement;
    size_t size;

    if(this != NULL && index<vector_len(this) && index>= 0)
    {
        if(!vector_getSize(this, &size))
        {
            pFirstElement = this->pElement;
            for(int i=0;i<vector_len(this);i++)
            {
                if(i == index)
                {
                    pElement = pFirstElement+i*size;
                    break;
                }
            }
        }
    }
    return pElement;
}

void* vector_getElementById(Vector* this, int* idParameter, int(*getId)(void*,void*), int (*isEmpty)(void*))
{
    void* pElement = NULL;
    void* tempElement;
    void* firstElement;
    size_t size;
    int id;

    if(this != NULL && getId != NULL && idParameter != NULL)
    {
        if(!vector_getSize(this, &size))
        {
            firstElement=this->pElement;
            for(int i=0;i<vector_len(this);i++)
            {
                tempElement = firstElement+i*size;
                if(!isEmpty(tempElement))
                {
                    if(!getId(tempElement, &id))
                    {
                        //printf("\nID Obtenido: %d ---- id Parametro: %d", id, *idParameter);
                        if(id == *idParameter)
                        {
                            pElement = tempElement;
                            break;
                        }
                    }
                }
            }
        }
    }
    return pElement;
}



int vector_setElement(Vector* this, int index, void* pElement)
{
    int set = -1;
    void* temp;
    size_t size;

    if(this != NULL && index>=0 && index<vector_len(this) && pElement != NULL)
    {
        temp = vector_getElement(this, index);
        if(temp != NULL)
        {
            if(!vector_getSize(this, &size))
            {
                memmove(temp, pElement, size);
                set = 0;
            }
        }
    }
    return set;
}

int vector_sort(Vector* this, int (*pFunc)(void*, void*),int order)
{
    int returnAux =-2;
    int comparison;
    void* firstElement;
    void* secondElement;
    void* tempElement;
    size_t size;

    if(this != NULL && pFunc != NULL && (order == 0 || order == 1))
    {
        returnAux = -1;
        if(!vector_getSize(this, &size))
        {
            for(int i=0;i<vector_len(this)-1;i++)
            {
                firstElement = vector_getElement(this, i);
                for(int j=i+1;j<vector_len(this);j++)
                {
                    secondElement = vector_getElement(this, j);
                    if(firstElement != NULL && secondElement != NULL)
                    {
                        comparison = pFunc(firstElement, secondElement);
                        if((comparison == 1 && order == 1) || (comparison == -1 && order == 0))
                        {
                            tempElement = firstElement;
                            firstElement = secondElement;
                            secondElement = tempElement;
                            returnAux = 0;
                        }
                    }
                }
            }
        }
    }
    return returnAux;
}

int vector_searchEmptySpace(Vector* this, int (*checkSpace)(void*))
{
    int index = -2;
    void* pElement;
    if(this != NULL && checkSpace != NULL)
    {
        index = -1;
        for(int i=0;i<vector_len(this);i++)
        {
            pElement = vector_getElement(this, i);
            if(checkSpace(pElement))
            {
                index = i;
                break;
            }
        }
    }
    return index;
}

int vector_map(Vector* this, int(*pFunc)(void*))
{
    int mappedElements = -1;
    void* pElement;

    if(this != NULL && pFunc != NULL)
    {
        mappedElements = 0;
        for(int i=0;i<vector_len(this);i++)
        {
            pElement = vector_getElement(this, i);
            pFunc(pElement);
            mappedElements++;
        }
    }
    return mappedElements;
}

int vector_searchById(Vector* this, int(*compare)(void*, void*), int(*isEmpty)(void*),
                      int(*getId)(void* pElement, void*pParameter), int* targetId)
{
    int index = -2;
    void* pElement;
    int idParameter;

    if(this != NULL && compare != NULL && getId != NULL && targetId != NULL)
    {
        index = -1;
        for(int i=0;i<vector_len(this);i++)
        {
            pElement = vector_getElement(this, i);
            if(pElement != NULL)
            {
                if(!isEmpty(pElement))
                {
                    if(!getId(pElement, &idParameter))
                    {
                        if(!compare(&idParameter, targetId))
                        {
                            index = i;
                            break;
                        }
                    }
                }
            }
        }
    }
    return index;
}

int vector_filter(Vector* this, int(*filter)(void*,void*),void* criteria, void* buffer)
{
    Vector this2;
    size_t size;
    int len;
    int index = -1;
    void* pElement;

    if(this != NULL)
    {
        index = 0;
        len = vector_len(this);
        if(!vector_getSize(this, &size))
        {
            this2 = vector_new(buffer, len, size);
            for(int i=0;i<len;i++)
            {
                pElement = vector_getElement(this, i);
                if(!filter(pElement, criteria))
                {
                    vector_setElement(&this2, index, pElement);
                    index++;
                }
            }
        }
    }
    return index;
}
