/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:19:46 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/04/15 12:56:17 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillitft.h"

static size_t	ft_count_elem_in_file(int fd)
{
	char		buf[1];
	int			ret;
	size_t		count;

	ret = 0;
	count = 1;
	while ((ret = read(fd, buf, 1)))
	{
		if (ret == -1)
			ft_putstr("error\n");
		count++;
	}
	return (count);
}

static char		*ft_read_and_fill(char *argv, size_t *count)
{
	char		*str;
	char		buf[1];
	int			ret;
	int			i;
	int			fd;

	i = 0;
	str = NULL;
	if ((fd = open(argv, O_RDONLY)) == -1)
		return (NULL);
	if ((*count = ft_count_elem_in_file(fd)) > 547 || (*count) < 21)
		return (NULL);
	if (close(fd) == -1)
		return (NULL);
	fd = open(argv, O_RDONLY);
	str = ft_strnew(*count);
	if (str == NULL)
		return (NULL);
	while ((ret = read(fd, buf, 1)))
		str[i++] = buf[0];
	str[i] = '\0';
	if (close(fd) == -1)
		return (NULL);
	return (str);
}

static int		ft_exit(char *str)
{
	ft_putstr("error\n");
	free(str);
	return (1);
}

static int		ft_exit2(void)
{
	ft_putstr("usage: fillit [file]\n");
	return (1);
}

int				main(int argc, char **argv)
{
	size_t			count;
	char			*str;
	t_list			*s_array;
	size_t			len_s_array;

	str = NULL;
	count = 0;
	if (argc != 2)
		return (ft_exit2());
	if (!(str = ft_read_and_fill(argv[1], &count)) || ft_check_str(str) == 1)
		return (ft_exit(str));
	len_s_array = count / 21 * 4;
	if (!(s_array = ft_create_and_fill_struct_array(str, len_s_array)) ||
		(ft_check_tetr(s_array, len_s_array) == 1))
	{
		free(s_array);
		return (ft_exit(str));
	}
	ft_solve_general(ft_sqrt(len_s_array), s_array, count / 21);
	free(str);
	free(s_array);
	return (0);
}
