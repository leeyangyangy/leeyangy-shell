/**
******************************************************************************
* File Name      : command.c
* Author         : leeyangy
* E-mail         : liyangyang0713@foxmail.com
* Create         : 2024/5/27 16:44
******************************************************************************
*/

#define WUNTRACED 2

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>

#include "command.h"
// #include "shell_linker.h"

int leeyangy_launch(char **args)
{
    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == 0)
    {
        // Child process
        if (execvp(args[0], args) == -1)
        {
            perror("leeyangy");
        }
        exit(EXIT_FAILURE);
    }
    else if (pid < 0)
    {
        // Error forking
        perror("leeyangy");
    }
    else
    {
        // Parent process
        do
        {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}

/*
  List of builtin commands, followed by their corresponding functions.
 */
char *builtin_str[] = {
    "cd",
    "help",
    "exit"};

int (*builtin_func[])(char **) = {
    &leeyangy_cd,
    &leeyangy_help,
    &leeyangy_exit};

int leeyangy_num_builtins()
{
    return sizeof(builtin_str) / sizeof(char *);
}

/*
  Builtin function implementations.
*/
int leeyangy_cd(char **args)
{
    if (args[1] == NULL)
    {
        fprintf(stderr, "leeyangy: expected argument to \"cd\"\n");
    }
    else
    {
        if (chdir(args[1]) != 0)
        {
            perror("leeyangy");
        }
    }
    return 1;
}

int leeyangy_help(char **args)
{
    int i;
    printf("Author LEEYANGY🙂\n");
    printf("Type program names and arguments, and hit enter.\n");
    printf("The following are built in:\n");

    for (i = 0; i < leeyangy_num_builtins(); i++)
    {
        printf("  %s\n", builtin_str[i]);
    }

    printf("Use the man command for information on other programs.\n");
    return 1;
}

int leeyangy_exit(char **args)
{
    return 0;
}

int leeyangy_execute(char **args)
{
    int i;

    if (args[0] == NULL)
    {
        // An empty command was entered.
        return 1;
    }

    for (i = 0; i < leeyangy_num_builtins(); i++)
    {
        if (strcmp(args[0], builtin_str[i]) == 0)
        {
            return (*builtin_func[i])(args);
        }
    }

    return leeyangy_launch(args);
}
