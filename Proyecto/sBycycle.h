#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef SBYCYCLE_H_INCLUDED
#define SBYCYCLE_H_INCLUDED

typedef struct
{
    int idBycycle;
    int idOwner;
    int wheelSize;
    char brand[26];
    char colour[26];
    int isEmpty;
}sBycycle;

#endif // SBYCYCLE_H_INCLUDED

/** \brief Gets the value of the lastId variable, which is private
 *
 * \return int Value of lastId
 *
 */
int bycycle_getLastId();
/** \brief Decreases the value of the lastId variable and returns it's new value
 *
 * \return int New value of lastId
 *
 */
int bycycle_decreaseLastId();
/** \brief Increases the value of the lastId variable and returns it's new value
 *
 * \return int New value of lastId
 *
 */
int bycycle_increaseLastId();

/** \brief Sets the value of the given bycycle to the values passed as parameters
 *
 * \param this sBycycle* Pointer to bycycle
 * \param idBycycle int Bycycle ID
 * \param idOwner int Owner ID
 * \param wheelSize int Wheel Size
 * \param brand char* Bycycle's brand
 * \param colour char* Bycycle's colour
 * \return int -1 if pointer is NULL
                0 if ok
 *
 */
int bycycle_newParameters(sBycycle* this, int idBycycle, int idOwner, int wheelSize, char* brand, char* colour);

/** \brief Initializes a bycycle
 *
 * \param this void* Pointer to bycycle
 * \return int -1 if pointer is NULL
                0 if ok
 *
 */
int bycycle_initializeOne(void* this);

/** \brief Sets the Bycycle's ID
 *
 * \param this sBycycle* Pointer to bycycle
 * \param idBycycle int New ID
 * \return int -1 if pointer is NULL
                0 if ok
 *
 */

int bycycle_setIdBycycle(sBycycle* this, int idBycycle);
/** \brief Sets the Bycycle's owner ID
 *
 * \param this sBycycle* Pointer to bycycle
 * \param idOwner int New owner's ID
 * \return int -1 if pointer is NULL
                0 if ok
 *
 */
int bycycle_setIdOwner(sBycycle* this, int idOwner);
/** \brief Sets the logical removal value
 *
 * \param this sBycycle* Pointer to bycycle
 * \param isEmpty int New value
 * \return int  -1 if pointer is NULL
                0 if ok
 *
 */
int bycycle_setIsEmpty(sBycycle* this, int isEmpty);
/** \brief  Sets the wheel size of the bycycle
 *
 * \param this sBycycle* Pointer to bycycle
 * \param wheelSize int New wheel size
 * \return int -1 if pointer is NULL
                0 if ok
 *
 */
int bycycle_setWheelSize(sBycycle* this, int wheelSize);
/** \brief Sets the bycycle's brand
 *
 * \param this sBycycle* Pointer to bycycle
 * \param brand char* New brand
 * \return int -1 if pointer is NULL
                0 if ok
 *
 */
int bycycle_setBrand(sBycycle* this, char* brand);
/** \brief Sets the colour of the bycycle
 *
 * \param this sBycycle* Pointer to bycycle
 * \param colour char* New colour
 * \return int -1 if pointer is NULL
                0 if ok
 *
 */
int bycycle_setColour(sBycycle* this, char* colour);

/** \brief Gets the value of the bycycle's ID
 *
 * \param this void* Pointer to bycycle
 * \param idBycycle void* Output pointer of the bycycle's id
 * \return int -1 if pointer is NULL
                0 if ok
 *
 */
int bycycle_getIdBycycle(void* this, void* idBycycle);
/** \brief Gets the value of the bycycle's owner's ID
 *
 * \param this void* Pointer to bycycle
 * \param idOwner void* Output pointer of the owner's id
 * \return int -1 if pointer is NULL
                0 if ok
 *
 */
int bycycle_getIdOwner(void* this, void* idOwner);
/** \brief Gets the value of the bycycle's logical removal value
 *
 * \param this void* Pointer to bycycle
 * \param isEmpty void* Output pointer of the bycycle's isEmpty value
 * \return int -1 if pointer is NULL
                0 if ok
 *
 */
