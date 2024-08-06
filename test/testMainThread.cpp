#include <gtest/gtest.h>

TEST(main, teststub) {
    int result = 0;
    ASSERT_EQ(result, 0);
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}