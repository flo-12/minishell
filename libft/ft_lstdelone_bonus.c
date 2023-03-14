/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:07:02 by mvomiero          #+#    #+#             */
/*   Updated: 2022/12/09 17:07:19 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	else
	{
		del(lst->content);
		free(lst);
	}
}

/* 
if there are no lst or del, of course you just return.
Otherwise, you apply del to the content, and free then lst.
 */

/* void	del(void *p)
{
	(void)p;
}

int main(void)
{

    size_t    i = 0;
    t_list    *lst1 = ft_lstnew(ft_strdup("ciao"));

    ft_lstadd_back(&lst1, ft_lstnew("One"));
    ft_lstadd_back(&lst1, ft_lstnew("Two"));
    ft_lstadd_back(&lst1, ft_lstnew(""));

    t_list    *lst1_lead;

	// Sp you first have to set the lead to lst1->next->next, beacuse you are 
	//deleting lst1->next so since that number it isnt gonna work. So from the
	// output you see you get printed just the last two nodes.
    lst1_lead = lst1->next->next;

	ft_lstdelone(lst1->next, del);

    printf("\nft_lstsize(lst1) = [%d]\n", ft_lstsize(lst1_lead));
    printf("----- lst1->content -----\n");
    while(lst1_lead != NULL)
    {
        printf("[%zu] = [%s]\n", i, (char *)lst1_lead->content);
        lst1_lead = lst1_lead->next;
        i += 1;
    }
    printf("-----   lst1  end   -----\n\n");
} */

/* 
//This is another main to check that even if you cut one node it cant go on.

int main(void)
{

    size_t    i = 0;
    t_list    *lst1 = ft_lstnew(ft_strdup("ciao"));

    ft_lstadd_back(&lst1, ft_lstnew("One"));
    ft_lstadd_back(&lst1, ft_lstnew("Two"));
    ft_lstadd_back(&lst1, ft_lstnew(""));

    t_list    *lst1_lead;
    lst1_lead = lst1;
	ft_lstdelone(lst1->next, del);
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