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
    vehicles.add(make_shared<Train>("Trian1", 10));
    vehicles.add(make_shared<Plane>("Plain1", 10, 0));
    vehicles.add(make_shared<Plane>("Plain2", 10, 1));
    vehicles.add(make_shared<Ship>("Sheap1", 10, 0.91));

    const auto index = index_of_min_cost(vehicles, 10, 50);

    ASSERT_EQ(index, 1);
}
