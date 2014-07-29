/**
 * @Author: WangLiyang
 * @Date:   2014/07/11 23:32:32
 * @Brief:  
 */

#include <stdlib.h>
#include <gtest/gtest.h>

#include <sp_people.h>

class PeopleTest : public ::testing::Test {
protected:
    PeopleTest() {}
    virtual ~PeopleTest() {}

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

TEST_F(PeopleTest, test_parse) {
    wly::People test_people;

    /// good case
    ASSERT_EQ(0, test_people.parse_from_string("Wangliyang\t24\t40N\t115E"));
    ASSERT_EQ(0, test_people.get_name().compare("Wangliyang"));
    ASSERT_EQ(24, (int)test_people.get_age());
    ASSERT_EQ(-40, test_people.get_latitude());
    ASSERT_EQ(115, test_people.get_longitude());

    /// bad cases
    ASSERT_EQ(-1, test_people.parse_from_string(nullptr));
    ASSERT_EQ(-1, test_people.parse_from_string("Wangliyang24\t40N\t115E"));
    ASSERT_EQ(-1, test_people.parse_from_string("Wangliyang24\t40N\t"));
    ASSERT_EQ(-1, test_people.parse_from_string("Wangliyang\t24\t100N\t115E"));
    ASSERT_EQ(-1, test_people.parse_from_string("Wangliyang\t24\t40N\t115"));
}
