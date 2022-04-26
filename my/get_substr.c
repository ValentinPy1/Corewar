/*
** EPITECH PROJECT, 2021
** my
** File description:
** get_substr.c
*/

#include <stdlib.h>
#include "my.h"

char *get_substr(char **str, char end)
{
    int i = 0;
    char *sub;

    while ((*str)[i] && (*str)[i] != end) {
        i++;
    }
    sub = malloc(sizeof(char) * (i + 1));
    my_strncpy(sub, *(str), i);
    *(str) += i;
    while (**str && **str == end)
        *str += 1;
    sub[i] = '\0';
    return sub;
}

size_t get_char_index_in_str(const char *str, char target)
{
    size_t i = 0;

    while (str[i]) {
        if (str[i] == target) {
            return i;
        }
        ++i;
    }
    return i;
}
