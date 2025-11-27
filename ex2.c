/******************
Name: Ahmad abubker
ID: 213109192
Assignment: 2
*******************/

#include <stdio.h>

int main() {
    int choice = 0;

    while (choice != 6) {
        printf("Welcome to our games, please choose an option:\n");
        printf("1. Ducky's Unity Game\n");
        printf("2. The Memory Game\n");
        printf("3. Professor Pat's Power Calculation\n");
        printf("4. The Duck Parade\n");
        printf("5. The Mystery of the Repeated Digits\n");
        printf("6. Good Night Ducks\n");

        scanf("%d", &choice);

        if (choice == 6) {
            printf("Good night! See you at the pond tomorrow.\n");
            return 0;
        }

        if (choice < 1 || choice > 6) {
            printf("Invalid option, please try again\n");
            continue;
        }

        switch (choice) {
            case 1: {
                int unity_number;
                int sumof1 = 0;
                int i;

                printf("please enter a positive number:\n");
                scanf("%d", &unity_number);

                for (;;) {
                    if (unity_number <= 0) {
                        printf("Invalid number, please try again\n");
                        scanf("%d", &unity_number);
                    } else {
                        break;
                    }
                }

                for (i = 0; i < 32; i++) {
                    if ((unity_number & (1 << i)) != 0) {
                        sumof1++;
                    }
                }
                printf("Ducky earns %d corns\n", sumof1);
                break;
            }

            case 2: {
                unsigned long long binary_dataset = 0;
                int duck_choice;
                int ducks_num;
                int i;

                printf("please enter the number of ducks:\n");
                scanf("%d", &ducks_num);

                while (ducks_num <= 0 || ducks_num > 64) {
                    printf("Invalid number, please try again\n");
                    scanf("%d", &ducks_num);
                }
                printf("you entered %d ducks\n", ducks_num);

                for (i = 0; i < ducks_num; i++) {
                    printf("duck %d do QUAK? 1 for yes, 0 for no\n", i + 1);
                    scanf("%d", &duck_choice);

                    if (duck_choice == 0 || duck_choice == 1) {
                        binary_dataset |= ((unsigned long long)duck_choice << i);
                    } else {
                        printf("Invalid number, please try again\n");
                        i--;
                    }
                }

                for (i = 0; i < ducks_num; i++) {
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
                int professor_number = 0;
                int exponent = 0;
                int your_power = 1;
                int i;

                printf("please enter the number\n");
                scanf("%d", &professor_number);

                while (professor_number < 0) {
                    printf("Invalid number, please try again\n");
                    scanf("%d", &professor_number);
                }

                printf("please enter the exponent\n");
                scanf("%d", &exponent);
                while (exponent < 0) {
                    printf("Invalid number, please try again\n");
                    scanf("%d", &exponent);
                }

                for (i = 0; i < exponent; i++) {
                    your_power = your_power * professor_number;
                }
                printf("your power is: %d\n", your_power);
                break;
            }

            case 4: {
                int ducks_number;
                unsigned long long binary_data = 0;
                unsigned long long upper;
                unsigned long long lower;
                int i, g, s;
                int spacing = 8;
                int remainder;

                printf("please enter number of ducks:\n");
                scanf("%d", &ducks_number);
                while (ducks_number <= 0) {
                    printf("Invalid number, please try again\n");
                    scanf("%d", &ducks_number);
                }

                upper = ducks_number / 10;
                lower = ducks_number % 10;
                binary_data = (upper << 32) | lower;

                for (i = 0; i < (int)(binary_data >> 32); i++) {
                    for (g = 0; g < 10; g++) {
                        printf("   _");
                        printf("  ");
                        for (s = 0; s < spacing; s++) printf(" ");
                    }
                    printf("\n");
                    for (g = 0; g < 10; g++) {
                        printf("__(o)>");
                        for (s = 0; s < spacing; s++) printf(" ");
                    }
                    printf("\n");
                    for (g = 0; g < 10; g++) {
                        printf("\\___)");
                        printf(" ");
                        for (s = 0; s < spacing; s++) printf(" ");
                    }
                    printf("\n");
                }

                remainder = (int)(((binary_data << 32)) >> 32);

                for (g = 0; g < remainder; g++) {
                    printf("   _");
                    printf("  ");
                    for (s = 0; s < spacing; s++) printf(" ");
                }
                printf("\n");
                for (g = 0; g < remainder; g++) {
                    printf("__(o)>");
                    for (s = 0; s < spacing; s++) printf(" ");
                }
                printf("\n");
                for (g = 0; g < remainder; g++) {
                    printf("\\___)");
                    printf(" ");
                    for (s = 0; s < spacing; s++) printf(" ");
                }
                printf("\n");
                break;
            }

            case 5: {
                int mystery_number = 0;
                printf("please enter number\n");
                scanf("%d", &mystery_number);
                while (mystery_number <= 0) {
                    printf("Invalid number, please try again\n");
                    scanf("%d", &mystery_number);
                }
                while (mystery_number > 0) {
                    int current_digit = mystery_number % 10;
                    int temp;
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
            }
        }
    }
    return 0;
}