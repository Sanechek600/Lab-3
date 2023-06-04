#include <gtest/gtest.h>

#include <vehicle/vehicle.h>

using namespace std;



TEST(IndexOfMinCost, NoResult) {
    VehicleList vehicles;

    const auto index = index_of_min_cost(vehicles, 0, 0);

    ASSERT_EQ(index, -1);
}

TEST(IndexOfMinCost, AddInsertDeleteTest) {
    VehicleList vehicles;

    auto v1 = make_shared<Train>("Trian1", 10);
    auto v2 = make_shared<Train>("Trian2", 10);
      

    vehicles.add(v1);
    vehicles.insert(v2, 0);

    ASSERT_EQ(vehicles[0].get()->equals(v2), true);
    ASSERT_EQ(vehicles[1].get()->equals(v1), true);

    vehicles.remove(0);

    ASSERT_EQ(vehicles[0].get()->equals(v1), true);
}

TEST(IndexOfMinCost, Main) {
    VehicleList vehicles;
    vehicles.add(make_shared<Train>("Trian1", 10));
    vehicles.add(make_shared<Plane>("Plain1", 10, 0));
    vehicles.add(make_shared<Ship>("Sheap1", 10, 0.91));

    EXPECT_NEAR(vehicles[0]->compute_cost(10, 50), 5000, 1);
    EXPECT_NEAR(vehicles[1]->compute_cost(10, 50), 2500, 1);
    EXPECT_NEAR(vehicles[2]->compute_cost(10, 50), 4995, 1);

    const auto index = index_of_min_cost(vehicles, 10, 50);

    ASSERT_EQ(index, 1);
}
