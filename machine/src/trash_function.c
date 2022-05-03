/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** trash_function.c
*/

// void get_data(char *path)
// {
//     int data = 0;
//     int *option;
//     int fd = open(path, O_RDONLY);

//     read(fd, &data, sizeof(char));
//     data -= 1;
//     printf("data : %d\n", data);
//     // if (data > 16 || data < 1)
//     //     write(1, "Naah invalid index\n", 20);
//     // else {
//         option = get_args(data, fd);
//         MNEMONIC[data].func(option, ram, process);
//     // }
// }

// int *get_args(int index, int fd)
// {
//     int nb_arg = op_tab[index].nbr_args;
//     int *data = malloc(sizeof(int) * (nb_arg + 1));

//     for (int args = 0; args < nb_arg; args++) {
//         read(fd, &op_tab[index].type[args], sizeof(char));
//     }
//     for (int i = 0; i < nb_arg; i++) {
//         read(fd, &data[i], sizeof(&op_tab[index].type[i]));
//     }
//     return data;
// }
