#include <pthread.h>
#include <sp_lsh.h>

namespace wly {

int LSH::init() {
    PeopleManager* ppm = PeopleManager::get_instance();
    if (nullptr == ppm) {
        std::cerr << "get people manager instance failed" << std::endl;
        return -1;
    }
    std::vector<People>* ppvec = ppm->get_people_vec();
    if (nullptr == ppvec) {
        std::cerr << "get people vec failed" << std::endl;
        return -1;
    }
    if (0 == ppvec->size()) {
        std::cerr << "get empty people vec" << std::endl;
        return -1;
    }

    /// init hash func and start load thread
    /// multi-thread, or this stage will be toooooooo slow... >_<
    pthread_t load_thrds[FLAGS_h];
    _lsh_hash_vec.clear();
    _lsh_hash_vec.resize(FLAGS_h);
    for (int i = 0; i < FLAGS_h; ++i) {
        _lsh_hash_vec.at(i).rand_people.rand_set();
        pthread_create(load_thrds + i, nullptr, load_hash, static_cast<void*>(&_lsh_hash_vec.at(i)));
    }

    void* pret = nullptr;
    for (int i = 0; i < FLAGS_h; ++i) {
        pthread_join(load_thrds[i], &pret);
        if (nullptr != pret) {
            std::cerr << "init lsh " << i << " failed" << std::endl;
            return -1;
        }
    }

    return 0;
}

/**
 *      compare people|distance
 *      @param      left    [in]    cmp left
 *      @param      right   [in]    cmp right
 *      @return     true        left < right
 *                  false       left >= right
 */
static inline bool cmp_people_dis(const std::pair<People, double>& left,
        const std::pair<People, double>& right) {
    return left.second < right.second;
}

int LSH::query_similar_people(const People& people,
        std::vector<People>& similar_people) {
    std::unordered_set<int> pre_get_set;
    PeopleManager* ppm = PeopleManager::get_instance();
    if (nullptr == ppm) {
        std::cerr << "get people manager instance failed" << std::endl;
        return -1;
    }

    /// get people from every hash
    int key = 0;
    for (const auto& cur_hash : _lsh_hash_vec) {
        key = (int)(cur_hash.rand_people.calc_dis(people)) >> FLAGS_n;
        // std::cout << "key: " << key << std::endl;

        /// get bucket
        const std::unordered_map<int, std::vector<size_t> >& cur_lsh_hash = cur_hash.lsh_hash;
        const std::vector<int>& cur_lsh_keys = cur_hash.lsh_hash_keys;
        auto map_iter = cur_lsh_hash.find(key);
        /// no bucket, find the close bucket
        if (cur_lsh_hash.end() == map_iter) {
            const auto vec_iter = lower_bound(cur_lsh_keys.begin(),
                        cur_lsh_keys.end(), key);
            key = (vec_iter != cur_lsh_keys.end() ? *vec_iter :
                    cur_lsh_keys.at(cur_lsh_keys.size() - 1));
            map_iter = cur_lsh_hash.find(key);
            if (cur_lsh_hash.end() == map_iter) {
                std::cerr << "get bucket failed" << std::endl;
                continue;
            }
        }
        // std::cout << "found key: " << map_iter->first << std::endl;
        // std::cout << "bucket size: " << map_iter->second.size() << std::endl;

        /// set people id into pre get set
        for (const auto& found_people : map_iter->second) {
            if (pre_get_set.end() == pre_get_set.find(found_people)) {
                pre_get_set.insert(found_people);
            }
        }
    }

    /// calc the real distance
    std::vector<std::pair<People, double> > people_dis_vec;
    People* cur_people = nullptr;
    std::pair<People, double> cur_people_dis;
    // std::cout << "pre get set size " << pre_get_set.size() << std::endl;
    for (const auto people_id : pre_get_set) {
        cur_people = ppm->get_peopl_by_index(people_id);
        if (nullptr == cur_people) {
            std::cerr << "get bad people index " << people_id << std::endl;
            continue;
        }
        cur_people_dis.first = *cur_people;
        cur_people_dis.second = cur_people->calc_dis(people);

        if (people_dis_vec.size() < (size_t)FLAGS_c) {
            people_dis_vec.push_back(cur_people_dis);
            std::make_heap(people_dis_vec.begin(), people_dis_vec.end(), cmp_people_dis);
        } else if (cur_people_dis.second < people_dis_vec.at(0).second) {
            std::pop_heap(people_dis_vec.begin(), people_dis_vec.end(), cmp_people_dis);
            people_dis_vec.pop_back();
            people_dis_vec.push_back(cur_people_dis);
            std::push_heap(people_dis_vec.begin(), people_dis_vec.end(), cmp_people_dis);
        }
    }

    /// copy to result
    similar_people.clear();
    for (const auto& people_dis : people_dis_vec) {
        similar_people.push_back(people_dis.first);
    }
    return 0;
}

void* LSH::load_hash(void* arg) {
    if (nullptr == arg) {
        std::cerr << "load hash failed, arg is nullptr" << std::endl;
        return (void*)1;
    }

    PeopleManager* ppm = PeopleManager::get_instance();
    if (nullptr == ppm) {
        std::cerr << "get people manager instance failed" << std::endl;
        return (void*)1;
    }
    std::vector<People>* ppvec = ppm->get_people_vec();
    if (nullptr == ppvec) {
        std::cerr << "get people vec failed" << std::endl;
        return (void*)1;
    }

    int key = 0;
    lsh_unit_t* lsh_unit = static_cast<lsh_unit_t*>(arg);
    for (size_t j = 0; j < ppvec->size(); ++j) {
        People& cur_people = ppvec->at(j);
        key = (int)(lsh_unit->rand_people.calc_dis(cur_people)) >> FLAGS_n;

        auto iter = lsh_unit->lsh_hash.find(key);
        if (iter == lsh_unit->lsh_hash.end()) {
            lsh_unit->lsh_hash.insert(std::pair<int, std::vector<size_t> >(
                        key, std::vector<size_t>(1, j)));
            lsh_unit->lsh_hash_keys.push_back(key);
        } else {
            iter->second.push_back(j);
        }
    }
    /// sort, to binary search
    std::sort(lsh_unit->lsh_hash_keys.begin(), lsh_unit->lsh_hash_keys.end());

    /// print log
    std::cout << "finish init hash, bucket num ["
        << lsh_unit->lsh_hash_keys.size() << "]" << std::endl;
    return nullptr;

 
}

}
