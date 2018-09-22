/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_general.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:59:45 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/04/14 19:38:44 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillitft.h"

static int	ft_tetr_not_placed(t_list *s_arr, int *k, char **map, int size)
{
	if (ft_maxx(s_arr, *k, 4) < size - 1)
		ft_centre_tetr(s_arr, *k, s_arr[*k].x + 1, s_arr[*k].y);
	else if (ft_maxx(s_arr, *k, 4) == size - 1
			&& ft_maxy(s_arr, *k, 4) < size - 1)
		ft_centre_tetr(s_arr, *k, 0, s_arr[*k].y + 1);
	else
	{
		if (ft_step_back(s_arr, map, &(*k), size) == 0)
			return (1);
		else
			ft_centre_tetr(s_arr, *k, 100, 100);
	}
	return (0);
}

static int	ft_exit(t_list *s_arr, int k, char **map, int size)
{
	if (k == 0 && s_arr[k].x > size - 1 && s_arr[k].y > size - 1)
	{
		ft_clear_array(map);
		return (1);
	}
	return (0);
}

static int	ft_solve(t_list *s_arr, size_t count_tetr, char **map, int size)
{
	int		k;
	size_t	count;

	k = 0;
	count = 0;
	while (count < count_tetr)
	{
		if (ft_check_place(s_arr, k, map, size) == 0)
		{
			ft_fill_array_by_tetr(s_arr, k, map, s_arr[k].c);
			if (++count == count_tetr)
				return (0);
			k += 4;
			ft_centre_tetr(s_arr, k, 0, 0);
		}
		if (ft_check_place(s_arr, k, map, size) == 1)
		{
			if (ft_tetr_not_placed(s_arr, &k, map, size) == 1)
				count = k / 4;
		}
		if (ft_exit(s_arr, k, map, size) == 1)
			return (1);
	}
	return (0);
}

int			ft_solve_general(size_t size_map, t_list *s_array, size_t cnt_tetr)
{
	char		**map;
	int			size;

	size = (int)size_map;
	map = ft_createarray(size, '.');
	if (map == NULL)
		return (1);
	ft_centre_tetr(s_array, 0, 0, 0);
	if (ft_solve(s_array, cnt_tetr, map, size) == 1)
		ft_solve_general(size + 1, s_array, cnt_tetr);
	else
	{
		ft_printarray_charx2(map);
		ft_clear_array(map);
	}
	return (0);
}
