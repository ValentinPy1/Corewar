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

ope_t *get_ope(vm_t *vm, int adress, process_t *process)
{
    ope_t *ope = malloc(sizeof(ope_t));
    char args_type;
    char *mem = vm->ram->mem;
    char *size_type = malloc(MAX_ARGS_NUMBER * sizeof(char));

    ope->size = 1;
    ope->code = mem[adress]; // ça c'est null
    get_args_type(ope, &adress, mem);
    for (int i = 0; i < MAX_ARGS_NUMBER; ++i)
        size_type[i] = t_size(ope->type[i]);
    ope->size += sum_char(size_type);
    ++adress;
    ope->args = get_args(mem, &adress, ope->code, size_type);
    free(size_type);
    get_op_real_args(vm, ope, adress, process);
    ope->nbr_cycles = op_tab[ope->code - 1].nbr_cycles;
    return ope;
}

void destroy_ope(ope_t *ope)
{
    free(ope->type);
    free(ope->args);
    free(ope);
}
