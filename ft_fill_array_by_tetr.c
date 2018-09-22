/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_array_by_tetr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 18:11:50 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/04/12 18:11:03 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillitft.h"

void	ft_fill_array_by_tetr(t_list *s_array, int k, char **array, char c)
{
	int count;

	count = 4;
	while (count > 0)
	{
		array[s_array[k].y][s_array[k].x] = c;
		k++;
		count--;
	}
}
