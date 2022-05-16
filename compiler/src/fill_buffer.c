/*
** EPITECH PROJECT, 2022
** fill_buffer
** File description:
** Source code to fill buffer
*/
#include "asm_struct.h"
#include <stdio.h>
#include "my.h"

bool is_param_label(exec_t *ex, buffer_t *buffer, char *param, int i);
int get_param_size_from_type(int type, int param_index, int instruct_code);

static void check_param(char *param, buffer_t *buffer, int i) {
    switch (param[0]) {
        case 'r':
            ++param;
            buffer->params[i].size = T_REG;
            break;
        case DIRECT_CHAR:
            ++param;
            buffer->params[i].size = T_DIR;
            break;
        default:
            buffer->params[i].size = T_IND;
    }
}

void get_param(exec_t *ex, buffer_t *buffer, char **line, int i)
{
    char *param = get_substr(line, ',');
    printf("getting param [%s]\n", param);
    if (!param)
        return;
    while (*param && *param == ' ')
         ++param;
    check_param(param, buffer, i);
    if (is_param_label(ex, buffer, param, i))
        return;
    ex->tmp_head += get_param_size_from_type(buffer->params[i].size, i,
    buffer->instruct_code);
    printf("--------------------------head += %d\n", get_param_size_from_type(buffer->params[i].size, i, buffer->instruct_code));
    buffer->params[i].value = my_getnbr(param);
}

void put_params_in_buffer(exec_t *ex, buffer_t *buffer, char **line)
{
    for (int i = 0; i < buffer->param_nbr; ++i) {
        get_param(ex, buffer, line, i);
    }
}

int get_head_delta_from_func(int instruct_code)
{
    printf("instruct code is %d, [%s]\n", instruct_code, op_tab[instruct_code - 1].mnemonique);
    if ((instruct_code == 1 || instruct_code == 9
    || instruct_code == 12 || instruct_code == 15)) {
        printf("delta is 1\n");
        return 1;
    }
    printf("detla is 2\n");
    return 2;
}

int fill_buffer(exec_t *ex, buffer_t *buffer, char **line, int op_index)
{
    buffer->instruct_code = op_tab[op_index].code;
    ex->tmp_head += get_head_delta_from_func(buffer->instruct_code);
    printf("---------------code is %d---------head(instruct and encoding) += %d\n",buffer->instruct_code, get_head_delta_from_func(buffer->instruct_code));
    buffer->param_nbr = op_tab[op_index].nbr_args;
    put_params_in_buffer(ex, buffer, line);
    return 0;
}