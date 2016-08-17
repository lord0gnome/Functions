/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 12:29:20 by guiricha          #+#    #+#             */
/*   Updated: 2016/01/25 13:21:32 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

int			count_words(char *str)
{
	int	ret;
	int	i;

	i = 0;
	ret = 0;
	while(str[i])
	{
		while (is_space(str[i]) && str[i])
			i++;
		if (!is_space(str[i]) && str[i])
			ret++;
		while(!is_space(str[i]) && str[i])
			i++;
	}
	return (ret);
}

char	**ft_split(char *str)
{
	char	**ret;
	int		words;
	int		i;
	int		j;
	int		retindex;
	int		wordindex;

	if (!str)
		return (ret = NULL);
	words = count_words(str);
	if (words == 0)
	{
		ret = (char **)malloc(sizeof(char *) * 1);
		*ret = NULL;
		return (ret);
		
	}
	else
		ret = (char **)malloc(sizeof(char *) * (words + 1));
	i = 0;
	retindex = 0;
	while(str[i])
	{
		while (is_space(str[i]) && str[i])
			i++;
		if (!is_space(str[i]) && str[i])
		{
			j = 0;
			while(str[i + j] && !is_space(str[i + j]))
				j++;
			ret[retindex] = (char *)malloc(sizeof(char) * (j + 1));
			wordindex = 0;
			while (j-- && str[i + wordindex])
			{
				ret[retindex][wordindex] = str[i + wordindex];
				wordindex++;
			}
				ret[retindex][wordindex] = '\0';
		retindex++;
		i += wordindex;
		}
	}
	ret[retindex] = NULL;

	return (ret);
}
