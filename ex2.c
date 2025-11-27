/******************
Name: Ahmad abubker
ID: 213109192
Assignment: 2
*******************/

#include <stdio.h>

int main() {
    int choice = 0;

    /* Variables for Task 1 */
    int unity_number;
    int sumof1;
    int t1_i;

    /* Variables for Task 2 */
    unsigned long long binary_dataset;
    int duck_choice;
    int ducks_num;
    int t2_i;

    /* Variables for Task 3 */
    int professor_number;
    int exponent;
    int your_power;
    int t3_i;

    /* Variables for Task 4 */
    int ducks_number_t4;
    unsigned long long binary_data;
    unsigned long long upper;
    unsigned long long lower;
    int t4_i, t4_g, t4_s;
    int spacing;
    int remainder;

    /* Variables for Task 5 */
    int mystery_number;
    int current_digit;
    int temp;

    /* The Main Infinite Loop - Logic Gate Style */
    while (1) {

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
        scanf("%d", &choice);

        /* Logic Gate: Check Exact Match for Exit */
        if (choice == 6) {
            printf("Good night! See you at the pond tomorrow.\n");
            return 0;
        }

        /* Logic Gate: Check Range */
        if (choice < 1 || choice > 6) {
            printf("Invalid option, please try again\n");
            /* Force loop restart without using continue to avoid logic traps */
        }
        else {
            /* Valid Choice 1-5 enters Switch */
            switch (choice) {
                case 1:
                    sumof1 = 0;
                    printf("please enter a positive number:\n");
                    scanf("%d", &unity_number);

                    /* //////////////////////////////////////////// */
                    /* ///            Validity Check */
                    while (unity_number <= 0) {
                        printf("Invalid number, please try again\n");
                        scanf("%d", &unity_number);
                    }
                    /* //////////////////////////////////////////// */

                    /* /////////Masking Phase in each bit to check the 1s */
                    for (t1_i = 0; t1_i < 32; t1_i++) {
                        if ((unity_number & (1 << t1_i)) != 0) {
                            sumof1++;
                        }
                    }
                    /* ///////////////////////////////////////////////////////// */
                    /* /// */
                    printf("Ducky earns %d corns\n", sumof1);
                    break;

                case 2:
                    binary_dataset = 0;
                    printf("please enter the number of ducks:\n");
                    scanf("%d", &ducks_num);

                    /* ////////////////////////////////////// */
                    /* ////validity check */
                    while (ducks_num <= 0 || ducks_num > 64) {
                        printf("Invalid number, please try again\n");
                        scanf("%d", &ducks_num);
                    }
                    printf("you entered %d ducks\n", ducks_num);
                    /* /////////////////////////////////////////// */
                    /* /// */

                    for (t2_i = 0; t2_i < ducks_num; t2_i++) {
                        printf("duck %d do QUAK? 1 for yes, 0 for no\n", t2_i + 1);
                        scanf("%d", &duck_choice);

                        if (duck_choice == 0 || duck_choice == 1) {
                            binary_dataset |= ((unsigned long long)duck_choice << t2_i);
                        } else {
                            printf("Invalid number, please try again\n");
                            t2_i--;
                        }
                    }

                    for (t2_i = 0; t2_i < ducks_num; t2_i++) {
                        if (((binary_dataset >> t2_i) & 1) == 1) {
                            printf("duck number %d do Quak\n", t2_i + 1);
                        } else {
                            printf("duck number %d do Sh...\n", t2_i + 1);
                        }
                    }
                    break;

                case 3:
                    your_power = 1;
                    printf("please enter the number\n");
                    scanf("%d", &professor_number);
                    /* ////////////////////////////////////// */
                    /* ////validity check */
                    while (professor_number < 0) {
                        printf("Invalid number, please try again\n");
                        scanf("%d", &professor_number);
                    }
                    /* /////////////////////////////////////////// */

                    printf("please enter the exponent\n");
                    scanf("%d", &exponent);
                    while (exponent < 0) {
                        printf("Invalid number, please try again\n");
                        scanf("%d", &exponent);
                    }

                    for (t3_i = 0; t3_i < exponent; t3_i++) {
                        your_power = your_power * professor_number;
                    }
                    printf("your power is: %d\n", your_power);
                    break;

                case 4:
                    /* ////////////////////////////////////////////////////////////////////////////// */
                    /* in this section of the program we need to excute the program in the next order... */
                    /* ////////////////////////////////////////////////////////////////////////////////// */
                    binary_data = 0;
                    spacing = 8;

                    /* ////////validity  checker */
                    /* /// */
                    printf("please enter number of ducks:\n");
                    scanf("%d", &ducks_number_t4);
                    while (ducks_number_t4 <= 0) {
                        printf("Invalid number, please try again\n");
                        scanf("%d", &ducks_number_t4);
                    }

                    /* ///////////// */
                    /* in this program we need to save 2 kinds of informations... */

                    upper = ducks_number_t4 / 10;
                    lower = ducks_number_t4 % 10;

                    binary_data = (upper << 32) | lower;

                    for (t4_i = 0; t4_i < (int)(binary_data >> 32); t4_i++) {
                        for (t4_g = 0; t4_g < 10; t4_g++) {
                            printf("   _");
                            printf("  ");
                            for (t4_s = 0; t4_s < spacing; t4_s++) printf(" ");
                        }
                        printf("\n");
                        for (t4_g = 0; t4_g < 10; t4_g++) {
                            printf("__(o)>");
                            for (t4_s = 0; t4_s < spacing; t4_s++) printf(" ");
                        }
                        printf("\n");
                        for (t4_g = 0; t4_g < 10; t4_g++) {
                            printf("\\___)");
                            printf(" ");
                            for (t4_s = 0; t4_s < spacing; t4_s++) printf(" ");
                        }
                        printf("\n");
                    }

                    remainder = (int)((binary_data << 32) >> 32);

                    for (t4_g = 0; t4_g < remainder; t4_g++) {
                        printf("   _");
                        printf("  ");
                        for (t4_s = 0; t4_s < spacing; t4_s++) printf(" ");
                    }
                    printf("\n");
                    for (t4_g = 0; t4_g < remainder; t4_g++) {
                        printf("__(o)>");
                        for (t4_s = 0; t4_s < spacing; t4_s++) printf(" ");
                    }
                    printf("\n");
                    for (t4_g = 0; t4_g < remainder; t4_g++) {
                        printf("\\___)");
                        printf(" ");
                        for (t4_s = 0; t4_s < spacing; t4_s++) printf(" ");
                    }
                    printf("\n");
                    break;

                case 5:
                    printf("please enter number\n");
                    scanf("%d", &mystery_number);
                    while (mystery_number <= 0) {
                        printf("Invalid number, please try again\n");
                        scanf("%d", &mystery_number);
                    }

                    while (mystery_number > 0) {
                        current_digit = mystery_number % 10;
                        mystery_number = mystery_number / 10;
                        temp = mystery_number;

                        while (temp > 0) {
                            if (temp % 10 == current_digit) {
                                printf("%d appears more than once!\n", current_digit);
                                break;
                            }
                            temp = temp / 10;
                        }
                    }
                    break;
            } /* End Switch */
        } /* End Else */
    } /* End While(1) */

    return 0;
}