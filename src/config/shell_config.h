/**
******************************************************************************  
* File Name      : shell_config.h  
* Author         : leeyangy  
* E-mail         : liyangyang0713@foxmail.com  
* Create         : 2024/5/27 16:41  
******************************************************************************  
*/
#include <wchar.h>

#ifndef MYSHELL_SHELL_CONFIG_H
#define MYSHELL_SHELL_CONFIG_H

/******************************* readline configuration ****************************/

/* command line input buffer size(byte) */
#define CONFIG_SHELL_INPUT_BUFFSIZE (127U)

/* set 1 to enable command line edit */
#define CONFIG_SHELL_LINE_EDITING 1

/* ESC Control Sequence detect, such as Home, Delete, Arrow, etc. */
#define CONFIG_SHELL_KEY_SEQ_BIND 1

/* set 1 to enable Backslash('\') for line continuation */
#define CONFIG_SHELL_MULTI_LINE 1


/**
 * set 0 to disable history record.
 *
 * nano-shell will take `CONFIG_SHELL_HIST_MIN_RECORD*(2+CONFIG_SHELL_INPUT_BUFFSIZE)` bytes to
 *   record **at least** `CONFIG_SHELL_HIST_MIN_RECORD` histroys.
 * the maximum number of history records depends on the average length of the input.
 */
#define CONFIG_SHELL_HIST_MIN_RECORD (5U)


/******************************* command configuration ****************************/

#define CONFIG_SHELL_FUNC_BRIEF_USAGE 1

#define CONFIG_SHELL_CMD_BRIEF_USAGE  1

#define CONFIG_SHELL_CMD_LONG_HELP 1

/* nano-shell provides a built-in help command, set 0 to disable it */
#define CONFIG_SHELL_CMD_BUILTIN_HELP 1

/* config the max number of arguments, must be no less than 1. */
#define CONFIG_SHELL_CMD_MAX_ARGC (10U)


/******************************* shell io configuration ****************************/

/* config the buffer size (shell_printf()) */
#define CONFIG_SHELL_PRINTF_BUFFER_SIZE 128U

/*******************************  shell configuration  ****************************/
#define CONFIG_SHELL_PROMPT "⚡leeyangy-shell😀>> "


#endif //MYSHELL_SHELL_CONFIG_H
