/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 20:28:44 by sdell-un          #+#    #+#             */
/*   Updated: 2022/01/11 20:50:27 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
	int lens1;
	int lens2;
	int lenews;
	char *news;
	int i;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	lenews = (lens1 - 1) + lens2;
	news = (char *)malloc(lenews);
	i = 0;

}