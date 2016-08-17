/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 11:59:24 by guiricha          #+#    #+#             */
/*   Updated: 2016/01/25 12:28:00 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int start, int end)
{
	size_t	size;
	int		tempstrt;
	int		tempend;
	int		*table;
	int		dir;
	size_t	count;

	tempstrt = start;
	tempend = end;
	size = 1;
	count = 0;
	if (tempstrt > tempend)
	{
		while(tempstrt > tempend)
		{
			tempstrt--;
			size++;
			dir = 1;
		}
	}
	else if (tempstrt < tempend)
	{
		while(tempstrt < tempend)
		{
			tempstrt++;
			size++;
			dir = 0;
		}
	}
	else if (tempstrt == tempend)
		size = 1;
	if (!(table = (int *)malloc(sizeof(int) * size)))
		return (NULL);

	while (size)
		{
			if (dir)
				table[count++] = start--;
			else if (!dir)
				table[count++] = start++;
			size--;
		}
	return (table);
}
