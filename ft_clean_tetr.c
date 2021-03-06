/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_tetr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 17:00:50 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/04/11 14:19:27 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_clean_tetr(char **array, char c)
{
	int i;
	int j;

	i = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (array[i][j] == c)
				array[i][j] = '.';
			j++;
		}
		i++;
	}
}
