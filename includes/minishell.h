/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcivetta <fcivetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 13:48:09 by mciupek           #+#    #+#             */
/*   Updated: 2021/03/24 13:53:36 by fcivetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <signal.h>

# ifdef LINUX
#  include <linux/limits.h> 
# endif

# include "../libft/libft.h"
# include "parsing.h"
# include "utils.h"
# include "env.h"
# include "builtin.h"
# include "error.h"


# define PATH_MAX 4096
# define FD_SIZE 256
# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0
# define true 1
# define false 0

typedef struct  s_cmd
{
	int		nb_arg;
	int		max_arg;
	char	**cmd;
}				t_cmd;

typedef struct  t_cmds
{
    int		n_cmd;
    int		max_cmd;
    t_list	cmds;
    char	*out;
    char	*in;
    char	*err;
    int		background;
}				t_cmds;


#endif
