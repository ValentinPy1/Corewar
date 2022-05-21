/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** manage_ope2.c
*/

#include "machine.h"
#include "asm.h"
#include "adjust_size.h"

static void load_op_type_func(ope_t *ope, char encoding, int i)
{
    int type = encoding & (0b00000011);
    ope->type[MAX_ARGS_NUMBER - i - 1] = T_REG *
    (type == 0b01) + T_DIR * (type == 0b10)
    + T_IND * (type == 0b11);
    ope->size_type[MAX_ARGS_NUMBER - i - 1] = 0;
    ope->size_type[MAX_ARGS_NUMBER - i - 1] = T_REG *
    (type == 0b01) + T_DIR * (type == 0b10)
    + T_IND * (type == 0b11);
    if (adjust_size[ope->code - 1]) {
        adjust_size[ope->code - 1]
        (&(ope->size_type[MAX_ARGS_NUMBER - i - 1]), i);
    } else
        ope->size_type[MAX_ARGS_NUMBER - i - 1] = 1 *
        (type == 0b01) + DIR_SIZE * (type == 0b10)
        + IND_SIZE * (type == 0b11);
    encoding >>= 2;
    type = 0;
}

static void load_op_type(ope_t *ope, char encoding)
{
    char type = 0;
    for (int i = 0; i < MAX_ARGS_NUMBER; ++i) {
        // load_op_type_func(ope, encoding, i);
        type = encoding & (0b00000011);
        ope->type[MAX_ARGS_NUMBER - i - 1] = T_REG *
        (type == 0b01) + T_DIR * (type == 0b10)
        + T_IND * (type == 0b11);
        ope->size_type[MAX_ARGS_NUMBER - i - 1] = 0;
        ope->size_type[MAX_ARGS_NUMBER - i - 1] = T_REG *
        (type == 0b01) + T_DIR * (type == 0b10)
        + T_IND * (type == 0b11);
        if (adjust_size[ope->code - 1]) {
            adjust_size[ope->code - 1]
            (&(ope->size_type[MAX_ARGS_NUMBER - i - 1]), i);
        } else
            ope->size_type[MAX_ARGS_NUMBER - i - 1] = 1 *
            (type == 0b01) + DIR_SIZE * (type == 0b10)
            + IND_SIZE * (type == 0b11);
        encoding >>= 2;
        type = 0;
    }
    for (int i = op_tab[ope->code - 1].nbr_args; i < MAX_ARGS_NUMBER; ++i) {
        ope->size_type[i] = 0;
    }
}

ope_t *get_ope(vm_t *vm, int adress, process_t *process)
{
    ope_t *ope = malloc(sizeof(ope_t));
    char tmp = 0;
    int mod_adress = 0;

    if (!ope)
        return NULL;
    mod_adress = (adress++) % MEM_SIZE;
        if (mod_adress < 0)
            mod_adress = MEM_SIZE - mod_adress;
    tmp = vm->ram->mem[(mod_adress) % MEM_SIZE];
    ope->code = tmp;
    if (ope->code <= 0 || ope->code > 16) {
        if (ope)
            free(ope);
        return NULL;
    }
    tmp = 0;
    if (ope->code != 1 && ope->code != 9 && ope->code != 12 && ope->code != 15) {
        mod_adress = (adress++) % MEM_SIZE;
        if (mod_adress < 0)
            mod_adress = MEM_SIZE - mod_adress;
        tmp = vm->ram->mem[(mod_adress) % MEM_SIZE];
    } else {
        tmp = 0b01000000;
    }
    load_op_type(ope, (char) tmp);
    ope->nbr_cycles = op_tab[ope->code - 1].nbr_cycles;
    get_op_real_args(vm, ope, adress, process);
    ope->size = get_size_from_op(ope);
    process->wait = op_tab[ope->code - 1].nbr_cycles;
    return ope;
}