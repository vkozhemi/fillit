/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 17:45:38 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/04/15 13:03:07 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		ft_abs(int a)
{
	if (a < 0)
		a = -a;
	return (a);
}

int				ft_slen(int x1, int x2, int y1, int y2)
{
	int		sqw_len;

	sqw_len = ft_abs(x2 - x1) + ft_abs(y2 - y1);
	return (sqw_len);
}
