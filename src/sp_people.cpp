#include <sp_people.h>
#include <sp_util.h>

namespace wly {

void People::display() const {
    std::cout << "Name : [" << _name << "]" << std::endl;
    std::cout << "Age : [" << _age << "]" << std::endl;
    if (_latitude > 0) {
        std::cout << "Latitude : [" << _latitude << "S]" << std::endl;
    } else {
        std::cout << "Latitude : [" << -_latitude << "N]" << std::endl;
    }
    if (_longitude > 0) {
        std::cout << "Longitude : [" << _longitude << "E]" << std::endl;
    } else {
        std::cout << "Longitude : [" << -_longitude << "W]" << std::endl;
    }
}

int People::parse_from_string(const char* str) {
    /// check param
    if (nullptr == str) {
        std::cerr << "input str is nullptr" << std::endl;
        return -1;
    }

    /// format
    /// name \t age \t latitude \t longitude
    /// [A-Z|a-z]{1,31} \t [0, 120] \t [0,90][S|N] \t [0,180][E|S]
    const char* cp = str;
    size_t index_cur = 0;
    size_t index_pre = 0;

    /// get name
    while ((*cp != SPLIT_CHAR) && (*cp != '\0')) {
        ++cp;
        ++index_cur;
    }
    if ((SPLIT_CHAR != *cp) ||
            (index_cur <= index_pre)) {
        goto FAIL;
    } else {
        _name.assign(str + index_pre, index_cur - index_pre);
    }
    ++cp;
    index_pre = ++index_cur;

    /// get age
    _age = 0;
    while ((*cp >= '0') && (*cp <= '9')) {
        _age *= 10;
        _age += (*cp - '0');
        ++cp;
        ++index_cur;
    }
    if ((SPLIT_CHAR != *cp) ||
            (index_cur <= index_pre) ||
            (_age > MAX_AGE)) {
        goto FAIL;
    }
    ++cp;
    index_pre = ++index_cur;

    /// get latitude
    _latitude = 0;
    while ((*cp >= '0') && (*cp <= '9')) {
        _latitude *= 10;
        _latitude += (*cp - '0');
        ++cp;
        ++index_cur;
    }
    if ((('S' != *cp) && ('N' != *cp)) ||
            (index_cur <= index_pre) ||
            (_latitude > MAX_LATITUDE)) {
        goto FAIL;
    }
    _latitude *= ('S' == *cp ? 1 : -1);
    ++cp;
    if (SPLIT_CHAR != *cp) {
        goto FAIL;
    }
    ++cp;
    index_pre = (index_cur += 2);

    /// get longitude
    _longitude = 0;
    while ((*cp >= '0') && (*cp <= '9')) {
        _longitude *= 10;
        _longitude += (*cp - '0');
        ++cp;
        ++index_cur;
    }
    if ((('E' != *cp) && ('W' != *cp)) ||
            (index_cur <= index_pre) ||
            (_longitude > MAX_LONGITUDE)) {
        goto FAIL;
    }
    _latitude *= ('E' == *cp ? 1 : -1);
    ++cp;
    if ('\0' != *cp) {
        goto FAIL;
    }

    return 0;

FAIL:
    _name = "ERROR";
    _age = _latitude = _longitude = 0;
    std::cerr << "bad format [" << str << "]" << std::endl;
    return -1;
}

double People::calc_dis(const People& people) const {
    double dis_age = (double)this->_age - people._age;
    double dis_loc = get_distance(this->_latitude, this->_longitude,
            people._latitude, people._longitude);
    double dis = sqrt(pow(dis_age * dis_age, FLAGS_wa) +
            pow(dis_loc * dis_loc, FLAGS_wl));
    // std::cout << pow(dis_age * dis_age, FLAGS_wa) << "\t" << pow(dis_loc * dis_loc, FLAGS_wl) << std::endl;
    return dis;

}

void People::rand_set() {
    int name_len = rand() % (NAME_LENGTH - 1) + 1;
    _name = std::string(1, rand() % 26 + 'A');
    for (int i = 0; i < name_len; ++i) {
        _name.append(1, rand() % 26 + 'a');
    }
    _age = rand() % MAX_AGE;
    _latitude = rand() % MAX_LATITUDE * (0 == (rand() & 0x1) ? 1 : -1);
    _longitude = rand() % MAX_LONGITUDE * (0 == (rand() & 0x1) ? 1 : -1);
}

std::string People::to_string() const {
    std::ostringstream oss;
    /// name
    oss << _name << SPLIT_CHAR;
    /// age
    oss << _age << SPLIT_CHAR;
    /// latitude
    oss << abs(_latitude) << (_latitude > 0 ? 'S' : 'N') << SPLIT_CHAR;
    /// longitude
    oss << abs(_longitude) << (_longitude > 0 ? 'E' : 'W');
    return oss.str();
}

}
