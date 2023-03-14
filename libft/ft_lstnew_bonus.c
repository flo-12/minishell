/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:26:07 by mvomiero          #+#    #+#             */
/*   Updated: 2022/12/09 17:26:22 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* typedef	struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list; */

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

/* 
So basically you create the new node.
Then you set malloc for it. the type will be the (t_list *), the size what is 
inside t_list (you use the (*new_node) notation), because it will be the size 
of the two pointers contained inside the t_list.
then you just set the content = content,
and the next = to NULL...because it is the last element of the linked list!
 */

/* 

here the main to test it. Quite easy: you declare two nodes, you assign the valu
es and then you link the two addresses.

int main ()
{
	t_list	*node1;
	t_list	*node2;

	node1 = ft_lstnew(ft_strdup("ciao"));
	node2 = ft_lstnew("mondo");
	node1->next = node2;
	printf("content: %s\nnext: %s", node1->content, node2->content);
	return (0);
} */