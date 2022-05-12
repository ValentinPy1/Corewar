// /*
// ** EPITECH PROJECT, 2021
// ** corewar
// ** File description:
// ** write_parameters.c
// */

// #include <unistd.h>
// #include <stdlib.h>
// #include <stdio.h>
// #include <fcntl.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <sys/types.h>
// #include <sys/stat.h>
// #include "asm_struct.h"
// #include "asm.h"
// #include "op.h"
// #include "my.h"

// static void use_label(int *p_values, int i, exec_t *ex)
// {
//     int j = 0;


// }

// static void write_params_size_and_value(int p_nbr, char *p_sizes,
// int *p_values, exec_t *ex)
// {
//     for (int i = 0; i < p_nbr; ++i) {
//         wexec(&(p_sizes[i]), sizeof(char), ex);
//     }
//     for (int i = 0; i < p_nbr; ++i) {
//         use_label(p_values, i, ex);
//         invert_endianess(&(p_values[i]), p_sizes[i]);
//         wexec(&(p_values[i]), p_sizes[i], ex);
//     }
// }

// static int process_curr_param(char **line, char *p_sizes,
// int *p_values, exec_t *ex)
// {
//     char *param = NULL;

//     param = get_substr(line, ',');
//     if (!param)
//         return 1;
//     handle_param(param, p_sizes, p_values, ex);
//     return 0;
// }

// static int write_n_parameters(char **line, int p_nbr, exec_t *ex)
// {
//     char *p_sizes = malloc(sizeof(char) * p_nbr);
//     int *p_values = malloc(sizeof(int) * p_nbr);
//     int progress = 0;

//     if (p_sizes == NULL)
//         return 1;
//     while (**line && progress < p_nbr) {
//         if (process_curr_param(line, p_sizes + progress,
//         p_values + progress, ex))
//             return 1;
//         ++progress;
//     }
//     write_params_size_and_value(p_nbr, p_sizes, p_values, ex);
//     free(p_sizes);
//     free(p_values);
//     return 0;
// }

// int write_parameters(char **line, exec_t *ex, int index)
// {
//     int expected_p_nbr = op_tab[index].nbr_args;
//     int p_nbr = count_char_in_str(*line, SEPARATOR_CHAR) + 1;

//     if (!(*line)) {
//         if (expected_p_nbr == 0)
//             return 0;
//         else
//             return 1;
//     }
//     if (p_nbr != expected_p_nbr)
//         return 1;
//     if (write_n_parameters(line, expected_p_nbr, ex))
//         return 1;
//     return 0;
// }
