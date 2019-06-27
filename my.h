/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** my.h
*/

#ifndef MY_H_
	#define MY_H_

typedef struct opt_s {
    char *cd;
    char *setenv;
    char *unsetenv;
    char *env;
    char *exit;
    char **myenv;
} t_opt;

int     access_error(char *choice);
char    *more_clean(char *str);
int     my_bin_path(char *bin, char **arg, char **env,char *path);
char	**get_tab(char *str, char c);
char    **capt_path(char **env);
char    *my_strcat(char *dest, char *src);
int     my_puterror_spe(char *str);
int     isex(t_opt *opt, char *choice);
int     ex(t_opt *opt, char *choice);
int     cd_home(t_opt *opt);
char    *get_home(t_opt *opt);
char    *my_home(char *dest, char *src);
int     my_putstr_spe(char *str);
char    *cd(char *cmd, char *oldpwd, t_opt *opt);
int     find(char *src, char *tofind);
int     shell(t_opt *opt, char **envi);
char    *my_strcpy(char *dest, char const *src);
void    my_putchar(char n);
int     my_strlen(char const *str);
int     my_putstr(char const *str);
int     my_getnbr(char  const *str);
int     my_strcmp(char const *s1, char const *s2);
char	**str_to_tab(char *str);
char    **get_arg(char *choice);
char    *my_strncpy(char *dest, char *src, int n);
int     my_puterror(char *str);
void    sigsev();
int     command(char *choice, char **env, t_opt *opt);
char    *get_ex(char *choice);
int     my_fork(char *bin, char **arg, char **env);
int     how_many_cmd(char *str);
char    *clean_str(char *str);
int     find_cd(char *src, char *tofind);
void    free_tab(char **cmd);
int     find_home(char *src, char *tofind);

#endif /* !MY_H_ */
