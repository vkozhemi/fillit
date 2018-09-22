/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createarray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 11:14:53 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/04/14 15:23:42 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillitft.h"

static int	ft_exit(char *str, char **array)
{
	if (str == NULL)
	{
		ft_clear_array(array);
		return (1);
	}
	return (0);
}

char		**ft_createarray(int size, char filler)
{
	char	**new_array;
	int		i;
	int		k;

	i = -1;
	if (size <= 0 || !filler)
		return (NULL);
	new_array = (char**)malloc(sizeof(char*) * (size + 1));
	if (new_array == NULL)
		return (NULL);
	while (++i < size)
	{
		k = 0;
		new_array[i] = ft_strnew(size);
		if (ft_exit(new_array[i], new_array) == 1)
			return (NULL);
		while (k < size)
		{
			new_array[i][k] = filler;
			k++;
		}
		new_array[i][k] = '\0';
	}
	new_array[i] = NULL;
	return (new_array);
}
