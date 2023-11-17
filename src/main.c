#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "patient_info.h"
#include "ERROR_STATE.h"

Patient *arr[100];
int slots[5] = {0};
int counter = 0;
char reservations[5][20] = {
    "2:00pm to 2:30pm",
    "2:30pm to 3:00pm",
    "3:00pm to 3:30pm",
    "4:00pm to 4:30pm",
    "4:30pm to 5:00pm"};

void admin(void);
void user(void);
void clear_input_buffer();

void main(void)
{
    while (1)
    {
        u8 c;
        u32 input;
        printf("==============================================\n");
        printf("               |MAIN MENU|\n");
        printf("               -----------\n");
        printf("1 -> Enter admin mode\n");
        printf("2 -> Enter user mode\n");
        printf("3 -> Quit\n");
        printf("==============================================\n");

        c = getchar();
        input = c - '0';

        clear_input_buffer();

        if (input == 1)
            admin();
        else if (input == 2)
            user();
        else if (input == 3)
            break;
        else
            printf("Invalid input\n");
    }
}
