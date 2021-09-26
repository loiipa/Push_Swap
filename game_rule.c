/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rule.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 12:32:53 by cjang             #+#    #+#             */
/*   Updated: 2021/08/20 19:42:06 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_cd_list **lst)
{
	if (!(*lst) || (*lst)->next == *lst)
		return ;
	(*lst)->prev->next = (*lst)->next;
	(*lst)->next->prev = (*lst)->prev;
	(*lst)->prev = (*lst)->next;
	(*lst)->next = (*lst)->next->next;
	(*lst)->prev->next = *lst;
	(*lst)->next->prev = *lst;
	*lst = (*lst)->prev;
}

void	ft_push(t_cd_list **lst_1, t_cd_list **lst_2)
{
	t_cd_list	*lst_move;

	if (!(*lst_1))
		return ;
	lst_move = ft_cdlist_cuttop(lst_1);
	ft_cdlst_add(lst_2, lst_move);
}

void	ft_rotate(t_cd_list **lst, char *s)
{
	if (!(*lst))
		return ;
	if (ft_strcmp("next", s) == 0)
		*lst = (*lst)->next;
	else if (ft_strcmp("prev", s) == 0)
		*lst = (*lst)->prev;
}
