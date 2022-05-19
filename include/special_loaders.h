/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** special_loaders.h
*/

#ifndef _SPE_LOAD_H_
    #define _SPE_LOAD_H_
    #include "machine.h"

typedef void (*special_loader_t)(vm_t *vm, process_t *process,
ope_t *ope, int adress);
static special_loader_t special_loaders[] = {
    &load_live,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    &load_zjmp,
    &load_ldi,
    &load_sti,
    &load_fork,
    NULL,
    &load_ldi,
    &load_fork,
    NULL
};

#endif
