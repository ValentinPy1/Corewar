/*
** EPITECH PROJECT, 2021
** struct_init
** File description:
** s_init.c
*/

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "my.h"
#include "s_init.h"
#include "strt_stru.h"

static int set_mem_from_str(char **template, char **data, void *var)
{
    size_t index = get_char_index_in_str(
    (const char *) _choice_char, (*template)[0]);

    ++*template;
    if (_mem_setters[index](var, data, template) == INT_MIN)
        return 84;
}

static int fill_obj_from_template(char **template, void **vars,
char **data)
{
    size_t len = my_strlen(*data);
    int var_index = 0;
    int out = 0;

    while (**data && **template) {
        if (out)
            return 84;
        if (**template == '%') {
            ++*template;
            out = set_mem_from_str(template, data, vars[var_index++]);
            continue;
        }
        if (**template != **data) {
            return 84;
        }
        ++*template;
        ++*data;
    }
    return 0;
}

int strt_stru(char *template, char *data, int n_members, ...)
{
    va_list va;
    void *vars[n_members];

    va_start(va, n_members);
    for (int i = 0; i < n_members; ++i) {
        vars[i] = va_arg(va, void *);
    }
    va_end(va);
    if (data == NULL || template == NULL)
        return 84;;
    return fill_obj_from_template(&template, vars, &data);
}
