/**
 * @Author: WangLiyang
 * @Date:   2014/07/13 15:57:29
 * @Brief:  
 */

#include <stdlib.h>
#include <gtest/gtest.h>

#include <sp_people_manager.h>

class PeopleManagerTest : public ::testing::Test {
protected:
    PeopleManagerTest() {}
    virtual ~PeopleManagerTest() {}

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

TEST_F(PeopleManagerTest, test_load) {
    wly::PeopleManager* ppm = nullptr;
    std::vector<wly::People>* ppvec = nullptr;
    wly::People* pp = nullptr;
    
    ppm = wly::PeopleManager::get_instance();
    ASSERT_NE((wly::PeopleManager*)nullptr, ppm);
    ppm->reset();

    ppvec = ppm->get_people_vec();
    ASSERT_NE((std::vector<wly::People>*)nullptr, ppvec);
    ASSERT_EQ(0u, ppvec->size());

    /// good cases
    /// 10 good lines
    ASSERT_EQ(0, ppm->load_people("./test_data/people.dat.10g0b"));
    ASSERT_EQ(10u, ppvec->size());
    pp = ppm->get_peopl_by_index(0);
    ASSERT_NE((wly::People*)nullptr, pp);
    ASSERT_EQ(0, pp->get_name().compare("Zn"));
    pp = ppm->get_peopl_by_index(10);
    ASSERT_EQ((wly::People*)nullptr, pp);
    /// 8 good lines, 2 bad lines
    ASSERT_EQ(0, ppm->load_people("./test_data/people.dat.8g2b"));
    ASSERT_EQ(8u, ppvec->size());
    pp = ppm->get_peopl_by_index(0);
    ASSERT_NE((wly::People*)nullptr, pp);
    ASSERT_EQ(0, pp->get_name().compare("Xh"));
    pp = ppm->get_peopl_by_index(8);
    ASSERT_EQ((wly::People*)nullptr, pp);

    /// bad case
    /// no file
    ASSERT_EQ(-1, ppm->load_people("./test_data/people.dat.no"));
    ASSERT_EQ(0u, ppvec->size());
    pp = ppm->get_peopl_by_index(0);
    ASSERT_EQ(nullptr, pp);
}
