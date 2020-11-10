#include "gtest/gtest.h"
#include "matrix.h"
namespace {
    class MTest : public ::testing::Test {
        protected:
            Matrix m = Matrix(3, 4);
            Matrix n = Matrix(3, 4);
            Matrix p = Matrix(3, 5);
    };
    TEST_F(MTest, BordersCheck) {

        ASSERT_ANY_THROW(m.At(-1,0));
        ASSERT_ANY_THROW(m.At(3,3));
        ASSERT_ANY_THROW(m.At(2,4));
        ASSERT_ANY_THROW(m.At(0,-1));
        ASSERT_ANY_THROW(n+p);
        ASSERT_TRUE((m+n).At(2,3) == 0);
        ASSERT_TRUE(m == n);
    }
}
