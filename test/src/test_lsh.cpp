/**
 * @Author: WangLiyang
 * @Date:   2014/07/13 17:11:52
 * @Brief:  test utils
 */
#include <stdlib.h>
#include <gtest/gtest.h>

#include <sp_lsh.h>

class LSHTest : public ::testing::Test {
protected:
    LSHTest() {}
    virtual ~LSHTest() {}

    virtual void SetUp()
    {
        // SetUp
    }
    
    virtual void TearDown()
    {
        // TearDown
    }
};

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST_F(LSHTest, test_init) {
    wly::LSH test_lsh;
    /// empty people vec
    ASSERT_EQ(-1, test_lsh.init());

    /// load test people then init
    wly::PeopleManager* ppm = wly::PeopleManager::get_instance();
    ASSERT_NE((wly::PeopleManager*)nullptr, ppm);
    ASSERT_EQ(0, ppm->load_people("./test_data/people.dat.10g0b"));
    ASSERT_EQ(0, test_lsh.init());
    ASSERT_EQ(wly::LSH_HASH_COUNT, test_lsh.get_hash_vec_size());
}

TEST_F(LSHTest, test_query) {
    /// init lsh
    wly::LSH test_lsh;
    wly::PeopleManager* ppm = wly::PeopleManager::get_instance();
    ASSERT_NE((wly::PeopleManager*)nullptr, ppm);
    ASSERT_EQ(0, ppm->load_people("./test_data/people.dat.10000"));
    ASSERT_EQ(0, test_lsh.init());

    wly::People test_people;
    test_people.rand_set();
    std::vector<wly::People> test_simpeople_vec;
    ASSERT_EQ(0, test_lsh.query_similar_people(test_people, test_simpeople_vec));

    /// show result
    std::cout << "found similar people for:" << std::endl;
    test_people.display();
    std::cout << "=================================" << std::endl;
    std::cout << "found:" << std::endl;
    for (const auto& people : test_simpeople_vec) {
        people.display();
        std::cout << "..............." << std::endl;
    }
}
