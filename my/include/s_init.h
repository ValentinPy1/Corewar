/*
** EPITECH PROJECT, 2021
** struct_init
** File description:
** s_init.h
*/

#ifndef B0443DDB_F5D2_45BC_A918_B2282A4AA42D
    #define B0443DDB_F5D2_45BC_A918_B2282A4AA42D
    #define offsetof(type, member) ((size_t) (&(((type *)NULL)->member)))
    #include <stdlib.h>
    #include <stdarg.h>

char *get_substr(char **str, char end);
int get_char_index_in_str(const char *str, char target);
static int set_mem_from_str(char **template, char **data, void *var);
static int fill_obj_from_template(char **template, void **vars,
char **data);
int strt_stru(char *template, char *data, int n_members, ...);
int set_mem_int(void *var, char **data,
__attribute__((unused)) char **template);
int set_mem_str(void *var, char **data, char **template);

#endif
