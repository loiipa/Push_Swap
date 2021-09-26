/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 23:49:31 by cjang             #+#    #+#             */
/*   Updated: 2021/08/24 00:44:42 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	tok_line(char *s, char **next)
{
	int		len;

	if (!s)
		return (0);
	len = ft_strlen(s);
	if (len == 0)
		return (0);
	else if (s[len - 1] == '\n')
	{
		s[len - 1] = '\0';
		*next = NULL;
		return (1);
	}
	len--;
	while (len > 0 && s[len - 1] != '\n')
		len--;
	if (s[len - 1] == '\n')
	{
		s[len - 1] = '\0';
		*next = ft_strdup(&s[len]);
		if (!(*next))
			exit_message("ft_strdup error", 1);
		return (1);
	}
	return (0);
}

int	ft_isendl(char *s)
{
	while (*s)
	{
		if (*s == '\n')
			return (1);
		else
			s++;
	}
	return (0);
}
