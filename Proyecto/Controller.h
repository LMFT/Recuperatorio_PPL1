#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED



#endif // CONTROLLER_H_INCLUDED

#include "sService.h"
#include "sOwner.h"
#include "sWork.h"
#include "sBycycle.h"
#include "Vector.h"
#include "Input.h"
#include "Ui.h"


/** \brief Initializes and hardcore the data inside the given vectors
 *
 * \param works Vector* Pointer to works array
 * \param services Vector* Pointer to services array
 * \param bycycles Vector* Pointer to bycycles array
 * \param owners Vector* Pointer to owners array
 * \return int 0 if ok
                -1 if any pointers are NULL
 *
 */
int controller_initProgram(Vector* works, Vector* services, Vector* bycycles, Vector* owners);
/** \brief Adds a new work to the list
 *
 * \param works Vector* Pointer to works array
 * \param services Vector* Pointer to services array
 * \param bycycles Vector* Pointer to bycycles array
 * \return int -1 if any pointers are NULL or the user cancels the input
                0 if ok
 *
 */
int controller_addWork(Vector* works, Vector* services, Vector* bycycles);
/** \brief Asks the user to input the data related to the new work
 *
 * \param new sWork* Pointer to the new work
 * \param services Vector* Pointer to services array
 * \param bycycles Vector* Pointer to bycycles array
 * \return int 0 if ok
                -1 if any pointers are NULL
 *
 */
int controller_inputWork(sWork* new, Vector* services, Vector* bycycles);
/** \brief Modifies the selected work
 *
 * \param works Vector* Pointer to works array
 * \param services Vector* Pointer to services array
 * \param bycycles Vector* Pointer to bycycles array
 * \return int -1 if any pointers are NULL or the user cancels the modification
                0 if ok
 *
 */
int controller_editWork(Vector* works, Vector* services, Vector* bycycles);
/** \brief Removes a work from the list
 *
 * \param works Vector* Pointer to works array
 * \return int 0 if ok
                -1 if the user cancels the removal or pointers are NULL
 *
 */
int controller_removeWork(Vector* works);
/** \brief Lists all the current works
 *
 * \param works Vector* Pointer to works array
 * \return int -1 if pointer is NULL
                Amount of elements printed if ok
 *
 */
int controller_listWorks(Vector* works);
/** \brief Lists all the current services
 *
 * \param services Vector* Pointer to services array
 * \return int -1 if pointer is NULL
                Amount of elements printed if ok
 *
 */
int controller_listServices(Vector* services);
/** \brief Prints the list of works and shows the total amount of earnings from all the works
 *
 * \param works Vector* Pointer to works array
 * \param services Vector* Pointer to services array
 * \param bycycles Vector* Pointer to bycycles array
 * \param owners Vector* Pointer to owners array
 * \return float -1 if any pointers are NULL
                    Total earnings if OK
 *
 */
float controller_TotalEarnings(Vector* works, Vector* services ,Vector* bycycles, Vector* owners);
/** \brief Sorts the array of works using the bycycle's brands as criteria
 *
 * \param works Vector* Pointer to works array
 * \param bycycles Vector* Pointer to bycycles array
 * \return int -1 if either pointers are NULL
                0 if ok
 *
 */
int controller_sortWorksByBrand(Vector* works, Vector* bycycles);
/** \brief Compares two given works using their associated bycycle's brands as criteria
 *
 * \param firstWork sWork* Pointer to first work
 * \param secondWork sWork* Pointer to second work
 * \param bycycles Vector* Pointer to array of bycycles
 * \return int -2 if any pointers are NULL
                -1 if first work's brand is closer to A than second work's one
                0 if brands are the same
                1 if first work's brand is closer to z than second work's one
 *
 */
int controller_compareWorksByBrand(sWork* firstWork, sWork* secondWork, Vector* bycycles);
/** \brief Sorts, compares and list all works using the bycycle's brand as criteria
 *
 * \param works Vector* Pointer to works array
 * \param services Vector* Pointer to services array
 * \param bycycles Vector* Pointer to bycycles array
 * \param owners Vector* Pointer to owners array
 * \return int -1 if any pointers are NULL
                Amount of elements printed if OK
 *
 */
int controller_listWorksByBrand(Vector* works, Vector* bycycles, Vector* services, Vector* owners);
/** \brief Gets a bycycle from the array using a work as the criteria to get its ID
 *
 * \param work sWork* Pointer to work
 * \param bycycles Vector* Pointer to array of bycycles
 * \return sBycycle*    NULL if any pointers are NULL
                        Bycycle that match the work's bycycle ID if ok
 *
 */
sBycycle* controller_getBycycleByWork(sWork* work, Vector* bycycles);
/** \brief Gets and prints the most done services
 *
 * \param works Vector* Pointer to works array
 * \param services Vector* Pointer to services array
 * \param bycycles Vector* Pointer to bycycles array
 * \param owners Vector* Pointer to owners array
 * \return int  -1 if any pointers are NULL
                Amount of printed services if ok
 *
 */
int controller_listMostDoneServices(Vector* works, Vector* services, Vector* bycycles, Vector* owners);
/** \brief Prints all the works associated with the given service
 *
 * \param service sService* Pointer to service
 * \param works Vector* Pointer to works array
 * \param bycycles Vector* Pointer to bycycles array
 * \param owners Vector* Pointer to owners array
 * \return int  0 if ok
                -1 if any pointers are NULL
 * \return int
 *
 */
