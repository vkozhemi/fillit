/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_step_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 14:04:40 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/04/15 13:03:19 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillitft.h"

int		ft_step_back(t_list *s_array, char **map, int *k, int size)
{
	if (*k == 0)
	{
		ft_centre_tetr(s_array, *k, 100, 100);
		return (1);
	}
	*k -= 4;
	ft_clean_tetr(map, s_array[*k].c);
	if (ft_maxx(s_array, *k, 4) < size - 1)
		ft_centre_tetr(s_array, *k, s_array[*k].x + 1, s_array[*k].y);
	else if (ft_maxx(s_array, *k, 4) == size - 1 &&
			ft_maxy(s_array, *k, 4) < size - 1)
		ft_centre_tetr(s_array, *k, 0, s_array[*k].y + 1);
	else
		ft_step_back(s_array, map, k, size);
	return (0);
}
