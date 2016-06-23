/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 10:01:42 by exam              #+#    #+#             */
/*   Updated: 2016/06/23 14:22:42 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa_base(int v, int base)
{
	int		length;
	int		sign;
	int		bck;
	char	*ret;

	bck = v;
	length = 1;
	sign = v < 0 ? 1 : 0;
	if (base != 10)
		sign = 0;
	if (base < 2 || base > 16)
		return (NULL);
	while (bck /= base)
		length++;
	if (!(ret = (char *)malloc(sizeof(char) * length + sign + 1)))
		return (NULL);
	ret[length + sign] = '\0';
	ret[0] = '-';
	while (length--)
	{
		ret[length + sign] = v < 0 ? (-(v % -(base))) + 48 : (v % base) + 48;
		ret[length + sign] += ret[length + sign] > 57 ? 7 : 0;
		v /= base;
	}
	return (ret);
}
