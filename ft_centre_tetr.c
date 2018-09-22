/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_centre_tetr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 17:24:28 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/04/14 19:33:03 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillitft.h"

void		ft_centre_tetr(t_list *s_array, int k, int x, int y)
{
	int		dx;
	int		dy;
	int		count;

	dx = x - s_array[k].x;
	dy = y - s_array[k].y;
	count = 4;
	while (count > 0)
	{
		s_array[k].x += dx;
		s_array[k].y += dy;
		k++;
		count--;
	}
}
