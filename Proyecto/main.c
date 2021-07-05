/***********************************************************

Teniendo en cuenta la consigna propuesta para la primera instancia del
parcial deber�n:
1- Agregar una estructura m�s al proyecto. La misma deber� poder
relacionarse de alguna forma con las trabajadas en la primera instancia.
Deber� refactorizar el programa para utilizar tambi�n esta estructura. La
estructura debe tener sentido dentro del dominio que estamos manejando.
2- Crear por lo menos dos informes complejos que involucren las 3
estructuras trabajadas. No se podr�n utilizar los informes ya solicitados,
debido a que formar�an parte de la refactorizaci�n.
3- Entregar un documento con el prototipo y documentaci�n de cada funci�n
que utilizan en el programa seg�n cada biblioteca. No es necesario hacerlo
con las funciones accesorias, solo las que forman parte del n�cleo del
programa.
4- Grabar un video de no m�s de 10 minutos de duraci�n, explicando las
funciones m�s importantes de su programa. La explicaci�n tiene que ser clara
y deber� incluir las funciones refactorizadas y los nuevos informes. Las
funciones deben ser explicadas, no queremos la lectura del c�digo.


Lucas Ferrini

*************************************************************/

#include "Controller.h"
#define W 10
#define S 10
#define B 10
#define O 10


int main()
{
    sWork myWorks[W];
    Vector works = vector_new(myWorks, W, sizeof(sWork));

    sService myServices[S];
    Vector services = vector_new(myServices, S, sizeof(sService));

    sBycycle myBycycles[B];
    Vector bycycles = vector_new(myBycycles, B, sizeof(sBycycle));

    sOwner myOwners[O];
    Vector owners = vector_new(myOwners, O, sizeof(sOwner));
    int option;

    if(!controller_initProgram(&works, &services, &bycycles, &owners))
    {
        do
        {
            option = Ui_CreateMenu("Menu Principal", "\nIngrese una opcion: ", 13,  "Alta trabajo",
                                                                                    "Modificar Trabajo",
                                                                                    "Baja trabajo",
                                                                                    "Listar Trabajos",
                                                                                    "Listar Servicios",
                                                                                    "Total en pesos por servicios prestados",
                                                                                    "Trabajos ordenados por marca de bicicleta",
                                                                                    "Listar servicios con mas trabajos",
                                                                                    "Listar servicios con datos de bicicleta",
                                                                                    "Cantidad de bicicletas rojas",
                                                                                    "Mostrar propietarios que mas gastaron",
                                                                                    "Mostrar trabajos ordenados por numeros de telefono",
                                                                                    "Salir");
            switch(option)
            {
                case 1:
                    controller_addWork(&works, &services, &bycycles);
                    break;
                case 2:
                    controller_editWork(&works, &services, &bycycles);
                    break;
                case 3:
                    controller_removeWork(&works);
                    break;
                case 4:
                    controller_listWorks(&works);
                    break;
                case 5:
                    controller_listServices(&services);
                    break;
                case 6:
                    controller_TotalEarnings(&works, &services, &bycycles, &owners);
                    break;
                case 7:
                    controller_listWorksByBrand(&works, &bycycles, &services, &owners);
                    break;
                case 8:
                    controller_listMostDoneServices(&works, &services, &bycycles, &owners);
                    break;
                case 9:
                    controller_listServicesWithBycycles(&works, &services, &bycycles, &owners);
                    break;
                case 10:
                    controller_listRedBycycles(&works, &bycycles, &services, &owners);
                    break;
                case 11:
                    controller_OwnersThatSpentMost(&works, &services, &bycycles, &owners);
                    break;
                case 12:
                    controller_ListWorksByPhoneNumber(&works, &bycycles, &owners, &services);
                    break;
                case 13:
                    if(!Input_Confirmation("\nEsta seguro que desea salir? s/n: ", "\nOpcion invalida", 's', 'n'))
                    {
                        option--;
                    }
                    break;
            }
            printf("\n\n");
            system("pause");
            system("cls");
        }while(option != 13);
    }
    else
    {
        printf("Algo salio mal al iniciar el programa. Codigo de error: 2");
        system("pause");
        exit(2);
    }
    return 0;
}
