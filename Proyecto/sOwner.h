#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef SOWNER_H_INCLUDED
#define SOWNER_H_INCLUDED


/*typedef struct
{
    int areaCode;
    int phoneNumber;
}PhoneNumber;*/

typedef struct
{
    int id;
    char name[26];
    int phone;
    int isEmpty;
}sOwner;

#endif // SOWNER_H_INCLUDED

/** \brief Gets the value of the lastId variable, which is private
 *
 * \return int Value of lastId
 *
 */
int owner_getLastId();
/** \brief Decreases the value of the lastId variable and returns it's new value
 *
 * \return int New value of lastId
 *
 */
int owner_decreaseLastId();
/** \brief Increases the value of the lastId variable and returns it's new value
 *
 * \return int New value of lastId
 *
 */
int owner_increaseLastId();


/** \brief Sets the value of the given work to the values passed as parameters
 *
 * \param new sOwner* Pointer to owner
 * \param id int New id
 * \param name char* New name
 * \param phone int New phone
 * \return int -1 if pointer is NULL
                0 if ok
 *
 */
int owner_newParameters(sOwner* new, int id, char* name, int phone);
/** \brief Initializes a owner
 *
 * \param this void* Pointer to owner
 * \return int -1 if pointer is NULL
                0 if ok
 *
 */
int owner_initializeOne(void* this);

/** \brief Sets the owner id
 *
 * \param this sOwner* Pointer to owner
 * \param id int New id
 * \return int -1 if pointer is NULL
                0 if ok
 *
 */
int owner_setId(sOwner* this, int id);
/** \brief Sets the owner isEmpty
 *
 * \param this sOwner* Pointer to owner
 * \param isEmpty int New isEmpty
 * \return int -1 if pointer is NULL
                0 if ok
 *
 */
int owner_setIsEmpty(sOwner* this, int isEmpty);
/** \brief Sets the owner name
 *
 * \param this sOwner* Pointer to owner
 * \param name int New name
 * \return int -1 if pointer is NULL
                0 if ok
 *
 */
int owner_setName(sOwner* this, char* name);
/** \brief Sets the owner phone
 *
 * \param this sOwner* Pointer to owner
 * \param phone int New phone
 * \return int -1 if pointer is NULL
                0 if ok
 *
 */
int owner_setPhone(sOwner* this, int phone);

/** \brief Gets the value of the owner id
 *
 * \param this void* Pointer to owner
 * \param id void* Output pointer of the owner id
 * \return int -1 if pointer is NULL
                0 if ok
 *
 */
int owner_getId(void* this, void* id);
/** \brief Gets the value of the owner isEmpty
 *
 * \param this void* Pointer to owner
 * \param isEmpty void* Output pointer of the owner isEmpty
 * \return int -1 if pointer is NULL
                0 if ok
 *
 */
int owner_getIsEmpty(void* this, void* isEmpty);
/** \brief Gets the value of the owner name
 *
 * \param this void* Pointer to owner
 * \param name void* Output pointer of the owner name
 * \return int -1 if pointer is NULL
                0 if ok
 *
 */
int owner_getName(void* this, void* name);
/** \brief Gets the value of the owner phone
 *
 * \param this void* Pointer to owner
 * \param phone void* Output pointer of the owner phone
 * \return int -1 if pointer is NULL
                0 if ok
 *
 */
int owner_getPhone(void* this, void* phone);

/** \brief Compares the id of two owners
 *
 * \param firstOwner void* Pointer to the first owner
 * \param secondOwner void* Pointer to the second owner
 * \return int  -2 if either pointers are NULL
                -1 if first id is less than second id
                0 if ids match
                1 if first id is more than second id
 *
 */
int owner_compareById(void* firstOwner, void* secondOwner);
/** \brief Compares the name of two owners
 *
 * \param firstOwner void* Pointer to the first owner
 * \param secondOwner void* Pointer to the second owner
 * \return int  -2 if either pointers are NULL
                -1 if first name is less than second name
                0 if names match
                1 if first name is more than second name
 *
 */
int owner_compareByName(void* firstOwner, void* secondOwner);
/** \brief Compares the phone of two owners
 *
 * \param firstOwner void* Pointer to the first owner
 * \param secondOwner void* Pointer to the second owner
 * \return int  -2 if either pointers are NULL
                -1 if first phone is less than second phone
                0 if phones match
                1 if first phone is more than second phone
 *
 */
int owner_compareByPhone(void* firstOwner, void* secondOwner);

/** \brief Hardcodes 4 owners
 *
 * \param this sOwner* Array of owners
 * \return int amount of elements hardcoded
 *
 */
int owner_hardcode(sOwner* this);
/** \brief Prints a owner
 *
 * \param this void* Pointer to owner
 * \return int -1 if pointer is NULL
                0 if ok
 *
 */
int owner_printOne(void* this);
/** \brief Checks if the current owner has been logically removed
 *
 * \param this void* Pointer to owner
 * \return int  -2 if pointer is NULL
                0 if element is occupied
                1 if element is available
 *
 */
int owner_checkEmptySpace(void* this);

/** \brief Gets all the owner information and outputs it through each pointer
 *
 * \param this void* Pointer to owner
 * \param id int* Output pointer for the owner's id
 * \param name char* Output pointer for the owner's name
 * \param phone int* Output pointer for the owner's phone
 * \return int -1 if pointer is NULL
                0 if ok
 *
 */
int owner_getAll(void* this, int* id, char* name, int* phone);