int controller_printWorksByService(sService* service, Vector* works, Vector* bycycles, Vector* owners);
/** \brief Counts how many times each service was performed
 *
 * \param works Vector* Pointer to works array
 * \param services Vector* Pointer to services array
 * \param counters int* Output pointer for the counters
 * \return int  -1 if either pointers are NULL
                Amount of different services counted if ok
 *
 */
int controller_countServices(Vector* works, Vector* services, int* counters);
/** \brief Prints the information of a work using the data of bycycles and services whenever is possible
 *
 * \param works Vector* Pointer to works array
 * \param services Vector* Pointer to services array
 * \param bycycles Vector* Pointer to bycycles array
 * \param owners Vector* Pointer to owners array
 * \return int  Amount of works listed if ok
                -1 if any pointers are NULL
 *
 */
int controller_listServicesWithBycycles(Vector* works, Vector* services, Vector* bycycles, Vector* owners);
/** \brief Gets a service using a given work as criteria to get it's ID
 *
 * \param work sWork* Pointer to given work
 * \param services Vector* Pointer to services array
 * \return sService*    NULL if any pointers are NULL
                        Service provided if ok
 *
 */
sService* controller_getServiceByWork(sWork* work, Vector* services);
/** \brief Lists all bycycles whose colour matches "Rojo" (Red)
 *
 * \param works Vector* Pointer to works array
 * \param services Vector* Pointer to services array
 * \param bycycles Vector* Pointer to bycycles array
 * \param owners Vector* Pointer to owners array
 * \return int  Amount of bycycles if ok
                -1 if any pointers are NULL
 *
 */
int controller_listRedBycycles(Vector* works, Vector* bycycles, Vector* services, Vector* owners);
/** \brief Lists the owners of bycycles that spent the most in services
 *
 * \param works Vector* Pointer to works array
 * \param services Vector* Pointer to services array
 * \param bycycles Vector* Pointer to bycycles array
 * \param owners Vector* Pointer to owners array
 * \return int  Amount of bycycles if ok
                -1 if any pointers are NULL
 *
 */
int controller_OwnersThatSpentMost(Vector* works, Vector* services, Vector* bycycles, Vector* owners);
/** \brief Compares if the owner id of a bycycle matchs the id of an owner
 *
 * \param bycycle sBycycle* Pointer to bycycle
 * \param owner sOwner* Pointer to owner
 * \return int -2 if either pointers are NULL
                -1 if ids don't match
                0 if ids match
 *
 */
int controller_compareBycycleAndOwner(sBycycle* bycycle, sOwner* owner);
/** \brief Counts how much every owner spent in services
 *
 * \param works Vector* Pointer to works array
 * \param services Vector* Pointer to services array
 * \param bycycles Vector* Pointer to bycycles array
 * \param owners Vector* Pointer to owners array
 * \param totals float* Output pointer to store the accumulated values
 * \return -1 if any pointers are NULL
            Amount of owners counted if ok
 *
 */

int controller_countEarningsPerOwner(Vector* works, Vector* services, Vector* bycycles, Vector* owners, float* totals);
/** \brief Compares if a given work was done to a given owner using the bycycle's ids to make a match
 *
 * \param owner sOwner* Pointer to owner
 * \param work sWork* Pointer to work
 * \param bycycles Vector* Pointer to bycycles array
 * \return int -2 if any pointers are NULL
                -1 if the given work wasn't done to the given owner
                0 if the given work was done to the given owner
 *
 */
int controller_compareOwnerByWork(sOwner* owner, sWork* work, Vector* bycycles);
/** \brief Sorts the works array using the bycycle's owner phone number as a criteria
 *
 * \param works Vector* Pointer to works array
 * \param bycycles Vector* Pointer to bycycles array
 * \param owners Vector* Pointer to owners array
 * \return int  -1 if any pointers are NULL
                0 if the array was sorted
 *
 */
int controller_sortWorksByPhoneNumber(Vector* works, Vector* bycycles, Vector* owners);
/** \brief Sorts and prints the works using the bycycle's owner phone number as a criteria
 *
 * \param works Vector*
 * \param bycycles Vector*
 * \param owners Vector*
 * \param services Vector*
 * \return int
 *
 */
int controller_ListWorksByPhoneNumber(Vector* works, Vector* bycycles, Vector* owners, Vector* services);
/** \brief Gets an owner using a bycycle as a criteria to get its ID
 *
 * \param bycycle sBycycle* Pointer to bycycle
 * \param owners Vector* Pointer to owners array
 * \return sOwner* NULL if either pointers are NULL
                    Pointer to the owner of the bycycle if ok
 *
 */
sOwner* controller_getOwnerByBycycle(sBycycle* bycycle, Vector* owners);
/** \brief Prints all data related to a given work, including the data contained in its related structs
 *
 * \param work sWork* Pointer to the work to print
 * \param service sService* Pointer to its related service
 * \param bycycle sBycycle* Pointer to its related bycycle
 * \param owner sOwner* Pointer to the bycycle's owner
 * \return int -1 if any pointers are NULL
                0 if the data was printed
 *
 */
int controller_printInform(sWork* work, sService* service, sBycycle* bycycle, sOwner* owner);
