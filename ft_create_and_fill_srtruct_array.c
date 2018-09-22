/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_and_fill_srtruct_array.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 19:31:14 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/04/14 19:03:30 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillitft.h"

static void			ft_change_params(char *c, int *count_sharp)
{
	if (*count_sharp == 0)
	{
		*c += 1;
		*count_sharp = 4;
	}
}

static void			ft_fill_struct_array(t_list *struct_array, int i,
									char c, int *k)
{
	struct_array[(*k)].x = (i + 1 - i / 21) % 5;
	struct_array[(*k)].y = (i + 1 - (i / 21) * 21) / 5 + 1;
	struct_array[(*k)].c = c;
	(*k)++;
}

t_list				*ft_create_and_fill_struct_array(char *str, size_t len)
{
	int			i;
	int			k;
	int			count_sharp;
	char		c;
	t_list		*struct_array;

	i = 0;
	k = 0;
	count_sharp = 4;
	c = 'A';
	struct_array = (t_list*)malloc(sizeof(t_list) * (len));
	if (struct_array == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == '#')
		{
			ft_fill_struct_array(struct_array, i, c, &k);
			count_sharp--;
		}
		ft_change_params(&c, &count_sharp);
		i++;
	}
	return (struct_array);
}
