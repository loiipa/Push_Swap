/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rule_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 12:35:01 by cjang             #+#    #+#             */
/*   Updated: 2021/08/25 13:33:50 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rule_branch_2(t_cd_list **lst_a, t_cd_list **lst_b, char *s)
{
	if (ft_strcmp("ra", s) == 0)
		ft_rotate(lst_a, "next");
	else if (ft_strcmp("rb", s) == 0)
		ft_rotate(lst_b, "next");
	else if (ft_strcmp("rr", s) == 0)
	{
		ft_rotate(lst_a, "next");
		ft_rotate(lst_b, "next");
	}
	else if (ft_strcmp("rra", s) == 0)
		ft_rotate(lst_a, "prev");
	else if (ft_strcmp("rrb", s) == 0)
		ft_rotate(lst_b, "prev");
	else if (ft_strcmp("rrr", s) == 0)
	{
		ft_rotate(lst_a, "prev");
		ft_rotate(lst_b, "prev");
	}
	else
		exit_message("Error", 1);
}

static void	ft_rule_branch_1(t_cd_list **lst_a, t_cd_list **lst_b, char *s)
{
	if (ft_strcmp("sa", s) == 0)
		ft_swap(lst_a);
	else if (ft_strcmp("sb", s) == 0)
		ft_swap(lst_b);
	else if (ft_strcmp("ss", s) == 0)
	{
		ft_swap(lst_a);
		ft_swap(lst_b);
	}
	else if (ft_strcmp("pa", s) == 0)
		ft_push(lst_b, lst_a);
	else if (ft_strcmp("pb", s) == 0)
		ft_push(lst_a, lst_b);
	else
		ft_rule_branch_2(lst_a, lst_b, s);
}

void	push_swap_order(char *s, t_cd_list **lst_a, t_cd_list **lst_b)
{
	int			i;
	char		s_tmp[ORDER_SIZE];

	i = 0;
	while (*s != '\0')
	{
		if (*s == ' ')
		{
			s_tmp[i++] = '\0';
			ft_rule_branch_1(lst_a, lst_b, s_tmp);
			if (ft_strlen(s_tmp) > 0)
				ft_putendl_fd(s_tmp, 1);
			i = 0;
		}
		else
			s_tmp[i++] = *s;
		s++;
	}
	s_tmp[i++] = '\0';
	ft_rule_branch_1(lst_a, lst_b, s_tmp);
	if (ft_strlen(s_tmp) > 0)
		ft_putendl_fd(s_tmp, 1);
}

void	checker_order(char *s, t_cd_list **lst_a, t_cd_list **lst_b)
{
	int			i;
	char		s_tmp[ORDER_SIZE];

	i = 0;
	while (*s != '\0')
	{
		if (*s == '\n')
		{
			s_tmp[i++] = '\0';
			ft_rule_branch_1(lst_a, lst_b, s_tmp);
			i = 0;
		}
		else
			s_tmp[i++] = *s;
		s++;
		if (i >= ORDER_SIZE)
			exit_message("Error", 1);
	}
	s_tmp[i] = '\0';
	if (i != 0)
		ft_rule_branch_1(lst_a, lst_b, s_tmp);
}
