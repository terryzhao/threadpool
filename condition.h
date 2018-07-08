/*
 * =====================================================================================
 *
 *       Filename:  condition.h
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2018年07月08日 10时51分55秒
 *       Revision:  none
 *
 *         Author:  Terry Zhao
 *   Organization:
 *
 * =====================================================================================
 */
#ifndef _CONDITION_H
#define _CONDITION_H

#include <pthread.h>

typedef struct condition {
    pthread_mutex_t pmutex;
    pthread_cond_t  pcond;
}condition_t;

int condition_init(condition_t *cond);
int condition_lock(condition_t *cond);
int condition_unlock(condition_t *cond);
int condition_wait(condition_t *cond);
int condition_timewait(condition_t *cond, const struct timespec *abstime);
int condition_signal(condition_t *cond);
int condition_broadcast(condition_t *cond);
int condition_destroy(condition_t *cond);

#endif //_CONDITION_H

