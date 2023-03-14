/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:10:41 by mvomiero          #+#    #+#             */
/*   Updated: 2022/12/09 17:11:12 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	*lst = NULL;
}

/* 

// HERE THE FUNCTION EXPLAINED

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (!lst || !del)
		return;
	while (*lst)
	{
		// SO HERE I JUST STORE THE NEXT ADRESS OF LST IN A TEMPORARY VARIABLE
		temp = (*lst)->next;
		// HERE I JUST FREE WHAT IS CURRENTLY AT LST WITH FUNCTION DEL
		ft_lstdelone(*lst, del);
		// I HAVE DELETED LST, NOW I SET LST = TEMP (remember, it is the follo
		//wing address) --> so like that I keep going on and deleting
		*lst = temp;
	}
	*lst = NULL;
} */

/* 

The main used to test it.

void	del(void *p)
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

    lst1_lead = lst1;

	//Ok so we break it at lis1->next->next so it will print just the first two 
	
	ft_lstclear(&(lst1->next->next), del);

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