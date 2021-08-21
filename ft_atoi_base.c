/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araramya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 11:11:05 by araramya          #+#    #+#             */
/*   Updated: 2020/12/10 12:34:17 by araramya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int		get_order_in_base(char c, char *base)
{
	int order;

	order = 0;
	while (base[order] && base[order] != c)
		order++;
	if (order >= ft_strlen(base))
		return (-1);
	return (order);
}

int		ft_is_space(char c)
{
	if (c == '\n' || c == '\t' || c == '\v'
		|| c == '\r' || c == '\f' || c == ' ')
		return (1);
	return (0);
}

int		base_check_syntax(char *base)
{
	int i;
	int j;

	if (ft_strlen(base) <= 1)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] < 32 || base[i] > 127 || ft_is_space(base[i]) ||
			base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_atoi_base(char *str, char *base)
{
	int i;
	int len;
	int sign;
	int result;

	i = 0;
	sign = 1;
	result = 0;
	if (!base_check_syntax(base))
		return (0);
	len = ft_strlen(base);
	while (ft_is_space(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (get_order_in_base(str[i], base) >= 0)
	{
		result = result * len + get_order_in_base(str[i], base);
		i++;
	}
	return (result * sign);
}

// int main()
// {
// 	printf("%c\n", ft_atoi_base("01011001", "01"));
// }