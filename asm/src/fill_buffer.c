/*
** EPITECH PROJECT, 2022
** fill_buffer
** File description:
** Source code to fill buffer
*/
#include <stdio.h>
#include <stdbool.h>
#include "asm_struct.h"
#include "asm.h"
#include "my.h"

static bool is_number(char *str)
{
    bool space = 0;
    int i = 0;

    for (; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\t') {
            space = true;
            break;
        }
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    if (!space)
        return true;
    for (; str[i]; ++i) {
        if (str[i] != ' ' && str[i] != '\t') {
            return false;
        }
    }
    return true;
}

void get_param(exec_t *ex, buffer_t *buffer, char **line, int i)
{
    char *param = get_substr(line, ',');
    if (!param)
        return;
    while (*param && *param == ' ')
        ++param;
    set_param_size(&param, buffer, i);
    if (is_param_label(ex, buffer, param, i))
        return;
    if (!is_number(param))
        exit(84);
    ex->tmp_head += get_param_size_from_type(buffer->params[i].size, i,
    buffer->instruct_code);
    buffer->params[i].value = my_getnbr(param);
}

void put_params_in_buffer(exec_t *ex, buffer_t *buffer, char **line)
{
    for (int i = 0; i < buffer->param_nbr; ++i) {
        if (**line == '\0')
            return;
        get_param(ex, buffer, line, i);
        ++(buffer->found_n_param);
    }
}

int get_head_delta_from_func(int instruct_code)
{
    if ((instruct_code == 1 || instruct_code == 9
    || instruct_code == 12 || instruct_code == 15)) {
        return 1;
    }
    return 2;
}

int fill_buffer(exec_t *ex, buffer_t *buffer, char **line, int op_index)
{
    buffer->instruct_code = op_tab[op_index].code;
    ex->tmp_head += get_head_delta_from_func(buffer->instruct_code);
    buffer->param_nbr = op_tab[op_index].nbr_args;
    buffer->found_n_param = 0;
    put_params_in_buffer(ex, buffer, line);
    if (buffer->found_n_param != buffer->param_nbr)
        exit(84);
    while (**line) {
        if (**line != '\t' && **line != ' ')
            exit(84);
        ++(*line);
    }
    error_handling_args_type(buffer);
    return 0;
}
