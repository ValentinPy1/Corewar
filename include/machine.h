/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** machine.h
*/

#ifndef __MACHINE__
    #define __MACHINE__

#include "my.h"

typedef struct ram_s {
    char *ram;
    int size;
} ram_t;

typedef struct process_s {
    int live_number;
    char *reg;
    int pc;
    bool carry;
} process_t;

typedef struct event_s {
    void (*func)(int *option, ram_t *ram, process_t *process);
} event_t;

//MACHINE
void live(int *option);
void ld_func(int *option, ram_t *cpu, process_t *process);
ram_t *constructor_ram(void);
process_t **constructor_process(int nbr_of_team);

#endif