/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-un <sdell-un@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 00:13:54 by sdell-un          #+#    #+#             */
/*   Updated: 2022/01/19 05:59:24 by sdell-un         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nwlist;
	t_list	*firstnode;
	int		i;

	if (!lst || !f || !del)
		return (NULL);
	i = 0;
	while (!lst)
	{
		while (lst->content)
		{
			nwlist = ft_lstnew(f(lst->content));
			if (!nwlist)
			{
				ft_lstclear(&lst, del);
				ft_lstclear(&nwlist, del);
				return (NULL);
			}
			if (i++ == 1)
				firstnode = nwlist;
		}
		lst = lst->next;
	}
	return (firstnode);
}
