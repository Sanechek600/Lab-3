#pragma once

#include <memory>
#include <vector>

namespace vehicle {

    const float PI = 3.141592f;

    const float EPSILON = 0.00001f;



    enum class VType {
        Train,
        Plane,
        Ship
    };



    class Vehicle;

    using VehiclePtr = std::shared_ptr<Vehicle>;

    class Vehicle {
    private:
        float _base_tariff;
    public:
        virtual float compute_cost(float mass, float range) const = 0;

        virtual VehiclePtr clone() const = 0;
        virtual bool equals(VehiclePtr other) const = 0;

        virtual ~Vehicle() = default;

        float get_bt() const;
        void set_bt(float bt);
    protected:
        Vehicle() = default;
        Vehicle(const Vehicle&) = default;
        Vehicle& operator=(const Vehicle&) = default;
    };



    class Train : public Vehicle {
    public:
        Train(float base_tariff);

        float compute_cost(float mass, float range) const override;

        VehiclePtr clone() const override;
        bool equals(VehiclePtr other) const override;
    };

    enum AirEngType {
        Turboprop,
        Jet
    };

    class Plane : public Vehicle {
    private:
        AirEngType _eng_type;

    public:
        Plane(float base_tariff, AirEngType eng_type);

        AirEngType get_et() const;

        float compute_cost(float mass, float range) const override;

        VehiclePtr clone() const override;
        bool equals(VehiclePtr other) const override;
    };



    class Ship : public Vehicle {
    private:
        float _range_mod;

    public:
        Ship(float base_tariff, float eng_type);

        float get_rm() const;

        float compute_cost(float mass, float range) const override;

        VehiclePtr clone() const override;
        bool equals(VehiclePtr other) const override;
    };


    class VehicleList {
    private:
        std::vector<VehiclePtr> _vehicles;

    public:
        VehicleList() = default;

        VehicleList(const VehicleList& other);

        VehicleList& operator=(const VehicleList& rhs);

        int size() const;

        VehiclePtr operator[](int index) const;

        void add(VehiclePtr f);

        void swap(VehicleList& other);
    };



    int index_of_min_cost(const VehicleList& vehicles, float mass, float range);
}
