/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** constructor.c
*/

#include "op.h"
#include "machine.h"

ram_t *constructor_ram(void)
{
    ram_t *ram = malloc(sizeof(ram_t));
    ram->ram = load_battle_zone();
    return ram;
}

process_t *constructor_process(void)
{
    process_t *process = malloc(sizeof(process_t));
    process->reg = load_reg();
    process->pc = 0;
    process->carry = false;
    process->live_number = 0;
    return process;
}