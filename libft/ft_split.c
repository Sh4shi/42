/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 01:54:13 by sdell-un          #+#    #+#             */
/*   Updated: 2022/01/14 16:25:31 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ptr_word(char *s, char c, int i)
{
	while (i > 0 && *s != c)
		i--;
	if (*s == c)
		return (*s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int	i; /* indice per s */
	int	count; /* conta quante parole ci sono (lunghezza per malloc) */
	char *matrix;
	char *word; /* trova la parola */
	int	lenw;
	int	index;

	i = 0;
	count = 2; /* 1 per il null + 1 parola compresa */
	if (!s)
		return (NULL);
	while(s[i]) /* conta numero parole */
	{
		if (s[i] == c)
			count++;
		i++;
	}
	matrix = (char *)malloc(count); /* malloc per tot parole */
	if (!matrix)
		return (NULL);
	index = 0;
	while (count > 0) /* finche non alloca tutte le parole */
	{
		i = i - lenw; /**********************************************teoricamente passa alla parola precedente/successiva di matrix*/
		while (matrix[index] != '\0')
		{
			word = ptr_word(&(s[i]), c, i); /* trova l'inizio della parola (e' un puntatore al puntatore di s*/
			lenw = i - (ft_strlen(word)); /* lunghezza della parola */
			matrix[index] = word; /* assegno la parola alla matrice */
			index++;
			count--;
		}
	}
}
