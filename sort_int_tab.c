/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 18:58:55 by guiricha          #+#    #+#             */
/*   Updated: 2016/02/01 19:04:56 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	sort_int_tab(int *tab, unsigned int size)
{
	int bck;
	unsigned int index;
	unsigned int j;

	index = 0;
	while (index < size)
	{
		j = index;
		while (j < size)
		{
			if (tab[index] > tab[j])
			{
				bck = tab[index];
				tab[index] = tab[j];
				tab[j] = bck;
			}
			j++;
		}
		index++;
		
	}
}
