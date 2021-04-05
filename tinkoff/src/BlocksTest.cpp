#include "gtest/gtest.h"
#include "vect.h"

TEST (FillCheckTest, assertTrue) {
    std::vector<std::string> s1 = {"x", "y", "x", "z", "z"};
    std::vector<std::string> s2 = {"1", "1", "y", "f", "2"};
    EXPECT_EQ (true, fill_check(s1, s2));
}

TEST (FillCheckTest, assertFalse) {
    std::vector<std::string> s1 = {"x", "y", "x", "z", "z", "x"};
    std::vector<std::string> s2 = {"1", "1", "y", "f", "2", "z"};
    EXPECT_EQ (false, fill_check(s1, s2));
}

TEST (ValidTest, assertTrue){
    auto inp = std::make_shared<std::vector<std::string>>();
    inp->push_back("x");
    inp->push_back("y");
    inp->push_back("1");
    EXPECT_EQ (true, is_valid(inp));
}
