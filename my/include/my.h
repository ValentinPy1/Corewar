/*
** EPITECH PROJECT, 2021
** my
** File description:
** my.h
*/

#ifndef E8F4AAB3_FEEC_484E_B2FD_F9DCB1703BD4
    #define E8F4AAB3_FEEC_484E_B2FD_F9DCB1703BD4
    #include <stdlib.h>
    #include <stdbool.h>

int my_strlen(const char *str);
void my_strcpy(char *dest, const char *src);
char *my_strdup(const char *str);
void *my_memcpy(void *dest, const void *src, size_t size, size_t o_size);
void my_realloc(void *elt, size_t size, size_t o_size);
int my_strcmp(const char *str1, const char *str2);
int getnbr_until_non_digit(char **str);
void my_strncpy(char *dest, char *str, int n);
char *get_substr(char **str, char end);
int  get_char_index_in_str(const char *str, char target);
int my_putstr(char const *str);
void my_put_nbr(int nb);
void my_putchar(char c);

#endif
