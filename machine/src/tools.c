/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** tools.c
*/

#include "machine.h"

int sum_char(char *size_type)
{
    int total = 0;

    for (int i = 0; i < MAX_ARGS_NUMBER; ++i)
        total += size_type[i];
    return total;
}

// char *unpack_type(char packed)
// {
//     char *type = malloc(sizeof(char) * MAX_ARGS_NUMBER);
//     type[0] = packed / 64;
//     type[1] = packed / 16 % 4;
//     type[2] = packed / 4 % 4;
//     type[3] = packed % 4;
//     return type;
// }

// char *specific_type(char op_code)
// {
//     char *type = malloc(MAX_ARGS_NUMBER * sizeof(char));
//     for (int i = 0; i < MAX_ARGS_NUMBER; ++i)
//         type[i] = 0;
//     type[0] = op_tab[op_code - 1].type[0];
// }

// void get_args_type(ope_t *ope, int *adress, char *mem)
// {
//     if (ope->code == 1 || ope->code == 9 ||
//     ope->code == 12 || ope->code == 15) {
//         ope->type = specific_type(ope->code);
//     } else {
//         *adress += 1;
//         ope->type = unpack_type(mem[*adress]);
//         ope->size += 1;
//     }
// }