/*
** EPITECH PROJECT, 2021
** my
** File description:
** string.c
*/

#include <stdlib.h>
#include <stddef.h>

int my_strlen(char *str)
{
    int i = 0;

    while (str[i++]);
    return i - 1;
}

void my_strcpy(char *dest, char *src)
{
    while (*dest++ = *src++);
}

char *my_strdup(char *str)
{
    char *new = malloc(sizeof(char) * (my_strlen(str) + 1));

    if (str == NULL) {
        free(new);
        return NULL;
    }
    if (new == NULL) {
        return NULL;
    }
    my_strcpy(new, str);
    return new;
}

void *my_memcpy(void *dest, const void *src, size_t size, size_t o_size)
{
    int i = 0;
    char *d_cast = (char *) dest;
    const char *s_cast = (const char *) src;

    if (dest == NULL)
        dest = malloc(size);
    if (dest == NULL)
        return NULL;
    while (i < o_size) {
        *(d_cast + i) = *(s_cast + i);
        ++i;
    }
    return dest;
}

void *my_realloc(void *elt, size_t size, size_t o_size)
{
    void *new = malloc(size);

    new = my_memcpy(new, elt, size, o_size);
    free(elt);
    return new;
}
