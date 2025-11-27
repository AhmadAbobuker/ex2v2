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
        scanf("%d", &choice);

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
                printf("please enter a positive number:\n");
                int unity_number;

                ////////////////////////////////////////////
                ///            Validity Check
                scanf("%d", &unity_number);
                for (;;) {
                    if (unity_number <= 0) {
                        printf("Invalid number, please try again\n");
                        scanf("%d", &unity_number);
                    } else {
                        break;
                    }
                }
                ////////////////////////////////////////////
                /////////Masking Phase in each bit to check the 1s
                int sumof1 = 0;
                for (int i = 0; i < 32; i++) {
                    if ((unity_number & (1 << i)) != 0) {
                        sumof1++;
                    }
                }
                /////////////////////////////////////////////////////////
                ///
                printf("Ducky earns %d corns\n", sumof1);
                break;
            }

            case 2: {
                unsigned long long binary_dataset = 0;
                int duck_choice;
                int ducks_num;
                printf("please enter the number of ducks:\n");
                scanf("%d", &ducks_num);
                //////////////////////////////////////
                ////validity check
                while (ducks_num <= 0 || ducks_num > 64) {
                    printf("Invalid number, please try again\n");
                    scanf("%d", &ducks_num);
                }
                printf("you entered %d ducks\n", ducks_num);
                ///////////////////////////////////////////
                ///
                for (int i = 0; i < ducks_num; i++) {
                    printf("duck %d do QUAK? 1 for yes, 0 for no\n", i + 1);
                    scanf("%d", &duck_choice);

                    if (duck_choice == 0 || duck_choice == 1) {
                        binary_dataset |= ((unsigned long long)duck_choice << i);
                    } else {
                        printf("Invalid number, please try again\n");
                        i--;
                    }
                }

                for (int i = 0; i < ducks_num; i++) {
                    if (((binary_dataset >> i) & 1) == 1) {
                        printf("duck number %d do Quak\n", i + 1);
                    }
                    if (((binary_dataset >> i) & 1) == 0) {
                        printf("duck number %d do Sh...\n", i + 1);
                    }
                }
                break;
            }

            case 3: {
                printf("please enter the number\n");
                int professor_number = 0;
                scanf("%d", &professor_number);
                //////////////////////////////////////
                ////validity check
                while (professor_number < 0) {
                    printf("Invalid number, please try again\n");
                    scanf("%d", &professor_number);
                }
                ///////////////////////////////////////////
                ///
                int exponent = 0;
                printf("please enter the exponent\n");
                scanf("%d", &exponent);
                while (exponent < 0) {
                    printf("Invalid number, please try again\n");
                    scanf("%d", &exponent);
                }
                int your_power = 1;
                for (int i = 0; i < exponent; i++) {
                    your_power = your_power * professor_number;
                }
                printf("your power is: %d\n", your_power);
                break;
            }

            case 4: {
                //////////////////////////////////////////////////////////////////////////////
                /*in this section of the program we need to excute the program in the next order
                 a loop for drawing
                 stages loop each stage corresponds with "number of lines" n
                 n answers to mathmatics ,might be n%10 ?
                 and an if statment if we are on any n above 0 not equal it mean new line is needed
                 special case is the last loop last line  */
                //////////////////////////////////////////////////////////////////////////////////
                int ducks_number;
                ////////validity  checker
                ///
                printf("please enter number of ducks:\n");
                scanf("%d", &ducks_number);
                while (ducks_number <= 0) {
                    printf("Invalid number, please try again\n");
                    scanf("%d", &ducks_number);
                }

                /////////////

                /*in this program we need to save 2 kinds of informations
                  how many times are we looping in 10s
                  and how many variables does the last line has
                  ill approach this storing data in a 64 bit integer
                  the first 32 bits are going to be the number we have for 10s
                  the last 32 bits are how many varibles are in the last line
                  although its not effcient for memory since our first vairable is an int
                  so obviously the memory storing could be done in 8-12 bits each but
                  memory isnt the case of the assignment*/
                unsigned long long binary_data = 0;
                unsigned long long upper = ducks_number / 10; // 32-bit upper
                unsigned long long lower = ducks_number % 10; // 32-bit lower

                binary_data = (upper << 32) | lower;

                for (int i = 0; i < (int)(binary_data >> 32); i++) {
                    int spacing = 8;
                    for (int g = 0; g < 10; g++) {
                        printf("   _");
                        printf("  ");
                        for (int s = 0; s < spacing; s++) printf(" ");
                    }
                    printf("\n");
                    for (int g = 0; g < 10; g++) {
                        printf("__(o)>");
                        for (int s = 0; s < spacing; s++) printf(" ");
                    }
                    printf("\n");
                    for (int g = 0; g < 10; g++) {
                        printf("\\___)");
                        printf(" ");
                        for (int s = 0; s < spacing; s++) printf(" ");
                    }
                    printf("\n");
                }
                int spacing = 8;
                int remainder = (int)(((binary_data << 32)) >> 32);

                for (int g = 0; g < remainder; g++) {
                    printf("   _");
                    printf("  ");
                    for (int s = 0; s < spacing; s++) printf(" ");
                }
                printf("\n");
                for (int g = 0; g < remainder; g++) {
                    printf("__(o)>");
                    for (int s = 0; s < spacing; s++) printf(" ");
                }
                printf("\n");
                for (int g = 0; g < remainder; g++) {
                    printf("\\___)");
                    printf(" ");
                    for (int s = 0; s < spacing; s++) printf(" ");
                }
                printf("\n");
                break;
            }

            case 5: {
                printf("please enter number\n");
                int mystery_number = 0;
                scanf("%d", &mystery_number);
                while (mystery_number <= 0) {
                    printf("Invalid number, please try again\n");
                    scanf("%d", &mystery_number);
                }
                while (mystery_number > 0) {
                    int current_digit = mystery_number % 10;
                    mystery_number = mystery_number / 10;
                    int temp = mystery_number;
                    while (temp > 0) {
                        if (temp % 10 == current_digit) {
                            printf("%d appears more than once!\n", current_digit);
                            break;
                        }
                        temp = temp / 10;
                    }
                }
                break;
            }
        }
    }
    return 0;
}