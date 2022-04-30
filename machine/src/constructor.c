/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** constructor.c
*/

#include "my.h"
#include "op.h"

cpu_t *constructor(void)
{
    cpu_t *cpu = malloc(sizeof(cpu_t));
    cpu->ram = load_battle_zone();
    cpu->reg = load_reg();
    cpu->carry = 1;
    return cpu;
}