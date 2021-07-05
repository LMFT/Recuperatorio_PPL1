#include "Comparison.h"

int Compare_Elements(void* firstObject, void* secondObject, size_t size)
{
    int comparison = -2;

    if(firstObject != NULL && secondObject != NULL)
    {
        comparison = memcmp(firstObject, secondObject, size);
        if(comparison > 0)
        {
            comparison = 1;
        }
        else
        {
            if(comparison < 0)
            {
                comparison = -1;
            }
        }
    }
    return comparison;
}

int Swap_Elements(void* firstObject, void* secondObject, size_t size)
{
    int swap = -1;
    void* temp;

    if(firstObject != NULL && secondObject != NULL)
    {
        swap = 0;
        temp = malloc(size);
        memmove(temp, firstObject, size);
        memmove(firstObject, secondObject, size);
        memmove(secondObject, temp, size);
        free(temp);
    }
    return swap;
}

int Comparison_CheckParityInt(int number)
{
    int parity;
    if(number%2 == 0)
    {
        parity = 1;
    }
    else
    {
        parity=0;
    }
    return parity;
}

int Comparison_NumberIsPrime(int number)
{
    int isPrime = 1;
    for(int i=2;i<number/2;i++)
    {
        if(number%i == 0)
        {
            isPrime = 0;
            break;
        }
    }
    return isPrime;
}

int Comparison_GetMax(int* array, int size, int* max)
{
    int gotMax = -1;

    if(array != NULL && max != NULL && size>0)
    {
        for(int i=0;i<size;i++)
        {
            if(i==0 || *(array+i)>*max)
            {
                *max = *(array+i);
                gotMax = 0;
            }
        }
    }
    return gotMax;
}

int Comparison_GetMaxFloat(float* array, int size, float* max)
{
    int gotMax = -1;

    if(array != NULL && max != NULL && size>0)
    {
        for(int i=0;i<size;i++)
        {
            if(i==0 || *(array+i)>*max)
            {
                *max = *(array+i);
                gotMax = 0;
            }
        }
    }
    return gotMax;
}
