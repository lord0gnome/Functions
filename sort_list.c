/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 18:46:56 by guiricha          #+#    #+#             */
/*   Updated: 2016/02/01 18:55:05 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list *start;
	t_list *temp;
	t_list *temp2;
	int bck;

	temp = lst;
	start = lst;
	while (temp)
	{
		temp2 = temp;
		while (temp2)
		{
			if (!cmp(temp->data, temp2->data))
			{
				bck = temp->data;
				temp->data = temp2->data;
				temp2->data = bck;
			}
			temp2 = temp2->next;
		}
	temp = temp->next;
	}
	return (start);
}
