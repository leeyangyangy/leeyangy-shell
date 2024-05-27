/**
******************************************************************************  
* File Name      : io.h  
* Author         : leeyangy  
* E-mail         : liyangyang0713@foxmail.com  
* Create         : 2024/5/27 17:07  
******************************************************************************  
*/

#ifndef MYSHELL_IO_H
#define MYSHELL_IO_H

/**
* @Brief: put single character
* @Param: [char ch]
* @return: void
* @Author: liyangyang
* @Date: 2024/5/27 17:57
* @Description:
*/
extern void my_putc(char ch);

/**
 * @brief printf() for nano-shell
 *
 */
extern int shell_printf(const char *format, ...) __attribute__((format(printf, 1, 2)));


extern void shell_puts(const char *str);

/**
* @Brief: This function should do the actual transmission of the character.
 *        It can also be implemented by macro definition, for example:
 *        ```
 *        #define low_level_write_char(ch) \
 *          do {                           \
 *            uart_send_char(ch);          \
 *          } while(0)
 *        ```
* @Param: ch the character to be transmitted.
* @return:
* @Author: liyangyang
* @Date: 2024/5/27 18:27
* @Description:  TODO: low_level_write_char
*/
extern void low_level_write_char(char ch);
// TODO: uart_send_char
extern void uart_send_char(char ch);

#endif //MYSHELL_IO_H
