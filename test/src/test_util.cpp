/**
 * @Author: WangLiyang
 * @Date:   2014/07/11 23:21:59
 * @Brief:  test utils
 */
#include <stdlib.h>
#include <gtest/gtest.h>

#include <sp_util.h>

class UtilTest : public ::testing::Test {
protected:
    UtilTest() {}
    virtual ~UtilTest() {}

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

TEST_F(UtilTest, test_distance) {
    ASSERT_DOUBLE_EQ(0.0, wly::get_distance(1, 1, 1, 1));
    ASSERT_DOUBLE_EQ(wly::get_distance(1, 10, 1, 20),
            wly::get_distance(-1, 10, -1, 20));
    ASSERT_DOUBLE_EQ(wly::get_distance(10, 90, 10, 100),
            wly::get_distance(-10, -10, -10, -20));
}
