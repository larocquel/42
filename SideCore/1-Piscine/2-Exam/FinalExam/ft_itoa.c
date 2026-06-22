/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:25:16 by leoaguia          #+#    #+#             */
/*   Updated: 2024/10/05 11:05:17 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_itoa(int nbr);

int	main(void)
{
	int	n = 123;
	char *string;

	string = ft_itoa(n);
	printf("n: %i\nstring: %s\n", n, string);
	free(string);
}

char	*ft_itoa(int nbr)
{
	char	*srv;		// String com os nums na ordem reversa
	char	*str;		// String com os nums na ordem normal
	long	n = nbr;	// Conversao de int para long a fim de lidar com os limites
	long	temp = nbr;	// Usado p medir o size do numero
	int		size = 1;	// Tamanho do numero
	int		neg = 0;	// Indicador de negativo: 0 = positivo, 1 = negativo
	int		i;
	int		j;
	int		last;

	// Lidar com os sinal e calcular o size do numero.
	while(temp > 9 || temp < 0)
	{
		if (temp < 0)	// Se for negativo, eu converto todos para positivo
		{
			temp = -temp;
			n = -n;
			size++;
			neg = 1;
		}
		temp = temp / 10;
		size++;
	}

	// Alocar memoria para as duas strings, a normal e a reversa.
	srv = malloc(sizeof(char) * size + 1);
	if (!srv)
		return (NULL);
	str = malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);

	// Preencher a string reversa com os numeros e lidando com o sinal
	if (neg == 1)
		srv[size - 1] = '-';
	i = 0;
	while(n > 9)
	{
		srv[i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}
	srv[i] = n + '0';
	srv[size] = '\0';

	// Prencher a string na ordem normal a partir da reversa
	j = 0;
	last = size - 1;
	while(last >= 0)
	{
		str[j] = srv[last];
		j++;
		last--;
	}
	str[j] = '\0';
	return (str);
}
