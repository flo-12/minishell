/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:05:33 by mvomiero          #+#    #+#             */
/*   Updated: 2022/12/09 17:06:16 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/* void	f(void *p)
{
	printf("%s\n", p);
}

int main(void)
{

    size_t    i = 0;
    t_list    *lst1 = ft_lstnew("ciao");

    ft_lstadd_back(&lst1, ft_lstnew("oneciaoiaosdofihsod"));
    ft_lstadd_back(&lst1, ft_lstnew("two"));
    ft_lstadd_back(&lst1, ft_lstnew("ciao"));

    t_list    *lst1_lead;
    lst1_lead = lst1;

	ft_lstiter(lst1, &f);

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