/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_num_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 16:35:19 by cjang             #+#    #+#             */
/*   Updated: 2021/08/19 23:27:16 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_num(t_cd_list *lst, int len)
{
	int			i;
	int			max;
	t_cd_list	*lst_tmp;

	if (!lst)
		exit_message("find_max_num error", 1);
	max = lst->content;
	lst_tmp = lst->next;
	i = 1;
	while (i < len)
	{
		if (lst_tmp->content > max)
			max = lst_tmp->content;
		lst_tmp = lst_tmp->next;
		i++;
	}
	return (max);
}

int	find_min_num(t_cd_list *lst, int len)
{
	int			i;
	int			min;
	t_cd_list	*lst_tmp;

	if (!lst)
		exit_message("find_min_num error", 1);
	min = lst->content;
	lst_tmp = lst->next;
	i = 1;
	while (i < len)
	{
		if (lst_tmp->content < min)
			min = lst_tmp->content;
		lst_tmp = lst_tmp->next;
		i++;
	}
	return (min);
}

int	find_prev_num(t_cd_list *lst, int len, int num)
{
	int			prev_num;
	int			i;

	if (!lst)
		exit_message("find_prev_num error", 1);
	prev_num = find_min_num(lst, len);
	i = 0;
	while (i < len)
	{
		if (prev_num < lst->content && lst->content < num)
			prev_num = lst->content;
		lst = lst->next;
		i++;
	}
	return (prev_num);
}

int	find_next_num(t_cd_list *lst, int len, int num)
{
	int			next_num;
	int			i;

	if (!lst)
		exit_message("find_next_num error", 1);
	next_num = find_max_num(lst, len);
	i = 0;
	while (i < len)
	{
		if (num < lst->content && lst->content < next_num)
			next_num = lst->content;
		lst = lst->next;
		i++;
	}
	return (next_num);
}

int	find_half_num(t_cd_list *lst, int len)
{
	int			num;
	int			i;

	if (!lst)
		exit_message("find_half_num error", 1);
	num = find_min_num(lst, len);
	i = 1;
	while (i < len / 2)
	{
		num = find_next_num(lst, len, num);
		i++;
	}
	return (num);
}
