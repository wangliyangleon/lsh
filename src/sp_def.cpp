#include <sp_def.h>

namespace wly {

/// defines of gflags
DEFINE_string(f, DEFAULT_DATA_PATH, "input people file path");
DEFINE_double(wa, DEFAULT_AGE_DIS_WIEGHT, "weight for age");
DEFINE_double(wl, DEFAULT_LOC_DIS_WIEGHT, "weight for location");
DEFINE_int32(h, LSH_HASH_COUNT, "hash count");
DEFINE_int32(n, LSH_HASH_PN, "param for bucket size");
DEFINE_int32(c, DEFAULT_SIM_PEOPLE_COUNT, "sim people count");

}
