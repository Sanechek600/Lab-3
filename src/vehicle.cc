#include <function/function.h>

#include <cassert>
#include <cmath>
#include <stdexcept>

using namespace vehicle;
using namespace std;




float Vehicle::get_bt() const {
    return _base_tariff;
}

void Vehicle::set_bt(float bt) {
    _base_tariff = bt;
}

Train::Train(const float base_tariff) {
    set_bt(base_tariff);
}

float Train::compute_cost(const float mass, const float range) const {
    return mass * range * get_bt();
}

VehiclePtr Train::clone() const {
    return make_shared<Train>(get_bt());
}

bool Train::equals(VehiclePtr other) const {
    const auto downcasted_other = dynamic_pointer_cast<Train>(other);
    if (downcasted_other == nullptr) {
        return false;
    }

    return get_bt() == downcasted_other->get_bt();
}


Plane::Plane(const float base_tariff, const AirEngType eng_type) :
    _eng_type(eng_type)
{
    set_bt(base_tariff);
}

AirEngType Plane::get_et() const {
    return _eng_type;
}

float Plane::compute_cost(const float mass, const float range) const {
    return (get_et() == AirEngType::Turboprop) ? (range < 1000) ? mass * range * get_bt() * 0.5 : mass * range * get_bt() * 1.5 : (range < 1000) ? mass * range * get_bt() * 1.5 : mass * range * get_bt() * 0.5;
}

VehiclePtr Plane::clone() const {
    return make_shared<Plane>(get_bt(), _eng_type);
}

bool Plane::equals(VehiclePtr other) const {
    const auto downcasted_other = dynamic_pointer_cast<Plane>(other);
    if (downcasted_other == nullptr) {
        return false;
    }

    return (get_bt() == downcasted_other->get_bt())&&(_eng_type == downcasted_other->_eng_type);
}


Ship::Ship(const float base_tariff, const float range_mod) {
    _range_mod = (range_mod >= 0.9 && range_mod <= 1.0) ? range_mod : 0;
    set_bt(base_tariff);
}

float Ship::get_rm() const {
    return _range_mod;
}

float Ship::compute_cost(const float mass, const float range) const {
    return mass * range * get_bt() * pow(_range_mod, range / 5000);
}

VehiclePtr Ship::clone() const {
    return make_shared<Plane>(get_bt(), _range_mod);
}

bool Ship::equals(VehiclePtr other) const {
    const auto downcasted_other = dynamic_pointer_cast<Ship>(other);
    if (downcasted_other == nullptr) {
        return false;
    }

    return (get_bt() == downcasted_other->get_bt()) && (_range_mod == downcasted_other->_range_mod);
}