/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:26:45 by mvomiero          #+#    #+#             */
/*   Updated: 2022/12/09 17:26:57 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

/* int main(void)
{
	char **array = ft_split ("ciao marco come stai", ' ');

	t_list *node0;

	ft_lstadd_front(&node0, ft_lstnew(array[3]));
	printf("%s\n", node0->content);
	node0->next = NULL;

	t_list *node1 = ft_lstnew(array[2]);
	ft_lstadd_front(&node0, node1);
	printf("%s\n", node1->content);

	t_list *node2 = ft_lstnew(array[1]);
	ft_lstadd_front(&node0, node2);
	printf("%s\n", node2->content);

	t_list *node3 = ft_lstnew(array[0]);
	ft_lstadd_front(&node0, node3);
	printf("%s\n", node3->content);



	for (t_list *curr = node3; curr != NULL; curr = curr->next)
	{
		printf("yeeee %s\n", curr->content);
		printf("%p\n", curr->next);
	}

	printf("\n	SIZE\n	%d\n", ft_lstsize(node3));
} */