/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** get_op_index.c
*/

#include "op.h"
#include "asm.h"
#include "my.h"

int get_op_index(char *op)
{
    for (int i = 0; i < OP_NBR; ++i) {
        if (!op_tab[i].mnemonique)
            return -1;
        if (my_strcmp(op, op_tab[i].mnemonique) == 0)
            return i;
    }
    return -1;
}
