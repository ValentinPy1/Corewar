/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** get_option.c
*/

#include "machine.h"
#include "my.h"

static int is_cor(char *str)
{
    int x = 0;
    for (; str[x] != 0; x++)
        if (str[x] == '.' && str[x + 1] == 'c'
        && str[x + 2] == 'o' && str[x + 3] == 'r')
            return 1;
    return 0;
}

static int get_farest_a(vm_t *vm, char *path)
{
    int x = 0;
    int i = 0;
    int count = 0;
    static int previous = 0;
    int fd = open(path, O_RDONLY);
    char *tmp = malloc(sizeof(char) * MEM_SIZE);
    while (read(fd, tmp, 1)) count++;
    if (previous == 0) {
        previous = 1;
        return 0;
    }
    for (i = MEM_SIZE - 1; vm->ram->mem[i % MEM_SIZE] != 0; i--);
        return count;
    return(MEM_SIZE - count - i);
}

void lauch_prog(vm_t *vm, char *path, int *a_n, int n_save)
{
    if (a_n[1] == 0) {
        a_n[1] = n_save;
    }
    if (a_n[0] == 0) {
        a_n[0] = get_farest_a(vm, path);
    }
    load_prog(vm, path, a_n[0], a_n[1]);
}

void my_get_option(vm_t *vm, int ac, char **av)
{
    int i = 1;
    int *a_n = malloc(sizeof(int) * 2);
    static int n_save = 1;
    a_n[0] = 0;
    a_n[1] = 0;
    for (; i < ac; i++) {
        if (av[i][0] == '-' && av[i][1] == 'n')
            a_n[1] = my_getnbr(av[i + 1]);
        if (av[i][0] == '-' && av[i][1] == 'a')
            a_n[0] = my_getnbr_hexa(av[i + 1]);
        if (is_cor(av[i])) {
            lauch_prog(vm, av[i], a_n, n_save);
            n_save++;
            a_n[0] = 0;
            a_n[1] = 0;
        }
    }
}

int get_nbr_of_champ(char **av)
{
    int nbr = 0;
    for (int y = 0; av[y] != NULL; y++) {
        for (int x = 0; av[y][x] != 0; x++) {
            nbr = ((av[y][x] == '.' && av[y][x + 1] == 'c'
            && av[y][x + 2] == 'o' && av[y][x + 3] == 'r')) ?
                nbr + 1 : nbr;
        }
    }
    return nbr;
}
