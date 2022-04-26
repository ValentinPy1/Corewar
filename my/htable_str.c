/*
** EPITECH PROJECT, 2021
** my
** File description:
** htable_str.c
*/

#include <stdio.h>
#include "./include/my.h"
#include "./include/hashtable.h"

unsigned hash_str(char *str)
{
    int i = 0;
    unsigned hash = 0;

    while (str[i]) {
        hash += hash * 31 + str[i];
        ++i;
    }
    return hash;
}

htable_t *new_htable_str(size_t size)
{
    htable_t *new = new_htable((unsigned (*)(void *)) &hash_str,
    size, (int (*)(void *, void *)) &my_strcmp);

    return new;
}
