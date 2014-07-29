/**
 * @Author: WangLiyang
 * @Date:   2014/07/11 21:18:48
 * @Brief:  
 */
#ifndef _SP_TIMER_H_
#define _SP_TIMER_H_

#include <time.h>
#include <sys/time.h>
#include <stdint.h>

namespace wly {

/**
 * @Class:  Timer
 * @Brief:  timer, for calc time
 */
class Timer {
public:

    /**
     *      constructor
     */
    Timer() {
        _start_t.tv_sec = 0;
        _start_t.tv_usec = 0;

        _check_t.tv_sec = 0;
        _check_t.tv_usec = 0;
    }

    /**
     *      set start time
     */
    inline void start() {
        gettimeofday(&_start_t, nullptr);
        _check_t = _start_t;
    }

    /**
     *      set check time
     */
    inline void check() {
        gettimeofday(&_check_t, nullptr);
    }

    /**
     *      get time in usec
     *      @return     long    get time in usec
     */
    inline long usec_elapsed() const {
        return (_check_t.tv_sec - _start_t.tv_sec) * 1000 * 1000L +
            (_check_t.tv_usec - _start_t.tv_usec);
    }

    /**
     *      get time in msec
     *      @return     long    get time in msec
     */
    inline long msec_elapsed() const {
        return usec_elapsed() / 1000L;
    }

    /**
     *      get time in sec
     *      @return     long    get time in sec
     */
    inline long sec_elapsed() const {
        return msec_elapsed() / 1000L;
    }

private:
    /// start time
    struct timeval _start_t;
    /// chech time
    struct timeval _check_t;
};

}

#endif
