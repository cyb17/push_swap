#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

int	ft_isdigit(int c)
{
	if (c <= '9' && c >= '0')
		return (2048);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		nb;
	int		sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (str[i] && (str[i] == ' ' || ((str[i] > 8 && str[i] < 14))))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * sign);
}


int ft_strcmp(char *s1, char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (1);
		s1++;
		s2++;
	}
	return (0);
}

int	ft_parsing(char **argv)
{
	int		i;
	int		j;
	long	nbr;

	i = 0;
	j = 0;
	while (argv + i)
	{
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (0);
			j++;
		}
		nbr = ft_atoi(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			return (0);
		i++;
	}
	while (--i)
		if (ft_strcmp(argv[i], argv[i - 1]) == 0)
			return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc < 3)
		return (0);
	if (ft_parsing(argv + 1) == 0)
		write(2, "Error", 5);
	return (0);
}
