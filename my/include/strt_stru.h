/*
** EPITECH PROJECT, 2021
** my
** File description:
** mem_setters_array.h
*/

#ifndef EB9958D0_DF3D_46F4_935B_8C91BB0F7950
    #define EB9958D0_DF3D_46F4_935B_8C91BB0F7950
    #include "s_init.h"

typedef int (*_mem_setter_t)(void *var, char **data, char **template);
static const _mem_setter_t _mem_setters[] = {
    &set_mem_int,
    &set_mem_str,
    NULL
};
static const char *_choice_char = "ds";

#endif
