/**
 * @Author: WangLiyang
 * @Date:   2014/07/11 19:17:51
 * @Brief:  produce people file
 */

#include <gflags/gflags.h>
#include <sp_people.h>

DEFINE_int32(pc, 10000000, "people Count");

int main(int argc, char **argv) {
    gflags::ParseCommandLineFlags(&argc, &argv, true);
    srand((int)time(0));
    wly::People people;

    for (int i = 0; i < FLAGS_pc; ++i) {
        people.rand_set();
        std::cout << people.to_string() << std::endl;
    }
}
