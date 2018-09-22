/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillitft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 14:41:39 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/04/14 19:40:54 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLITFT_H
# define FILLITFT_H

# include <fcntl.h>
# include <sys/types.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	int			x;
	int			y;
	char		c;
}					t_list;

int					ft_check_str(char *str);
t_list				*ft_create_and_fill_struct_array(char*str, size_t len);
int					ft_check_tetr(t_list *ar, size_t len);
void				ft_centre_tetr(t_list *s_array, int k, int x, int y);
size_t				ft_sqrt(size_t nb);
char				**ft_createarray(int size, char filler);
int					ft_check_place(t_list *s_array, int k, char **array,
									int size);
void				ft_fill_array_by_tetr(t_list *s_array, int k, char **array,
									char c);
void				ft_clean_tetr(char **array, char c);
void				ft_clear_array(char **str);
int					ft_solve_general(size_t size, t_list *s_array,
									size_t count_tetr);
int					ft_maxy(t_list *s_array, int k, int size);
int					ft_maxx(t_list *s_array, int k, int size);
int					ft_step_back(t_list *s_array, char **map, int *k, int size);
void				ft_putstr(char const *s);
char				*ft_strnew(size_t size);
void				ft_printarray_charx2(char **array);
int					ft_slen(int x1, int x2, int y1, int y2);

#endif
