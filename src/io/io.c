/**
******************************************************************************  
* File Name      : io.c  
* Author         : leeyangy  
* E-mail         : liyangyang0713@foxmail.com  
* Create         : 2024/5/27 17:07  
******************************************************************************  
*/

#include <stdio.h>
#include <stdarg.h>

#include "io.h"
#include "../config/shell_config.h"



// 检查是否定义了 __GUNC__ 宏，该宏用于检查编译器是否为 GNU(GCC) 编译器
#if defined(__GNUC__)
// 检查是否已经定义了__weak宏。如果没有定义，下面的代码块将被执行
#ifndef __weak
#define __weak __attribute__((weak))
// 结束 #ifndef __weak条件
#endif /* __weak */
// 结束了#if defined(__GNUC__)条件
#endif /* __GNUC__ */


/******************************* err log ****************************/
#if !(CONFIG_SHELL_PRINTF_BUFFER_SIZE > 0)
#error "the value of CONFIG_SHELL_PRINTF_BUFFER_SIZE must be greater than 0!"
#endif
/******************************* err log ****************************/

void low_level_write_char(char ch) {
    uart_send_char(ch);  // Hypothetical function to send a character via UART
}

// Hypothetical hardware-specific function that sends a character.
void uart_send_char(char ch) {
    // Hardware-specific code to send 'ch' through UART
    // This is platform and hardware dependent and would be implemented accordingly.
}

__weak int shell_printf(const char *format, ...) {
    static char shell_printf_buffer[CONFIG_SHELL_PRINTF_BUFFER_SIZE];

    int length = 0;

    va_list ap;
    va_start(ap, format);

    length = vsnprintf(shell_printf_buffer, CONFIG_SHELL_PRINTF_BUFFER_SIZE, format, ap);

    va_end(ap);

//    for (int i = 0; i < length; i++) {
//        low_level_write_char(shell_printf_buffer[i]);
//    }

    return length;
}

/**
* @Brief: put string
* @Param: [const char *str]
* @return: void
* @Author: liyangyang
* @Date: 2024/5/27 17:57
* @Description:
*/
__weak void shell_puts(const char *str) {
//    while (*str) {
//        low_level_write_char(*str);
//        str++;
//    }
    printf("%s",str);
}

/**
* @Brief: put single character
* @Param: [char ch]
* @return: void
* @Author: liyangyang
* @Date: 2024/5/27 17:57
* @Description:
*/
__weak void shell_putc(char ch) {
//    low_level_write_char(ch);
    printf("%c\n",ch);
}