/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_linked_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 12:47:52 by cjang             #+#    #+#             */
/*   Updated: 2021/08/19 22:41:41 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cd_list	*ft_cdlst_new(int content)
{
	t_cd_list	*new_list;

	new_list = (t_cd_list *)malloc(sizeof(t_cd_list));
	if (!new_list)
		return (NULL);
	new_list->content = content;
	new_list->prev = NULL;
	new_list->next = NULL;
	return (new_list);
}

void	ft_cdlst_del_all(t_cd_list **lst)
{
	if (!(*lst))
		return ;
	(*lst)->prev->next = NULL;
	while ((*lst)->next != NULL)
	{
		*lst = (*lst)->next;
		free((*lst)->prev);
	}
	free(*lst);
}

void	ft_cdlst_add(t_cd_list **lst, t_cd_list *new)
{
	if (!(*lst))
	{
		new->prev = new;
		new->next = new;
		*lst = new;
	}
	else
	{
		new->prev = (*lst)->prev;
		new->next = *lst;
		*lst = new;
		(*lst)->prev->next = *lst;
		(*lst)->next->prev = *lst;
	}
}

t_cd_list	*ft_cdlist_cuttop(t_cd_list **lst)
{
	t_cd_list	*old_top;

	if (!(*lst))
		return (NULL);
	old_top = *lst;
	if ((*lst)->next == *lst)
	{
		*lst = NULL;
		return (old_top);
	}
	else
	{
		(*lst)->prev->next = (*lst)->next;
		(*lst)->next->prev = (*lst)->prev;
		*lst = (*lst)->next;
		return (old_top);
	}
}

int	ft_cdlist_len(t_cd_list *lst)
{
	t_cd_list	*lst_cmp;
	int			len;

	if (!(lst))
		return (0);
	lst_cmp = lst->next;
	len = 1;
	while (lst != lst_cmp)
	{
		lst_cmp = lst_cmp->next;
		len++;
	}
	return (len);
}
