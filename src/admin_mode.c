#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "patient_info.h"
#include "ERROR_STATE.h"

extern Patient *arr[100];
extern int counter;
extern int slots[5];
extern char reservations[5][20];

void clear_input_buffer(void)
{
    u8 c;
    while (getchar() != '\n')
        ;
}

Error_state check_ID(u32 IDa, u32 *index)
{
    for (u32 i = 0; i < counter; i++)
    {
        if (arr[i]->ID == IDa)
        {
            *index = i;
            return ID_FOUND;
        }
    }
    return ID_NOT_FOUND;
}

Error_state add_patient_rec(void)
{
    u32 ID;
    u32 index;
    arr[counter] = (Patient *)malloc(sizeof(Patient));
    arr[counter]->slot_reservation = 0;
    printf("ID: ");
    scanf("%d", &ID);
    getchar();
    if (check_ID(ID, &index) == ID_FOUND)
        return ID_INVALID;
    else
        arr[counter]->ID = ID;

    printf("Name: ");
    scanf("%s", arr[counter]->name);
    getchar();
    printf("Age: ");
    scanf("%d", &arr[counter]->age);
    getchar();
    printf("Gender: ");
    scanf("%c", &arr[counter]->gender);
    getchar();
    counter++;
    return OK;
}

Error_state edit_patient_rec(void)
{
    u32 ID;
    u32 newID;
    u32 index;
    printf("ID: ");
    scanf("%d", &ID);
    getchar();
    if (check_ID(ID, &index) == ID_NOT_FOUND)
        return ID_INVALID;
    else
    {
        printf("New name: ");
        scanf("%s", arr[index]->name);
        getchar();
        printf("New age: ");
        scanf("%d", &arr[index]->age);
        getchar();
        printf("New gender: ");
        scanf("%c", &arr[index]->gender);
        getchar();
        printf("New ID: ");
        scanf("%d", &newID);
        getchar();
        if (check_ID(newID, &index) == ID_FOUND)
            return ID_INVALID;
        else
        {
            scanf("%d", &arr[index]->ID);
            getchar();
        }
    }
    return OK;
}

Error_state reserve_slot()
{
    u32 ID;
    u32 slot;
    u32 index;
    printf("Press the corresponding number to reserve a slot\n");
    for (u32 i = 0; i < 5; i++)
        if (slots[i] == 0)
            printf("%d -> %s\n", i + 1, reservations[i]);
    printf("Patient ID: ");
    scanf("%d", &ID);
    getchar();
    if (check_ID(ID, &index) == ID_NOT_FOUND)
        return ID_INVALID;
    if (arr[index]->slot_reservation != 0)
        return MORE_THAN_ONE_RES;
    printf("Desired slot: ");
    scanf("%d", &slot);
    getchar();
    if (slot > 5 || slot < 1)
        return SLOT_INVALID;
    else if (slots[slot - 1] == 1)
        return SLOT_INVALID;
    else
    {
        slots[slot - 1] = 1;
        arr[index]->slot_reservation = slot;
    }
    return OK;
}

Error_state cancel_reservation()
{
    u32 ID;
    u32 index;
    printf("Patient ID: ");
    scanf("%d", &ID);
    getchar();
    if (check_ID(ID, &index) == ID_FOUND)
        slots[(arr[index]->slot_reservation) - 1] = 0;
    else
        return ID_INVALID;
    return OK;
}