int bycycle_getIsEmpty(void* this, void* isEmpty);
/** \brief Gets the value of the bycycle's wheel size
 *
 * \param this void* Pointer to bycycle
 * \param wheelSize void* Output pointer of the bycycle's wheel size
 * \return int -1 if pointer is NULL
                0 if ok
 *
 */
int bycycle_getWheelSize(void* this, void* wheelSize);
/** \brief Gets the value of the bycycle's brand
 *
 * \param this void* Pointer to bycycle
 * \param brand void* Output pointer of the
 * \return int -1 if pointer is NULL
                0 if ok
 *
 */
int bycycle_getBrand(void* this, void* brand);
/** \brief Gets the value of the bycycle's colour
 *
 * \param this void* Pointer to bycycle
 * \param colour void* Output pointer of the bycycle's colour
 * \return int -1 if pointer is NULL
                0 if ok
 *
 */
int bycycle_getColour(void* this, void* colour);

/** \brief Compares the id of two bycycles
 *
 * \param firstBycycle void* Pointer to the first bycycle
 * \param secondBycycle void* Pointer to the second bycycle
 * \return int  -2 if either pointers are NULL
                -1 if first id is less than second id
                0 if ids match
                1 if first id is more than second id
 *
 */
int bycycle_compareByIdBycycle(void* firstBycycle, void* secondBycycle);
/** \brief Compares the id of two bycycles' owners
 *
 * \param firstBycycle void* Pointer to the first bycycle
 * \param secondBycycle void* Pointer to the second bycycle
 * \return int  -2 if either pointers are NULL
                -1 if first id is less than second id
                0 if ids match
                1 if first id is more than second id
 *
 */
int bycycle_compareByIdOwner(void* firstBycycle, void* secondBycycle);
/** \brief Compares the wheel size of two bycycles
 *
 * \param firstBycycle void* Pointer to the first bycycle
 * \param secondBycycle void* Pointer to the second bycycle
 * \return int  -2 if either pointers are NULL
                -1 if first wheel size is less than second wheels size
                0 if wheels size match
                1 if first wheel size is more than second wheels size
 *
 */
int bycycle_compareByWheelSize(void* firstBycycle, void* secondBycycle);
/** \brief Compares the brand of two bycycles
 *
 * \param firstBycycle void* Pointer to the first bycycle
 * \param secondBycycle void* Pointer to the second bycycle
 * \return int  -2 if either pointers are NULL
                -1 if first brand is less than second brands
                0 if brands match
                1 if first brands is more than second brand
 *
 */
int bycycle_compareByBrand(void* firstBycycle, void* secondBycycle);
/** \brief Compares the colour of two bycycles
 *
 * \param firstBycycle void* Pointer to the first bycycle
 * \param secondBycycle void* Pointer to the second bycycle
 * \return int  -2 if either pointers are NULL
                -1 if first colour is less than second colour
                0 if colours match
                1 if first colour is more than second colour
 *
 */
int bycycle_compareByColour(void* firstBycycle, void* secondBycycle);

/** \brief Hardcodes 5 bycycles
 *
 * \param this sBycycle* Array of bycycles
 * \return int amount of elements hardcoded
 *
 */
int bycycle_hardcode(sBycycle* this);
/** \brief Prints a bycycle
 *
 * \param this void* Pointer to bycycle
 * \return int  -1 if pointer is NULL
                0 if ok
 *
 */
int bycycle_printOne(void* this);
/** \brief Checks if the current bycycle has been logically removed
 *
 * \param this void* Pointer to bycycle
 * \return int  -2 if pointer is NULL
                0 if element is occupied
                1 if element is available
 *
 */
int bycycle_checkEmptySpace(void* this);
/** \brief Gets all the bycycle information and outputs it through each pointer
 *
 * \param this void* Pointer to bycycle
 * \param idBycycle int* Output pointer for the bycycle id
 * \param idOwner int* Output pointer for the  owner id
 * \param wheelSize int* Output pointer for the wheel size
 * \param brand char* Output pointer for the brand
 * \param colour char* Output pointer for the colour
 * \return int -1 if any pointers are NULL
                0 if ok
 *
 */
int bycycle_getAll(void* this, int* idBycycle, int* idOwner,int* wheelSize,char* brand,char* colour);
