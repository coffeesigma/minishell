#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <signal.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <dirent.h>
# include <termios.h>
# include <termcap.h>

# define PROMPT "FASTshell$ "

typedef struct s_cmd
{
	char	*cmd;
	char	**args;
	int		pipe[2];
}	t_cmd;

typedef struct s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_shell
{
	t_env		*env;
	t_cmd		*cmd;
}	t_shell;

// Mandatory functions
void	ft_error(char *str);
void	ft_free(char **str);
void	ft_free_cmd(t_cmd *cmd);
void	ft_free_env(t_env *env);
void	ft_free_shell(t_shell *shell);
void	ft_init_cmd(t_cmd *cmd);
void	ft_init_env(t_env *env);
void	ft_init_shell(t_shell *shell);
void	ft_parse_cmd(t_shell *shell, char *line);
void	ft_parse_env(t_shell *shell, char **env);
void	ft_print_cmd(t_cmd *cmd);
void	ft_print_env(t_env *env);
void	ft_print_shell(t_shell *shell);
void	ft_prompt(void);
void	ft_run_cmd(t_shell *shell);
void	ft_run_pipe(t_shell *shell);
void	ft_run_shell(t_shell *shell);
void	ft_set_env(t_shell *shell, char *name, char *value);
void	ft_unset_env(t_shell *shell, char *name);

#endif