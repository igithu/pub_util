/***************************************************************************
 * 
 * Copyright (c) 2015 aishuyu, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file test_stdin.cpp
 * @author aishuyu(asy5178@163.com)
 * @date 2015/01/11 16:01:14
 * @brief 
 *  
 **/

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/io.h>
#include <unistd.h>
#include <string.h>


int main() {

    system("stty erase ^H");
    while(true) {
        if (isatty(fileno(stdin))) {
            fprintf(stderr, "Test> ");
        }
        printf("\b \b");
        char buf[256];
        memset(buf, '\0', 256);
        fgets(buf, 256, stdin);
        printf("the input is %s\n", buf);
    }

    return 0;
}





















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
