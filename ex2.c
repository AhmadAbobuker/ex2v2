/******************
Name: Ahmad abubker
ID: 213109192
Assignment: 2
*******************/

#include <stdio.h>

int main() {
    /* ============================================================= */
    /* CPU REGISTERS (Variables declared at very top for C89)       */
    /* ============================================================= */

    /* General Purpose Registers */
    int reg_choice = 0;
    int reg_input = 0;
    int reg_counter = 0;
    int reg_status = 0;
    int reg_temp = 0;

    /* Task Specific Registers */
    int t1_bits = 0;
    int t1_index = 0;

    int t2_count = 0;
    int t2_iter = 0;
    int t2_val = 0;
    unsigned long long t2_mem = 0;

    int t3_base = 0;
    int t3_exp = 0;
    int t3_res = 1;

    int t4_total = 0;
    int t4_row_len = 0;
    int t4_col_idx = 0;
    int t4_space_idx = 0;

    int t5_num = 0;
    int t5_digit = 0;
    int t5_scan = 0;
    int t5_sub_scan = 0;

    /* ============================================================= */
    /* PROGRAM START (LOGIC ENTRY)                                  */
    /* ============================================================= */

MENU_LABEL:
    /* 1. Display Interface */
    printf("Welcome to our games, please choose an option:\n");
    printf("1. Ducky's Unity Game\n");
    printf("2. The Memory Game\n");
    printf("3. Professor Pat's Power Calculation\n");
    printf("4. The Duck Parade\n");
    printf("5. The Mystery of the Repeated Digits\n");
    printf("6. Good Night Ducks\n");

    /* 2. Input Gate */
    /* SAFETY: If scanf returns not 1, input stream died. Jump to EXIT. */
    if (scanf("%d", &reg_choice) != 1) goto EXIT_LABEL;

    /* 3. Logic Routing (Simulating Switch/If Chains) */
    if (reg_choice == 6) goto EXIT_LABEL;
    if (reg_choice == 1) goto TASK_1;
    if (reg_choice == 2) goto TASK_2;
    if (reg_choice == 3) goto TASK_3;
    if (reg_choice == 4) goto TASK_4;
    if (reg_choice == 5) goto TASK_5;

    /* Fallthrough: Invalid Input */
    printf("Invalid option, please try again\n");
    goto MENU_LABEL; /* Jump back to start */

    /* ============================================================= */
    /* TASK 1: DUCKY'S UNITY GAME (BIT LOGIC)                       */
    /* ============================================================= */
TASK_1:
    printf("please enter a positive number:\n");

T1_INPUT_GATE:
    if (scanf("%d", &reg_input) != 1) goto EXIT_LABEL;
    if (reg_input <= 0) {
        printf("Invalid number, please try again\n");
        goto T1_INPUT_GATE;
    }

    /* Bitwise Logic Gate */
    t1_bits = 0;
    t1_index = 0;

T1_LOOP_START:
    if (t1_index >= 32) goto T1_END; /* Loop Condition */

    /* Logic Gate: AND operation */
    if ((reg_input & (1 << t1_index)) != 0) {
        t1_bits++;
    }
    t1_index++;
    goto T1_LOOP_START;

T1_END:
    printf("Ducky earns %d corns\n", t1_bits);
    goto MENU_LABEL;


    /* ============================================================= */
    /* TASK 2: THE MEMORY GAME (REGISTER STORAGE)                   */
    /* ============================================================= */
TASK_2:
    t2_mem = 0;
    printf("please enter the number of ducks:\n");

T2_INPUT_GATE:
    if (scanf("%d", &t2_count) != 1) goto EXIT_LABEL;
    /* Logic: (A <= 0) OR (A > 64) -> Error */
    if (t2_count <= 0) goto T2_ERROR;
    if (t2_count > 64) goto T2_ERROR;
    goto T2_VALID;

T2_ERROR:
    printf("Invalid number, please try again\n");
    goto T2_INPUT_GATE;

T2_VALID:
    printf("you entered %d ducks\n", t2_count);
    t2_iter = 0;

T2_READ_LOOP:
    if (t2_iter >= t2_count) goto T2_PRINT_PHASE;

    printf("duck %d do QUAK? 1 for yes, 0 for no\n", t2_iter + 1);
    if (scanf("%d", &t2_val) != 1) goto EXIT_LABEL;

    if (t2_val == 1) {
        /* Set Bit Logic */
        t2_mem = t2_mem | ((unsigned long long)1 << t2_iter);
        t2_iter++;
        goto T2_READ_LOOP;
    }
    if (t2_val == 0) {
        /* Zero Bit Logic (Do nothing, just advance) */
        t2_iter++;
        goto T2_READ_LOOP;
    }

    /* Fallthrough: Invalid binary input */
    printf("Invalid number, please try again\n");
    goto T2_READ_LOOP; /* Retry same index (t2_iter not incremented) */

T2_PRINT_PHASE:
    t2_iter = 0;

T2_PRINT_LOOP:
    if (t2_iter >= t2_count) goto MENU_LABEL;

    reg_temp = t2_iter + 1; /* 1-based index */

    /* Check Bit Gate */
    if (((t2_mem >> t2_iter) & 1) == 1) {
        printf("duck number %d do Quak\n", reg_temp);
    } else {
        printf("duck number %d do Sh...\n", reg_temp);
    }

    t2_iter++;
    goto T2_PRINT_LOOP;


    /* ============================================================= */
    /* TASK 3: POWER CALCULATION (MULTIPLICATION GATE)              */
    /* ============================================================= */
TASK_3:
    printf("please enter the number\n");

T3_BASE_GATE:
    if (scanf("%d", &t3_base) != 1) goto EXIT_LABEL;
    if (t3_base < 0) {
        printf("Invalid number, please try again\n");
        goto T3_BASE_GATE;
    }

    printf("please enter the exponent\n");

T3_EXP_GATE:
    if (scanf("%d", &t3_exp) != 1) goto EXIT_LABEL;
    if (t3_exp < 0) {
        printf("Invalid number, please try again\n");
        goto T3_EXP_GATE;
    }

    /* Calculation Logic */
    t3_res = 1;
    reg_counter = 0;

T3_CALC_LOOP:
    if (reg_counter >= t3_exp) goto T3_END;
    t3_res = t3_res * t3_base;
    reg_counter++;
    goto T3_CALC_LOOP;

T3_END:
    printf("your power is: %d\n", t3_res);
    goto MENU_LABEL;


    /* ============================================================= */
    /* TASK 4: THE DUCK PARADE (DISPLAY CONTROLLER)                 */
    /* ============================================================= */
TASK_4:
    printf("please enter number of ducks:\n");

T4_INPUT_GATE:
    if (scanf("%d", &t4_total) != 1) goto EXIT_LABEL;

    /* FIX: Allow 0 to be valid. Only reject negatives. */
    if (t4_total < 0) {
        printf("Invalid number, please try again\n");
        goto T4_INPUT_GATE;
    }

T4_ROW_START:
    if (t4_total <= 0) goto MENU_LABEL; /* Exit if 0 or finished */

    /* Logic: If remaining > 10, draw 10. Else draw remaining. */
    if (t4_total >= 10) {
        t4_row_len = 10;
    } else {
        t4_row_len = t4_total;
    }

    /* --- LINE 1 GENERATOR --- */
    t4_col_idx = 0;
T4_L1_LOOP:
    if (t4_col_idx >= t4_row_len) goto T4_L1_END;
    printf("   _");
    printf("  "); /* 2 spaces */
    /* 8 spaces loop hardcoded */
    t4_space_idx = 0;
T4_S1: if (t4_space_idx >= 8) goto T4_S1_DONE; printf(" "); t4_space_idx++; goto T4_S1;
T4_S1_DONE:
    t4_col_idx++;
    goto T4_L1_LOOP;
T4_L1_END:
    printf("\n");

    /* --- LINE 2 GENERATOR --- */
    t4_col_idx = 0;
T4_L2_LOOP:
    if (t4_col_idx >= t4_row_len) goto T4_L2_END;
    printf("__(o)>");
    /* 8 spaces loop hardcoded */
    t4_space_idx = 0;
T4_S2: if (t4_space_idx >= 8) goto T4_S2_DONE; printf(" "); t4_space_idx++; goto T4_S2;
T4_S2_DONE:
    t4_col_idx++;
    goto T4_L2_LOOP;
T4_L2_END:
    printf("\n");

    /* --- LINE 3 GENERATOR --- */
    t4_col_idx = 0;
T4_L3_LOOP:
    if (t4_col_idx >= t4_row_len) goto T4_L3_END;
    printf("\\___)");
    printf(" "); /* 1 space */
    /* 8 spaces loop hardcoded */
    t4_space_idx = 0;
T4_S3: if (t4_space_idx >= 8) goto T4_S3_DONE; printf(" "); t4_space_idx++; goto T4_S3;
T4_S3_DONE:
    t4_col_idx++;
    goto T4_L3_LOOP;
T4_L3_END:
    printf("\n");

    /* Decrement Counter */
    t4_total = t4_total - 10;
    goto T4_ROW_START;


    /* ============================================================= */
    /* TASK 5: REPEATED DIGITS (REVERSE SCANNER)                    */
    /* ============================================================= */
TASK_5:
    printf("please enter number\n");

T5_INPUT_GATE:
    if (scanf("%d", &t5_num) != 1) goto EXIT_LABEL;
    if (t5_num <= 0) {
        printf("Invalid number, please try again\n");
        goto T5_INPUT_GATE;
    }

T5_OUTER_LOOP:
    if (t5_num <= 0) goto MENU_LABEL;

    /* Get LSB */
    t5_digit = t5_num % 10;

    /* Shift Right */
    t5_num = t5_num / 10;

    /* Load Sub-Scanner */
    t5_scan = t5_num;

T5_INNER_LOOP:
    if (t5_scan <= 0) goto T5_OUTER_LOOP; /* No duplicates found for this digit */

    t5_sub_scan = t5_scan % 10;

    if (t5_sub_scan == t5_digit) {
        printf("%d appears more than once!\n", t5_digit);
        goto T5_OUTER_LOOP; /* Found it, move to next digit */
    }

    t5_scan = t5_scan / 10;
    goto T5_INNER_LOOP;


    /* ============================================================= */
    /* EXIT GATE                                                    */
    /* ============================================================= */
EXIT_LABEL:
    printf("Good night! See you at the pond tomorrow.\n");
    return 0;
}