/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 13:08:55 by mugurel           #+#    #+#             */
/*   Updated: 2022/10/24 16:22:37 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_baserror(char *base, int *erreur)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (base[0] == '\0' || base[1] == '\0')
		*erreur = 1;
	while (base[i] && *erreur == 0)
	{
		j = i;
		while (base[j] != '\0')
		{
			j++;
			if (base[i] == base[j])
				*erreur = 1;
		}
		if (base[i] == '+' || base[i] == '-' || base[i] == '%'
			|| base[i] == '/' || base[i] == '*' || base[i] == '='
			|| base[i] == ',' || base[i] == '.'
			|| base[i] < 33 || base[i] > 126)
			*erreur = 1;
		else
			i++;
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	erreur;
	int	basel;
	int	n;

	n = nbr;
	basel = 0;
	erreur = 0;
	ft_baserror(base, &erreur);
	if (erreur == 0)
	{
		if (n < 0)
		{
			ft_putchar('-');
			n *= -1;
		}
		while (base[basel] != '\0')
			basel++;
		if (nbr >= basel)
		{
			ft_putnbr_base(n / basel, base);
			ft_putnbr_base(n % basel, base);
		}
		else
			ft_putchar(base[n]);
	}
}
