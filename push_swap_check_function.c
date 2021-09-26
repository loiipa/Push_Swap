/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_check_function.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:08:34 by cjang             #+#    #+#             */
/*   Updated: 2021/08/19 23:28:01 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_range_of_int(char *str)
{
	int			sign;
	long long	number;

	sign = 1;
	number = 0;
	while (*str == ' ')
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10 + *str - '0';
		if (number * sign < MIN_OF_INT || MAX_OF_INT < number * sign)
			return (0);
		str++;
	}
	while (*str)
	{
		if (*str != ' ')
			return (0);
		str++;
	}
	return (1);
}

int	check_str_num(char *s)
{
	int		i;
	int		num;

	i = 0;
	num = 0;
	while (s[i])
	{
		if (ft_isdigit(s[i]) == 0 && ft_issign(s[i]) == 0 && s[i] != ' ')
			return (0);
		else if (ft_issign(s[i]) == 1 && ft_isdigit(s[i + 1]) == 0)
			return (0);
		else if (ft_isdigit(s[i]) == 1 && ft_issign(s[i + 1]) == 1)
			return (0);
		else if (ft_isdigit(s[i]) == 1 && (s[i + 1] == ' ' || s[i + 1] == '\0'))
			num++;
		if (num < 0)
			exit_message("Number of numbers is Out of int size.", 1);
		i++;
	}
	return (num);
}

int	check_sort(t_cd_list *lst)
{
	int			num;
	t_cd_list	*lst_tmp;

	num = lst->content;
	lst_tmp = lst->next;
	while (lst_tmp != lst)
	{
		if (num > lst_tmp->content)
			return (0);
		num = lst_tmp->content;
		lst_tmp = lst_tmp->next;
	}
	return (1);
}
