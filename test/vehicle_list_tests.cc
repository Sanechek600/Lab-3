#include <gtest/gtest.h>

#include <vehicle/vehicle.h>

using namespace vehicle;
using namespace std;



TEST(IndexOfMinCost, NoResult) {
    VehicleList vehicles;

    const auto index = index_of_min_cost(vehicles, 0, 0);

    ASSERT_EQ(index, -1);
}

TEST(IndexOfMinCost, Main) {
    VehicleList vehicles;
    vehicles.add(make_shared<Train>(10));
    vehicles.add(make_shared<Plane>(10, 0));
    vehicles.add(make_shared<Plane>(10, 1));
    vehicles.add(make_shared<Ship>(10, 0.91));

    const auto index = index_of_min_cost(vehicles, 10, 50);

    ASSERT_EQ(index, 1);
}
