/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_interactive.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:31:33 by fbecht            #+#    #+#             */
/*   Updated: 2023/04/21 17:31:37 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
//#include "../../includes/minishell_flo.h"

/*
* Ignore the SIGQUIT signal.
*/
void	ignore_sigquit(void)
{
	struct sigaction	s_sigact;

	ft_memset(&s_sigact, 0, sizeof(s_sigact));
	s_sigact.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &s_sigact, 0);
}

/*
* Reset the user input prompt to a new blank line
*/
void	reset_prompt(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

/*
* Define the behaviour for CTRL+C (SIGINT) and CTR+/ (SIGQUIT)
* in interactive mode, meaning minishell is awaiting user
* input (user can enter commands).
*	CTRL+C (SIGINT) -> reset user input (with "^C" at end of
						line - with a \n) to a new blank line
*	CTR+/ (SIGQUIT) -> do nothing / ignore signal
*/
void	signal_interactive(void)
{
	struct sigaction	s_sigact;

	ignore_sigquit();
	ft_memset(&s_sigact, 0, sizeof(s_sigact));
	s_sigact.sa_handler = reset_prompt;
	sigaction(SIGINT, &s_sigact, 0);
}
