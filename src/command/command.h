/**
******************************************************************************
* File Name      : command.h
* Author         : leeyangy
* E-mail         : liyangyang0713@foxmail.com
* Create         : 2024/5/27 16:45
******************************************************************************
*/

#ifndef MYSHELL_COMMAND_H
#define MYSHELL_COMMAND_H

/*
  Function Declarations for builtin shell commands:
 */
int leeyangy_cd(char **args);
int leeyangy_help(char **args);
int leeyangy_exit(char **args);

int leeyangy_execute(char **args);
// int leeyangy_launch(char **args);

#endif //MYSHELL_COMMAND_H

