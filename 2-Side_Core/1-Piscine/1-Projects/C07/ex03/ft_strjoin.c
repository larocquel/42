/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 20:52:02 by leoaguia          #+#    #+#             */
/*   Updated: 2024/09/23 22:00:45 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_arraylen(int size, char **strs, char *sep)
{
	int	len;
	int	i;

	if (size == 0)
		return (0);
	len = 0;
	i = 0;
	while (i < size)
		len += ft_strlen(strs[i++]);
	len += (size - 1) * ft_strlen(sep);
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		i;
	int		j;
	int		k;
	int		l;

	result = (char *) malloc(ft_arraylen(size, strs, sep) + 1);
	if (!result)
		return (NULL);
	k = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			result[k++] = strs[i][j++];
		l = 0;
		while (sep[l] && i != size - 1)
			result[k++] = sep[l++];
		i++;
	}
	result[k] = '\0';
	return (result);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*array[] = {"RUN", "RUN", "FIRE"};
	printf("%s\n", ft_strjoin(3, array, "&"));
}
*/
