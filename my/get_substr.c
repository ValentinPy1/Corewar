/*
** EPITECH PROJECT, 2021
** my
** File description:
** get_substr.c
*/

#include <stdlib.h>
#include "my.h"

char *my_strcat(char *dest, char *src)
{
    int i = 0;
    int j = 0;

    while (dest[i])
        ++i;
    while (src[j])
        dest[i++] = src[j++];
    return dest;
}

char *get_substr(char **str, char end)
{
    int i = 0;
    char *sub;

    while ((*str)[i] && (*str)[i] != end) {
        i++;
    }
    if (!*str && end != '\0')
        return NULL;
    sub = malloc(sizeof(char) * (i + 1));
    my_strncpy(sub, *(str), i);
    *(str) += i;
    while (**str && **str == end)
        *str += 1;
    sub[i] = '\0';
    return sub;
}

int get_char_index_in_str(const char *str, char target)
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
