/*
** EPITECH PROJECT, 2022
** type_test1
** File description:
** Source code of type tester
*/

#include "asm.h"

int type_test_live(buffer_t *buffer)
{
    int tmp;

    for (int index = 0; index < buffer->param_nbr; index++) {
        tmp = buffer->params[index].size;
        tmp &= ~(op_tab[buffer->instruct_code - 1].type[index]);
        if (tmp)
            exit(84);
    }
    return (0);
}