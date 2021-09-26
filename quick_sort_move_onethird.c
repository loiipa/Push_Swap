/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_move_onethird.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 16:55:12 by cjang             #+#    #+#             */
/*   Updated: 2021/08/20 14:50:51 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_b_down(t_cd_list **lst_a, t_cd_list **lst_b, int len)
{
	int			onethrid_num;
	int			twothird_num;
	t_cd_list	*lst_tmp;
	int			i;

	i = 0;
	lst_tmp = *lst_b;
	while (i++ < len)
		lst_tmp = lst_tmp->prev;
	onethrid_num = find_onethird_num(lst_tmp, len);
	twothird_num = find_twothird_num(lst_tmp, len);
	i = 0;
	while (i++ < len)
	{
		push_swap_order("rrb", lst_a, lst_b);
		if (onethrid_num < (*lst_b)->content && \
			(*lst_b)->content < twothird_num)
			push_swap_order("pa ra", lst_a, lst_b);
		else if ((*lst_b)->content >= twothird_num)
			push_swap_order("pa", lst_a, lst_b);
	}
}

static void	stack_b_up(t_cd_list **lst_a, t_cd_list **lst_b, int len)
{
	int			onethrid_num;
	int			twothird_num;
	int			i;

	i = 0;
	onethrid_num = find_onethird_num(*lst_b, len);
	twothird_num = find_twothird_num(*lst_b, len);
	while (i < len)
	{
		if ((*lst_b)->content <= onethrid_num)
			push_swap_order("rb", lst_a, lst_b);
		else if (onethrid_num < (*lst_b)->content && \
				(*lst_b)->content < twothird_num)
			push_swap_order("pa ra", lst_a, lst_b);
		else if ((*lst_b)->content >= twothird_num)
			push_swap_order("pa", lst_a, lst_b);
		i++;
	}
}

static void	stack_a_down(t_cd_list **lst_a, t_cd_list **lst_b, int len)
{
	int			onethrid_num;
	int			twothird_num;
	t_cd_list	*lst_tmp;
	int			i;

	i = 0;
	lst_tmp = *lst_a;
	while (i++ < len)
		lst_tmp = lst_tmp->prev;
	onethrid_num = find_onethird_num(lst_tmp, len);
	twothird_num = find_twothird_num(lst_tmp, len);
	i = 0;
	while (i++ < len)
	{
		push_swap_order("rra", lst_a, lst_b);
		if ((*lst_a)->content <= onethrid_num)
			push_swap_order("pb rb", lst_a, lst_b);
		else if (onethrid_num < (*lst_a)->content && \
				(*lst_a)->content < twothird_num)
			push_swap_order("pb", lst_a, lst_b);
	}
}

static void	stack_a_up(t_cd_list **lst_a, t_cd_list **lst_b, int len)
{
	int			onethrid_num;
	int			twothird_num;
	int			i;

	i = 0;
	onethrid_num = find_onethird_num(*lst_a, len);
	twothird_num = find_twothird_num(*lst_a, len);
	while (i < len)
	{
		if ((*lst_a)->content <= onethrid_num)
			push_swap_order("pb rb", lst_a, lst_b);
		else if (onethrid_num < (*lst_a)->content && \
				(*lst_a)->content < twothird_num)
			push_swap_order("pb", lst_a, lst_b);
		else if ((*lst_a)->content >= twothird_num)
			push_swap_order("ra", lst_a, lst_b);
		i++;
	}
}

void	quick_sort_move(t_cd_list **lst_a, t_cd_list **lst_b, int len, int loc)
{
	if (!(*lst_a) || loc > 4 || loc < 1)
		exit_message("quick_sort_move error", 1);
	if (loc == 1 && ft_cdlist_len(*lst_b) != len)
		stack_b_down(lst_a, lst_b, len);
	else if (loc == 1 || loc == 2)
		stack_b_up(lst_a, lst_b, len);
	else if (loc == 3 && ft_cdlist_len(*lst_a) != len)
		stack_a_down(lst_a, lst_b, len);
	else if (loc == 3 || loc == 4)
		stack_a_up(lst_a, lst_b, len);
}
