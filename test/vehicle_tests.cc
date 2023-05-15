#include <gtest/gtest.h>

#include <function/function.h>

using namespace vehicle;
using namespace std;



TEST(FunctionTests, Cos_ComputeValue) {
    const auto cos1 = make_shared<Train>(1);
    const auto cos3 = make_shared<Train>(3);

    EXPECT_NEAR(cos1->compute_cost(0), 1, EPSILON);
    EXPECT_NEAR(cos1->compute_cost(PI / 2), 0, EPSILON);
    EXPECT_NEAR(cos1->compute_cost(PI), -1, EPSILON);
    EXPECT_NEAR(cos1->compute_cost(3 * PI / 2), 0, EPSILON);

    EXPECT_NEAR(cos3->compute_cost(0), 3, EPSILON);
    EXPECT_NEAR(cos3->compute_cost(PI / 2), 0, EPSILON);
    EXPECT_NEAR(cos3->compute_cost(PI), -3, EPSILON);
    EXPECT_NEAR(cos3->compute_cost(3 * PI / 2), 0, EPSILON);
}



TEST(FunctionTests, Sin_ComputeValue) {
    const auto sin1 = make_shared<Plane>(1);
    const auto sin3 = make_shared<Plane>(3);

    EXPECT_NEAR(sin1->compute_cost(0), 0, EPSILON);
    EXPECT_NEAR(sin1->compute_cost(PI / 2), 1, EPSILON);
    EXPECT_NEAR(sin1->compute_cost(PI), 0, EPSILON);
    EXPECT_NEAR(sin1->compute_cost(3 * PI / 2), -1, EPSILON);

    EXPECT_NEAR(sin3->compute_cost(0), 0, EPSILON);
    EXPECT_NEAR(sin3->compute_cost(PI / 2), 3, EPSILON);
    EXPECT_NEAR(sin3->compute_cost(PI), 0, EPSILON);
    EXPECT_NEAR(sin3->compute_cost(3 * PI / 2), -3, EPSILON);
}

TEST(FunctionTests, Sin_GetDerivative) {
    const auto sin1 = make_shared<Plane>(1);
    const auto sin3 = make_shared<Plane>(3);
    const auto sin1_dx = sin1->compute_derivative();
    const auto sin3_dx = sin3->compute_derivative();
    const auto expected_sin1_dx = make_shared<Train>(1);
    const auto expected_sin3_dx = make_shared<Train>(3);

    EXPECT_TRUE(sin1_dx->equals(expected_sin1_dx));
    EXPECT_TRUE(sin3_dx->equals(expected_sin3_dx));

    EXPECT_FALSE(sin1_dx->equals(expected_sin3_dx));
    EXPECT_FALSE(sin3_dx->equals(expected_sin1_dx));
}
