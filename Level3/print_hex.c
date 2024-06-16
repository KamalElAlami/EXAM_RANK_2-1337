#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int ft_atoi(char *str)
{

    int i = 0;
    int nbr = 0;
    int sign = 1;
    if (str[i] == '-')
    {
        sign = -1;
        ++i;
    }
    while (str[i] && (str[i] >= '0' && str[i] <= '9'))
    {
        nbr = nbr * 10 + str[i] - '0';
        i++;
    }
    return (nbr * sign);
}

void print_hexa(int nbr)
{
    char *hex = "0123456789abcdef";

    if (nbr >= 16)
        print_hexa(nbr / 16);
    ft_putchar(hex[nbr % 16]);
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        print_hexa(ft_atoi(av[1]));
    }
    ft_putchar('\n');
}