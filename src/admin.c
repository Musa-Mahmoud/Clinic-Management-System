#include <stdio.h>
#include "STD_TYPES.h"
#include "patient_info.h"
#include "ERROR_STATE.h"
#include "ADMIN_API.h"

extern Patient *arr[100];
extern int counter;
extern int slots[5];

void admin(void)
{
    u8 c;
    u32 input;

    // promting the user
admin_main_menu:
    printf("==============================================\n");
    printf("               |ADMIN MENU|\n");
    printf("               ------------\n");
    printf("1 -> Add a new patient record.\n");
    printf("2 -> Edit patient record.\n");
    printf("3 -> Reserve a slot with the doctor.\n");
    printf("4 -> Cancel reservation.\n");
    printf("5 -> Exit admin mode.\n");
    printf("==============================================\n");
    c = getchar();
    input = c - '0';

    clear_input_buffer();

    switch (input)
    {
        Error_state es;
    case 1:
        es = add_patient_rec();
        if (es == ID_INVALID)
            printf("Invalid ID\n");
        goto admin_main_menu;
        break;
    case 2:
        es = edit_patient_rec();
        if (es == ID_INVALID)
            printf("Invalid ID\n");
        goto admin_main_menu;
        break;
    case 3:
        es = reserve_slot();
        if (es == ID_INVALID)
            printf("Patient not found\n");
        else if (es == MORE_THAN_ONE_RES)
            printf("Patient has already reserved a slot\n");
        else if (es == SLOT_INVALID)
            printf("Invalid slot\n");
        goto admin_main_menu;
        break;
    case 4:
        es = cancel_reservation();
        if (es == ID_INVALID)
            printf("Invalid ID\n");
        goto admin_main_menu;
        break;
    case 5:
        return;
    default:
        printf("Invalid input\n");
        goto admin_main_menu;
    }
}
