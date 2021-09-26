/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_main_tree.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 11:57:45 by cjang             #+#    #+#             */
/*   Updated: 2021/08/20 14:50:54 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_one_two(t_cd_list **lst_a, t_cd_list **lst_b, int len, int loc)
{
	if (len == 1)
	{
		if (loc == 1 && ft_cdlist_len(*lst_b) != len)
			push_swap_order("rrb pa", lst_a, lst_b);
		else if (loc == 2 || loc == 1)
			push_swap_order("pa", lst_a, lst_b);
		else if (loc == 3 && ft_cdlist_len(*lst_a) != len)
			push_swap_order("rra", lst_a, lst_b);
	}
	else if (len == 2)
	{
		if (loc == 1 && ft_cdlist_len(*lst_b) != len)
			push_swap_order("rrb rrb pa pa", lst_a, lst_b);
		else if (loc == 2 || loc == 1)
			push_swap_order("pa pa", lst_a, lst_b);
		else if (loc == 3 && ft_cdlist_len(*lst_a) != len)
			push_swap_order("rra rra", lst_a, lst_b);
		if ((*lst_a)->content > (*lst_a)->next->content)
			push_swap_order("sa", lst_a, lst_b);
	}
}

static void	sort_four(t_cd_list **lst_a, t_cd_list **lst_b, int len, int loc)
{
	quick_sort_move_half(lst_a, lst_b, len, loc);
	quick_sort(lst_a, lst_b, len / 2, 4);
	quick_sort(lst_a, lst_b, len / 2, 2);
}

static void	sort_main(t_cd_list **lst_a, t_cd_list **lst_b, int len, int loc)
{
	quick_sort_move(lst_a, lst_b, len, loc);
	if (loc == 1)
	{
		quick_sort(lst_a, lst_b, (len + 2) / 3, 4);
		quick_sort(lst_a, lst_b, (len + 1) / 3, 3);
		quick_sort(lst_a, lst_b, len / 3, 2);
	}
	else if (loc == 2)
	{
		quick_sort(lst_a, lst_b, (len + 2) / 3, 4);
		quick_sort(lst_a, lst_b, (len + 1) / 3, 3);
		quick_sort(lst_a, lst_b, len / 3, 1);
	}
	else if (loc == 3)
	{
		quick_sort(lst_a, lst_b, (len + 2) / 3, 4);
		quick_sort(lst_a, lst_b, (len + 1) / 3, 2);
		quick_sort(lst_a, lst_b, len / 3, 1);
	}
	else if (loc == 4)
	{
		quick_sort(lst_a, lst_b, (len + 2) / 3, 3);
		quick_sort(lst_a, lst_b, (len + 1) / 3, 2);
		quick_sort(lst_a, lst_b, len / 3, 1);
	}
}

void	quick_sort(t_cd_list **lst_a, t_cd_list **lst_b, int len, int loc)
{
	if (len < 3)
		sort_one_two(lst_a, lst_b, len, loc);
	else if (len == 3)
		sort_three(lst_a, lst_b, loc);
	else if (len == 4)
		sort_four(lst_a, lst_b, len, loc);
	else if (len > 4)
		sort_main(lst_a, lst_b, len, loc);
}
