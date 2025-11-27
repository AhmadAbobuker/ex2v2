/******************
Name: Ahmad abubker
ID: 213109192
Assignment: 2
*******************/

#include <stdio.h>

int main() {
    int choice = 0;

    while (choice != 6) {
        ////////////////////////////////////////////////////////////
        /////Main menu
        printf("Welcome to our games, please choose an option:\n");
        printf("1. Ducky's Unity Game\n");
        printf("2. The Memory Game\n");
        printf("3. Professor Pat's Power Calculation\n");
        printf("4. The Duck Parade\n");
        printf("5. The Mystery of the Repeated Digits\n");
        printf("6. Good Night Ducks\n");
        ////////////////////////////////////////////////////////////

        /////////////////////////////////////////////////
        ////choice&validity
        if (scanf("%d", &choice) != 1) return 0; // Safety check

        if (choice == 6) {
            printf("Good night! See you at the pond tomorrow.\n");
            return 0;
        }

        if (choice < 1 || choice > 6) {
            printf("Invalid option, please try again\n");
            continue;
        }
        ///////////////////////////////////////////////////

        switch (choice) {
            case 1: {
                int unity_number;
                int sum_of_ones = 0;
                int i;

                printf("please enter a positive number:\n");
                scanf("%d", &unity_number);

                ////////////////////////////////////////////
                ///            Validity Check
                while (unity_number <= 0) {
                    printf("Invalid number, please try again\n");
                    scanf("%d", &unity_number);
                }
                ////////////////////////////////////////////

                /////////Masking Phase in each bit to check the 1s
                for (i = 0; i < 32; i++) {
                    if ((unity_number & (1 << i)) != 0) {
                        sum_of_ones++;
                    }
                }
                /////////////////////////////////////////////////////////
                ///
                printf("Ducky earns %d corns\n", sum_of_ones);
                break;
            }

            case 2: {
                unsigned long long binary_dataset = 0;
                int ducks_amount;
                int duck_status;
                int i;

                printf("please enter the number of ducks:\n");
                scanf("%d", &ducks_amount);

                //////////////////////////////////////
                ////validity check
                while (ducks_amount <= 0 || ducks_amount > 64) {
                    printf("Invalid number, please try again\n");
                    scanf("%d", &ducks_amount);
                }
                printf("you entered %d ducks\n", ducks_amount);
                ///////////////////////////////////////////

                for (i = 0; i < ducks_amount; i++) {
                    printf("duck %d do QUAK? 1 for yes, 0 for no\n", i + 1);
                    scanf("%d", &duck_status);

                    if (duck_status == 1) {
                        binary_dataset |= ((unsigned long long)1 << i);
                    } else if (duck_status == 0) {
                        /* Do nothing */
                    } else {
                        printf("Invalid number, please try again\n");
                        i--;
                    }
                }

                for (i = 0; i < ducks_amount; i++) {
                    if (((binary_dataset >> i) & 1) == 1) {
                        printf("duck number %d do Quak\n", i + 1);
                    } else {
                        printf("duck number %d do Sh...\n", i + 1);
                    }
                }
                break;
            }

            case 3: {
                int professor_number;
                int exponent;
                int power_result = 1;
                int i;

                printf("please enter the number\n");
                scanf("%d", &professor_number);

                //////////////////////////////////////
                ////validity check
                while (professor_number < 0) {
                    printf("Invalid number, please try again\n");
                    scanf("%d", &professor_number);
                }
                ///////////////////////////////////////////

                printf("please enter the exponent\n");
                scanf("%d", &exponent);
                while (exponent < 0) {
                    printf("Invalid number, please try again\n");
                    scanf("%d", &exponent);
                }

                for (i = 0; i < exponent; i++) {
                    power_result *= professor_number;
                }
                printf("your power is: %d\n", power_result);
                break;
            }

            case 4: {
                /* ////////////////////////////////////////////////////////////////////////////// */
                /* in this section of the program we need to excute the program in the next order
                 a loop for drawing... */
                /* ////////////////////////////////////////////////////////////////////////////////// */

                int ducks_in_parade;
                int row_length;
                int i, j;

                ////////validity  checker
                printf("please enter number of ducks:\n");
                scanf("%d", &ducks_in_parade);

                /* BUG FIX: Use < 0 so 0 is accepted as a valid exit condition */
                while (ducks_in_parade < 0) {
                    printf("Invalid number, please try again\n");
                    scanf("%d", &ducks_in_parade);
                }
                /////////////

                /* Logic to handle the drawing loops */
                while (ducks_in_parade > 0) {
                    if (ducks_in_parade >= 10) {
                        row_length = 10;
                    } else {
                        row_length = ducks_in_parade;
                    }

                    for (i = 0; i < row_length; i++) {
                        printf("   _");
                        printf("  ");
                        for(j=0; j<8; j++) printf(" ");
                    }
                    printf("\n");

                    for (i = 0; i < row_length; i++) {
                        printf("__(o)>");
                        for(j=0; j<8; j++) printf(" ");
                    }
                    printf("\n");

                    for (i = 0; i < row_length; i++) {
                        printf("\\___)");
                        printf(" ");
                        for(j=0; j<8; j++) printf(" ");
                    }
                    printf("\n");

                    ducks_in_parade -= 10;
                }
                break;
            }

            case 5: {
                int mystery_number;
                int current_digit;
                int temp_scanner;
                int check_num;

                printf("please enter number\n");
                scanf("%d", &mystery_number);

                /* Validity Check */
                while (mystery_number <= 0) {
                    printf("Invalid number, please try again\n");
                    scanf("%d", &mystery_number);
                }

                while (mystery_number > 0) {
                    current_digit = mystery_number % 10;
                    mystery_number /= 10;

                    check_num = mystery_number;
                    while (check_num > 0) {
                        temp_scanner = check_num % 10;
                        if (temp_scanner == current_digit) {
                            printf("%d appears more than once!\n", current_digit);
                            break;
                        }
                        check_num /= 10;
                    }
                }
                break;
            }
        }
    }
    return 0;
}