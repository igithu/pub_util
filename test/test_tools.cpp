/***************************************************************************
 * 
 * Copyright (c) 2015 aishuyu, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file test_tools.cpp
 * @author aishuyu(asy5178@163.com)
 * @date 2015/01/09 15:53:01
 * @brief 
 *  
 **/

#include "../tools/tools.h"

#include <stdio.h>

int main() {

    if (!PUBLIC_UTIL::CreateDir("/tmp/tt/ttsub")) {
        printf("fialed\n");
    }

    return 0;
}





















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
