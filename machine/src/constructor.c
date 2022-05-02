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

process_t **constructor_process(int nbr_of_team)
{
    process_t **process = malloc(sizeof(process_t *) * nbr_of_team);
    for (int i = 0; i < nbr_of_team; i++) {
        process[i] = malloc(sizeof(process_t));
        process[i]->reg = malloc(sizeof(char) * REG_NUMBER);
        process[i]->pc = 0;
        process[i]->live_number = 0;
        process[i]->carry = 0;
    }
    return process;
}