#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "patient_info.h"
#include "ERROR_STATE.h"
#include "ADMIN_API.h"

extern Patient *arr[100];
extern int counter;
extern int slots[5];
extern char reservations[5][20];

Error_state view_rec()
{
    if(counter > 0)
    {
        u32 index;
        u32 ID;
        printf("ID: ");
        scanf("%d", &ID);
        getchar();
        if(check_ID(ID, &index) == ID_NOT_FOUND)
            return ID_INVALID;
        else
        {
                printf("Name: ");
                printf("%s\n", arr[index]->name);
                printf("Age: ");
                printf("%d\n", arr[index]->age);
                printf("Gender: ");
                printf("%c\n", arr[index]->gender);
                printf("reservation: ");
                printf("%d\n", arr[index]->slot_reservation);
        }
    }
    else
        return NOT_OK;
    return OK;
}

Error_state view_today_res()
{
    u32 flag = 0;
    for(u32 i = 0; i < counter; i++)
    {
        if(arr[i]->slot_reservation != 0)
        {
            flag = 1;
            printf("Patient ID: %d -> %s\n", arr[i]->ID, reservations[(arr[i]->slot_reservation)-1]);
        }
    }
    if(flag)
        return OK;
    else
        return SLOT_INVALID;
}
