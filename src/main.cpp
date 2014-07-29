#include <sp_lsh.h>
#include <sp_timer.h>

inline void trim_str(char* str) {
    if (nullptr != str) {
        size_t len = strlen(str);
        if (len > 0 && '\n' == str[len - 1]) {
            str[len - 1] = '\0';
        }
    }
}


int main(int argc, char **argv) {
    gflags::ParseCommandLineFlags(&argc, &argv, true);
    srand((int)time(0));
    wly::Timer timer;
    wly::LSH lsh;

    /// 1. get and load people manager
    timer.start();
    wly::PeopleManager* ppm = wly::PeopleManager::get_instance();
    if (nullptr == ppm) {
        std::cerr << "get people manager instance failed" << std::endl;
        return -1;
    }
    if (0 != ppm->load_people(wly::FLAGS_f)) {

    }
    timer.check();
    std::cout << "finished load people data, cost "
        << timer.msec_elapsed() << " msec" << std::endl;

    /// 2. init lsh
    timer.start();
    if (0 != lsh.init()) {
        std::cerr << "init lsh failed" << std::endl;
        return -1;
    }
    timer.check();
    std::cout << "finished init lsh, cost "
        << timer.msec_elapsed() << " msec" << std::endl;

    /// 3. static test
    /*
    timer.start();
    wly::People rand_people;
    rand_people.rand_set();
    std::vector<wly::People> similar_people;
    if (0 != lsh.query_similar_people(rand_people, similar_people)) {
        std::cerr << "get similar people failed" << std::endl;
        return -1;
    }
    timer.check();
    std::cout << "finished query lsh, cost "
        << timer.msec_elapsed() << " msec" << std::endl;
    std::cout << "found similar people for:" << std::endl;
    rand_people.display();
    std::cout << "=================================" << std::endl;
    std::cout << "found:" << std::endl;
    for (const auto& people : similar_people){
        people.display();
        std::cout << "..............." << std::endl;
    }
    */

    /// 4. input test case
    std::string format_str = "";
    char field_buf[wly::NAME_LENGTH];
    wly::People test_people;
    std::cout << "Begin Service..." << std::endl;
    std::cout << "\tIf you want to end the program,"
        "input *END* anytime you want." << std::endl;

    for (;;) {
        format_str = "";
        std::cout << "*Please input name..." << std::endl;
        fgets(field_buf, wly::NAME_LENGTH, stdin);
        trim_str(field_buf);
        if (0 == strcmp(field_buf, "*END*")) {
            break;
        }
        format_str += field_buf;
        format_str += std::string(1, wly::SPLIT_CHAR);

        std::cout << "*Please input age..." << std::endl;
        fgets(field_buf, wly::NAME_LENGTH, stdin);
        trim_str(field_buf);
        if (0 == strcmp(field_buf, "*END*")) {
            break;
        }
        format_str += field_buf;
        format_str += std::string(1, wly::SPLIT_CHAR);

        std::cout << "*Please input latitude... (like 11N, 32S)" << std::endl;
        fgets(field_buf, wly::NAME_LENGTH, stdin);
        trim_str(field_buf);
        if (0 == strcmp(field_buf, "*END*")) {
            break;
        }
        format_str += field_buf;
        format_str += std::string(1, wly::SPLIT_CHAR);

        std::cout << "*Please input longitude... (like 123E, 33W)" << std::endl;
        fgets(field_buf, wly::NAME_LENGTH, stdin);
        trim_str(field_buf);
        if (0 == strcmp(field_buf, "*END*")) {
            break;
        }
        format_str += field_buf;

        if (0 == test_people.parse_from_string(format_str.c_str())) {
            std::cout << "get similor people for: " << std::endl;
            test_people.display();

            timer.start();
            std::vector<wly::People> similar_people;
            if (0 != lsh.query_similar_people(test_people, similar_people)) {
                std::cerr << "get similar people failed" << std::endl;
                return -1;
            }
            timer.check();
            std::cout << "found:" << std::endl;
            for (const auto& people : similar_people){
                people.display();
                std::cout << "..............." << std::endl;
            }
            std::cout << "this query cost "
                << timer.msec_elapsed() << " msec" << std::endl;
        }
    }



    return 0;
}
