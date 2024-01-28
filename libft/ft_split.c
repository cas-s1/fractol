/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:41:50 by co-neill          #+#    #+#             */
/*   Updated: 2023/04/29 17:13:37 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_all(char **array, int i)
{
	while (i >= 0)
	{
		free(array[i]);
		i--;
	}
	free(array);
}

static int	count_words(const char *s, char c)
{
	int	num_words;

	num_words = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			num_words++;
		while (*s && *s != c)
			s++;
	}
	return (num_words);
}

static int	count_word_length(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static char	**allocate_words(char **array, const char *s, char c)
{
	int	length;
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == c)
		{
			s++;
			continue ;
		}
		length = count_word_length(s, c);
		array[i] = (char *) malloc((length + 1) * sizeof(char));
		if (!array[i])
		{
			free_all(array, i);
			return (0);
		}
		ft_strlcpy(array[i], s, length + 1);
		s += length;
		i++;
	}
	array[i] = 0;
	return (array);
}

char	**ft_split(const char *s, char c)
{
	char	**array;
	int		num_words;

	num_words = count_words(s, c);
	array = (char **) malloc((num_words + 1) * sizeof(char *));
	if (!array)
		return (0);
	array = allocate_words(array, s, c);
	return (array);
}
