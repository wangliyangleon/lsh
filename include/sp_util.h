/**
 * @Author: WangLiyang
 * @Date:   2014/07/11 19:06:53
 * @Brief:  
 */
#ifndef _SP_UTIL_H_
#define _SP_UTIL_H_

#include <sp_def.h>

namespace wly {

/**
 *      get distance by latitude and longitude
 *      @param      lat1    [in]    latitude1
 *      @param      lng1    [in]    longitude1
 *      @param      lat2    [in]    latitude2
 *      @param      lng2    [in]    longitude2
 *      @return     double  distance
 */
double get_distance(double lat1, double lng1, double lat2, double lng2);

}

#endif
