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

// ope_t *get_ope(vm_t *vm, int adress, process_t *process)
// {
//     ope_t *ope = malloc(sizeof(ope_t));
//     char args_type;
//     char *mem = vm->ram->mem;
//     ope->size = 1;
//     ope->code = mem[adress % MEM_SIZE]; // ça c'est null
//     if (ope->code != 1 && ope->code != 9 &&
//     ope->code != 12 && ope->code != 15) {
//         ope->type = unpack_type(mem[++adress]);
//         ope->size_type = (char[MAX_ARGS_NUMBER]) {t_size(ope->type[0]),
//         t_size(ope->type[1]), t_size(ope->type[2]), t_size(ope->type[3])};
//         ope->size += 1 + sum_char(ope->size_type);
//         get_op_real_args(vm, ope, adress, process);
//     } else {
//         // TODO for live zjmp fork lfork a function to assignate specific arg type
//         // ope->type = ...
//         // ope->size_type = ...
//     }
//     ++adress;
//     ope->args = get_args(mem, &adress, ope->code, ope->size_type);
//     ope->nbr_cycles = op_tab[ope->code - 1].nbr_cycles;
//     return ope;
// }

static void load_op_type(ope_t *ope, char encoding)
{
    char type = 0;

    for (int i = 0; i < MAX_ARGS_NUMBER; ++i) {
        type = encoding & (0b00000011);
        ope->type[MAX_ARGS_NUMBER - i - 1] = T_REG * (type == 0b01) + T_DIR * (type == 0b10)
        + T_IND * (type == 0b11);
        ope->size_type[MAX_ARGS_NUMBER - i - 1] = 0;
        ope->size_type[MAX_ARGS_NUMBER - i - 1] = T_REG * (type == 0b01) + T_DIR * (type == 0b10)
        + T_IND * (type == 0b11);
        if (adjust_size[ope->code - 1]) {
            adjust_size[ope->code - 1](&(ope->size_type[MAX_ARGS_NUMBER - i - 1]), i);
        } else
            ope->size_type[MAX_ARGS_NUMBER - i - 1] = 1 * (type == 0b01) + DIR_SIZE * (type == 0b10)
            + IND_SIZE * (type == 0b11);
        encoding >>= 2;
        type = 0;
    }
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

ope_t *get_ope(vm_t *vm, int adress, process_t *process)
{
    ope_t *ope = malloc(sizeof(ope_t));
    int tmp = 0;

    if (!ope)
        return NULL;
    load_to_ptr(&tmp, adress++, vm, sizeof(char));
    ope->code = tmp;
    if (ope->code <= 0) {
        free(ope);
        return NULL;
    }
    tmp = 0;
    load_to_ptr(&tmp, adress++, vm, sizeof(char));
    load_op_type(ope, (char) tmp);
    ope->size = get_size_from_op(ope);
    ope->nbr_cycles = op_tab[ope->code - 1].nbr_cycles;
    get_op_real_args(vm, ope, adress, process);
    process->wait = op_tab[ope->code - 1].nbr_cycles;
    char c = 0;
    for (int i = 0; i < op_tab[ope->code - 1].nbr_args; ++i) {
        printf("process: %p :: arg n°%d of [%s]: %d\n", process, i, op_tab[ope->code - 1].mnemonique, ope->real_args[i]);
    }
    read(0, &c, 1);
    return ope;
}

void destroy_ope(ope_t *ope)
{
    // TODO
}
