#include <sp_util.h>

namespace wly {
    
double get_distance(double lat1, double lng1, double lat2, double lng2) {
    /// copy from google map
    auto get_rad = [] (double d) ->double {
        return d * M_PI / 180.0;
    };
    double radLat1 = get_rad(lat1);
    double radLat2 = get_rad(lat2);
    double a = radLat1 - radLat2;
    double b = get_rad(lng1) - get_rad(lng2);
    double s = 2 * asin(sqrt(pow(sin(a / 2), 2) + 
                cos(radLat1) * cos(radLat2) * pow(sin(b / 2), 2)));
    s *= EARTH_RADIUS;
    s = round(s * 10000) / 10000;
    return s;

}

}
