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

//give a string of hexadecimal and return a int

int my_getnbr_hexa(char *str)
{
    int i = 0;
    int n = 0;
    int len = my_strlen(str);

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9')
            n = n * 16 + str[i] - '0';
        else if (str[i] >= 'a' && str[i] <= 'f')
            n = n * 16 + str[i] - 'a' + 10;
        else if (str[i] >= 'A' && str[i] <= 'F')
            n = n * 16 + str[i] - 'A' + 10;
        i++;
    }
    return n;
}
