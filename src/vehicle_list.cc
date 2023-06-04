#include <vehicle/vehicle.h>

#include <stdexcept>
#include <iostream>

using namespace std;



VehicleList::VehicleList(const VehicleList& other) {
    const auto n = other.size();
    _vehicles.reserve(n);
    for (int i = 0; i < n; ++i) {
        _vehicles.push_back(other[i]->clone());
    }
}

VehicleList& VehicleList::operator=(const VehicleList& rhs) {
    VehicleList copy(rhs);
    copy.swap(*this);
    return *this;
}

int VehicleList::size() const {
    return static_cast<int>(_vehicles.size());
}

VehiclePtr VehicleList::operator[](const int index) const {
    return _vehicles.at(index);
}

void VehicleList::add(VehiclePtr v) {
    _vehicles.push_back(v);
}

void VehicleList::insert(VehiclePtr v, const int index) {
    _vehicles.insert(_vehicles.begin() + index, v);
}

void VehicleList::remove(const int index) {
    _vehicles.erase(_vehicles.begin() + index);
}

void VehicleList::swap(VehicleList& other) {
    std::swap(this->_vehicles, other._vehicles);
}

void VehicleList::print(ostream& out) {
    for (int i = 0; i < size(); ++i) {
        this->_vehicles.at(i).get()->print(out);
        out << endl;
    }
}

int index_of_min_cost(const VehicleList& vehicles, const float mass, const float range) {
    int min_index = -1;
    float min_value = 100000000;

    const auto n = vehicles.size();
    for (int i = 0; i < n; ++i) {
        const auto value = vehicles[i]->compute_cost(mass, range);
        if (min_index == -1 or min_value > value) {
            min_index = i;
            min_value = value;
        }
    }

    return min_index;
}
