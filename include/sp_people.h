/**
 * @Author: WangLiyang
 * @Date:   2014/07/11 19:09:16
 * @Brief:  
 */
#ifndef _SP_PEOPLE_H_
#define _SP_PEOPLE_H_

#include <sp_def.h>

namespace wly {

/**
 * @Class:  People
 * @Brief:  define of people
 */
class People {
public:
    /**
     *      constructor
     */
    People() :
        _name("NotInit"),
        _age(0u),
        _latitude(0),
        _longitude(0) {}

    /**
     *      constructor
     *      @param      name        [in]    name
     *      @param      age         [in]    name
     *      @param      latitude    [in]    latitude
     *      @param      longitude   [in]    longitude
     */
    People(const std::string& name, uint32_t age, int latitude, int longitude) :
        _name(name),
        _age(age),
        _latitude(latitude),
        _longitude(longitude) {}

    /**
     *      copy constructor
     *      @param      people      [in]    people
     */
    People(const People& people) :
        _name(people._name),
        _age(people._age),
        _latitude(people._latitude),
        _longitude(people._longitude) {}

    /**
     *      operator =
     *      @param      people      [in]    people
     *      @return     People      *this
     */
    People& operator =(const People& people) {
        if (this != &people) {
            _name = people._name;
            _age = people._age;
            _latitude = people._latitude;
            _longitude = people._longitude;
        }
        return *this;
    }

    /**
     *      set name for people
     *      @param  name    [in]    name
     */
    inline void set_name(const std::string name) {
        _name = name;
    }

    /**
     *      set age for people
     *      @param  age     [in]    age
     */
    inline void set_age(uint32_t age) {
        _age = age;
    }

    /**
     *      set latitude for people
     *      @param  latitude    [in]    latitude
     */
    inline void set_latitude(int latitude) {
        _latitude = latitude;
    }

    /**
     *      set longitude for people
     *      @param  longitude    [in]    longtitude
     */
    inline void set_longitude(int longitude) {
        _longitude = longitude;
    }

    /**
     *      get name
     *      @return     string      name of people
     */
    inline std::string get_name() const {
        return _name;
    }

    /**
     *      get age
     *      @return     uint32_t    age of people
     */
    inline uint32_t get_age() const {
        return _age;
    }

    /**
     *      get latitude
     *      @return     int         latitude of people
     */
    inline int get_latitude() const {
        return _latitude;
    }

    /**
     *      get longitude
     *      @return     int         longitude of people
     */
    inline int get_longitude() const {
        return _longitude;
    }

    /**
     *      show people info
     */
    void display() const;

    /**
     *      parse data from string
     *      @param      str     [in]    input string
     *      @return     0       succ
     *                  -1      fail
     */
    int parse_from_string(const char* str);

    /**
     *      calc distance
     *      @param      people  [in]    target people
     *      @return     double  dis result
     */
    double calc_dis(const People& people) const;

    /**
     *      set peole random
     */
    void rand_set();

    /**
     *      conv people to string
     *      @return     string      people to string
     */
    std::string to_string() const;


private:
    /// people name
    std::string _name;
    /// people age
    uint32_t _age;
    /// people location
    int _latitude;
    int _longitude;
};

}

#endif
