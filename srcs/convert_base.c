/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:43:00 by yobougre          #+#    #+#             */
/*   Updated: 2022/04/01 19:05:19 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_header.h"

int	ft_atoi_base(char *str, char *base)
{
	int	output;
	int	i;
	int	nega;

	nega = 1;
	output = 0;
	i = 0;
	if (ft_check(base) == 0)
		return (0);
	while ((str[i] >= 7 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			nega *= -1;
		i++;
	}
	while (check_nbr(str[i], base))
	{
		if (check_nbr(str[i], base))
			output = output * ft_check(base) + find_in_base(str[i], base);
		i++;
	}
	return (output * nega);
}

void	output_size(int nb, int *size, char *base)
{
	if (nb < 0)
	{
		*size += 1;
		output_size((nb * -1), size, base);
	}
	else if (nb < ft_check(base) && nb >= 0)
		*size += 1;
	else
	{
		output_size(nb / ft_check(base), size, base);
		output_size(nb % ft_check(base), size, base);
	}
}

char	*ft_itoa_base(int nb, char *base, int m_size, char *output)
{
	long	nbr;
	long	i;
	int		j;

	i = ft_check(base);
	nbr = nb;
	j = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		output[0] = '-';
		j = 1;
	}
	output[m_size] = '\0';
	m_size--;
	while (j <= m_size)
	{
		output[m_size] = base[nbr % i];
		nbr = nbr / i;
		m_size--;
	}
	return (output);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*output;
	int		size;

	size = 0;
	if (ft_check(base_from) == 0 || ft_check(base_to) == 0)
		return (NULL);
	output_size(ft_atoi_base(nbr, base_from), &size, base_to);
	output = malloc(sizeof(char) * size + 1);
	if (!(output))
	{
		output = NULL;
		return (output);
	}
	output = ft_itoa_base(ft_atoi_base(nbr, base_from), base_to, size, output);
	return (output);
}
