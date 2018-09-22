/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 16:45:19 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/04/14 14:43:33 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillitft.h"

int		ft_check_place(t_list *s_array, int k, char **array, int size)
{
	int		count;

	count = 4;
	while (count > 0 && s_array[k].y <= size - 1 && s_array[k].x <= size - 1 &&
			array[s_array[k].y][s_array[k].x] == '.')
	{
		k++;
		count--;
	}
	if (count != 0)
		return (1);
	return (0);
}
