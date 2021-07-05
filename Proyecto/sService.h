#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef SSERVICE_H_INCLUDED
#define SSERVICE_H_INCLUDED

typedef struct
{
    int id;
    char description[26];
    float price;
    int isEmpty;
}sService;

#endif // SSERVICE_H_INCLUDED
/** \brief Gets the value of the lastId variable, which is private
 *
 * \return int Value of lastId
 *
 */
int service_getLastId();
/** \brief Decreases the value of the lastId variable and returns it's new value
 *
 * \return int New value of lastId
 *
 */
int service_decreaseLastId();
/** \brief Increases the value of the lastId variable and returns it's new value
 *
 * \return int New value of lastId
 *
 */
int service_increaseLastId();

/** \brief Sets the value of the given service to the values passed as parameters
 *
 * \param this sService* Pointer to service
 * \param idService int Service ID
 * \param price float Service price
 * \param description char* Service description
 * \return int -1 if pointer is NULL
                0 if ok
 *
 */
int service_newParameters(sService* new, int id, char* description, float price);
/** \brief Initializes a service
 *
 * \param this void* Pointer to service
 * \return int -1 if pointer is NULL
                0 if ok
 *
 */
int service_initializeOne(void* this);
/** \brief Sets the service ID
 *
 * \param this sService* Pointer to service
 * \param idService int New ID
 * \return int -1 if pointer is NULL
                0 if ok
 *
 */
int service_setId(sService* this, int id);
/** \brief Sets the service isEmpty
 *
 * \param this sService* Pointer to service
 * \param isEmpty int New isEmpty
 * \return int -1 if pointer is NULL
                0 if ok
 *
 */
int service_setIsEmpty(sService* this, int isEmpty);
/** \brief Sets the service description
 *
 * \param this sService* Pointer to service
 * \param description char* New description
 * \return int -1 if pointer is NULL
                0 if ok
 *
 */
int service_setDescription(sService* this, char* description);
/** \brief Sets the service price
 *
 * \param this sService* Pointer to service
 * \param price float New price
 * \return int -1 if pointer is NULL
                0 if ok
 *
 */
int service_setPrice(sService* this, float price);
/** \brief Gets the value of the service ID
 *
 * \param this void* Pointer to service
 * \param idService void* Output pointer of the service id
 * \return int -1 if pointer is NULL
                0 if ok
 *
 */
int service_getId(void* this, void* id);
/** \brief Gets the value of the service isEmpty
 *
 * \param this void* Pointer to service
 * \param isEmpty void* Output pointer of the service isEmpty
 * \return int -1 if pointer is NULL
                0 if ok
 *
 */
int service_getIsEmpty(void* this, void* isEmpty);
/** \brief Gets the value of the service description
 *
 * \param this void* Pointer to service
 * \param description void* Output pointer of the service description
 * \return int -1 if pointer is NULL
                0 if ok
 *
 */
int service_getDescription(void* this, void* description);
/** \brief Gets the value of the service price
 *
 * \param this void* Pointer to service
 * \param price void* Output pointer of the service price
 * \return int -1 if pointer is NULL
                0 if ok
 *
 */
int service_getPrice(void* this, void* price);
/** \brief Compares the id of two services
 *
 * \param firstService void* Pointer to the first service
 * \param secondService void* Pointer to the second service
 * \return int  -2 if either pointers are NULL
                -1 if first id is less than second id
                0 if ids match
                1 if first id is more than second id
 *
 */
int service_compareById(void* firstService, void* secondService);
/** \brief Compares the description of two services
 *
 * \param firstService void* Pointer to the first service
 * \param secondService void* Pointer to the second service
 * \return int  -2 if either pointers are NULL
                -1 if first description is less than second description
                0 if descriptions match
                1 if first description is more than second description
 *
 */
int service_compareByDescription(void* firstService, void* secondService);
/** \brief Compares the prices of two services
 *
 * \param firstService void* Pointer to the first service
 * \param secondService void* Pointer to the second service
 * \return int  -2 if either pointers are NULL
                -1 if first prices is less than second prices
                0 if prices match
                1 if first prices is more than second prices
 *
 */
int service_compareByPrice(void* firstService, void* secondService);
/** \brief Hardcodes 4 services
 *
 * \param this sService* Array of services
 * \return int amount of elements hardcoded
 *
 */
int service_hardcode(sService* this);
/** \brief Prints a service
 *
 * \param this void* Pointer to service
 * \return int -1 if pointer is NULL
                0 if ok
 *
 */
int service_printOne(void* this);
/** \brief Checks if the current service has been logically removed
 *
 * \param this void* Pointer to service
 * \return int  -2 if pointer is NULL
                0 if element is occupied
                1 if element is available
 *
 */
int service_checkEmptySpace(void* this);
/** \brief Gets all the service information and outputs it through each pointer
 *
 * \param this void* Pointer to service
 * \param id int* Output pointer for the service id
 * \param description char* Output pointer for the service description
 * \param price float* Output pointer for the service price
 * \return int -1 if pointer is NULL
                0 if ok
 *
 */
int service_getAll(void* this, int* id, char* description, float* price);
