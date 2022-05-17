/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** ldi.c
*/

#include <stdlib.h>
#include "machine.h"
#include "asm.h"

void ldi_func(vm_t *vm, process_t *process, ope_t *ope)
{
    int value = 0;
    int tmp = 0;
    int adress = process->pc + ope->real_args[0] % IDX_MOD;

    load_to_ptr(&value, adress, vm, IND_SIZE);
    tmp = ope->real_args[1];
    tmp = tmp + value;
    adress = process->pc + tmp % IDX_MOD;
    load_to_ptr(&value, adress, vm, REG_SIZE);
    invert_endianess(&value, REG_SIZE);
    process->reg[ope->real_args[2]] = value;
}

/*----------------------------------------------------------------
int instruct_code
int cycle_to_complete
int param_nbr[MAX_ARG_NBR]
int param_type[MAX_ARG_NBR]
int args_vanilla[MAX_ARG_NBR]
int args_real[MAX_ARG_NBR]

*/
