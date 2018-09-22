/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maxy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 12:09:03 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/04/12 20:07:56 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillitft.h"

int		ft_maxy(t_list *s_array, int k, int size)
{
	int		max_y;

	max_y = s_array[k].y;
	while (size > 1)
	{
		if (s_array[k + 1].y > max_y)
			max_y = s_array[k + 1].y;
		k++;
		size--;
	}
	return (max_y);
}
