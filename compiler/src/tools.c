/*
** EPITECH PROJECT, 2022
** tools
** File description:
** Source code of tools.c
*/
#include "my.h"
#include "asm_struct.h"
#include <stdio.h>

void remove_ending_char(char *str, char c)
{
    int i = my_strlen(str);

    while (i > 0 && str[i] != c)
        --i;
    if (str[i] == c)
        str[i] = '\0';
}

int get_sum_param_len(buffer_t buffer)
{
    int sum = 0;

    for (int i = 0; i < buffer.param_nbr; ++i) {
        sum += buffer.params[i].size;
    }
    return sum;
}

int get_param_value(param_t param, exec_t *ex)
{
    if (!(param.is_label)) {
        return param.value;
    }
    printf("value is a label\n");
    // printf("param is a label, label index = [%d], adress [%d], id [%s]\n", param.value, ex->labels[param.value].adress, ex->labels[param.value].id);
    return ex->labels[param.value].adress - ex->head_last_instruct;
}