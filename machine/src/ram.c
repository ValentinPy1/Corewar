/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** ram.c
*/

#include "machine.h"

void load_battle_zone(ram_t *ram)
{
    ram->mem = malloc(sizeof(char) * MEM_SIZE);

    for (int i = 0; i < MEM_SIZE; ++i)
        ram->mem[i] = 0;
}

void setup_ram(vm_t *vm)
{
    vm->ram = malloc(sizeof(ram_t));
    load_battle_zone(vm->ram);
}
