#include <sp_people_manager.h>

namespace wly {

PeopleManager* PeopleManager::_instance = nullptr;
PeopleManager::Garbo PeopleManager::_garbo;

void PeopleManager::reset() {
    _people_vec.clear();
}

int PeopleManager::load_people(const std::string& file) {
    char line[BUF_MAX_LENGTH];
    size_t line_len = 0;
    size_t line_index = 0;
    size_t error_count = 0;
    reset();

    /// open file
    FILE* fp = fopen(file.c_str(), "r");
    if (nullptr == fp) {
        std::cerr << "open people data file " << file.c_str() << " failed" << std::endl;
        return -1;
    }

    People cur_people;
    while (fgets(line, BUF_MAX_LENGTH, fp)) {
        line_len = strlen(line);
        if (0 == line_len) {
            continue;
        }
        if ('\n' == line[line_len - 1]) {
            line[line_len - 1] = '\0';
        }
        if (0 == cur_people.parse_from_string(line)) {
            _people_vec.push_back(cur_people);
            ++line_index;
        } else {
            ++error_count;
        }
    }
    std::cout << "finished load all data, succ [" << line_index
        << "], failed [" << error_count << "]" << std::endl;
    return 0;
}

}
