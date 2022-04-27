/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** asm.h
*/

#ifndef D65B1F03_6566_4A0A_AC5E_1E78CE3A97B0
    #include <stdlib.h>
    #define D65B1F03_6566_4A0A_AC5E_1E78CE3A97B0
    #define OP_NBR 23

int compile_file(char *filename);
int get_op_index(char *op);
int write_instruct(char **line, int fd);
void invert_endianess(void *var, size_t size);

    #define wexec(var, size, stream) \
    do { \
        invert_endianess(&var, sizeof(var)); \
        write(stream, &var, size); \
    } while (0)

#endif
