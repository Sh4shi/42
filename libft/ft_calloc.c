/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:26:03 by sdell-un          #+#    #+#             */
/*   Updated: 2022/01/11 18:46:43 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*calloc(size_t count, size_t size)
{
	void	*r;
	size_t	i;

	r = (void *)malloc(size * count);
	if(!r)
		return (NULL);
	i = 0;
	while(i < count)
	{
		r[i] = 0;
		i++;
	}
	return (r);
}

fdsfsd
