/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimitop <tsimitop@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:18:41 by tsimitop          #+#    #+#             */
/*   Updated: 2024/05/29 15:37:47 by tsimitop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handle_redir(t_shell *shell_info, t_command *cur)
{
	if (cur->input_fd != -1)
	{
		if (shell_info->fd[0] != -1)
			close(shell_info->fd[0]);
		if (dup2(cur->input_fd, STDIN_FILENO) == -1)
		{
			perror("dup2 for input_fd failed");
			exit(EXIT_FAILURE);
		}
		close(cur->input_fd);
	}
	if (cur->output_fd != -1)
	{
		if (shell_info->fd[1] != -1)
			close(shell_info->fd[1]);
		if (dup2(cur->output_fd, STDOUT_FILENO) == -1)
		{
			perror("dup2 for output_fd failed");
			exit(EXIT_FAILURE);
		}
		close(cur->output_fd);
	}
}

void	fork_fail(void)
{
	perror("fork");
	exit (EXIT_FAILURE);
}

void	execute_cmd(t_shell *shell_info, t_command *cmd_to_exec)
{
	char		*full_path;
	char		**paths_in_env;

	if (cmd_to_exec->is_builtin == true)
		execute_builtin(shell_info, cmd_to_exec);
	else
	{
		if (cmd_to_exec->cmd == NULL)
			exit(0);
		paths_in_env = ft_path_in_envmini(shell_info->env_mini);
		full_path = find_cmd_in_env_mini(cmd_to_exec->cmd, paths_in_env);
		if (!full_path || !paths_in_env)
			cmd_error(cmd_to_exec);
		execve(full_path, cmd_to_exec->full_cmd, paths_in_env);
		free(full_path);
		cmd_error(cmd_to_exec);
	}
}
