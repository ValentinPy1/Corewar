/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** machine.h
*/

#ifndef __MACHINE__
    #define __MACHINE__


typedef struct process_s {
    int live_number;
    char *reg;
    int pc;
    bool carry;
} process_t;

#endif