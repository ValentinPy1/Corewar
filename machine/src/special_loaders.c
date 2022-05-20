/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** special_loaders.c
*/

#include "machine.h"
#include "asm.h"

void load_live(vm_t *vm, process_t *process, ope_t *ope, int adress)
{
    adress %= MEM_SIZE;
    if (adress < 0)
        adress = MEM_SIZE - adress;
    ope->real_args[0] = 0;
    for (int i = 0; i < sizeof(int); ++i) {
        ((char *) &(ope->real_args[0]))[i] =
        *((char *) vm->ram->mem + (adress + i) % MEM_SIZE);
    }
    ope->size_type[0] = REG_SIZE;
    for (int i = 1; i < MAX_ARGS_NUMBER; ++i)
        ope->size_type[i] = 0;
}

void load_zjmp(vm_t *vm, process_t *process, ope_t *ope, int adress)
{
    ope->real_args[0] = get_index_value(vm, adress);
    ope->size_type[0] = IND_SIZE;
}

void load_ldi(vm_t *vm, process_t *process, ope_t *ope, int adress)
{
    ope->real_args[0] = get_index_value(vm, adress);
    adress = (adress + IND_SIZE) % MEM_SIZE;
    ope->real_args[1] = get_index_value(vm, adress);
    adress = (adress + IND_SIZE) % MEM_SIZE;
    ope->real_args[2] = 0;
    ope->real_args[2] = *((char *) vm->ram->mem + adress);
    ope->size_type[0] = IND_SIZE;
    ope->size_type[1] = IND_SIZE;
    ope->size_type[2] = 1;
    ope->size_type[3] = 0;
    invert_endianess(&(ope->real_args[2]), sizeof(char));
}

void load_sti(vm_t *vm, process_t *process, ope_t *ope, int adress)
{
    for (int i = 0; i < 3; ++i)
        ope->real_args[i] = 0;
    ((char *) &(ope->real_args[0]))[0]
    = *((char *) vm->ram->mem + (adress++) % MEM_SIZE);
    ope->size_type[0] = sizeof(char);
    ope->size_type[1] = (ope->type[1] == T_REG) ? sizeof(char) : IND_SIZE;
    memcpy_size(&(ope->real_args[1]),
    (vm->ram->mem + adress % MEM_SIZE), ope->size_type[1]);
    invert_endianess(&(ope->real_args[1]), ope->size_type[1]);
    adress = (adress + ope->size_type[1]) % MEM_SIZE;
    ope->size_type[2] = (ope->type[2] == T_REG) ? sizeof(char) : IND_SIZE;
    memcpy_size(&(ope->real_args[2]),
    (vm->ram->mem + adress % MEM_SIZE), ope->size_type[1]);
    invert_endianess(&(ope->real_args[2]), ope->size_type[2]);
    for (int i = 3; i < MAX_ARGS_NUMBER; ++i) {
        ope->size_type[i] = 0;
    }
}

void load_fork(vm_t *vm, process_t *process, ope_t *ope, int adress)
{
    ope->real_args[0] = get_index_value(vm, adress);
    ope->size_type[0] = IND_SIZE;
    for (int i = 1; i < MAX_ARGS_NUMBER; ++i) {
        ope->size_type[i] = 0;
    }
}
