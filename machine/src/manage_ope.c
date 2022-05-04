/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** manage_op.c
*/

#include "machine.h"

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

char *unpack_type(char packed)
{
    char *type = malloc(sizeof(char) * MAX_ARGS_NUMBER);
    type[0] = packed / 64;
    type[1] = packed / 16 % 4;
    type[2] = packed / 4 % 4;
    type[3] = packed % 4;
    return type;
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

ope_t *get_ope(vm_t *vm, int adress)
{
    ope_t *ope = malloc(sizeof(ope_t));
    char args_type;
    char *mem = vm->ram->mem;

    ope->size = 1;
    ope->code = mem[adress];
    if (ope->code != 1 && ope->code != 9 &&
    ope->code != 12 && ope->code != 15) {
        ope->type = unpack_type(mem[++adress]);
        ope->size_type = (char[MAX_ARGS_NUMBER]) {t_size(ope->type[0]),
        t_size(ope->type[1]), t_size(ope->type[2]), t_size(ope->type[3])};
        ope->size += 1 + sum_char(ope->size_type);
    } else {
        // TODO for live zjmp fork lfork a function to assignate specific arg type
        // ope->type = ...
        // ope->size_type = ...
    }
    ++adress;
    ope->args = get_args(mem, &adress, ope->code, ope->size_type);
    ope->nbr_cycles = op_tab[ope->code - 1].nbr_cycles;
    return ope;
}

void destroy_ope(ope_t *ope)
{
    // TODO
}