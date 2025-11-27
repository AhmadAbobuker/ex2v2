/******************
Name: Ahmad abubker
ID: 213109192
Assignment: 2
*******************/

#include <stdio.h>

int main() {
    /* ==================================================== */
    /* SYSTEM MEMORY REGISTERS                */
    /* (All variables declared at top for stability)   */
    /* ==================================================== */

    /* System Flags */
    int system_active = 1;
    int user_selection = 0;

    /* Register Bank: Task 1 (Unity Game) */
    int t1_input_reg = 0;
    int t1_counter_reg = 0;
    int t1_loop_idx = 0;

    /* Register Bank: Task 2 (Memory Game) */
    int t2_count_reg = 0;
    int t2_type_reg = 0;
    int t2_loop_idx = 0;
    unsigned long long t2_storage_reg = 0;
    int t2_display_idx = 0;

    /* Register Bank: Task 3 (Power Calc) */
    int t3_base_reg = 0;
    int t3_exp_reg = 0;
    int t3_result_reg = 1;
    int t3_loop_idx = 0;

    /* Register Bank: Task 4 (Duck Parade) */
    int t4_total_ducks = 0;
    unsigned long long t4_packed_data = 0;
    unsigned long long t4_high_bits = 0;
    unsigned long long t4_low_bits = 0;
    int t4_rows_count = 0;
    int t4_rem_count = 0;
    int t4_row_idx = 0;
    int t4_draw_idx = 0;
    int t4_space_idx = 0;
    int t4_tab_width = 8; /* Defined constant for spacing */

    /* Register Bank: Task 5 (Repeated Digits) */
    int t5_main_num = 0;
    int t5_target_digit = 0;
    int t5_scanner_num = 0;

    /* ==================================================== */
    /* MAIN LOGIC GATE                     */
    /* ==================================================== */

    while (system_active == 1) {

        /* GATE: Menu Display */
        printf("Welcome to our games, please choose an option:\n");
        printf("1. Ducky's Unity Game\n");
        printf("2. The Memory Game\n");
        printf("3. Professor Pat's Power Calculation\n");
        printf("4. The Duck Parade\n");
        printf("5. The Mystery of the Repeated Digits\n");
        printf("6. Good Night Ducks\n");

        /* GATE: Input Capture */
        scanf("%d", &user_selection);

        /* GATE: Routing Logic */
        if (user_selection == 6) {
            /* EXIT SIGNAL */
            printf("Good night! See you at the pond tomorrow.\n");
            system_active = 0;
        }
        else if (user_selection < 1 || user_selection > 6) {
            /* ERROR SIGNAL */
            printf("Invalid option, please try again\n");
        }
        else {
            /* PROCESS SIGNAL */
            switch (user_selection) {

                /* ================= CASE 1 ================= */
                case 1:
                    t1_counter_reg = 0; /* Reset Counter */

                    printf("please enter a positive number:\n");
                    scanf("%d", &t1_input_reg);

                    /* VALIDATION LOOP GATE */
                    while (t1_input_reg <= 0) {
                        printf("Invalid number, please try again\n");
                        scanf("%d", &t1_input_reg);
                    }

                    /* BITWISE OPERATION GATE */
                    for (t1_loop_idx = 0; t1_loop_idx < 32; t1_loop_idx++) {
                        if ((t1_input_reg & (1 << t1_loop_idx)) != 0) {
                            t1_counter_reg++;
                        }
                    }

                    printf("Ducky earns %d corns\n", t1_counter_reg);
                    break;

                /* ================= CASE 2 ================= */
                case 2:
                    t2_storage_reg = 0; /* Clear Memory */

                    printf("please enter the number of ducks:\n");
                    scanf("%d", &t2_count_reg);

                    /* VALIDATION LOOP GATE (+Overflow Protection) */
                    while (t2_count_reg <= 0 || t2_count_reg > 64) {
                        printf("Invalid number, please try again\n");
                        scanf("%d", &t2_count_reg);
                    }

                    printf("you entered %d ducks\n", t2_count_reg);

                    /* INPUT STORAGE GATE */
                    for (t2_loop_idx = 0; t2_loop_idx < t2_count_reg; t2_loop_idx++) {
                        printf("duck %d do QUAK? 1 for yes, 0 for no\n", t2_loop_idx + 1);
                        scanf("%d", &t2_type_reg);

                        if (t2_type_reg == 0 || t2_type_reg == 1) {
                            /* Low-Level Bit Packing */
                            t2_storage_reg = t2_storage_reg | ((unsigned long long)t2_type_reg << t2_loop_idx);
                        } else {
                            printf("Invalid number, please try again\n");
                            t2_loop_idx--; /* Logic Rewind */
                        }
                    }

                    /* OUTPUT READ GATE */
                    for (t2_loop_idx = 0; t2_loop_idx < t2_count_reg; t2_loop_idx++) {
                        t2_display_idx = t2_loop_idx + 1;
                        if (((t2_storage_reg >> t2_loop_idx) & 1) == 1) {
                            printf("duck number %d do Quak\n", t2_display_idx);
                        } else {
                            printf("duck number %d do Sh...\n", t2_display_idx);
                        }
                    }
                    break;

                /* ================= CASE 3 ================= */
                case 3:
                    t3_result_reg = 1; /* Reset Multiplier Identity */

                    printf("please enter the number\n");
                    scanf("%d", &t3_base_reg);

                    /* BASE VALIDATION GATE */
                    while (t3_base_reg < 0) {
                        printf("Invalid number, please try again\n");
                        scanf("%d", &t3_base_reg);
                    }

                    printf("please enter the exponent\n");
                    scanf("%d", &t3_exp_reg);

                    /* EXPONENT VALIDATION GATE */
                    while (t3_exp_reg < 0) {
                        printf("Invalid number, please try again\n");
                        scanf("%d", &t3_exp_reg);
                    }

                    /* MULTIPLICATION GATE */
                    for (t3_loop_idx = 0; t3_loop_idx < t3_exp_reg; t3_loop_idx++) {
                        t3_result_reg = t3_result_reg * t3_base_reg;
                    }

                    printf("your power is: %d\n", t3_result_reg);
                    break;

                /* ================= CASE 4 ================= */
                case 4:
                    printf("please enter number of ducks:\n");
                    scanf("%d", &t4_total_ducks);

                    /* VALIDATION GATE */
                    while (t4_total_ducks <= 0) {
                        printf("Invalid number, please try again\n");
                        scanf("%d", &t4_total_ducks);
                    }

                    /* DATA PACKING GATE (Manual Register Management) */
                    t4_high_bits = t4_total_ducks / 10;
                    t4_low_bits = t4_total_ducks % 10;
                    t4_packed_data = (t4_high_bits << 32) | t4_low_bits;

                    /* UNPACKING GATE 1: FULL ROWS */
                    t4_rows_count = (int)(t4_packed_data >> 32);

                    for (t4_row_idx = 0; t4_row_idx < t4_rows_count; t4_row_idx++) {
                        /* Layer 1 */
                        for (t4_draw_idx = 0; t4_draw_idx < 10; t4_draw_idx++) {
                            printf("   _");
                            printf("  ");
                            for (t4_space_idx = 0; t4_space_idx < t4_tab_width; t4_space_idx++) printf(" ");
                        }
                        printf("\n");
                        /* Layer 2 */
                        for (t4_draw_idx = 0; t4_draw_idx < 10; t4_draw_idx++) {
                            printf("__(o)>");
                            for (t4_space_idx = 0; t4_space_idx < t4_tab_width; t4_space_idx++) printf(" ");
                        }
                        printf("\n");
                        /* Layer 3 */
                        for (t4_draw_idx = 0; t4_draw_idx < 10; t4_draw_idx++) {
                            printf("\\___)");
                            printf(" ");
                            for (t4_space_idx = 0; t4_space_idx < t4_tab_width; t4_space_idx++) printf(" ");
                        }
                        printf("\n");
                    }

                    /* UNPACKING GATE 2: REMAINDER */
                    t4_rem_count = (int)((t4_packed_data << 32) >> 32);

                    /* Layer 1 */
                    for (t4_draw_idx = 0; t4_draw_idx < t4_rem_count; t4_draw_idx++) {
                        printf("   _");
                        printf("  ");
                        for (t4_space_idx = 0; t4_space_idx < t4_tab_width; t4_space_idx++) printf(" ");
                    }
                    printf("\n");
                    /* Layer 2 */
                    for (t4_draw_idx = 0; t4_draw_idx < t4_rem_count; t4_draw_idx++) {
                        printf("__(o)>");
                        for (t4_space_idx = 0; t4_space_idx < t4_tab_width; t4_space_idx++) printf(" ");
                    }
                    printf("\n");
                    /* Layer 3 */
                    for (t4_draw_idx = 0; t4_draw_idx < t4_rem_count; t4_draw_idx++) {
                        printf("\\___)");
                        printf(" ");
                        for (t4_space_idx = 0; t4_space_idx < t4_tab_width; t4_space_idx++) printf(" ");
                    }
                    printf("\n");
                    break;

                /* ================= CASE 5 ================= */
                case 5:
                    printf("please enter number\n");
                    scanf("%d", &t5_main_num);

                    /* VALIDATION GATE */
                    while (t5_main_num <= 0) {
                        printf("Invalid number, please try again\n");
                        scanf("%d", &t5_main_num);
                    }

                    /* REVERSE SCANNING LOGIC */
                    while (t5_main_num > 0) {
                        /* Latch current LSB */
                        t5_target_digit = t5_main_num % 10;
                        /* Shift Right */
                        t5_main_num = t5_main_num / 10;

                        /* Load Scanner */
                        t5_scanner_num = t5_main_num;

                        /* Inner Scan Loop */
                        while (t5_scanner_num > 0) {
                            if (t5_scanner_num % 10 == t5_target_digit) {
                                printf("%d appears more than once!\n", t5_target_digit);
                                break; /* Short Circuit */
                            }
                            t5_scanner_num = t5_scanner_num / 10;
                        }
                    }
                    break;
            }
        }
    }
    return 0;
}