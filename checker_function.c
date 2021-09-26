/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 23:49:31 by cjang             #+#    #+#             */
/*   Updated: 2021/09/26 21:29:26 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	tok_line_back(char *s, char **next, char tok)
{
	int		len;

	if (!s)
		return (0);
	else if (ft_ischar(s, tok) == 0)
		return (0);
	len = ft_strlen(s);
	if (len > 0 && s[len - 1] == '\n')
	{
		s[len - 1] = '\0';
		*next = NULL;
		return (1);
	}
	while (len > 0 && s[len - 1] != tok)
		len--;
	if (len > 0 && s[len - 1] == tok)
	{
		s[len - 1] = '\0';
		*next = ft_strdup(&s[len]);
		if (!(*next))
			exit_message("ft_strdup error", 1);
		return (1);
	}
	return (0);
}

int ft_ischar(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		else
			s++;
	}
	return (0);
}
