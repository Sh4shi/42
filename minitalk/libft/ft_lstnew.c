J/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:57:24 by sdell-un          #+#    #+#             */
/*   Updated: 2022/01/18 22:05:45 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nnode;	

	nnode = malloc(sizeof(*nnode));
	if (!nnode)
		return (NULL);
	nnode->content = content;
	nnode->next = NULL;
	return (nnode);
}
