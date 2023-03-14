/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:25:37 by mvomiero          #+#    #+#             */
/*   Updated: 2022/12/09 17:25:50 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

/* 
// Always the same main I use to test linked lists
int main(void)
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

	//Is not changing the value if I put node 0 or node3...why?

	printf("\n	SIZE\n	%d\n", ft_lstsize(node0));
	printf("\n	Last\n	%s\n", (ft_lstlast(node0))->content);
} */