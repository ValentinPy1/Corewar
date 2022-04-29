#include "my.h"
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "op.h"
#include <unistd.h>

static const event_t event[1] = {
    &live,
    &ld_func
};

int get_data(void)
{
    int fd = open("oui.cor", O_RDONLY);
    int fd2 = open("42.cor", O_RDONLY);
    int data = 0;
    int *option[3];
    int data_name = 0;
    process_t *curr_process = malloc(sizeof(process_t));
    read(fd, &data, sizeof(char));
    read(fd2, &option[0], sizeof(int));
    event[data].func(option);
}

int main(int ac, char **av)
{
    get_data();
    return 0;
}