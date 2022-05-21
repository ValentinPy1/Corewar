/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** manage_op.c
*/

#include "machine.h"
#include "asm.h"
#include "adjust_size.h"

char t_size(char type)
{
    switch (type) {
        case 1:
            return 1;
        case 2:
            return DIR_SIZE;
        case 3:
            return IND_SIZE;
        default:
            return 0;
    }
}

int *get_args(char *mem, int *adress, int code, char *size_type)
{
    int args_nbr = op_tab[code - 1].nbr_args;
    int *args = malloc(sizeof(int) * args_nbr);
    int offset = 0;

    for (int arg = 0; arg < args_nbr; ++arg) {
        args[arg] = 0;
        for (int byte = 0; byte < size_type[arg]; ++byte) {
            args[arg] += mem[*adress + offset] *
            pow(16, size_type[arg] - byte);
            ++offset;
        }
    }
    return args;
}

int get_size_from_op(ope_t *op)
{
    int size = 1;

    if (op->code != 1 && op->code != 9 && op->code != 12 && op->code != 15)
        ++size;
    for (int i = 0; i < MAX_ARGS_NUMBER; ++i) {
        size += op->size_type[i];
    }
    return size;
}

void destroy_ope(ope_t *ope)
{
    if (ope)
        free(ope);
}
