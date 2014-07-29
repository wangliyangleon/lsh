/**
 * @Author: WangLiyang
 * @Date:   2014/07/11 19:11:48
 * @Brief:  
 */
#ifndef _SP_DEF_H_
#define _SP_DEF_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <time.h>
#include <math.h>
#include <gflags/gflags.h>

namespace wly {

/// input file format def
const uint32_t NAME_LENGTH = 12;
const uint32_t BUF_MAX_LENGTH = 1024;
const char SPLIT_CHAR = '\t';
const uint32_t MAX_AGE = 120;
const int MAX_LATITUDE = 90;
const int MAX_LONGITUDE = 180;
const char * const DEFAULT_DATA_PATH = "./data/people.dat";

/// def for calc
const double EARTH_RADIUS = 6378.137;
const int DEFAULT_SIM_PEOPLE_COUNT = 10;

/// def for algorithm
const double DEFAULT_AGE_DIS_WIEGHT = 2.5;
const double DEFAULT_LOC_DIS_WIEGHT = 1.0;
const size_t LSH_HASH_COUNT = 10;
const int LSH_HASH_PN = 1;

/// declare of gflags
DECLARE_string(f);
DECLARE_double(wa);
DECLARE_double(wl);
DECLARE_int32(h);
DECLARE_int32(n);
DECLARE_int32(c);

}

#endif
