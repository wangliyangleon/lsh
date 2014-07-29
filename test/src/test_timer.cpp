/**
 * @Author: WangLiyang
 * @Date:   2014/07/11 23:26:09
 * @Brief:  test timer
 */
#include <stdlib.h>
#include <gtest/gtest.h>

#include <sp_timer.h>

class TimerTest : public ::testing::Test {
protected:
    TimerTest() {}
    virtual ~TimerTest() {}

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

TEST_F(TimerTest, test_timer) {
    wly::Timer test_timer;
    test_timer.start();
    usleep(2000);

    sleep(1);
    test_timer.check();
    ASSERT_EQ(1, test_timer.sec_elapsed());
    sleep(1);
    test_timer.check();
    ASSERT_EQ(2, test_timer.sec_elapsed());

    test_timer.start();
    test_timer.check();
    ASSERT_EQ(0, test_timer.sec_elapsed());
}

