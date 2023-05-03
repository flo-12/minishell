/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:07:20 by fbecht            #+#    #+#             */
/*   Updated: 2023/04/21 13:07:22 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
//#include "../../includes/minishell_flo.h"

/*
* Print a new line
*/
void	print_newline(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_on_new_line();
}

/*
* Define the behaviour for CTRL+C (SIGINT) and CTR+/ (SIGQUIT)
* in non-interactive mode, meaning minishell is executing the
* commands the user entered.
*	CTRL+C (SIGINT) -> quit process and print "^C" with a \n
*	CTR+/ (SIGQUIT) -> quit process and print "^\Quit (core dumped)"
*						with a \n
* In both cases minishell doesn't have to react to the signals
* (because processes will) and just has to print a newline.
*/
void	signal_non_interactive()
{
	struct sigaction	s_sigact;

	ft_memset(&s_sigact, 0, sizeof(s_sigact));
	s_sigact.sa_handler = print_newline;
	sigaction(SIGINT, &s_sigact, 0);
	sigaction(SIGQUIT, &s_sigact, 0);
}
