/**
******************************************************************************  
* File Name      : constant.h
* Author         : leeyangy  
* E-mail         : liyangyang0713@foxmail.com  
* Create         : 2024/5/26 3:21  
******************************************************************************  
*/

#ifndef MYSHELL_INIT_H
#define MYSHELL_INIT_H

// shell version
#define MY_SHELL_BUILD_VERDION "1.0"

// get system date time ,use __DATE__ __TIME__
char* init_info=" _      ______ ________     __      _   _  _______     __   _____ _    _ ______ _      _       __      ____   ___  \n"
                "| |    |  ____|  ____\\ \\   / //\\   | \\ | |/ ____\\ \\   / /  / ____| |  | |  ____| |    | |      \\ \\    / /_ | / _ \\ \n"
                "| |    | |__  | |__   \\ \\_/ //  \\  |  \\| | |  __ \\ \\_/ /  | (___ | |__| | |__  | |    | |       \\ \\  / / | || | | |\n"
                "| |    |  __| |  __|   \\   // /\\ \\ | . ` | | |_ | \\   /    \\___ \\|  __  |  __| | |    | |        \\ \\/ /  | || | | |\n"
                "| |____| |____| |____   | |/ ____ \\| |\\  | |__| |  | |     ____) | |  | | |____| |____| |____     \\  /   | || |_| |\n"
                "|______|______|______|  |_/_/    \\_\\_| \\_|\\_____|  |_|    |_____/|_|  |_|______|______|______|     \\/    |_(_)___/ \n"
                "Welcome to the leeyangy-shell " MY_SHELL_BUILD_VERDION "\r\n"
                "Build time: " __DATE__ " " __TIME__ "\n"
                "Source code: https://github.com/leeyangyangy/leeyangy-shell\n"
                "More new features are being developed.\n"
                "Please input help to get help info.\n";



#endif //MYSHELL_INIT_H
