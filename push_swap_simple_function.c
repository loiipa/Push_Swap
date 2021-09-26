/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_simple_function.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 11:14:05 by cjang             #+#    #+#             */
/*   Updated: 2021/08/25 13:29:52 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_issign(int c)
{
	if (c == '-' || c == '+')
		return (1);
	else
		return (0);
}

void	exit_message(char *s, int i)
{
	if (ft_strcmp(s, "Error") == 0)
		write(2, "Error\n", 6);
	else
		ft_putendl_fd(s, 1);
	exit(i);
}

void	free_book(char **book, size_t index)
{
	while (index > 0)
		free(book[--index]);
	free(book);
}
