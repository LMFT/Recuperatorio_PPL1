#include "Controller.h"

int controller_initProgram(Vector* works, Vector* services, Vector* bycycles, Vector* owners)
{
    sWork* myWorks;
    sService* myServices;
    sBycycle* myBycycles;
    sOwner* owner;
    int returnAux = -1;
    if(works != NULL && services != NULL && bycycles != NULL)
    {
        myWorks = (sWork*)vector_getElement(works, 0);
        myServices = (sService*)vector_getElement(services, 0);
        myBycycles = (sBycycle*)vector_getElement(bycycles, 0);
        owner = (sOwner*) vector_getElement(owners, 0);
        if(myWorks != NULL && myBycycles != NULL && myServices != NULL && owner)
        {
            if(vector_map(works, work_initializeOne) == vector_len(works) &&
               vector_map(services, service_initializeOne) == vector_len(services) &&
               vector_map(bycycles, bycycle_initializeOne) == vector_len(bycycles) &&
               vector_map(owners, owner_initializeOne))
            {
                if(service_hardcode(myServices) == 4)
                {
                    if(bycycle_hardcode(myBycycles) == 5)
                    {
                        if(work_hardcode(myWorks) == 5)
                        {
                            if(owner_hardcode(owner))
                            {
                                returnAux = 0;
                            }
                        }
                    }
                }
            }

        }
    }
    return returnAux;
}

int controller_addWork(Vector* works, Vector* services, Vector* bycycles)
{
    sWork new;
    int newWork = -1;
    int index;

    if(works != NULL && services != NULL && bycycles != NULL)
    {
        index = vector_searchEmptySpace(works, work_checkEmptySpace);
        if(index>=0)
        {
            work_increaseLastId();
            if(!controller_inputWork(&new, services, bycycles))
            {
                printf("\n%10s %10s %10s %6s", "ID Trabajo", "ID Servicio", "ID Bicicleta", "Fecha");
                if(!work_printOne(&new))
                {
                    if(Input_Confirmation("\nDesea agregar este elemento? s/n: ", "\nOpcion incorrecta", 's', 'n'))
                    {
                        if(!vector_setElement(works, index, &new))
                        {
                            newWork = 0;
                        }
                    }
                }
            }
        }
    }
    if(newWork)
    {
        work_decreaseLastId();
    }
    return newWork;
}

int controller_inputWork(sWork* new, Vector* services, Vector* bycycles)
{
    int newWork = -1;
    int idService;
    int idBycycle;
    sDate date;
    int day;
    int month;
    int year;
    if(new != NULL)
    {
        printf("\n%3s %13s %9s", "ID Servicio", "Descripcion", "Precio");
        if(vector_map(services, service_printOne) > 0)
        {
            Input_IntInRange(&idService, "\nIngrese el ID del servicio: ", 20000, service_getLastId(),
                             "\nNo se encuentra el ID ingresado.");
            if(vector_searchById(services, service_compareById, service_checkEmptySpace, service_getId, &idService) >= 0)
            {
                printf("\n%3s %10s %7s %9s %10s", "ID Bicicleta", "ID duenio", "Marca", "Color", "Rodado");
                if(vector_map(bycycles, bycycle_printOne) > 0)
                {
                    Input_IntInRange(&idBycycle, "\nIngrese el ID de la bicicleta: ", 25, bycycle_getLastId(),
                                     "\nNo se encuentra el ID ingresado.");
                    if(vector_searchById(bycycles, bycycle_compareByIdBycycle, bycycle_checkEmptySpace,
                                                                bycycle_getIdBycycle, &idBycycle) >= 0)
                    {
                        Input_IntInRange(&day, "\nIngrese el dia en que se realizo el trabajo: ", 1, 31,
                                                                                "\nEste numero de dia no existe");

                        Input_IntInRange(&month, "\nIngrese el mes en que se realizo el trabajo: ", 1, 12,
                                                                                "\nEste numero de mes no existe");

                        Input_IntOverValue(&year, "\nIngrese el a%co en que se realizo el trabajo: ", 2000,
                                                    "\nEl a%co en que se realizo el trabajo debe ser al menos 2000", 164);
                        if(!date_newDate(&date, day, month, year))
                        {
                            if(!work_newParameters(new, work_getLastId(), idService, idBycycle, date))
                            {
                                newWork = 0;
                            }
                        }
                    }
                }
            }
        }
    }
    return newWork;
}

