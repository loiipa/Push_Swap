/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_move_half.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 16:24:22 by cjang             #+#    #+#             */
/*   Updated: 2021/08/19 23:28:24 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_b_down(t_cd_list **lst_a, t_cd_list **lst_b, int len)
{
	int			half_num;
	int			i;
	t_cd_list	*lst_tmp;

	i = 0;
	lst_tmp = *lst_b;
	while (i++ < len)
		lst_tmp = lst_tmp->prev;
	half_num = find_half_num(lst_tmp, len);
	i = 0;
	while (i++ < len)
	{
		push_swap_order("rrb", lst_a, lst_b);
		if ((*lst_b)->content > half_num)
			push_swap_order("pa", lst_a, lst_b);
	}
}

static void	stack_b_up(t_cd_list **lst_a, t_cd_list **lst_b, int len)
{
	int			half_num;
	int			i;

	i = 0;
	half_num = find_half_num(*lst_b, len);
	while (i++ < len)
	{
		if ((*lst_b)->content <= half_num)
			push_swap_order("rb", lst_a, lst_b);
		else if ((*lst_b)->content > half_num)
			push_swap_order("pa", lst_a, lst_b);
	}
	if (ft_cdlist_len(*lst_b) != len / 2)
	{
		i = 0;
		while (i++ < len / 2)
			push_swap_order("rrb", lst_a, lst_b);
	}
}

static void	stack_a_down(t_cd_list **lst_a, t_cd_list **lst_b, int len)
{
	int			half_num;
	int			i;
	t_cd_list	*lst_tmp;

	i = 0;
	lst_tmp = *lst_a;
	while (i++ < len)
		lst_tmp = lst_tmp->prev;
	half_num = find_half_num(lst_tmp, len);
	i = 0;
	while (i++ < len)
	{
		push_swap_order("rra", lst_a, lst_b);
		if ((*lst_a)->content <= half_num)
			push_swap_order("pb", lst_a, lst_b);
	}
}

static void	stack_a_up(t_cd_list **lst_a, t_cd_list **lst_b, int len)
{
	int			half_num;
	int			i;

	i = 0;
	half_num = find_half_num(*lst_a, len);
	while (i++ < len)
	{
		if ((*lst_a)->content <= half_num)
			push_swap_order("pb", lst_a, lst_b);
		else if ((*lst_a)->content > half_num)
			push_swap_order("ra", lst_a, lst_b);
	}
	if (ft_cdlist_len(*lst_a) != (len + 1) / 2)
	{
		i = 0;
		while (i++ < (len + 1) / 2)
			push_swap_order("rra", lst_a, lst_b);
	}
}

void	quick_sort_move_half(t_cd_list **lst_a, t_cd_list **lst_b, \
		int len, int loc)
{
	if (!(*lst_a) || loc > 4 || loc < 1)
		exit_message("quick_sort_move_half error", 1);
	if (loc == 1 && ft_cdlist_len(*lst_b) != len)
		stack_b_down(lst_a, lst_b, len);
	else if (loc == 1 || loc == 2)
		stack_b_up(lst_a, lst_b, len);
	else if (loc == 3 && ft_cdlist_len(*lst_a) != len)
		stack_a_down(lst_a, lst_b, len);
	else if (loc == 3 || loc == 4)
		stack_a_up(lst_a, lst_b, len);
}
