/*
** EPITECH PROJECT, 2022
** args_type
** File description:
** Header
*/


#ifndef ARGS_TYPE_H_
    #define ARGS_TYPE_H_
    #include "asm.h"

typedef int (*type_tester_t)(buffer_t *buffer);

static const type_tester_t TESTER_TYPE[] = {
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


#endif /* !ARGS_TYPE_H_ */
