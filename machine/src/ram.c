/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** ram.c
*/

#include "machine.h"

char *load_battle_zone(void)
{
    char *battle_zone = malloc(sizeof(char) * MEM_SIZE);

    for (int i = 0; i < MEM_SIZE; ++i)
        battle_zone[i] = 0;
    return battle_zone;
}

ram_t *setup_ram(void)
{
    ram_t *ram = malloc(sizeof(ram_t));
    ram->mem = load_battle_zone();
    return ram;
}
