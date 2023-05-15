#include <gtest/gtest.h>

#include <function/function.h>

using namespace vehicle;
using namespace std;



TEST(IndexOfFunctionWithMaxValue, NoResult) {
    VehicleList functions;

    const auto index = index_of_min_cost(functions, 0);

    ASSERT_EQ(index, -1);
}

TEST(IndexOfFunctionWithMaxValue, ArgZero) {
    VehicleList functions;
    functions.add(make_shared<Train>(1));
    functions.add(make_shared<Train>(2));
    functions.add(make_shared<Train>(2));
    functions.add(make_shared<Train>(1));

    const auto index = index_of_min_cost(functions, 0);

    ASSERT_EQ(index, 1);
}

TEST(IndexOfFunctionWithMaxValue, ArgPi) {
    VehicleList functions;
    functions.add(make_shared<Train>(2));
    functions.add(make_shared<Train>(1));
    functions.add(make_shared<Train>(1));
    functions.add(make_shared<Train>(2));

    const auto index = index_of_min_cost(functions, PI);

    ASSERT_EQ(index, 1);
}
