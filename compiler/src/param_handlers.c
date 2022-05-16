/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** param_handlers.c
*/

#include <stdlib.h>
#include "asm.h"
#include "my.h"
#include "op.h"

int count_char_in_str(char *str, char c)
{
    int i = 0;
    int count = 0;

    while (str[i]) {
        if (str[i] == c)
            ++count;
        ++i;
    }
    return count;
}

char *get_label_from_param(char *param)
{
    size_t i = 0;
    int len = my_strlen(param);
    char *label = malloc(sizeof(char) * (len + 1));

    while (param[i] && get_char_index_in_str(LABEL_CHARS, param[i]) != -1) {
        label[i] = param[i];
        ++i;
    }
    label[i] = '\0';
    return label;
}

int get_label_value(exec_t *ex, char *label, int delta_head)
{
    int i = get_label_index(label, ex);

    if (i == -1) {
        register_forward_label(label, ex, delta_head);
        return 0;
    }
    add_label_reference(ex, i, delta_head);
    return ex->labels[i].adress;
}

void handle_param(char *param, char *p_sizes, int *p_values, exec_t *ex)
{
    char *label;

    while (*param && *param == ' ')
         ++param;
    switch (param[0]) {
        case 'r':
            ++param;
            *p_sizes = T_REG;
            break;
        case DIRECT_CHAR:
            ++param;
            *p_sizes = T_DIR;
            break;
        default:
            *p_sizes = T_IND;
            break;
    }
    if (param[0] == LABEL_CHAR) {
        label = get_label_from_param(++param);
        p_values[0] = get_label_value(ex, label, *p_sizes); //p_size -> T_REG OU T_LAB?
    } else
        p_values[0] = my_getnbr(param);
}
