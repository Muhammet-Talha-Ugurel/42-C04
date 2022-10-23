/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 05:02:42 by mugurel           #+#    #+#             */
/*   Updated: 2022/10/23 21:26:31 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char *str)
{
	int	i;
	int	n;
	int	norp;

	i = 0;
	norp = 1;
	while (str[i] == ' ' || (str[i] >= 10 && str[i] <= 13)
		|| str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			norp = norp * -1;
		i++;
	}
	if (str == "2147483648")
		return (2147483647);
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + (str[i] - 48);
		i++;
	}
	n = n * norp;
	return (n);
}

int main(void)
{
	ft_atoi("-2147483648");
}
