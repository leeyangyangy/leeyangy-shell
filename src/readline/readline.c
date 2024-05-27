/**
******************************************************************************
* File Name      : readline.c
* Author         : leeyangy
* E-mail         : liyangyang0713@foxmail.com
* Create         : 2024/5/27 16:44
******************************************************************************
*/

#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "readline.h"

#define LEEYANGY_RL_BUFSIZE 1024
#define LEEYANGY_TOK_BUFSIZE 64
#define LEEYANGY_TOK_DELIM " \t\r\n\a"

/**
 * @brief get character
 * 
*/
char *leeyangy_read_line(void)
{
    int bufsize = LEEYANGY_RL_BUFSIZE;
    int position = 0;
    char *buffer = malloc(sizeof(char) * bufsize);
    int c;

    if (!buffer)
    {
        fprintf(stderr, "leeyangy: allocation error\n");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        // Read a character
        c = getchar();

        // If we hit EOF, replace it with a null character and return.
        if (c == EOF || c == '\n')
        {
            buffer[position] = '\0';
            return buffer;
        }
        else
        {
            buffer[position] = c;
        }
        position++;

        // If we have exceeded the buffer, reallocate.
        if (position >= bufsize)
        {
            bufsize += LEEYANGY_RL_BUFSIZE;
            buffer = realloc(buffer, bufsize);
            if (!buffer)
            {
                fprintf(stderr, "leeyangy: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}

char **leeyangy_split_line(char *line)
{
    int bufsize = LEEYANGY_TOK_BUFSIZE, position = 0;
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token;

    if (!tokens)
    {
        fprintf(stderr, "leeyangy: allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, LEEYANGY_TOK_DELIM);
    while (token != NULL)
    {
        tokens[position] = token;
        position++;

        if (position >= bufsize)
        {
            bufsize += LEEYANGY_TOK_BUFSIZE;
            tokens = realloc(tokens, bufsize * sizeof(char *));
            if (!tokens)
            {
                fprintf(stderr, "leeyangy: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, LEEYANGY_TOK_DELIM);
    }
    tokens[position] = NULL;
    return tokens;
}
