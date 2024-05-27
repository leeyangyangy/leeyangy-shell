/**
******************************************************************************
* File Name      : leeyangy_shell.c
* Author         : leeyangy
* E-mail         : liyangyang0713@foxmail.com
* Create         : 2024/5/26 2:06
******************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>

#include "constant/init.h"
#include "config/shell_config.h"
#include "io/io.h"
#include "command/command.h"
#include "readline/readline.h"

void leeyangy_shell_loop(void)
{

    char *line;
    char **args;
    int status;

    do
    {
        // 进入等待用户输入信息
        printf("%s", CONFIG_SHELL_PROMPT);
        line = leeyangy_read_line();
        args = leeyangy_split_line(line);
        status = leeyangy_execute(args);

        // 释放内存
        free(line);
        free(args);
    } while (status);
}

int main(int argc, char **argv)
{

    // 初始化信息
    puts(init_info);
    leeyangy_shell_loop();

    // need include <stdlib.h> ?
    return EXIT_SUCCESS;
}
