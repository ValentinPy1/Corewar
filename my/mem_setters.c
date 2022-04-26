/*
** EPITECH PROJECT, 2021
** struct_init
** File description:
** mem_setters.c
*/

#include "s_init.h"
#include "limits.h"
#include "my.h"

int set_mem_int(void *var, char **data,
__attribute__((unused)) char **template)
{
    int value = getnbr_until_non_digit(data);

    if (value == INT_MIN)
        return INT_MIN;
    *((int *) var) = value;
    return 0;
}

int set_mem_str(void *var, char **data, char **template)
{
    char end = **template;
    char **tmp = (char **) var;

    *tmp = get_substr(data, end);
    if (**data == '\0' && **data != '\0')
        return INT_MIN;
    ++*template;
    return 0;
}
