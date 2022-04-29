/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** create_cpu.c
*/

#include "my.h"
#include "op.h"

char *load_battle_zone(void)
{
    char *battle_zone = malloc(sizeof(char) * MEM_SIZE);
    int i = 0;

    while (i < MEM_SIZE) {
        battle_zone[i] = 0;
        i++;
    }
    return battle_zone;
}

char **load_reg(void)
{
    char **reg = malloc(sizeof(char *) * REG_NUMBER);
    for(int i = 0; i < REG_NUMBER; i++) {
        reg[i] = malloc(sizeof(char) * REG_SIZE);
    }
    return reg;
}

