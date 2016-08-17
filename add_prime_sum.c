/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 21:14:44 by guiricha          #+#    #+#             */
/*   Updated: 2016/01/18 21:56:05 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}

int		ft_atoi(const char *str)
{
	long result;
	int sign;

	result = 0;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return ((int)(result * sign));
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n = -n;
		}
		if (n >= 10)
		{
			ft_putnbr(n / 10);
			ft_putnbr(n % 10);
		}
		else
			ft_putchar(n + 48);
	}
}

void	add_prime_sum(int n)
{
	int total;
	int i;
	int j;
	int flag;

	i = 2;
	j = 2;
	total = 0;
	while (i <= n)
	{
		j = 2;
		flag = 0;
		while(j <= i/2)
		{
			if (i % j == 0)
				flag = 1;
			j++;
		}
		if (flag == 0)
			total += i;
		i++;
	}
	ft_putnbr(total);
	ft_putchar('\n');
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		add_prime_sum(ft_atoi(argv[1]));
	}
	else
	{
		ft_putchar('0');
		ft_putchar('\n');
	}
}
