#include <stdio.h>
#include <libc.h>
#include <limits.h>

static int	_skipper(char *str, int *i, int sign)
{
	while (str[*i] == 32 || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = sign * -1;
		(*i)++;
	}
	return (sign);
}

static int  get_value(char c, int base)
{
    if (c <= '9' && c >= '0')
        return (c - '0');
    if (c <= 'f' && c >= 'a' && base > 9)
        return (c - 'a' + 10);
    if (c <= 'F' && c >= 'A' && base > 9)
        return (c - 'A' + 10);
    return (-1);
}

int get_index(char c)
{
    char    *hex = "0123456789abcdef";
    char    *HEX = "0123456789ABCDEF";
    int i = 0;

    while (hex[i])
    {
        if (hex[i] == c || HEX[i] == c)
            return (i);
        i++;
    }
    return (-1);
}
int	ft_atoi_base(const char *str, int base)
{
	int				i;
    int             c;
	int				sign;
	unsigned long	number;


	i = 0;
	sign = 1;
	sign = _skipper((char *)str, &i, sign);
	number = 0;
	while (get_value(str[i], base) > 0)
	{
        number *= base;
        number += get_index(str[i]);
		if (number > LONG_MAX && sign == 1)
			return (-1);
		if (number > LONG_MAX && sign == -1)
			return (0);
		i++;
	}
	return (number * sign);
}
// // (10 * 16^1) + (10 * 16 ^0)
// int main()
// {
//     printf("%d\n", ft_atoi_base("54AFyuetyu", 16));
// }