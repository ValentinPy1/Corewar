/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** adjust_size.h
*/

#ifndef _ADJUST_H_
    #define _ADJUST_H_
    #include "asm.h"

typedef void (*size_adjuster_t)(int *, int);
static const size_adjuster_t adjust_size[] = {
    &adjust_live,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    &adjust_zjmp,
    &adjust_ldi,
    &adjust_sti,
    &adjust_fork,
    NULL,
    &adjust_ldi,
    &adjust_fork,
    NULL
};

#endif
