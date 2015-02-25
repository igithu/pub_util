/***************************************************************************
 * 
 * Copyright (c) 2014 aishuyu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file pthread_cond.h
 * @author aishuyu(asy5178@163.com)
 * @date 2014/11/17 11:11:01
 * @brief 
 *  
 **/




#ifndef  __PTHREAD_COND_H_
#define  __PTHREAD_COND_H_

#include "pthread_mutex.h"

namespace PUBLIC_UTIL {

class Condition {

    public:
        Condition() : create_success_(false) {
            int ret = pthread_cond_init(&cond_, NULL);
            if (0 == ret) {
                create_success_ = true;
            } else {
                fprintf(stderr, "pthread init cond failed! the error num is %d\n", ret);
            }
        }

        ~Condition() {
            int ret = pthread_cond_destroy(&cond_);
            if (0 != ret) {
                fprintf(stderr, "pthread destroy cond failed! the error num is %d\n", ret);
            }
        }

        bool IsSuccess() {
            return create_success_;
        }

        pthread_cond_t& MCondition() {
            return cond_;
        }
        
    private:
        bool create_success_;
        pthread_cond_t cond_;

};

static bool ConditionWait(Condition &cond, Mutex &mutex) {
    int ret = pthread_cond_wait(&cond.MCondition(), &mutex.MMutex());
    if (0 == ret) {
        return true;
    } 
    fprintf(stderr, "pthread wait cond and mutex failed! the error num is %d\n", ret);
    return false;
}

static bool ConditionSignal(Condition &cond) {
    int ret = pthread_cond_signal(&cond.MCondition());
    if (0 == ret) {
        return true;
    }
    fprintf(stderr, "pthread send signal failed! the error num is %d\n", ret);
    return false;
}

static bool ConditionBroadCast(Condition &cond) {
    int ret = pthread_cond_broadcast(&cond.MCondition());
    if (0 == ret) {
        return true;
    }
    fprintf(stderr, "pthread broadcast signal failed! the error num is %d\n", ret);
    return false;
} 

}  // end of namespace

#endif  //__PTHREAD_COND_H_


/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
