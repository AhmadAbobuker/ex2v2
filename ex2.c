/******************
Name: Ahmad abubker
ID: 213109192
Assignment: 2
*******************/

#include <stdio.h>

int main() {
    /* Main State Flags */
    int game_active = 1;
    int menu_choice = 0;

    /* Task 1 Variables */
    int t1_num = 0;
    int t1_sum = 0;
    int t1_i = 0;

    /* Task 2 Variables */
    int t2_count = 0;
    int t2_curr_duck = 0;
    int t2_type = 0;
    int t2_i = 0;
    unsigned long long t2_mask = 0;

    /* Task 3 Variables */
    int t3_base = 0;
    int t3_exp = 0;
    int t3_res = 0;
    int t3_i = 0;

    /* Task 4 Variables */
    int t4_total = 0;
    unsigned long long t4_pack = 0;
    int t4_rows = 0;
    int t4_rem = 0;
    int t4_i = 0;
    int t4_j = 0;
    int t4_s = 0;
    /* spacing constant defined as variable for C89 */
    int t4_space = 8;

    /* Task 5 Variables */
    int t5_num = 0;
    int t5_check = 0;
    int t5_digit = 0;
    int t5_temp = 0;

    /* Main Logic Loop */
    while (game_active == 1) {

        /* Reset Menu Choice */
        menu_choice = 0;

        /* ////////////////////////////////////////////////////////// */
        /* /////Main menu */
        printf("Welcome to our games, please choose an option:\n");
        printf("1. Ducky's Unity Game\n");
        printf("2. The Memory Game\n");
        printf("3. Professor Pat's Power Calculation\n");
        printf("4. The Duck Parade\n");
        printf("5. The Mystery of the Repeated Digits\n");
        printf("6. Good Night Ducks\n");
        /* ////////////////////////////////////////////////////////// */

        /* ///////////////////////////////////////////////// */
        /* ////choice&validity */
        scanf("%d", &menu_choice);
        /* /////////////////////////////////////////////////// */

        /* Logic Gate 1: Check Exit */
        if (menu_choice == 6) {
            printf("Good night! See you at the pond tomorrow.\n");
            game_active = 0;
        }
        /* Logic Gate 2: Check Invalid Range */
        else if (menu_choice < 1 || menu_choice > 6) {
            printf("Invalid option, please try again\n");
        }
        /* Logic Gate 3: Valid Selection */
        else {
            switch (menu_choice) {
                case 1:
                    /* Reset Variables */
                    t1_num = 0;
                    t1_sum = 0;
                    t1_i = 0;

                    printf("please enter a positive number:\n");
                    scanf("%d", &t1_num);

                    /* //////////////////////////////////////////// */
                    /* ///            Validity Check */
                    while (t1_num <= 0) {
                        printf("Invalid number, please try again\n");
                        scanf("%d", &t1_num);
                    }
                    /* //////////////////////////////////////////// */

                    /* /////////Masking Phase in each bit to check the 1s */
                    for (t1_i = 0; t1_i < 32; t1_i++) {
                        if ((t1_num & (1 << t1_i)) != 0) {
                            t1_sum++;
                        }
                    }
                    /* ///////////////////////////////////////////////////////// */
                    /* /// */
                    printf("Ducky earns %d corns\n", t1_sum);
                    break;

                case 2:
                    /* Reset Variables */
                    t2_count = 0;
                    t2_curr_duck = 0;
                    t2_type = 0;
                    t2_i = 0;
                    t2_mask = 0;

                    printf("please enter the number of ducks:\n");
                    scanf("%d", &t2_count);

                    /* ////////////////////////////////////// */
                    /* ////validity check */
                    /* Guard against 0, negative, and 64-bit overflow */
                    while (t2_count <= 0 || t2_count > 64) {
                        printf("Invalid number, please try again\n");
                        scanf("%d", &t2_count);
                    }
                    printf("you entered %d ducks\n", t2_count);
                    /* /////////////////////////////////////////// */
                    /* /// */

                    for (t2_i = 0; t2_i < t2_count; t2_i++) {
                        t2_curr_duck = t2_i + 1;
                        printf("duck %d do QUAK? 1 for yes, 0 for no\n", t2_curr_duck);
                        scanf("%d", &t2_type);

                        if (t2_type == 0 || t2_type == 1) {
                            /* Bit packing logic */
                            t2_mask = t2_mask | ((unsigned long long)t2_type << t2_i);
                        } else {
                            printf("Invalid number, please try again\n");
                            t2_i--; /* Logic Gate: Retry this index */
                        }
                    }

                    for (t2_i = 0; t2_i < t2_count; t2_i++) {
                        t2_curr_duck = t2_i + 1;
                        if (((t2_mask >> t2_i) & 1) == 1) {
                            printf("duck number %d do Quak\n", t2_curr_duck);
                        } else {
                            printf("duck number %d do Sh...\n", t2_curr_duck);
                        }
                    }
                    break;

                case 3:
                    /* Reset Variables */
                    t3_base = 0;
                    t3_exp = 0;
                    t3_res = 1;
                    t3_i = 0;

                    printf("please enter the number\n");
                    scanf("%d", &t3_base);
                    /* ////////////////////////////////////// */
                    /* ////validity check */
                    while (t3_base < 0) {
                        printf("Invalid number, please try again\n");
                        scanf("%d", &t3_base);
                    }
                    /* /////////////////////////////////////////// */

                    printf("please enter the exponent\n");
                    scanf("%d", &t3_exp);
                    while (t3_exp < 0) {
                        printf("Invalid number, please try again\n");
                        scanf("%d", &t3_exp);
                    }

                    for (t3_i = 0; t3_i < t3_exp; t3_i++) {
                        t3_res = t3_res * t3_base;
                    }
                    printf("your power is: %d\n", t3_res);
                    break;

                case 4:
                    /* ////////////////////////////////////////////////////////////////////////////// */
                    /* in this section of the program we need to excute the program in the next order */
                    /* ////////////////////////////////////////////////////////////////////////////////// */
                    /* Reset Variables */
                    t4_total = 0;
                    t4_pack = 0;
                    t4_rows = 0;
                    t4_rem = 0;
                    t4_i = 0;
                    t4_j = 0;
                    t4_s = 0;

                    /* ////////validity  checker */
                    /* /// */
                    printf("please enter number of ducks:\n");
                    scanf("%d", &t4_total);
                    while (t4_total <= 0) {
                        printf("Invalid number, please try again\n");
                        scanf("%d", &t4_total);
                    }
                    /* ///////////// */

                    /* in this program we need to save 2 kinds of informations */

                    /* Manual Bit Packing */
                    t4_rows = t4_total / 10;
                    t4_rem = t4_total % 10;
                    t4_pack = ((unsigned long long)t4_rows << 32) | t4_rem;

                    /* Loop for Full Rows */
                    for (t4_i = 0; t4_i < (int)(t4_pack >> 32); t4_i++) {
                        /* Line 1 */
                        for (t4_j = 0; t4_j < 10; t4_j++) {
                            printf("   _");
                            printf("  ");
                            for (t4_s = 0; t4_s < t4_space; t4_s++) printf(" ");
                        }
                        printf("\n");
                        /* Line 2 */
                        for (t4_j = 0; t4_j < 10; t4_j++) {
                            printf("__(o)>");
                            for (t4_s = 0; t4_s < t4_space; t4_s++) printf(" ");
                        }
                        printf("\n");
                        /* Line 3 */
                        for (t4_j = 0; t4_j < 10; t4_j++) {
                            printf("\\___)");
                            printf(" ");
                            for (t4_s = 0; t4_s < t4_space; t4_s++) printf(" ");
                        }
                        printf("\n");
                    }

                    /* Loop for Remainder */
                    t4_rem = (int)((t4_pack << 32) >> 32);

                    /* Line 1 */
                    for (t4_j = 0; t4_j < t4_rem; t4_j++) {
                        printf("   _");
                        printf("  ");
                        for (t4_s = 0; t4_s < t4_space; t4_s++) printf(" ");
                    }
                    printf("\n");
                    /* Line 2 */
                    for (t4_j = 0; t4_j < t4_rem; t4_j++) {
                        printf("__(o)>");
                        for (t4_s = 0; t4_s < t4_space; t4_s++) printf(" ");
                    }
                    printf("\n");
                    /* Line 3 */
                    for (t4_j = 0; t4_j < t4_rem; t4_j++) {
                        printf("\\___)");
                        printf(" ");
                        for (t4_s = 0; t4_s < t4_space; t4_s++) printf(" ");
                    }
                    printf("\n");
                    break;

                case 5:
                    /* Reset Variables */
                    t5_num = 0;
                    t5_check = 0;
                    t5_digit = 0;
                    t5_temp = 0;

                    printf("please enter number\n");
                    scanf("%d", &t5_num);
                    while (t5_num <= 0) {
                        printf("Invalid number, please try again\n");
                        scanf("%d", &t5_num);
                    }

                    while (t5_num > 0) {
                        t5_digit = t5_num % 10;
                        t5_num = t5_num / 10;

                        t5_check = t5_num;
                        while (t5_check > 0) {
                            if (t5_check % 10 == t5_digit) {
                                printf("%d appears more than once!\n", t5_digit);
                                break;
                            }
                            t5_check = t5_check / 10;
                        }
                    }
                    break;
            }
        }
    }
    return 0;
}