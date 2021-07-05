#include "Date.h"

#ifndef SWORK_H_INCLUDED
#define SWORK_H_INCLUDED

typedef struct
{
    int workId;
    int serviceId;
    int bycycleId;
    sDate date;
    int isEmpty;
}sWork;

#endif // SWORK_H_INCLUDED
/** \brief Gets the value of the lastId variable, which is private
 *
 * \return int Value of lastId
 *
 */
int work_getLastId();
/** \brief Decreases the value of the lastId variable and returns it's new value
 *
 * \return int New value of lastId
 *
 */
int work_decreaseLastId();
/** \brief Increases the value of the lastId variable and returns it's new value
 *
 * \return int New value of lastId
 *
 */
int work_increaseLastId();

/** \brief Sets the value of the given work to the values passed as parameters
 *
 * \param new sWork* Pointer to work
 * \param workId int New work id
 * \param serviceId int New service id
 * \param bycycleId int New bycycle id
 * \param workDate sDate New dat
 * \return int -1 if pointer is NULL
                0 if ok
 *
 */
int work_newParameters(sWork* new, int workId, int serviceId, int bycycleId, sDate workDate);
/** \brief Initializes a work
 *
 * \param this void* Pointer to work
 * \return int -1 if pointer is NULL
                0 if ok
 *
 */
int work_initializeOne(void* this);

/** \brief Sets the work id
 *
 * \param this sWork* Pointer to work
 * \param id int New id
 * \return int -1 if pointer is NULL
                0 if ok
 *
 */
int work_setWorkId(sWork* this, int id);
/** \brief Sets the work isEmpty
 *
 * \param this sWork* Pointer to work
 * \param isEmpty int New isEmpty
 * \return int -1 if pointer is NULL
                0 if ok
 *
 */
int work_setIsEmpty(sWork* this, int isEmpty);
/** \brief Sets the work's service id
 *
 * \param this sWork* Pointer to work
 * \param id int New service id
 * \return int -1 if pointer is NULL
                0 if ok
 *
 */
int work_setServiceId(sWork* this, int id);
/** \brief Sets the work's bycycle id
 *
 * \param this sWork* Pointer to work
 * \param id int New bycycle id
 * \return int -1 if pointer is NULL
                0 if ok
 *
 */
int work_setBycycleId(sWork* this, int id);
/** \brief Sets the work's date
 *
 * \param this sWork* Pointer to work
 * \param date sDate New date
 * \return int -1 if pointer is NULL
                0 if ok
 *
 */
int work_setDate(sWork* this, sDate date);

/** \brief Gets the value of the work id
 *
 * \param this void* Pointer to work
 * \param id void* Output pointer of the work id
 * \return int -1 if pointer is NULL
                0 if ok
 *
 */
int work_getWorkId(void* this, void* id);
/** \brief Gets the value of the work isEmpty
 *
 * \param this void* Pointer to work
 * \param isEmpty void* Output pointer of the work isEmpty
 * \return int -1 if pointer is NULL
                0 if ok
 *
 */
int work_getIsEmpty(void* this, void* isEmpty);
/** \brief Gets the value of the work's service id
 *
 * \param this void* Pointer to work
 * \param id void* Output pointer of the work's service id
 * \return int -1 if pointer is NULL
                0 if ok
 *
 */
int work_getServiceId(void* this, void* id);
/** \brief Gets the value of the work's bycycle id
 *
 * \param this void* Pointer to work
 * \param id void* Output pointer of the work's bycycle id
 * \return int -1 if pointer is NULL
                0 if ok
 *
 */
int work_getBycycleId(void* this, void* id);
/** \brief Gets the value of the work's date
 *
 * \param this void* Pointer to work
 * \param id void* Output pointer of the work's date
 * \return int -1 if pointer is NULL
                0 if ok
 *
 */
int work_getDate(void* this, void* date);

/** \brief Compares the id of two works
 *
 * \param firstWork void* Pointer to the first work
 * \param secondWork void* Pointer to the second work
 * \return int  -2 if either pointers are NULL
                -1 if first id is less than second id
                0 if ids match
                1 if first id is more than second id
 *
 */
int work_compareByWorkId(void* firstWork, void* secondWork);
/** \brief Compares the service id of two works
 *
 * \param firstWork void* Pointer to the first work
 * \param secondWork void* Pointer to the second work
 * \return int  -2 if either pointers are NULL
                -1 if first id is less than second id
                0 if ids match
                1 if first id is more than second id
 *
 */
int work_compareByServiceId(void* firstWork, void* secondWork);
/** \brief Compares the bycycle id of two works
 *
 * \param firstWork void* Pointer to the first work
 * \param secondWork void* Pointer to the second work
 * \return int  -2 if either pointers are NULL
                -1 if first id is less than second id
                0 if ids match
                1 if first id is more than second id
 *
 */
int work_compareByBycycleId(void* firstWork, void* secondWork);
/** \brief Compares the date of two works
 *
 * \param firstWork void* Pointer to the first work
 * \param secondWork void* Pointer to the second work
 * \return int  -2 if either pointers are NULL
                -1 if first date is less than second date
                0 if dates match
                1 if first date is more than second date
 *
 */
int work_compareByDate(void* firstWork, void* secondWork);

/** \brief Hardcodes 5 works
 *
 * \param this sWork* Array of works
 * \return int amount of elements hardcoded
 *
 */
int work_hardcode(sWork* myWorks);
/** \brief Prints a work
 *
 * \param this void* Pointer to work
 * \return int -1 if pointer is NULL
                0 if ok
 *
 */
int work_printOne(void* this);
/** \brief Checks if the current work has been logically removed
 *
 * \param this void* Pointer to work
 * \return int  -2 if pointer is NULL
                0 if element is occupied
                1 if element is available
 *
 */
int work_checkEmptySpace(void* this);
/** \brief Gets all the work information and outputs it through each pointer
 *
 * \param this void* Pointer to work
 * \param id int* Output pointer for the work's id
 * \param date sDate* Output pointer for the work's date
 * \param idService int* Output pointer for the work's service id
 * \param idBycycle int* Output pointer for the work's bycycle id
 * \return int -1 if pointer is NULL
                0 if ok
 *
 */
int work_getAll(void* this, int* idWork, sDate* date, int* idService, int* idBycycle);
