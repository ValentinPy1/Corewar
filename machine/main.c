#include "my.h"
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "op.h"
#include <unistd.h>

char * load_battle_zone(void)
{
    char *battle_zone = malloc(sizeof(char) * MEM_SIZE);
    int i = 0;

    while (i < MEM_SIZE) {
        battle_zone[i] = 0;
        i++;
    }
    return battle_zone;
}

void live(int *option)
{
    my_putstr("The player ");
    my_put_nbr((int)option[0]);
    my_putstr(" is alive..\n");
}

void ld_func(int *option)
{

}

static const event_t event[1] = {
    &live,
    &ld_func
};

int get_data(void)
{
    char *battle_zone = load_battle_zone();
    int fd = open("oui.cor", O_RDONLY);
    int fd2 = open("42.cor", O_RDONLY);
    int data = 0;
    int *option[3];
    int data_name = 0;
    read(fd, &data, sizeof(char));
    read(fd2, &option[0], sizeof(int));
    event[data].func(option);
    process_t *curr_process = malloc(sizeof(process_t));
}

int main(int ac, char **av)
{
    get_data();
    return 0;
}