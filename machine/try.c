/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** try.c
*/

    #include <unistd.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <sys/stat.h>
    #include <stdio.h>
    #include <stdlib.h>

int main (int ac, char **av)
{
    int i = 0;
    int fd = open("test.cor", O_RDONLY | O_CREAT, 0644);
    char *prog = malloc(sizeof(char) * 4000);
    char *buffer = malloc(sizeof(char) * 4000);
    int count = 0;
    read(fd, buffer, 8);
    printf("buffer : %s\n", buffer);
}