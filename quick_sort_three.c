/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 16:42:42 by cjang             #+#    #+#             */
/*   Updated: 2021/08/20 14:50:43 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_b_down(t_cd_list **lst_a, t_cd_list **lst_b)
{
	push_swap_order("rrb", lst_a, lst_b);
	if ((*lst_b)->content < (*lst_b)->prev->content && \
		(*lst_b)->content < (*lst_b)->prev->prev->content)
	{
		if ((*lst_b)->prev->content < (*lst_b)->prev->prev->content)
			push_swap_order("rrb rrb pa pa pa", lst_a, lst_b);
		else
			push_swap_order("rrb pa rrb pa pa", lst_a, lst_b);
	}
	else if ((*lst_b)->content < (*lst_b)->prev->content || \
			(*lst_b)->content < (*lst_b)->prev->prev->content)
	{
		if ((*lst_b)->prev->content < (*lst_b)->prev->prev->content)
			push_swap_order("rrb sb rrb pa pa pa", lst_a, lst_b);
		else
			push_swap_order("rrb pa pa rrb pa", lst_a, lst_b);
	}
	else if ((*lst_b)->content > (*lst_b)->prev->content && \
			(*lst_b)->content > (*lst_b)->prev->prev->content)
	{
		if ((*lst_b)->prev->content < (*lst_b)->prev->prev->content)
			push_swap_order("pa rrb rrb pa pa", lst_a, lst_b);
		else
			push_swap_order("pa rrb pa rrb pa", lst_a, lst_b);
	}
}

static void	stack_b_up(t_cd_list **lst_a, t_cd_list **lst_b)
{
	if ((*lst_b)->content < (*lst_b)->next->content && \
		(*lst_b)->content < (*lst_b)->next->next->content)
	{
		if ((*lst_b)->next->content < (*lst_b)->next->next->content)
			push_swap_order("sb pa sb pa sa pa", lst_a, lst_b);
		else
			push_swap_order("sb pa sb pa pa", lst_a, lst_b);
	}
	else if ((*lst_b)->content < (*lst_b)->next->content || \
			(*lst_b)->content < (*lst_b)->next->next->content)
	{
		if ((*lst_b)->next->content < (*lst_b)->next->next->content)
			push_swap_order("pa sb pa sa pa", lst_a, lst_b);
		else
			push_swap_order("sb pa pa pa", lst_a, lst_b);
	}
	else if ((*lst_b)->content > (*lst_b)->next->content && \
			(*lst_b)->content > (*lst_b)->next->next->content)
	{
		if ((*lst_b)->next->content < (*lst_b)->next->next->content)
			push_swap_order("pa sb pa pa", lst_a, lst_b);
		else
			push_swap_order("pa pa pa", lst_a, lst_b);
	}
}

static void	stack_a_down(t_cd_list **lst_a, t_cd_list **lst_b)
{
	push_swap_order("rra", lst_a, lst_b);
	if ((*lst_a)->content < (*lst_a)->prev->content && \
		(*lst_a)->content < (*lst_a)->prev->prev->content)
	{
		if ((*lst_a)->prev->content < (*lst_a)->prev->prev->content)
			push_swap_order("pb rra rra sa pa", lst_a, lst_b);
		else
			push_swap_order("rra sa rra sa", lst_a, lst_b);
	}
	else if ((*lst_a)->content < (*lst_a)->prev->content || \
			(*lst_a)->content < (*lst_a)->prev->prev->content)
	{
		if ((*lst_a)->prev->content < (*lst_a)->prev->prev->content)
			push_swap_order("rra pb rra sa pa", lst_a, lst_b);
		else
			push_swap_order("rra sa rra", lst_a, lst_b);
	}
	else if ((*lst_a)->content > (*lst_a)->prev->content && \
			(*lst_a)->content > (*lst_a)->prev->prev->content)
	{
		if ((*lst_a)->prev->content < (*lst_a)->prev->prev->content)
			push_swap_order("rra rra sa", lst_a, lst_b);
		else
			push_swap_order("rra rra", lst_a, lst_b);
	}
}

static void	stack_a_up(t_cd_list **lst_a, t_cd_list **lst_b)
{
	if ((*lst_a)->content < (*lst_a)->next->content && \
		(*lst_a)->content < (*lst_a)->next->next->content)
	{
		if ((*lst_a)->next->content < (*lst_a)->next->next->content)
			;
		else
			push_swap_order("ra sa rra", lst_a, lst_b);
	}
	else if ((*lst_a)->content < (*lst_a)->next->content || \
			(*lst_a)->content < (*lst_a)->next->next->content)
	{
		if ((*lst_a)->next->content < (*lst_a)->next->next->content)
			push_swap_order("sa", lst_a, lst_b);
		else
			push_swap_order("ra sa rra sa", lst_a, lst_b);
	}
	else if ((*lst_a)->content > (*lst_a)->next->content && \
			(*lst_a)->content > (*lst_a)->next->next->content)
	{
		if ((*lst_a)->next->content < (*lst_a)->next->next->content)
			push_swap_order("sa ra sa rra", lst_a, lst_b);
		else
			push_swap_order("sa ra sa rra sa", lst_a, lst_b);
	}
}

void	sort_three(t_cd_list **lst_a, t_cd_list **lst_b, int loc)
{
	if (loc == 1 && ft_cdlist_len(*lst_b) != 3)
		stack_b_down(lst_a, lst_b);
	else if (loc == 1 || loc == 2)
		stack_b_up(lst_a, lst_b);
	else if ((loc == 3 || loc == 4) && ft_cdlist_len(*lst_a) == 3)
	{
		if ((*lst_a)->content > (*lst_a)->next->content && \
			(*lst_a)->content > (*lst_a)->prev->content)
			push_swap_order("ra", lst_a, lst_b);
		else if (((*lst_a)->next->content > (*lst_a)->content && \
				(*lst_a)->next->content > (*lst_a)->prev->content))
			push_swap_order("rra", lst_a, lst_b);
		if ((*lst_a)->content > (*lst_a)->next->content)
			push_swap_order("sa", lst_a, lst_b);
	}
	else if (loc == 3)
		stack_a_down(lst_a, lst_b);
	else if (loc == 4)
		stack_a_up(lst_a, lst_b);
}
