#include <stdlib.h>
#include <string.h>

#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

typedef struct Vector
{
    void* pElement;
    size_t elementSize;
    int len;
}Vector;

#endif // VECTOR_H_INCLUDED

/** \brief Creates a Vector struct, initialize it's value and returns a copy of itself
 *
 * \param pElement  void* Pointer to the adress of the array to stroe
 * \param len       int Amount of elements in the array
 * \param size      size_t Size in bytes of an element of the array
 * \return Vector   - a null vector {NULL,0,0} if any parameters are NULL
 *                  -a vector set with the given parametrs if ok
 *
 */
Vector vector_new(void* pElement, int len, size_t size);
/** \brief Returns the amount of elements in the vector
 *
 * \param this Vector* Pointer to vector
 * \return int -1 if vector is NULL
                -Amount of elements if ok
 *
 */
int vector_len(Vector* this);
/** \brief Gets the size of the elements contained in a vector
 *
 * \param this Vector* Pointer to the vector
 * \param size size_t* Output pointer for the size of the element
 * \return int -1 if any pointers are NULL
 *              0 if ok
 *
 */
int vector_getSize(Vector* this, size_t* size);
/** \brief Gets the element stored at index in a vector
 *
 * \param this Vector* Pointer to the vector
 * \param index int Index of the element;
 * \return void*  NULL if vector is NULL or index minor to 0 or index bigger than vector's len
                    Adress of the element if ok
 *
 */
void* vector_getElement(Vector* this, int index);
/** \brief Gets the element of a vector that has the same ID as the one given as a parameter
 *
 * \param this Vector* Pointer to vector
 * \param idParameter int*  ID to search for
 * \param  int(*getId)(void*,void*) ID getter
 * \param  int (*isEmpty)(void*) Pointer to function to check if the element has been removed previously
 * \return void* NULL if couldn't find an element matching the ID or vector pointer is NULL or ID pointer is NULL
                 Address of element if ok
 *
 */
void* vector_getElementById(Vector* this, int* idParameter, int(*getId)(void*,void*), int (*isEmpty)(void*));
/** \brief Sets an element in the given index of a vector
 *
 * \param this Vector* Pointer to vector
 * \param index int Index of the element;
 * \param pElement void* Pointer to element to store
 * \return int -1 if any pointers are NULL or index is minor to 0 or bigger than the amount of elements
                0 if ok
 *
 */
int vector_setElement(Vector* this, int index, void* pElement);
/** \brief Sorts a vector using the criteria given through a function
 *
 * \param this Vector* Pointer to vector
 * \param int (*pFunc)(void*, void*) Compare function to sort the vector
 * \param order int 1 for ascending order, 0 for descending
 * \return int -1 if couldn't sort the vector
                0 if ok
 *
 */
int vector_sort(Vector* this, int (*pFunc)(void*, void*),int order);
/** \brief Searchs the current vector to find any empty slots
 *
 * \param this Vector* Pointer to vector
 * \param int (*checkSpace)(void*) Function to check if the current element is available to use
 * \return int -1 if vector is full
                index of the first empty space if ok
 *
 */
int vector_searchEmptySpace(Vector* this, int (*checkSpace)(void*));
/** \brief Applies the given function to every element in the vector
 *
 * \param this Vector* Pointer to vector
 * \param int(*pFunc)(void*) Pointer to function to apply
 * \return int -1 if either pointers are NULL
                amount of elements mapped if ok
 *
 */
int vector_map(Vector* this, int(*pFunc)(void*));
/** \brief Searchs a vector for an element that metchs the given ID
 *
 * \param Vector* this Pointer to vector
 * \param int(*compare)(void*, void*) ID Comparison function
 * \param int(*isEmpty)(void*) Function to check if the current element is available to use
 * \param int(*getId)(void* pElement, void*pParameter)
 * \param int* targetId
 * \return int vector_searchById(Vector* this, int(*compare)(void*,
 *
 */
int vector_searchById(Vector* this, int(*compare)(void*, void*),int(*isEmpty)(void*),
                      int(*getId)(void* pElement, void*pParameter), int* targetId);
/** \brief Filters a vector given a criteria. Stores the filtered elements in buffer
 *
 * \param this Vector* Pointer to vector
 * \param int(*filter)(void*,void*) Pointer tu function to apply criteria to every element
 * \param ciretia void* Criteria to filter
 * \param buffer void* Adress to store the filtered elements
 * \return int vector_filter(Vector* this,
 *
 */
int vector_filter(Vector* this, int(*filter)(void*,void*),void* criteria, void* buffer);
