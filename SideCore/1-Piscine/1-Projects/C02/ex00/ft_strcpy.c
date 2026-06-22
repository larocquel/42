/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:19:47 by leoaguia          #+#    #+#             */
/*   Updated: 2024/09/12 21:02:04 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
#include <unistd.h>
#include <string.h>

int	main(void)
{
	char	source[] = "42 rocks!";
	int		size = strlen(source);
	char	destine[size];
	
	ft_strcpy(destine, source);
	write(1, destine, size);
}
*/
