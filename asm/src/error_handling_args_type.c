/*
** EPITECH PROJECT, 2022
** error_handling_args_type
** File description:
** Source code to test if the type are goods 
*/
#include "asm_struct.h"
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

int error_handling_args_type(buffer_t *buffer)
{
    return (type_test_live(buffer));
}