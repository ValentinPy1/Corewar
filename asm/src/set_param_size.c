/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** set_param_size.c
*/

#include "asm.h"

void set_param_size(char **param, buffer_t *buffer, int i)
{
    switch ((*param)[0]) {
            case 'r':
                ++*param;
                buffer->params[i].size = T_REG;
                break;
            case DIRECT_CHAR:
                ++*param;
                buffer->params[i].size = T_DIR;
                break;
            default:
                buffer->params[i].size = T_IND;
        }
}
