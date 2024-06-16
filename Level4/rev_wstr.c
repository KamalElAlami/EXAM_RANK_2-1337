#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int main(int ac, char **av)
{
    int i = 0;
    int start;
    int end;

    if (ac == 2)
    {
        while (av[1][i])
            i++;
        while (i >= 0)
        {
            while (av[1][i] == ' ' || av[1][i] == '\t' || av[1][i] == '\0')
                i--;
            end = i;
            while (av[1][i] != ' ' && av[1][i] != '\t' && av[1][i] != '\0')
                i--;
            start = i + 1;
            while (start <= end)
                ft_putchar(av[1][start++]);
            if (i > 0)
                ft_putchar(' ');
        }
    }
    ft_putchar('\n');
}