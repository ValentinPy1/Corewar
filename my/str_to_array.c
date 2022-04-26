/*
** EPITECH PROJECT, 2021
** my
** File description:
** str_to_array.c
*/

#include "include/my.h"
#include <stdlib.h>
#include <stddef.h>

int count_words(char separator, char *str)
{
    int count = 1;
    int i = 0;

    while (str[i]) {
        if (str[i] == separator)
            ++count;
        ++i;
    }
    if (i == 0)
        count = 0;
    return count;
}

char *dup_between(char *str, int start, int end)
{
    char *dupped = malloc(sizeof(char) * (end + 1 - start));
    int i = 0;
    while (start < end) {
        dupped[i++] = str[start++];
    }
    return dupped;
}

void set_words(char **word_array, char *str, char separator, int elt_nbr)
{
    int i = 0;
    int start = 0;
    int len = my_strlen(str);
    int array_index = 0;

    while (i < len && array_index < elt_nbr) {
        start = i;
        printf("starting new word: i = %d\n", start);
        while (str[i] != separator)
            ++i;
        word_array[array_index++] = dup_between(str, start, i);
        ++i;
    }
    word_array[array_index] = NULL;
}

char **str_to_word_array(char *str, char separator)
{
    int i = 0;
    int elt_nbr = count_words(separator, str);
    char **word_array = malloc(sizeof(char *) * (elt_nbr + 1));

    set_words(word_array, str, separator, elt_nbr);
    return word_array;
}
