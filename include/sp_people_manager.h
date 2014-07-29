/**
 * @Author: WangLiyang
 * @Date:   2014/07/11 19:25:44
 * @Brief:  
 */
#ifndef _SP_PEOPLE_MANAGER_H_
#define _SP_PEOPLE_MANAGER_H_

#include <sp_people.h>

namespace wly {

/**
 * @Class:  PeopleManager
 * @Brief:  people manager
 */
class PeopleManager {

public:
    /**
     *      get singleton instance of people manager
     *      @return     PeopleManager*  instance
     */
    static PeopleManager* get_instance() {
        if (nullptr == _instance) {
            _instance = new (std::nothrow) PeopleManager();
            if (nullptr == _instance) {
                std::cerr << "alloc PeopleManager failed" << std::endl;
            }
        }
        return _instance;
    }

    /**
     * @Class:  Garbo
     * @Brief:  to delete the instance
     */
    class Garbo {
    public:
        ~Garbo() {
            if (nullptr != PeopleManager::_instance) {
                delete _instance;
                PeopleManager::_instance = nullptr;
            }
        }
    };

    /**
     *      reset people manager
     */
    void reset();

    /**
     *      load people data from file
     *      @param      file    [in]    input file
     *      @return     0       succ
     *                  -1      failed
     */
    int load_people(const std::string& file);

    /**
     *      get people vec
     *      @return     std::vector<People>*    pointer
     */
    inline std::vector<People>* get_people_vec() {
        return &_people_vec;
    }

    /**
     *      get people by index
     *      @return     People  people
     */
    inline People* get_peopl_by_index(size_t index) {
        return (index >= _people_vec.size() ? nullptr : &_people_vec.at(index));
    }


private:
    /// people vector
    std::vector<People> _people_vec;
    /// singleton pointer & garbo
    static PeopleManager* _instance;
    static Garbo _garbo;

};

}

#endif
