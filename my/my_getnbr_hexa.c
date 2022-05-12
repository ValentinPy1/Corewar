/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** my_getnbr_hexa.c
*/

static int get_char_index_in_str(const char *str, char c)
{
    int i = 0;

    while (str[i] && str[i] != c)
        i++;
    if (str[i] == '\0')
        return -1;
    return i;
}

int my_getnbr_hexa(const char *str)
{
    int i = 0;
    int nbr = 0;
    const char *basis = "0123456789abcdef";

    str += 2;
    while (str[i] != '\0') {
        nbr = nbr * 16 + get_char_index_in_str(basis, str[i]);
        i++;
    }
    return nbr;
}