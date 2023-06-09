#include <gtest/gtest.h>
#include <cstring>
#include <vehicle/vehicle.h>

using namespace std;


TEST(VehicleTests, ExceptionTest) {
    EXPECT_ANY_THROW(auto v = make_shared<Ship>("Sheap", 10, 1.5););
}

TEST(VehicleTests, Train_ComputeValue) {
    const auto train_cheap = make_shared<Train>(string("Train1"), 10);
    const auto train_exp = make_shared<Train>(string("Train2"), 100);

    EXPECT_NEAR(train_cheap->compute_cost(10, 50), 5000, 1);
    EXPECT_NEAR(train_cheap->compute_cost(100, 2000), 2000000, 1);

    EXPECT_NEAR(train_exp->compute_cost(10, 50), 50000, 1);
    EXPECT_NEAR(train_exp->compute_cost(100, 2000), 20000000, 1);
}

TEST(VehicleTests, Plane_ComputeValue) {
    const auto plane_tp = make_shared<Plane>(string("Plane1"), 10, 0);
    const auto plane_jet = make_shared<Plane>(string("Plane2"), 10, 1);

    EXPECT_NEAR(plane_tp->compute_cost(10, 50), 2500, 1);
    EXPECT_NEAR(plane_tp->compute_cost(100, 2000), 3000000, 1);

    EXPECT_NEAR(plane_jet->compute_cost(10, 50), 7500, 1);
    EXPECT_NEAR(plane_jet->compute_cost(100, 2000), 1000000, 1);
}

TEST(VehicleTests, Ship_ComputeValue) {
    const auto ship_exp = make_shared<Ship>(string("Ship1"), 10, 0.95);
    const auto ship_cheap = make_shared<Ship>(string("Ship2"), 10, 0.91);

    EXPECT_NEAR(ship_exp->compute_cost(10, 50), 4997, 1);
    EXPECT_NEAR(ship_exp->compute_cost(100, 2000), 1959383, 1);

    EXPECT_NEAR(ship_cheap->compute_cost(10, 50), 4995, 1);
    EXPECT_NEAR(ship_cheap->compute_cost(100, 2000), 1925956, 1);
}
