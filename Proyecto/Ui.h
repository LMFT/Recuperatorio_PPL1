#ifndef UI_H_INCLUDED
#define UI_H_INCLUDED



#endif // UI_H_INCLUDED

#include "Input.h"

/** \brief Creates a menu with a variable amount of options
 *
 * \param header[] char Header of the menu
 * \param inputMsg[] char Input message to ask for an option
 * \param amountOfOptions int Amount of options to print
 * \param ... char* A string representing an option. There should be as many strings as options
 * \return int [-1] if any pointers are NULL or the amount of options is less than 1
                Selected option otherwise
 *
 */
int Ui_CreateMenu(char header[],char inputMsg[], int amountOfOptions, ...);

void Ui_DebugMessage(int errorNumber);
