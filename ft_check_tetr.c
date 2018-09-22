/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tetr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 12:47:10 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/04/14 19:14:11 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillitft.h"

static int		ft_first_check(t_list *ar, int k)
{
	if (ft_slen(ar[k].x, ar[k + 1].x, ar[k].y, ar[k + 1].y) == 1
	|| ft_slen(ar[k].x, ar[k + 2].x, ar[k].y, ar[k + 2].y) == 1
	|| ft_slen(ar[k].x, ar[k + 3].x, ar[k].y, ar[k + 3].y) == 1)
		return (1);
	return (0);
}

static int		ft_second_check(t_list *ar, int k)
{
	if (ft_slen(ar[k + 1].x, ar[k + 2].x, ar[k + 1].y, ar[k + 2].y) == 1
	|| (ft_slen(ar[k].x, ar[k + 2].x, ar[k].y, ar[k + 2].y) == 1
	&& ft_slen(ar[k].x, ar[k + 1].x, ar[k].y, ar[k + 1].y) == 1
	&& ft_slen(ar[k + 2].x, ar[k + 3].x, ar[k + 2].y, ar[k + 3].y) == 1)
	|| (ft_slen(ar[k].x, ar[k + 3].x, ar[k].y, ar[k + 3].y) == 1
	&& ft_slen(ar[k + 2].x, ar[k + 3].x, ar[k + 2].y, ar[k + 3].y) == 1
	&& ft_slen(ar[k].x, ar[k + 1].x, ar[k].y, ar[k + 1].y) == 1)
	|| ft_slen(ar[k + 1].x, ar[k + 3].x, ar[k + 1].y, ar[k + 3].y) == 1)
		return (1);
	return (0);
}

static int		ft_third_check(t_list *ar, int k)
{
	if (ft_slen(ar[k + 2].x, ar[k + 3].x, ar[k + 2].y, ar[k + 3].y) == 1
	|| (ft_slen(ar[k + 1].x, ar[k + 3].x, ar[k + 1].y, ar[k + 3].y) == 1
	&& ft_slen(ar[k + 1].x, ar[k + 2].x, ar[k + 1].y, ar[k + 2].y) == 1)
	|| (ft_slen(ar[k].x, ar[k + 3].x, ar[k].y, ar[k + 3].y) == 1
	&& ft_slen(ar[k].x, ar[k + 1].x, ar[k].y, ar[k + 1].y) == 1 &&
	ft_slen(ar[k + 1].x, ar[k + 2].x, ar[k + 1].y, ar[k + 2].y) == 1))
		return (1);
	return (0);
}

int				ft_check_tetr(t_list *ar, size_t len)
{
	size_t		k;

	k = 0;
	while (k < len)
	{
		if (ft_first_check(ar, k) == 1)
		{
			if (ft_second_check(ar, k) == 1)
			{
				if (ft_third_check(ar, k) == 1)
					k += 4;
				else
					return (1);
			}
			else
				return (1);
		}
		else
			return (1);
	}
	return (0);
}