int controller_editWork(Vector* works, Vector* services, Vector* bycycles)
{
    int editedWork = -1;
    int idWork;
    int index;
    sWork* old;
    sWork new;

    if(works != NULL && services != NULL && bycycles != NULL)
    {
        printf("\n%10s %10s %10s %6s", "ID Trabajo", "ID Servicio", "ID Bicicleta", "Fecha");
        if(vector_map(works, work_printOne) > 0)
        {
            Input_IntInRange(&idWork, "\nIngrese el ID deseado: ", 1, work_getLastId(), "\nNo se encuentra el ID ingresado");
            index = vector_searchById(works, work_compareByWorkId, work_checkEmptySpace, work_getWorkId, &idWork);
            if(index>=0)
            {
                old = (sWork*) vector_getElement(works, index);
                if(old != NULL)
                {
                    if(!controller_inputWork(&new, services, bycycles))
                    {
                        printf("\nTrabajo original: ");
                        if(!work_printOne(old))
                        {
                            printf("\nTrabajo modificado: ");
                            if(!work_printOne(&new))
                            {
                                if(Input_Confirmation("\nDesea confirmar esta modificacion? s/n: ", "Respuesta invalida", 's', 'n'))
                                {
                                    if(!vector_setElement(works, index, &new))
                                    {
                                        editedWork = 0;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return editedWork;
}


int controller_removeWork(Vector* works)
{
    int idWork;
    int removedWork;
    sWork* target;

    if(works != NULL)
    {
        printf("\n%10s %10s %10s %6s", "ID Trabajo", "ID Servicio", "ID Bicicleta", "Fecha");
        if(vector_map(works, work_printOne) > 0)
        {
            Input_IntInRange(&idWork, "\nIngrese el ID deseado: ", 1, work_getLastId(), "\nNo se encuentra el ID ingresado");
            target = (sWork*)vector_getElementById(works, &idWork, work_getWorkId, work_checkEmptySpace);
            if(target != NULL)
            {
                printf("\n%10s %10s %10s %6s", "ID Trabajo", "ID Servicio", "ID Bicicleta", "Fecha");
                if(!work_printOne(target))
                {
                    if(Input_Confirmation("\nEsta seguro que desea dar de baja este trabajo? s/n: ", "Opcion invalida", 's', 'n'))
                    {
                        if(!work_initializeOne(target))
                        {
                            removedWork = 0;
                        }
                    }
                }
            }
        }
    }
    return removedWork;
}


int controller_listWorks(Vector* works)
{
    int printedWorks = -1;


    if(works != NULL)
    {
        printf("\n\n%s %5s %5s %10s", "ID Trabajo", "ID Servicio", "ID Bicicleta", "Fecha");
        printedWorks = vector_map(works, work_printOne);
    }
    return printedWorks;
}

int controller_listServices(Vector* services)
{
    int printedWorks = -1;

    if(services != NULL)
    {
        printf("\n%3s %13s %7s", "ID", "Descripcion", "Precio");
        printedWorks = vector_map(services, service_printOne);
    }
    return printedWorks;
}

float controller_TotalEarnings(Vector* works, Vector* services, Vector* bycycles, Vector* owners)
{
    float totalEarnings = -1;
    float currentEarnings;
    sWork* work;
    sService* service;
    sBycycle* bycycle;
    sOwner* owner;

    if(works != NULL && services != NULL)
    {
        totalEarnings = 0;
        printf("\n%8s %15s %13s %8s %10s %8s %10s %10s %12s", "Fecha","ID Trabajo","Descripcion","Precio",
                                                    "Marca","Color","Rodado","Nombre","Telefono");
        for(int i=0;i<vector_len(works);i++)
        {
            work = (sWork*)vector_getElement(works, i);
            if(!work_checkEmptySpace(work))
            {
                service = controller_getServiceByWork(work, services);
                if(!service_getPrice(service, &currentEarnings))
                {
                    bycycle = controller_getBycycleByWork(work, bycycles);
                    owner = controller_getOwnerByBycycle(bycycle, owners);
                    if(owner != NULL && bycycle != NULL)
                    {
                        controller_printInform(work, service, bycycle, owner);
                        totalEarnings+=currentEarnings;

                    }
                }
            }
        }
    }
    printf("\n\nLas ganancias totales por servicios prestados asciende a %.2f", totalEarnings);
    return totalEarnings;
}


int controller_sortWorksByBrand(Vector* works, Vector* bycycles)
{
    sWork* firstWork;
    sWork* secondWork;

    int sort = -1;

    if(works != NULL && bycycles != NULL)
    {
        for(int i=0;i<vector_len(works)-1;i++)
        {
            firstWork = (sWork*)vector_getElement(works, i);
            if(!work_checkEmptySpace(firstWork))
            {
                for(int j=i+1;j<vector_len(works);j++)
                {
                    secondWork = (sWork*)vector_getElement(works, j);
                    if(!work_checkEmptySpace(secondWork))
                    {
                        if(controller_compareWorksByBrand(firstWork, secondWork, bycycles) == 1)
                        {
                            Swap_Elements(firstWork, secondWork, sizeof(sWork));
                            sort = 0;

                        }
                    }
                }
            }
        }
    }
    return sort;
}

int controller_compareWorksByBrand(sWork* firstWork, sWork* secondWork, Vector* bycycles)
{
    sBycycle* firstBycycle;
    char firstBrand[26];

    sBycycle* secondBycycle;
    char secondBrand[26];

    int comparison = -2;

    firstBycycle = controller_getBycycleByWork(firstWork, bycycles);
    secondBycycle = controller_getBycycleByWork(secondWork, bycycles);

    if(!bycycle_getBrand(firstBycycle ,firstBrand))
    {
        if(!bycycle_getBrand(secondBycycle, secondBrand))
        {
            comparison = strcmp(firstBrand, secondBrand);
            if(comparison>0)
            {
                comparison = 1;
            }
            else
            {
                if(comparison<0)
                {
                    comparison = -1;
                }
            }
        }
    }
    return comparison;
}

int controller_listWorksByBrand(Vector* works, Vector* bycycles, Vector* services, Vector* owners)
{
    int printedElements = -1;
    sWork* work;
    sBycycle* bycycle;
    sService* service;
    sOwner* owner;
    if(works != NULL && bycycles != NULL)
    {
        printedElements = 0;
        if(!controller_sortWorksByBrand(works, bycycles))
        {
            printf("\n%8s %15s %13s %8s %10s %8s %10s %10s %12s",   "Fecha","ID Trabajo","Descripcion","Precio",
                                                                    "Marca","Color","Rodado","Nombre","Telefono");
            for(int i=0;i<vector_len(works);i++)
            {
                work = (sWork*)vector_getElement(works, i);
                if(!work_checkEmptySpace(work))
                {
                    bycycle = (sBycycle*)controller_getBycycleByWork(work, bycycles);
                    if(!bycycle_checkEmptySpace(bycycle))
                    {
                        service = controller_getServiceByWork(work, services);
                        owner = controller_getOwnerByBycycle(bycycle, owners);
                        if(!controller_printInform(work, service, bycycle, owner))
                        {
                            printedElements++;
                        }
                    }
                }
            }
        }
    }
    return printedElements;
}


sBycycle* controller_getBycycleByWork(sWork* work, Vector* bycycles)
{
    sBycycle* bycycle = NULL;
    int idBycycle;
    if(work!=NULL)
    {
        if(!work_getBycycleId(work, &idBycycle))
        {
            bycycle = (sBycycle*)vector_getElementById(bycycles, &idBycycle, bycycle_getIdBycycle, bycycle_checkEmptySpace);
        }
    }
    return bycycle;
}

int controller_listMostDoneServices(Vector* works, Vector* services, Vector* bycycles, Vector* owners)
{
    int counters[vector_len(services)];
    sService* current;
    int max;
    int listedServices = -1;

    if(works != NULL && services != NULL)
    {
        listedServices = 0;
        if(controller_countServices(works, services, counters))
        {
            if(!Comparison_GetMax(counters, vector_len(services), &max))
            {
                printf("\n%8s %15s %13s %8s %10s %8s %10s %10s %12s", "Fecha","ID Trabajo","Descripcion","Precio",
                                                    "Marca","Color","Rodado","Nombre","Telefono");
                for(int i=0;i<vector_len(services);i++)
                {
                    if(counters[i] == max)
                    {
                        current = (sService*)vector_getElement(services, i);
                        if(current!= NULL)
                        {
                            if(!controller_printWorksByService(current, works, bycycles, owners))
                            {
                                listedServices++;
                            }
                        }
                    }
                }
            }
        }
    }
    return listedServices;
}

int controller_printWorksByService(sService* service, Vector* works, Vector* bycycles, Vector* owners)
{
    int printedElements = -1;
    sWork* work;
    sBycycle* bycycle;
    sOwner* owner;
    int serviceId;
    int tempId;
    if(service!= NULL && works != NULL && bycycles != NULL && owners != NULL)
    {
        if(!service_getId(service, &serviceId))
        {
            printedElements = 0;
            for(int i=0;i<vector_len(works);i++)
            {
                work = (sWork*)vector_getElement(works, i);
                if(!work_getServiceId(work, &tempId))
                {
                    if(tempId == serviceId)
                    {
                        bycycle = controller_getBycycleByWork(work, bycycles);
                        owner = controller_getOwnerByBycycle(bycycle, owners);
                        if(!controller_printInform(work, service, bycycle, owner))
                        {
                            printedElements++;
                        }
                    }
                }
            }
        }
    }
    return printedElements;
}

int controller_countServices(Vector* works, Vector* services, int* counters)
{
    int countedServices = -1;
    sService* currentService;
    sWork* currentWork;
    int serviceId;
    int workId;
    if(works != NULL && services != NULL && counters != NULL)
    {
        countedServices = 0;
        for(int i=0;i<vector_len(services);i++)
        {
            counters[i] = 0;
            currentService = (sService*)vector_getElement(services, i);
            if(currentService != NULL)
            {
                if(!service_checkEmptySpace(currentService))
                {
                    countedServices++;
                    if(!service_getId(currentService, &serviceId))
                    {
                        for(int j=0;j<vector_len(works);j++)
                        {
                            currentWork = (sWork*)vector_getElement(works, j);
                            if(currentWork != NULL)
                            {
                                if(!work_checkEmptySpace(currentWork))
                                {
                                    if(!work_getServiceId(currentWork, &workId))
                                    {
                                        if(workId == serviceId)
                                        {
                                            counters[i]++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return countedServices;
}

int controller_listServicesWithBycycles(Vector* works, Vector* services, Vector* bycycles, Vector* owners)
{
    int listedWorks = -1;
    sWork* work;
    sBycycle* bycycle;
    sService* service;
    sOwner* owner;

    if(works!=NULL && services!=NULL && bycycles!=NULL)
    {
        listedWorks = 0;
        printf("\n%8s %15s %13s %8s %10s %8s %10s %10s %12s", "Fecha","ID Trabajo","Descripcion","Precio",
                                                    "Marca","Color","Rodado","Nombre","Telefono");
        for(int i=0;i<vector_len(works);i++)
        {
            work = (sWork*)vector_getElement(works, i);
            if(!work_checkEmptySpace(work))
            {
                bycycle = controller_getBycycleByWork(work, bycycles);
                service = controller_getServiceByWork(work, services);
                if(bycycle != NULL && service != NULL)
                {
                    owner = controller_getOwnerByBycycle(bycycle, owners);
                    if(!controller_printInform(work, service, bycycle, owner))
                    {
                        listedWorks++;
                    }
                }
            }
        }
    }
    return listedWorks;
}


sService* controller_getServiceByWork(sWork* work, Vector* services)
{
    int tempId;
    sService* service = NULL;
    if(work != NULL && services != NULL)
    {
        if(!work_getServiceId(work, &tempId))
        {
            service = (sService*)vector_getElementById(services, &tempId, service_getId, service_checkEmptySpace);
        }
    }
    return service;
}

int controller_listRedBycycles(Vector* works, Vector* bycycles, Vector* services, Vector* owners)
{
    int countedBycycles = -1;
    sWork* work;
    sBycycle* bycycle;
    sService* service;
    sOwner* owner;
    char colour[26];
    if(works != NULL && bycycles != NULL)
    {
        countedBycycles = 0;
        for(int i=0;i<vector_len(works);i++)
        {
            work = (sWork*)vector_getElement(works, i);
            if(work != NULL)
            {
                if(!work_checkEmptySpace(work))
                {
                    bycycle = controller_getBycycleByWork(work, bycycles);
                    if(bycycle != NULL)
                    {
                        if(!bycycle_getColour(bycycle, colour))
                        {
                            if(Text_toLowerCase(colour))
                            {
                                if(!strcmp(colour, "rojo"))
                                {
                                    service = controller_getServiceByWork(work, services);
                                    owner = controller_getOwnerByBycycle(bycycle, owners);
                                    if(!countedBycycles)
                                    {
                                        printf("\n%8s %15s %13s %8s %10s %8s %10s %10s %12s", "Fecha","ID Trabajo","Descripcion","Precio",
                                                    "Marca","Color","Rodado","Nombre","Telefono");
                                    }
                                    controller_printInform(work, service, bycycle, owner);
                                    countedBycycles++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(countedBycycles>0)
    {
        printf("\nHay un total de %d bicicletas rojas registradas", countedBycycles);
    }
    return countedBycycles;
}

int controller_OwnersThatSpentMost(Vector* works, Vector* services, Vector* bycycles, Vector* owners) // Mostrar
{
    float totals[vector_len(owners)];
    float max;
    int printedElements = -1;
    sOwner* owner;
    sWork* work;
    sBycycle* bycycle;
    sService* service;

    if(works!= NULL && services != NULL && bycycles != NULL && owners != NULL)
    {
        memset(totals, 0, sizeof(totals));
        printedElements = 0;
        if(!controller_countEarningsPerOwner(works, services, bycycles, owners, totals))
        {
            if(!Comparison_GetMaxFloat(totals, vector_len(owners), &max))
            {
                printf("\n%8s %15s %13s %8s %10s %8s %10s %10s %12s", "Fecha","ID Trabajo","Descripcion","Precio",
                                                    "Marca","Color","Rodado","Nombre","Telefono");
                for(int i=0;i<vector_len(owners);i++)
                {
                    if(totals[i] == max)
                    {
                        owner = (sOwner*)vector_getElement(owners,i);
                        for(int j=0;j<vector_len(works);j++)
                        {
                            work=(sWork*)vector_getElement(works, j);
                            if(work!=NULL)
                            {
                                bycycle = controller_getBycycleByWork(work, bycycles);
                                if(!controller_compareBycycleAndOwner(bycycle, owner))
                                {
                                    service = controller_getServiceByWork(work, services);
                                    if(service != NULL)
                                    {
                                        if(!controller_printInform(work, service, bycycle, owner))
                                        {
                                            printedElements++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return printedElements;
}

int controller_compareBycycleAndOwner(sBycycle* bycycle, sOwner* owner)
{
    int idBycycle;
    int idOwner;
    int comparison = -2;

    if(bycycle != NULL && owner != NULL)
    {
        comparison = -1;
        if(!bycycle_getIdBycycle(bycycle, &idBycycle) && !owner_getId(owner, &idOwner))
        {
            if(idBycycle == idOwner)
            {
                comparison = 0;
            }
        }
    }
    return comparison;
}

int controller_countEarningsPerOwner(Vector* works, Vector* services, Vector* bycycles, Vector* owners, float* totals) // Mostrar
{
    sOwner* owner;
    sWork* work;
    sService* service;
    int counts = -1;
    float tempPrice;

    if(works!= NULL && services != NULL && bycycles != NULL && owners != NULL && totals != NULL)
    {
        counts = 0;
        for(int i=0;i<vector_len(owners);i++)
        {
            owner = (sOwner*)vector_getElement(owners, i);
            if(!owner_checkEmptySpace(owner))
            {
                counts++;
                for(int j=0;j<vector_len(works);j++)
                {
                    work = (sWork*)vector_getElement(works, j);
                    if(!controller_compareOwnerByWork(owner, work, bycycles))
                    {
                        service = controller_getServiceByWork(work, services);
                        if(!service_getPrice(service, &tempPrice))
                        {
                            totals[i]+=tempPrice;
                        }
                    }
                }
            }
        }
    }
    return counts;
}


int controller_compareOwnerByWork(sOwner* owner, sWork* work, Vector* bycycles) // Mostrar
{
    sBycycle* bycycle;
    int idBycycle;
    int comparison = -2;
    if(owner!=NULL && work!=NULL)
    {
        comparison = -1;
        if(!work_getBycycleId(work, &idBycycle))
        {
            bycycle = controller_getBycycleByWork(work, bycycles);
            if(!controller_compareBycycleAndOwner(bycycle, owner))
            {
                comparison = 0;
            }
        }
    }
    return comparison;
}

int controller_sortWorksByPhoneNumber(Vector* works, Vector* bycycles, Vector* owners) // Mostrar
{
    sWork* firstWork;
    sWork* secondWork;
    sBycycle* firstBycycle;
    sBycycle* secondBycycle;
    sOwner* firstOwner;
    sOwner* secondOwner;
    int firstId;
    int secondId;
    int firstPhone;
    int secondPhone;
    int sort = -1;

    if(works != NULL && bycycles != NULL && owners != NULL)
    {
        for(int i=0;i<vector_len(works)-1;i++)
        {
            firstWork = (sWork*)vector_getElement(works, i);
            for(int j=i+1;j<vector_len(works);j++)
            {
                secondWork = (sWork*)vector_getElement(works, j);
                if(!work_getBycycleId(firstWork, &firstId) && !work_getBycycleId(secondWork, &secondId))
                {
                    firstBycycle=controller_getBycycleByWork(firstWork, bycycles);
                    secondBycycle=controller_getBycycleByWork(secondWork, bycycles);
                    if(!bycycle_checkEmptySpace(firstBycycle) && !bycycle_checkEmptySpace(secondBycycle))
                    {
                        firstOwner = controller_getOwnerByBycycle(firstBycycle, owners);
                        secondOwner = controller_getOwnerByBycycle(secondBycycle, owners);
                        if(!owner_getPhone(firstOwner, &firstPhone) && !owner_getPhone(secondOwner, &secondPhone))
                        {
                            if(firstPhone>secondPhone)
                            {
                                Swap_Elements(firstWork ,secondWork, sizeof(sWork));
                                sort = 0;
                            }
                        }
                    }
                }

            }
        }
    }
    return sort;
}

int controller_ListWorksByPhoneNumber(Vector* works, Vector* bycycles, Vector* owners, Vector* services) // Mostrar
{
    sWork* work;
    sService* service;
    sOwner* owner;
    sBycycle* bycycle;
    int tempId;
    int printedElements = -1;

    if(works != NULL &&services != NULL &&bycycles != NULL &&owners != NULL)
    {
        printedElements = 0;
        if(!controller_sortWorksByPhoneNumber(works, bycycles, owners))
        {
            printf("\n%8s %15s %13s %8s %10s %8s %10s %10s %12s", "Fecha","ID Trabajo","Descripcion","Precio",
                                                    "Marca","Color","Rodado","Nombre","Telefono");
            for(int i=0;i<vector_len(works);i++)
            {
                work = (sWork*)vector_getElement(works, i);
                if(!work_checkEmptySpace(work))
                {
                    service = controller_getServiceByWork(work, services);
                    bycycle = controller_getBycycleByWork(work, bycycles);
                    if(!bycycle_getIdOwner(bycycle, &tempId))
                    {
                        owner = controller_getOwnerByBycycle(bycycle, owners);
                        if(!controller_printInform(work, service, bycycle, owner))
                        {
                            printedElements++;
                        }
                    }
                }
            }
        }
    }
    return printedElements;
}

sOwner* controller_getOwnerByBycycle(sBycycle* bycycle, Vector* owners)
{
    sOwner* owner = NULL;
    int id;
    if(bycycle != NULL && owners != NULL)
    {
        if(!bycycle_getIdOwner(bycycle, &id))
        {
            owner = (sOwner*)vector_getElementById(owners, &id, owner_getId, owner_checkEmptySpace);
        }
    }
    return owner;
}

int controller_printInform(sWork* work, sService* service, sBycycle* bycycle, sOwner* owner)
{
    int idWork;
    sDate date;

    int idService;
    char description[26];
    float price;

    int idBycycle;
    int wheelSize;
    char brand[26];
    char colour[26];

    int idOwner;
    int phone;
    char name[26];

    int printedInform = -1;

    if(work != NULL && service != NULL && bycycle != NULL && owner != NULL)
    {
        if(!work_getAll(work, &idWork, &date, &idService, &idBycycle))
        {
            if(!service_getAll(service, &idService, description, &price))
            {
                if(!bycycle_getAll(bycycle, &idBycycle, &idOwner, &wheelSize, brand, colour))
                {
                    if(!owner_getAll(owner, &idOwner, name, &phone))
                    {
                        printf("\n");
                        date_print(&date);
                        printf(" %10d %14s %10.2f %10s %8s %8d %14s %12d", idWork, description, price, brand, colour, wheelSize, name, phone);
                        printedInform = 0;
                    }
                }
            }
        }
    }
    return printedInform;
}
