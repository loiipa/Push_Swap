/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_common_function.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 23:47:50 by cjang             #+#    #+#             */
/*   Updated: 2021/08/25 13:37:15 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_number(t_cd_list **lst, char *str)
{
	int			num;
	t_cd_list	*lst_tmp;

	num = ft_atoi(str);
	lst_tmp = ft_cdlst_new(num);
	if (!lst_tmp)
		exit_message("malloc fail", 1);
	ft_cdlst_add(lst, lst_tmp);
	lst_tmp = (*lst)->next;
	while (lst_tmp != *lst)
	{
		if (lst_tmp->content == (*lst)->content)
			exit_message("Error", 1);
		lst_tmp = lst_tmp->next;
	}
	*lst = (*lst)->next;
}

static void	argv_to_split(t_cd_list **lst_a, char *str)
{
	int		i;
	char	**book;

	i = 0;
	book = ft_split(str, ' ');
	if (book == NULL)
		exit_message("malloc fail", 1);
	while (book[i])
	{
		if (is_range_of_int(book[i]) == 1)
			add_number(lst_a, book[i]);
		else
			exit_message("Error", 1);
		i++;
	}
	free_book(book, i);
}

void	make_stack(int argc, char **argv, t_cd_list **lst_a)
{
	int		i;

	i = 0;
	while (++i < argc)
	{
		if (check_str_num(argv[i]) > 1)
			argv_to_split(lst_a, argv[i]);
		else if (check_str_num(argv[i]) == 1)
		{
			if (is_range_of_int(argv[i]) == 1)
				add_number(lst_a, argv[i]);
			else
				exit_message("Error", 1);
		}
		else
			exit_message("Error", 1);
	}
}
