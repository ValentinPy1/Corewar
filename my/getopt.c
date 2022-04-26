/*
** EPITECH PROJECT, 2021
** my
** File description:
** getopt.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <getopt.h>

static struct option long_options[]= {
    {"opt1", 0, NULL, 0},
    {"opt2", 0, NULL, 1},
    {"opt3", 0, NULL, 2},
};
static const char opt_string[] = "ab:c";

typedef void (*opt_handler_t)(void *param);
static const opt_handler_t opt_handlers[] = {
    NULL,
    NULL,
    NULL
};

void deal_with_options(char c, void *param)
{
    switch(c) {
        case 'a':
            break;
        case 'b':
            break;
        case 'c':
            break;
        default:
            opt_handlers[c](param);
    }
}

void exec_options(int argc, char **argv, void *param)
{
    char c = 0;
    int opt_index = 0;

    while (1) {
        opt_index = 0;
        c = getopt_long(argc, argv, opt_string, long_options, &opt_index);
        if (c == -1)
            break;
        deal_with_options(c, param);
    }
}
