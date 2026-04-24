/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoaguia <leoaguia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:27:45 by leoaguia          #+#    #+#             */
/*   Updated: 2024/11/12 16:43:02 by leoaguia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_splitfree(char **arr, int j)
{
	int	i;

	i = 0;
	while (i <= j)
		free(arr[i++]);
	free(arr);
	return (NULL);
}

static	int	ft_wordlen(char const *s, char c, int start)
{
	int	len;

	len = 0;
	while (s[start] && s[start] != c)
	{
		start++;
		len++;
	}
	return (len);
}

static	char	*ft_wordcopy(char const *s, char c, int start)
{
	char	*word;
	int		len;
	int		i;

	i = 0;
	len = ft_wordlen(s, c, start);
	word = malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (s[start] != c && s[start])
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

static	int	ft_wordcount(char const *s, char c)
{
	int	words;

	words = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			words++;
		while (*s && *s != c)
			s++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;

	arr = (char **) malloc((ft_wordcount(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			arr[j] = ft_wordcopy(s, c, i++);
			if (!arr[j])
				return (ft_splitfree(arr, j));
			j++;
		}
		while (s[i] != c && s[i])
			i++;
	}
	arr[j] = NULL;
	return (arr);
}
/*
#include <stdio.h>

int	main(void)
{
	char	**dest = ft_split("Hello, World!", ' ');
	int		i = 0;
	while(dest[i])
		printf("%s\n", dest[i++]);
	i = 0;
	while(dest[i])
		free(dest[i++]);
	free(dest);
}
*/
