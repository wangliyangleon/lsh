/**
 * @Author: WangLiyang
 * @Date:   2014/07/11 20:19:21
 * @Brief:  
 */
#ifndef _SP_LSH_H_
#define _SP_LSH_H_

#include <sp_people_manager.h>

namespace wly {

/**
 * @Struct: lsh_unit_t
 * @Brief:  lsh unit
 */
struct lsh_unit_t {
    /// a random people
    People rand_people;

    /// key: distance to rand_people >> N
    /// value: people in bucket
    std::unordered_map<int, std::vector<size_t> > lsh_hash;

    /// all keys, for binary search
    std::vector<int> lsh_hash_keys;
};

/**
 * @Class:  LSH
 * @Brief:  main algorithm
 */
class LSH {
public:
    /**
     *      init LSH by people manager
     *      @return     0       succ
     *                  -1      failed
     */
    int init();

    /**
     *      query similar people by input people
     *      @param      people          [in]    input people
     *      @param      similar_people  [in]    people that similar to input people
     *      @return     0       succ
     *                  -1      failed
     */
    int query_similar_people(const People& people,
            std::vector<People>& similar_people);

    /**
     *      get size of hash vec
     *      @return     size_t      size of hash vec
     */
    inline size_t get_hash_vec_size() {
        return _lsh_hash_vec.size();
    }


private:

    /**
     *      load lsh hash
     *      @param      arg     [in]    arg
     *      @return     nullptr        succ
     *                  (void*)1    failed
     */
    static void* load_hash(void* arg);

    /// lsh hash unit vec
    std::vector<lsh_unit_t> _lsh_hash_vec;

};

}

#endif
