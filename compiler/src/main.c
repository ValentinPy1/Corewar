/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** main.c
*/

#include <unistd.h>
#include "asm_help_msg.h"
#include "asm.h"

void display_help(void)
{
    write(1, help_msg, sizeof(help_msg));
}

int main(int argc, char *argv[])
{
    if (argc != 2)
        return 84;
    if (argv[1][0] == '-' && argv[1][1] == 'h') {
        display_help();
        return 0;
    }
    return compile_file(argv[1]);
}
