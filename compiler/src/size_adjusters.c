/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** size_adjusters.c
*/

#include "machine.h"
#include "asm.h"
#include "asm_struct.h"
#include "op.h"

void adjust_zjmp(int *size, int param_id)
{
    if (param_id == 0)
        *size = IND_SIZE;
}

void adjust_ldi(int *size, int param_id)
{
    if (param_id == 0 || param_id == 1)
        *size = IND_SIZE;
}

void adjust_sti(int *size,  int param_id)
{
    printf("in adjust sti\n");
    if (param_id != 1 && param_id != 2)
        return;
    if (*size == T_REG)
        return;
    *size = IND_SIZE;
}

void adjust_fork(int *size, int param_id)
{
    if (param_id == 0)
        *size = IND_SIZE;
}

void adjust_live(int *size, __attribute__((unused)) int param_id)
{
    *size = 4;
}
