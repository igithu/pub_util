/***************************************************************************
 * 
 * Copyright (c) 2014 aishuyu, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file test_pool.cpp
 * @author aishuyu(asy5178@163.com)
 * @date 2014/11/18 16:25:01
 * @brief 
 *  
 **/


#include "../thread_pool/thread_pool.h"

using namespace PUBLIC_UTIL;

class Test {
    public:
        Test(int num) : ii(num) {
        }

        ~Test() {
        }

        void Start() {
            ThreadPool pool(5);
            pool.Start();
            printf("Test Start\n");

            Params param;
            param.test_ptr = this;
            param.id = 99;
            printf("Test Start Processor\n");
            pool.Processor(Test::callback, &param);
            sleep(1);
        }

    private:
        int ii;

        struct Params {
            Test* test_ptr;
            int id; 
        };

        static void *callback(void *arg) {
            printf("Test callback\n");
            Params* ptr = (Params*) arg;
            if (ptr == NULL) {
                return NULL;
            }
            printf("Test ii: %d\n", ptr->test_ptr->ii);
            printf("Test id: %d\n", ptr->id);
        }
};

void *func1(void *arg) {
    printf("Func1: the Current thread id is %u, echo str %s\n", pthread_self(), (char*) arg);
    return NULL;
}

void *func2(void *arg) {
    printf("Func2: the Current thread id is %u, echo str %s\n", pthread_self(), (char*) arg);
    return NULL;
}

int main() {
    // ThreadPool pool(5);
    // pool.Start();
    // char* test_str = "thread pool test\n";
    // pool.Processor(func1, test_str);
    // pool.Processor(func2, test_str);
    // pool.Processor(func1, test_str);

    // sleep(1);
    Test test(44);
    test.Start();
}





















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
