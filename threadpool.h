/*
 * =====================================================================================
 *
 *       Filename:  threadpool.h
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2018年07月08日 11时03分04秒
 *       Revision:  none
 *
 *         Author:  Terry Zhao
 *   Organization:
 *
 * =====================================================================================
 */

#ifndef _THREAD_POOL_H_
#define _THREAD_POOL_H_

#include "condition.h"

typedef struct task {
    void *(*run)(void* args);
    void *arg;
    struct task* next;
}task_t;

typedef struct threadpool {
    condition_t ready;
    task_t*     first;
    task_t*     last;
    int         counter;
    int         idle;
    int         max_threads;
    int         quit;
}threadpool_t;

void threadpool_init(threadpool_t *pool, int threads);
void threadpool_add_task(threadpool_t *pool, void *(*run)(void *arg), void *arg);
void threadpool_destroy(threadpool_t *pool);

#endif //_THREAD_POOL_H_
