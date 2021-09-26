/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:56:12 by cjang             #+#    #+#             */
/*   Updated: 2021/09/26 21:29:22 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	read_part(int *i, char *s, char **line_tmp)
{
	*i = read(0, s, BUFFER_SIZE);
	if (i < 0)
		return (-1);
	s[*i] = '\0';
	if (*i == 0 && *line_tmp)
		exit_message("Error", 1);
	else if (*i == 0)
		return (0);
	else if (!(*line_tmp) && s[0] == '\n')
		exit_message("Error", 1);
	return (1);
}

static int	join_part(int *i, char *s, char **line_tmp)
{
	int		check;
	char	*line;

	while (*i > 0 && ft_ischar(s, '\n') == 0)
	{
		if (*line_tmp)
		{
			line = ft_strjoin(*line_tmp, s);
			free(*line_tmp);
		}
		else
			line = ft_strdup(s);
		*line_tmp = line;
		check = read_part(i, s, line_tmp);
		if (check <= 0)
			return (check);
	}
	return (1);
}

static void	order_part(char *s, char **line_tmp, \
						t_cd_list **lst_a, t_cd_list **lst_b)
{
	char	*line;

	if (*line_tmp)
	{
		line = ft_strjoin(*line_tmp, s);
		checker_order(line, lst_a, lst_b);
		free(*line_tmp);
		free(line);
	}
	else
		checker_order(s, lst_a, lst_b);
}

static int	checker(t_cd_list **lst_a, t_cd_list **lst_b, char **line_tmp)
{
	int		i;
	int		check;
	char	s[BUFFER_SIZE + 1];
	char	*line_tok;

	check = read_part(&i, s, line_tmp);
	if (check <= 0)
		return (check);
	while (i > 0)
	{
		join_part(&i, s, line_tmp);
		if (ft_ischar(s, '\n') > 0)
		{
			tok_line_back(s, &line_tok, '\n');
			order_part(s, line_tmp, lst_a, lst_b);
			*line_tmp = line_tok;
			check = read_part(&i, s, line_tmp);
			if (check <= 0)
				return (check);
		}
	}
	return (-1);
}

int	main(int argc, char *argv[])
{
	char		*line_tmp;
	t_cd_list	*lst_top_a;
	t_cd_list	*lst_top_b;

	line_tmp = NULL;
	if (argc < 2)
		return (1);
	make_stack(argc, argv, &lst_top_a);
	if (checker(&lst_top_a, &lst_top_b, &line_tmp) == -1)
		exit_message("Read Error", 1);
	if (line_tmp)
		free(line_tmp);
	if (check_sort(lst_top_a) == 1 && ft_cdlist_len(lst_top_b) == 0)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	ft_cdlst_del_all(&lst_top_a);
	ft_cdlst_del_all(&lst_top_b);
}
