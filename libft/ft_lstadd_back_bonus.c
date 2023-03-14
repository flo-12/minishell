/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:24:59 by mvomiero          #+#    #+#             */
/*   Updated: 2022/12/12 11:08:47 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*node;

	node = *alst;
	if (alst && *alst)
	{
		while (node -> next)
		{
			node = node -> next;
		}
		node -> next = new;
	}
	else
		*alst = new;
}

/* 
if exists lst and if there is something already there, you just go to the last 
element with the function (ft_lstlast), and you just set the next linker of this
last element = to the new element.
If lst is empty, you just fill it with new (else statement)
 */

/* int main(void)
{

    size_t    i = 0;
    t_list    *lst1 = ft_lstnew("ciao");

    ft_lstadd_back(&lst1, ft_lstnew("One"));
    ft_lstadd_back(&lst1, ft_lstnew("Two"));
    ft_lstadd_back(&lst1, ft_lstnew(""));

    t_list    *lst1_lead;
    lst1_lead = lst1;
    printf("\nft_lstsize(lst1) = [%d]\n", ft_lstsize(lst1));
    printf("----- lst1->content -----\n");
    while(lst1 != NULL)
    {
        printf("[%zu] = [%s]\n", i, (char *)lst1->content);
        lst1 = lst1->next;
        i += 1;
    }
    printf("-----   lst1  end   -----\n\n");
} */
