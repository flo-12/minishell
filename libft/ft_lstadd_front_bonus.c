/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:24:25 by mvomiero          #+#    #+#             */
/*   Updated: 2022/12/09 17:24:41 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* typedef	struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list; */

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/* 
So few code but a logic to understand. 
--- From the definition: lst: The address of a pointer to the first link of
a list. new: The address of a pointer to the node to be
added to the list.
process: firts you set the next ot the new to what is pointing lst, wich is
the actual first norde (t_list)of the list. Then you set what is pointing lst 
to the new node created. This way, the first norde is now new.

 */

/* 

// OMG that was such a looong work. But it works. and I quite understood 
//linked lists (I hope).

// Another even better main is in ft_lstsize.c

int main()
{
	t_list **node;
	t_list *node_00;
	t_list *node0 = ft_lstnew("hello");
	// just to check that the pointer next is NULL
	printf("%p\n", node0->next);
	t_list *node1 = ft_lstnew("mj");
	t_list *node2 = ft_lstnew("maroc");
	t_list *node3 = ft_lstnew("marcolino");

	node = &node0;
	ft_lstadd_front(node, node0);
	//so after the function, the pointer next is not 0 anymore
	//(dont know why)
	printf("node 0 -> next  %p\n", node0->next);
	//Ok so I reset it to null, because if not I don't have the finishing 
	//of my linked list anymore
	//I was trying to do that even under, but wasnt working. Keine Ahnung.
	node0->next = NULL;
	printf("node 0 -> next (we reset it)  %p\n", node0->next);
	//Successfully to print it

	//Ok I add some others nodes.
	ft_lstadd_front(node, node1);
	ft_lstadd_front(node, node2);
	ft_lstadd_front(node, node3);

	//all this under was just to set one next to NULL...
	//In order to be able to do the loop to prin it

	//This one works as well....why? ahahh
	//node0->next->next->next->next = NULL;

	// this works to set the NULL terminator.
	//node3->next->next->next->next = NULL;
	
	//This doesent work...why?
	//node0->next = 0;
	

	//just regular printing, versione della nonna
	printf("%s\n", node3->content);
	printf("%s\n", node3->next->content);
	printf("%s\n", node3->next->next->content);
	printf("%s\n", node3->next->next->next->content);
	printf("%p\n", node3->next->next->next->next);

	//for loop to print....GEIL!

	for (t_list *curr = node0; curr != NULL; curr = curr->next)
	{
		printf("yeeee%s\n", curr->content);
		printf("%p\n", curr->next);
	}
	return (0);
} */