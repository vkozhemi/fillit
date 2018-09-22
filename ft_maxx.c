/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maxx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 11:52:59 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/04/14 19:29:54 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillitft.h"

int		ft_maxx(t_list *s_array, int k, int size)
{
	int		max_x;

	max_x = s_array[k].x;
	while (size > 1)
	{
		if (s_array[k + 1].x > max_x)
			max_x = s_array[k + 1].x;
		k++;
		size--;
	}
	return (max_x);
}
