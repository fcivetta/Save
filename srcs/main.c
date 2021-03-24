/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcivetta <fcivetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 13:41:53 by mciupek           #+#    #+#             */
/*   Updated: 2021/03/24 17:00:38 by fcivetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	exec_cmd(char **cmd, char **env)
{
	pid_t	pid;
	int		status;

	status = 0;
	pid = fork();
	if (pid == -1)
		error(FRK_ERR);
	else if (pid > 0)
    {
		waitpid(pid, &status, 0);
		kill(pid, SIGTERM);
	}
    else
    {
		if (execve(cmd[0], cmd, env) == -1)
			error(SHL_ERR);
		exit(EXIT_FAILURE); //Pb exit ?
	}
	return (0);
}

static int	get_path(char **cmd,char **env)
{
	char	*path;
	char	*bin;
	char	**path_split;
	int		i;

//	path = ft_strdup(getenv("PATH"));
//	if (!path)
//		path = ft_strdup("/bin:/usr/local/bin:/usr/bin:/bin:/usr/local/sbin");
	path = NULL;
	if (cmd[0][0] != '/' && ft_strncmp(cmd[0], "./", 2) != 0)
	{
		i = 0;
		while (env[i])
		{
			if (!strncmp(env[i], "PATH=", 5))
			{
				path = ft_strdup(&env[i][5]);
				break;
			}
			i++;
		}
		if (path == NULL)
			error(PATH_ERR);
		path_split = ft_split(path, ':');
		free(path);
		path = NULL;
		i = 0;
		while (path_split[i])
		{
			bin = (char *)ft_calloc(sizeof(char), (ft_strlen(path_split[i]) + ft_strlen(cmd[0]) + 2));
			if (!bin)
				break ;
			ft_strcat(bin, path_split[i]);
			ft_strcat(bin, "/");
			ft_strcat(bin, cmd[0]);
			if (!access(bin, F_OK))
				break ;
			free(bin);
			i++;
		}
		free_array(path_split);
		free(cmd[0]);
		cmd[0] = bin;
	}
	else
	{
		free(path);
		path = NULL;
	}
	return( bin == NULL ? 0 : 1);
}

int	main(int argc, char **argv, char **envp)
{
    char	*line;
    //t_cmds	cmds;
    char	**cmd;
    t_list	*cmds;
    char	**tab_env;
	t_env	env;
    int		ret;
    
    env = dup_env(envp);
    write(1, "$> ", 3);
	ret = get_next_line(0, &line);
    while (ret > 0) 
    {
		ret = 0;
		cmds = NULL;
		parse_cmd(line, &cmds);
		while (cmds)
		{
			cmd = (char **)cmds->content;
/*








*/
		if (is_built_in(cmd[0]))
			exec_built_in(cmd, env)
		else




			if (cmd[0]) //Pas de message si cmd[0] du coup
			{
				get_path(cmd);
				if (!is_built_in(cmd[0]))
					ret = exec_cmd(cmd);
				else
					exec_built_in(cmd, env);
			}
			if (!ret)
				free_array(cmd);
			cmds = cmds->next;
		}
		free(line);
		write(1, "$> ", 3);
		ret = get_next_line(0, &line);
	}
	if (ret < 0)
		error(RD_ERR);
    free(line);
    return (0);
}
