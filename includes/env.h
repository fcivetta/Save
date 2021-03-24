/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcivetta <fcivetta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:58:37 by user42            #+#    #+#             */
/*   Updated: 2021/03/23 15:58:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "minishell.h"
//# include "builtin.h"

typedef struct	s_parent_env {
	char	*home;
	char	*path;
	char	*oldpwd;
	char	*pwd;
	char	*shlvl;
}		t_parent_env;

typedef	struct	s_env {
	char		*var;
	struct s_env	*next;
}		t_env;


t_parent_env	ft_parent_env(void);
t_env		*add_tail(char *var);
t_env		*dup_env(char **envp);
t_env		*add_env_var(char *var);
char		*get_env_var(char *var, t_env *env);


#endif
