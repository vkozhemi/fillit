/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 11:38:44 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/04/14 20:08:34 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillitft.h"

static int		ft_sub_check_str(char *str, int *i, int *n, int *count_sharp)
{
	if (str[*i] == '#')
		(*count_sharp)++;
	if (str[*i] == '\n' && (*i % *n) != 0)
		return (1);
	if (str[*i] == '\n' && (*i % *n) == 0)
		*n += 5;
	(*i)++;
	return (0);
}

int				ft_check_str(char *str)
{
	int			i;
	int			count;
	int			n;
	int			count_sharp;

	i = -1;
	n = 4;
	while (str[++i] != '\0')
	{
		count_sharp = 0;
		count = 21;
		while (--count > 0 && str[i] != '\0' && (str[i] == '.'
				|| str[i] == '#' || str[i] == '\n'))
			if (ft_sub_check_str(str, &i, &n, &count_sharp) == 1)
				return (1);
		if ((str[i] != '\n' && count == 0 && str[i] != '\0')
		|| (str[i - 1] != '\n' && count == 0)
		|| (str[i] == '\0' && count != 0) || count_sharp != 4)
			return (1);
		n++;
	}
	if (str[i] == '\0' && str[i - 1] == '\n' && str[i - 2] == '\n')
		return (1);
	return (0);
}
